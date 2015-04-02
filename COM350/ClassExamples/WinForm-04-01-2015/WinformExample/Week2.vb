Public Class Week2

    Public formHeight As Integer
    Public startingLocation As String = String.Empty

    Private Sub buttonLauncher_Click(sender As Object, e As EventArgs) Handles buttonLauncher.Click

        If fbdSelector.ShowDialog() = Windows.Forms.DialogResult.OK Then
            startingLocation = fbdSelector.SelectedPath
            textboxStartingLocation.Text = startingLocation
        End If

    End Sub

    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        Me.Text = "Week 2"
        formHeight = Me.Height

        'MessageBox.Show("The form height is: " & formHeight, "Caption", _
        '                MessageBoxButtons.OK, MessageBoxIcon.Information)
        Dim startingYValue As Integer = formHeight - (23 + 45)
        Dim defaultSize As Size = New Size(75, 23)
        Dim buttonDynamic As Button = New Button()
        buttonDynamic.Location = New Point(10, startingYValue)
        buttonDynamic.Size = defaultSize
        buttonDynamic.Text = "Dynamic"
        buttonDynamic.Name = "buttonDynamic"
        buttonDynamic.Visible = True

        Me.Controls.Add(buttonDynamic)

        comboBoxManual.Items.Add("Greenland")
        comboBoxManual.Items.Add("Iceland")
        comboBoxManual.Items.Add("Finland")
        comboBoxManual.Items.Add("Ireland")
        comboBoxManual.Items.Add("Poland")
        comboBoxManual.Items.Add("England")

        Dim arrayOfStrings As String() = {"one", "two", "three", "four", "five"}
        comboBoxGenerics.Items.Insert(0, "-- SELECT -- ")
        comboBoxGenerics.DataSource = arrayOfStrings


        comboBoxStates.DataSource = LoadStates()
        comboBoxStates.DisplayMember = "StateName"
        comboBoxStates.ValueMember = "StateAbbreviation"


    End Sub

    Private Function LoadData() As String()
        Return {"six", "seven", "eight", "nine", "ten"}
    End Function

    Private Sub comboBoxStates_SelectedIndexChanged(sender As Object, e As EventArgs) Handles comboBoxStates.SelectedIndexChanged

        textboxIndex.Text = comboBoxStates.SelectedIndex.ToString()
        Dim currentState As State = CType(comboBoxStates.SelectedItem, State)
        ' Dim currentState As State = DirectCast(comboBoxStates.SelectedItem, State)
        ' textboxValue.Text = currentState.StateAbbreviation

    End Sub

    Private Function LoadStates() As List(Of State)
        Dim listOfStates As List(Of State) = New List(Of State)()

        listOfStates.Add(New State With {
                            .StateAbbreviation = "OH",
                            .StateName = "Ohio"
                         })
        listOfStates.Add(New State With {
                            .StateAbbreviation = "NY",
                            .StateName = "New York"
                         })
        listOfStates.Add(New State With {
                            .StateAbbreviation = "GA",
                            .StateName = "Georgia"
                         })
        listOfStates.Add(New State With {
                            .StateAbbreviation = "WY",
                            .StateName = "Wyoming"
                         })
        listOfStates.Add(New State With {
                            .StateAbbreviation = "HI",
                            .StateName = "Hawaii"
                         })

        Return listOfStates
    End Function

    Private Sub ExitToolStripMenuItem_Click(sender As Object, e As EventArgs) Handles ExitToolStripMenuItem.Click
        Application.Exit()
    End Sub

    Private Sub LaunchTimerToolStripMenuItem_Click(sender As Object, e As EventArgs) Handles LaunchTimerToolStripMenuItem.Click
        Dim frmTimerForm As TimerForm = New TimerForm()
        frmTimerForm.ShowDialog()
    End Sub
End Class

' Type, Data Type, Custom Type, Custom Class
Public Class State

#Region "Members and Properties"
    Private _stateAbbreviation As String
    Public Property StateAbbreviation() As String
        Get
            Return _stateAbbreviation
        End Get
        Set(ByVal value As String)
            _stateAbbreviation = value
        End Set
    End Property

    Private _stateName As String
    Public Property StateName() As String
        Get
            Return _stateName
        End Get
        Set(ByVal value As String)
            _stateName = value
        End Set
    End Property
#End Region

End Class
