'********************************* Module Header **********************************\
' Module Name:  DataGridViewPaging.vb
' Project:      VBWinFormDataGridView
' Copyright (c) Microsoft Corporation.
' 
' This sample demonstrates how to page data in the  DataGridView control;
' 
' This source is subject to the Microsoft Public License.
' See http://www.microsoft.com/en-us/openness/resources/licenses.aspx#MPL.
' All other rights reserved.

' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
' EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
' WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
'**********************************************************************************/

Imports System.Data.SqlClient
Imports System.Configuration
Imports System.Collections.Generic


Namespace VBWinFormDataGridView.DataGridViewPaging

    Public Class MainForm
        Implements IOrderInformationRetriever

        Private PageSize As Integer = 30
        Private CurrentPageIndex As Integer = 1
        Private TotalPage As Integer
        Private connstr As String = ConfigurationManager.AppSettings("connectionString").ToString()
        Private conn As SqlConnection
        Private adapter As SqlDataAdapter
        Private command As SqlCommand
        Private dtable As DataTable

        Private Sub MainForm_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
            Me.conn = New SqlConnection(connstr)
            Me.adapter = New SqlDataAdapter()
            Me.command = conn.CreateCommand()

            ' Get total count of the pages
            Me.GetTotalPageCount()
            Me.dataGridView1.ReadOnly = True

            ' Load the first page of data
            Me.Text = "MainForm – Page " & Me.CurrentPageIndex.ToString()

            Dim intarray = Enumerable.Range(1, 25).Where(Function(numberin As Integer)
                                                             Return (numberin Mod 5) = 0
                                                         End Function) _
                                                    .Select(Function(numberin As Integer)
                                                                Return numberin.ToString()
                                                            End Function)

            For Each strin As String In intarray
                ComboBox1.Items.Add(strin)
            Next

            ComboBox1.SelectedIndex = ComboBox1.Items.Count - 1

        End Sub

        Private Sub GetTotalPageCount()
            command.Parameters.Clear()
            command.CommandType = CommandType.Text
            command.CommandText = "Select Count(OrderID) From Orders"
            Try
                conn.Open()
                Dim rowCount As Integer = CType(command.ExecuteScalar(), Integer)
                Me.TotalPage = rowCount / PageSize
                If rowCount Mod PageSize > 0 Then
                    Me.TotalPage += 1
                End If
            Catch ex As Exception
                MessageBox.Show(ex.Message)
            Finally
                conn.Close()
            End Try
        End Sub

        Private Function GetPageData(ByVal page As Integer) As DataTable
            Dim dt As DataTable = New DataTable()
            command.Parameters.Clear()
            command.CommandType = CommandType.StoredProcedure

            command.CommandText = "usp_paginateorders"

            command.Parameters.Add("@pageNumber", SqlDbType.Int).Value = page
            command.Parameters.Add("@numberOfRows", SqlDbType.Int).Value = PageSize
            Try
                Me.conn.Open()
                Me.adapter.SelectCommand = command
                Me.adapter.Fill(dt)
            Catch ex As Exception
                MessageBox.Show(ex.Message)
            Finally
                conn.Close()
            End Try
            Dim view As New DataView(dt)
            view.Sort = "CustomerID"
            Dim dtout As DataTable = view.ToTable()
            Me.dtable = dtout
            Return dtout
        End Function

        Private Sub toolStripButtonFirst_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles toolStripButtonFirst.Click
            Me.CurrentPageIndex = 1
            Me.Text = "MainForm – Page " & Me.CurrentPageIndex.ToString()
            Me.dataGridView1.DataSource = GetPageData(Me.CurrentPageIndex)
        End Sub

        Private Sub toolStripButtonPrev_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles toolStripButtonPrev.Click
            If Me.CurrentPageIndex > 1 Then
                Me.CurrentPageIndex -= 1
                Me.Text = "MainForm – Page " & Me.CurrentPageIndex.ToString()
                Me.dataGridView1.DataSource = GetPageData(Me.CurrentPageIndex)
            End If
        End Sub

        Private Sub toolStripButtonNext_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles toolStripButtonNext.Click
            If Me.CurrentPageIndex < Me.TotalPage Then
                Me.CurrentPageIndex += 1
                Me.Text = "MainForm – Page " & Me.CurrentPageIndex.ToString()
                Me.dataGridView1.DataSource = GetPageData(Me.CurrentPageIndex)
            End If
        End Sub

        Private Sub toolStripButtonLast_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles toolStripButtonLast.Click
            Me.CurrentPageIndex = TotalPage
            Me.Text = "MainForm – Page " & Me.CurrentPageIndex.ToString()
            Me.dataGridView1.DataSource = GetPageData(Me.CurrentPageIndex)
        End Sub

        Private Sub ComboBox1_SelectedIndexChanged(sender As Object, e As EventArgs) Handles ComboBox1.SelectedIndexChanged
            Me.PageSize = Int32.Parse(ComboBox1.Items(ComboBox1.SelectedIndex))
            Me.GetTotalPageCount()
            Me.dataGridView1.DataSource = GetPageData(Me.CurrentPageIndex)
        End Sub

        Public Function GetOrderInformationAmountTotal() As List(Of OrderInformation) Implements IOrderInformationRetriever.GetOrderInformationAmountTotal
            Dim dt As DataTable = New DataTable()
            command.Parameters.Clear()
            command.CommandType = CommandType.Text
            command.CommandText = _
            "SELECT Orders.OrderID, Customers.CompanyName, SUM([Order Details].UnitPrice * [Order Details].Quantity) as Aprice" _
            & "FROM [Orders]" _
            & "JOIN [Customers] ON Customers.CustomerID = Orders.CustomerID" _
            & "JOIN [Order Details] ON [Order Details].OrderID = Orders.OrderID" _
            & "WHERE Orders.CustomerID = (SELECT TOP 1 CustomerID" _
            & "FROM [Northwind].dbo.Orders" _
            & "GROUP BY CustomerID" _
            & "ORDER BY COUNT(*) DESC)" _
            & "GROUP BY Customers.CompanyName, Orders.OrderID" _
            & "ORDER BY Orders.OrderID DESC"

            Try
                conn.Open()
                Me.adapter.SelectCommand = command
                Me.adapter.Fill(dt)
            Catch ex As Exception
                MessageBox.Show(ex.Message)
            Finally
                conn.Close()
            End Try

            Dim drlist As New List(Of DataRow)
            For Each row As DataRow In dt.Rows
                drlist.Add(CType(row, DataRow))
            Next
            Return drlist.Select(Function(rowin As DataRow)
                                     Return New OrderInformation With {
                                         .CompanyName = rowin.Item("CompanyName"),
                                         .OrderId = rowin.Item("OrderID"),
                                         .OrderUnitPrice = rowin.Item("Aprice")
                                         }
                                 End Function)
        End Function
    End Class

End Namespace