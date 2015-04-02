<%--
/*********************************************************************
 * Glacier Point Project - Employee Directory Page
 * Date: 6/10/2014
 * By: Amrit Panesar - 77260
 *********************************************************************/
 --%>
<%@ Page Language="C#" MasterPageFile="~/GlacierPoint.Master" AutoEventWireup="true"
    CodeBehind="EmployeeDirectory.aspx.cs" Inherits="GlacierPoint.EmployeeDirectory"
    Title="GlacierPoint Employee Directory" %>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
    <h1>
        Employee Directory</h1>
    <asp:DataList ID="employeesList" runat="server" 
        OnItemCommand="employeesList_ItemCommand" CellPadding="4" ForeColor="#333333">
        <ItemTemplate>
            <asp:Literal ID="extraDetailsLiteral" runat="server" EnableViewState="false" />
            Name: <strong>
                <%#Eval("Name")%></strong><br />
            Username: <strong>
                <%#Eval("Username")%></strong><br />
            <asp:LinkButton ID="detailsButton" runat="server" Text='<%#"View more details about " + Eval("Name")%>'
                CommandName="MoreDetailsPlease" CommandArgument='<%#Eval("EmployeeId")%>' /><br />
            <asp:LinkButton ID="editButton" runat="server" Text='<%#"Edit employee " + Eval("Name")%>'
                CommandName="EditItem" CommandArgument='<%#Eval("EmployeeId")%>' />
        </ItemTemplate>
        <EditItemTemplate>
            Name:
            <asp:TextBox ID="nameTextBox" runat="server" Text='<%#Eval("Name")%>' /><br />
            Username:
            <asp:TextBox ID="usernameTextBox" runat="server" Text='<%#Eval("Username")%>' /><br />
            <asp:LinkButton ID="updateButton" runat="server" Text="Update Item" CommandName="UpdateItem"
                CommandArgument='<%#Eval("EmployeeId")%>' />
            or
            <asp:LinkButton ID="cancelButton" runat="server" Text="Cancel Editing" CommandName="CancelEditing"
                CommandArgument='<%#Eval("EmployeeId")%>' />
        </EditItemTemplate>
        <SeparatorTemplate>
            <hr />
        </SeparatorTemplate>
        <EditItemStyle BackColor="#95DFD6" BorderColor="Yellow" BorderStyle="Dashed" BorderWidth="2px" />
        <AlternatingItemStyle BackColor="White" />
        <FooterStyle BackColor="#507CD1" Font-Bold="True" ForeColor="White" />
        <HeaderStyle BackColor="#507CD1" Font-Bold="True" ForeColor="White" />
        <ItemStyle BackColor="#EFF3FB" />
        <SelectedItemStyle BackColor="#D1DDF1" Font-Bold="True" ForeColor="#333333" />
        <SeparatorStyle BackColor="White" />
    </asp:DataList><br />
    <br />
    <br />
</asp:Content>
