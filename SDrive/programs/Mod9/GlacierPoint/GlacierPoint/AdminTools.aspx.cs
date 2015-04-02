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
 * Glacier Point Project - Admin Tools Page
 * Date: 6/10/2014
 * By: Amrit Panesar - 77260
 *********************************************************************/
    public partial class AdminTools : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            // Read the employees list when initially loading the page
            if (!IsPostBack)
            {
                LoadEmployeesList();
            }

        }

        private void LoadEmployeesList()
        {
            // Declare objects
            SqlConnection conn;
            SqlCommand comm;
            SqlDataReader reader;

            // Read the connection string from Web.config
            string connectionString = ConfigurationManager.ConnectionStrings["GlacierPoint"].ConnectionString;

            // Initialize connection
            conn = new SqlConnection(connectionString);

            // Create command
            comm = new SqlCommand("SELECT EmployeeId, Name FROM gp_Employee", conn);

            // Enclose database code in Try-Catch-Finally
            try
            {
                // Open the connection
                conn.Open();

                // Execute the command
                reader = comm.ExecuteReader();

                // Populate the list of employees
                employeesList.DataSource = reader;
                employeesList.DataValueField = "EmployeeId";
                employeesList.DataTextField = "Name";
                employeesList.DataBind();

                // Close the reader
                reader.Close();
            }
            catch
            {
                // Display error message
                dbErrorLabel.Text = "Error loading employees<br />";
            }
            finally
            {
                // Close the connection
                conn.Close();
            }
            // Disable the update button
            updateButton.Enabled = false;

            // Clear any values in the TextBox controls
            nameTextBox.Text = "";
            usernameTextBox.Text = "";
            addressTextBox.Text = "";
            cityTextBox.Text = "";
            stateTextBox.Text = "";
            zipTextBox.Text = "";
            homePhoneTextBox.Text = "";
            extensionTextBox.Text = "";
            mobilePhoneTextBox.Text = "";
        }

        protected void selectButton_Click(object sender, EventArgs e)
        {
            // Declare objects
            SqlConnection conn;
            SqlCommand comm;
            SqlDataReader reader;

            // Read the connection string from Web.config
            string connectionString = ConfigurationManager.ConnectionStrings["GlacierPoint"].ConnectionString;

            // Initialize connection
            conn = new SqlConnection(connectionString);

            // Create command
            comm = new SqlCommand( "SELECT Name, Username, Address, City, State, Zip, HomePhone, Extension, MobilePhone FROM gp_Employee WHERE EmployeeId = @EmployeeId", conn);

            // Add command parameters
            comm.Parameters.Add("@EmployeeId", SqlDbType.Int);
            comm.Parameters["@EmployeeId"].Value = employeesList.SelectedItem.Value;

            // Enclose database code in Try-Catch-Finally
            try
            {
                // Open the connection
                conn.Open();

                // Execute the command
                reader = comm.ExecuteReader();
                
                // Display the data on the form
                if (reader.Read())
                {
                    nameTextBox.Text = reader["Name"].ToString();
                    usernameTextBox.Text = reader["Username"].ToString();
                    addressTextBox.Text = reader["Address"].ToString();
                    cityTextBox.Text = reader["City"].ToString();
                    stateTextBox.Text = reader["State"].ToString();
                    zipTextBox.Text = reader["Zip"].ToString();
                    homePhoneTextBox.Text = reader["HomePhone"].ToString();
                    extensionTextBox.Text = reader["Extension"].ToString();
                    mobilePhoneTextBox.Text = reader["MobilePhone"].ToString();
                }

                // Close the reader
                reader.Close();

                // Enable the Update button
                updateButton.Enabled = true;
                deleteButton.Enabled = true;
            }
            catch
            {
                // Display error message
                dbErrorLabel.Text =
                "Error loading employee details<br />";
            }
            finally
            {
                // Close the connection
                conn.Close();
            }
        }

        protected void updateButton_Click(object sender, EventArgs e)
        {
            // Declare objects
            SqlConnection conn;
            SqlCommand comm;

            // Read the connection string from Web.config
            string connectionString = ConfigurationManager.ConnectionStrings["GlacierPoint"].ConnectionString;

            // Initialize connection
            conn = new SqlConnection(connectionString);

            // Create command
            comm = new SqlCommand(
            "UPDATE gp_Employee SET Name=@Name, Username=@Username, " +
            "Address=@Address, City=@City, State=@State, Zip=@Zip, " +
            "HomePhone=@HomePhone, Extension=@Extension, " +
            "MobilePhone=@MobilePhone " +
            "WHERE EmployeeId=@EmployeeId", conn);

            // Add command parameters
            comm.Parameters.Add("@Name", SqlDbType.NVarChar, 50);
            comm.Parameters["@Name"].Value = nameTextBox.Text;
            comm.Parameters.Add("@Username", SqlDbType.NVarChar, 50);
            comm.Parameters["@Username"].Value = usernameTextBox.Text;
            comm.Parameters.Add("@Address", SqlDbType.NVarChar, 50);
            comm.Parameters["@Address"].Value = addressTextBox.Text;
            comm.Parameters.Add("@City", SqlDbType.NVarChar, 50);
            comm.Parameters["@City"].Value = cityTextBox.Text;
            comm.Parameters.Add("@State", SqlDbType.NVarChar, 50);
            comm.Parameters["@State"].Value = stateTextBox.Text;
            comm.Parameters.Add("@Zip", SqlDbType.NVarChar, 50);
            comm.Parameters["@Zip"].Value = zipTextBox.Text;
            comm.Parameters.Add("@HomePhone", SqlDbType.NVarChar, 50);
            comm.Parameters["@HomePhone"].Value = homePhoneTextBox.Text;
            comm.Parameters.Add("@Extension", SqlDbType.NVarChar, 50);
            comm.Parameters["@Extension"].Value = extensionTextBox.Text;
            comm.Parameters.Add("@MobilePhone", SqlDbType.NVarChar, 50);
            comm.Parameters["@MobilePhone"].Value = mobilePhoneTextBox.Text;
            comm.Parameters.Add("@EmployeeId", SqlDbType.Int);
            comm.Parameters["@EmployeeId"].Value = employeesList.SelectedItem.Value;

            // Enclose database code in Try-Catch-Finally
            try
            {
                // Open the connection
                conn.Open();

                // Execute the command
                comm.ExecuteNonQuery();
            }
            catch
            {
                // Display error message
                dbErrorLabel.Text = "Error updating employee details<br />";
            }
            finally
            {
                // Close the connection
                conn.Close();
            }
            // Refresh the employees list
            LoadEmployeesList();
        }

        protected void deleteButton_Click(object sender, EventArgs e)
        {
            // Define data objects
            SqlConnection conn;
            SqlCommand comm;

            // Read the connection string from Web.config
            string connectionString = ConfigurationManager.ConnectionStrings["GlacierPoint"].ConnectionString;

            // Initialize connection
            conn = new SqlConnection(connectionString);

            // Create command
            comm = new SqlCommand("DELETE FROM gp_Employee WHERE EmployeeId = @EmployeeId", conn);

            // Add command parameters
            comm.Parameters.Add("@EmployeeId", SqlDbType.Int);
            comm.Parameters["@EmployeeId"].Value = employeesList.SelectedItem.Value;
            try
            {
                // Open the connection
                conn.Open();

                // Execute the command
                comm.ExecuteNonQuery();
            }
            catch
            {
                // Display error message
                dbErrorLabel.Text = "Error deleting employee<br />";
            }
            finally
            {
                // Close the connection
                conn.Close();
            }
            // Refresh the employees list
            LoadEmployeesList();

        }

    }

}


