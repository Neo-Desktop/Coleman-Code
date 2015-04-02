<%--
/*********************************************************************
 * Glacier Point Project - Departments Page
 * Date: 6/10/2014
 * By: Amrit Panesar - 77260
 *********************************************************************/
 --%>
<%@ Page Language="C#" MasterPageFile="~/GlacierPoint.Master" AutoEventWireup="true"
    CodeBehind="Departments.aspx.cs" Inherits="GlacierPoint.Departments" Title="GlacierPoint Departments" %>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
    <h1>
        GlacierPoint Departments</h1>
    <asp:GridView ID="departmentsGrid" runat="server" AllowPaging="True" OnPageIndexChanging="departmentsGrid_PageIndexChanging"
        PageSize="4" AllowSorting="True" OnSorting="departmentsGrid_Sorting" 
        CellPadding="4" EnableModelValidation="True" ForeColor="#333333" 
        GridLines="None">
        <AlternatingRowStyle BackColor="White" ForeColor="#284775" />
        <EditRowStyle BackColor="#999999" />
        <FooterStyle BackColor="#5D7B9D" Font-Bold="True" ForeColor="White" />
        <HeaderStyle BackColor="#5D7B9D" Font-Bold="True" ForeColor="White" />
        <PagerStyle BackColor="#284775" ForeColor="White" HorizontalAlign="Center" />
        <RowStyle BackColor="#F7F6F3" ForeColor="#333333" />
        <SelectedRowStyle BackColor="#E2DED6" Font-Bold="True" ForeColor="#333333" />
    </asp:GridView>
</asp:Content>
