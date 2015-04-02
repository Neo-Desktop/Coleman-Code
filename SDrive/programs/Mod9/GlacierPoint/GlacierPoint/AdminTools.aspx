<%--
/*********************************************************************
 * Glacier Point Project - Admin Tools Page
 * Date: 6/10/2014
 * By: Amrit Panesar - 77260
 *********************************************************************/
 --%>
<%@ Page Language="C#" MasterPageFile="~/GlacierPoint.Master" AutoEventWireup="true"
    CodeBehind="AdminTools.aspx.cs" Inherits="GlacierPoint.AdminTools" Title="Untitled Page" %>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
    <h1>
        Admin Tools</h1>
    <asp:Label ID="dbErrorLabel" ForeColor="Red" runat="server" />
    <p>
        Select an employee to update:<br />
        <asp:DropDownList ID="employeesList" runat="server" />
        <asp:Button ID="selectButton" Text="Select" runat="server" OnClick="selectButton_Click" />
    </p>
    <p>
        <asp:Label ID="nameLabel" runat="server" Text="Name:" Width="100" />
        <asp:TextBox ID="nameTextBox" runat="server" />
    </p>
    <p>
        <asp:Label ID="usernameLabel" runat="server" Text="Username:" Width="100" />
        <asp:TextBox ID="usernameTextBox" runat="server" />
    </p>
    <p>
        <asp:Label ID="addressLabel" runat="server" Text="Address:" Width="100" />
        <asp:TextBox ID="addressTextBox" runat="server" />
    </p>
    <p>
        <asp:Label ID="cityLabel" runat="server" Text="City:" Width="100" />
        <asp:TextBox ID="cityTextBox" runat="server" />
    </p>
    <p>
        <asp:Label ID="stateLabel" runat="server" Text="State:" Width="100" />
        <asp:TextBox ID="stateTextBox" runat="server" />
    </p>
    <p>
        <asp:Label ID="zipLabel" runat="server" Text="Zip:" Width="100" />
        <asp:TextBox ID="zipTextBox" runat="server" />
    </p>
    <p>
        <asp:Label ID="homePhoneLabel" runat="server" Text="Home Phone:" Width="100" />
        <asp:TextBox ID="homePhoneTextBox" runat="server" />
    </p>
    <p>
        <asp:Label ID="extensionLabel" runat="server" Text="Extension:" Width="100" />
        <asp:TextBox ID="extensionTextBox" runat="server" />
    </p>
    <p>
        <asp:Label ID="mobilePhoneLabel" runat="server" Text="Mobile Phone:" Width="100" />
        <asp:TextBox ID="mobilePhoneTextBox" runat="server" />
    </p>
    <p>
        <asp:Button ID="updateButton" Text="Update Employee" Enabled="False" runat="server"
            OnClick="updateButton_Click" />
        <asp:Button ID="deleteButton" Text="Delete Employee" Enabled="False" runat="server"
            OnClick="deleteButton_Click" />
    </p>
</asp:Content>
