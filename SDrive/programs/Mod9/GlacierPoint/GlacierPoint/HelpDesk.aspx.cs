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
 * Glacier Point Project - Help Desk Page
 * Date: 6/10/2014
 * By: Amrit Panesar - 77260
 *********************************************************************/
     public partial class HelpDesk : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                // Declare objects
                SqlConnection conn;
                SqlCommand categoryComm;
                SqlCommand subjectComm;
                SqlDataReader reader;

                // Read the connection string from Web.config
                string connectionString = ConfigurationManager.ConnectionStrings["GlacierPoint"].ConnectionString;

                // Initialize connection
                conn = new SqlConnection(connectionString);

                // Create command to read the help desk categories
                categoryComm = new SqlCommand("SELECT CategoryId, Category FROM gp_HelpDeskCategory", conn);

                // Create command to read the help desk subjects
                subjectComm = new SqlCommand("SELECT SubjectId, Subject FROM gp_HelpDeskSubject", conn);

                try
                {
                    // Open the connection
                    conn.Open();

                    // Execute the category command
                    reader = categoryComm.ExecuteReader();

                    // Populate the list of categories
                    categoryList.DataSource = reader;
                    categoryList.DataValueField = "CategoryId";
                    categoryList.DataTextField = "Category";
                    categoryList.DataBind();

                    // Close the reader
                    reader.Close();

                    // Execute the subject command
                    reader = subjectComm.ExecuteReader();

                    // Populate the list of subjects
                    subjectList.DataSource = reader;
                    subjectList.DataValueField = "SubjectId";
                    subjectList.DataTextField = "Subject";
                    subjectList.DataBind();

                    // Close the reader
                    reader.Close();
                }
                finally
                {
                    // Close the connection
                    conn.Close();
                }
            }

        }

        protected void submitButton_Click(object sender, EventArgs e)
        {
            if (Page.IsValid)
            {
                // Define data objects
                SqlConnection conn;
                SqlCommand comm;

                // Read the connection string from Web.config
                string connectionString = ConfigurationManager.ConnectionStrings["GlacierPoint"].ConnectionString;

                // Initialize connection
                conn = new SqlConnection(connectionString);

                // Create insert command
                comm = new SqlCommand("sp_InsertHelpDesk", conn);
                comm.CommandType = System.Data.CommandType.StoredProcedure;

                // Add command parameters
                comm.Parameters.Add("@EmployeeId", System.Data.SqlDbType.Int);
                comm.Parameters["@EmployeeId"].Value = 5;

                comm.Parameters.Add("@StationNumber", System.Data.SqlDbType.Int);
                comm.Parameters["@StationNumber"].Value = stationTextBox.Text;

                comm.Parameters.Add("@CategoryId", System.Data.SqlDbType.Int);
                comm.Parameters["@CategoryId"].Value = categoryList.SelectedItem.Value;

                comm.Parameters.Add("@SubjectId", System.Data.SqlDbType.Int);
                comm.Parameters["@SubjectId"].Value = subjectList.SelectedItem.Value;

                comm.Parameters.Add("@Description", System.Data.SqlDbType.NVarChar, 50);
                comm.Parameters["@Description"].Value = descriptionTextBox.Text;

                comm.Parameters.Add("@StatusId", System.Data.SqlDbType.Int);
                comm.Parameters["@StatusId"].Value = 1;

                // Enclose database code in Try-Catch-Finally
                try
                {
                    // Open the connection
                    conn.Open();

                    // Execute the command
                    comm.ExecuteNonQuery();

                    // Reload page if the query executed successfully
                    Response.Redirect("HelpDesk.aspx");
                }
                catch
                {

                    // Display error message
                    dbErrorMessage.Text = "Error submitting help desk request! Please try again later, and/or change the entered data!";
                }
                finally
                {
                    // Close the connection
                    conn.Close();
                }
            }

        }
    }
}
