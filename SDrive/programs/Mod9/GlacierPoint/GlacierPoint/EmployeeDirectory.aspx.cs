using System;
using System.Data;
using System.Configuration;
using System.Collections;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Web.UI.HtmlControls;
using System.Data.SqlClient;

namespace GlacierPoint
{
/*********************************************************************
 * Glacier Point Project - Employee Directory Page
 * Date: 6/10/2014
 * By: Amrit Panesar - 77260
 *********************************************************************/
     public partial class EmployeeDirectory : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                BindList();
            }
        }

        protected void BindList()
        {
            // Define data objects
            SqlConnection conn;
            SqlCommand comm;
            SqlDataReader reader;

            // Read the connection string from Web.config
            string connectionString = ConfigurationManager.ConnectionStrings["GlacierPoint"].ConnectionString;

            // Initialize connection
            conn = new SqlConnection(connectionString);
            
            // Create command
            comm = new SqlCommand("SELECT EmployeeId, Name, Username FROM gp_Employee", conn);
            
            // Enclose database code in Try-Catch-Finally
            try
            {
                // Open the connection
                conn.Open();

                // Execute the command
                reader = comm.ExecuteReader();

                // Bind the reader to the repeater
                employeesList.DataSource = reader;
                employeesList.DataBind();

                // Close the reader
                reader.Close();
            }
            finally
            {
                // Close the connection
                conn.Close();
            }


        }

        protected void employeesList_ItemCommand(object source, DataListCommandEventArgs e)
        {
            // Which button was clicked?
            if (e.CommandName == "MoreDetailsPlease")
            {
                // Find the Literal control in the DataList item
                Literal li = (Literal)e.Item.FindControl("extraDetailsLiteral");

                // Add content to the Literal control
                li.Text = "Employee Id: <strong>" + e.CommandArgument + "</strong><br />";
            }
            else if (e.CommandName == "EditItem")
            {
                // Set the index of the item being edited
                employeesList.EditItemIndex = e.Item.ItemIndex;

                // Bind again the list to update the list
                BindList();
            }
            else if (e.CommandName == "CancelEditing")
            {
                // Cancel edit mode
                employeesList.EditItemIndex = -1;

                // Refresh the DataList
                BindList();
            }
            else if (e.CommandName == "UpdateItem")
            {
                // Get the employee ID
                int employeeId = Convert.ToInt32(e.CommandArgument);

                // Get the new username
                TextBox nameTextBox = (TextBox)e.Item.FindControl("nameTextBox");
                string newName = nameTextBox.Text;

                // Get the new name
                TextBox usernameTextBox = (TextBox)e.Item.FindControl("usernameTextBox");
                string newUsername = usernameTextBox.Text;

                // Update the item
                UpdateItem(employeeId, newName, newUsername);

                // Cancel edit mode
                employeesList.EditItemIndex = -1;

                // Refresh the DataList
                BindList();
            }

        }

        protected void UpdateItem(int employeeId, string newName, string newUsername)
        {
            // Declare data objects
            SqlConnection conn;
            SqlCommand comm;

            // Read the connection string from Web.config
            string connectionString = ConfigurationManager.ConnectionStrings["GlacierPoint"].ConnectionString;

            // Initialize connection
            conn = new SqlConnection(connectionString);

            // Create command
            comm = new SqlCommand("sp_UpdateEmployee", conn);

            // Specify we're calling a stored procedure
            comm.CommandType = System.Data.CommandType.StoredProcedure;

            // Add command parameters
            comm.Parameters.Add("@EmployeeId", SqlDbType.Int);
            comm.Parameters["@EmployeeId"].Value = employeeId;
            comm.Parameters.Add("@NewName", SqlDbType.VarChar, 50);
            comm.Parameters["@NewName"].Value = newName;
            comm.Parameters.Add("@NewUsername", SqlDbType.VarChar, 50);
            comm.Parameters["@NewUsername"].Value = newUsername;

            // Enclose database code in Try-Catch-Finally
            try
            {
                // Open the connection
                conn.Open();

                // Execute the command
                comm.ExecuteNonQuery();
            }
            finally
            {
                // Close the connection
                conn.Close();
            }
        }


    }
}
