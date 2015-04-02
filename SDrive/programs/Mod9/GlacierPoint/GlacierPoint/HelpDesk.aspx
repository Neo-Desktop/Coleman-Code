<%--
/*********************************************************************
 * Glacier Point Project - Help Desk Page
 * Date: 6/10/2014
 * By: Amrit Panesar - 77260
 *********************************************************************/
 --%>
<%@ Page Language="C#" MasterPageFile="~/GlacierPoint.Master" AutoEventWireup="true"
    CodeBehind="HelpDesk.aspx.cs" Inherits="GlacierPoint.HelpDesk" Title="Helpdesk Page" %>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
    <h1>
        Employee Help Desk Request</h1>
    <asp:Label ID="dbErrorMessage" ForeColor="Red" runat="server" />
    <p>
        Station Number:<br />
        <asp:TextBox ID="stationTextBox" runat="server" CssClass="textbox" />
        <asp:RequiredFieldValidator ID="stationNumReq" runat="server" ControlToValidate="stationTextBox"
            ErrorMessage="<br />Please enter a station number" Display="Dynamic" />
        <asp:CompareValidator ID="stationNumCheck" runat="server" ControlToValidate="stationTextBox"
            Operator="DataTypeCheck" Type="Integer" ErrorMessage="<br />Please enter a valid station number."
            Display="Dynamic" />
        <asp:RangeValidator ID="stationNumRangeCheck" runat="server" ControlToValidate="stationTextBox"
            MinimumValue="1" MaximumValue="50" Type="Integer" ErrorMessage="<br />Your station number must be between 1 and 50"
            Display="Dynamic" />
    </p>
    <p>
        Problem Category:<br />
        <asp:DropDownList ID="categoryList" runat="server" CssClass="dropdownmenu" />
    </p>
    <p>
        Problem Subject:<br />
        <asp:DropDownList ID="subjectList" runat="server" CssClass="dropdownmenu" />
    </p>
    <p>
        Problem Description:<br />
        <asp:TextBox ID="descriptionTextBox" runat="server" CssClass="textbox" Columns="40"
            Rows="4" TextMode="MultiLine" />
        <asp:RequiredFieldValidator ID="descriptionReq" runat="server" ControlToValidate="descriptionTextBox"
            ErrorMessage="<br />Please enter a description" Display="Dynamic" />
    </p>
    <p>
        <asp:Button ID="submitButton" runat="server" CssClass="button" Text="Submit Request"
            OnClick="submitButton_Click" />
    </p>
</asp:Content>
