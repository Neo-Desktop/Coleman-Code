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
 * Glacier Point Project - Departments Page
 * Date: 6/10/2014
 * By: Amrit Panesar - 77260
 *********************************************************************/
     public partial class Departments : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                BindGrid();
            }
        }

        private void BindGrid()
        {
            // Define data objects
            SqlConnection conn;
            DataSet dataSet = new DataSet();
            SqlDataAdapter adapter;

            //DataRow dataRow;
            SqlCommandBuilder commandBuilder;

            if (ViewState["DepartmentsDataSet"] == null)
            {

                // Read the connection string from Web.config
                string connectionString = ConfigurationManager.ConnectionStrings["GlacierPoint"].ConnectionString;

                // Initialize connection
                conn = new SqlConnection(connectionString);

                // Create adapter
                adapter = new SqlDataAdapter("SELECT DepartmentId, Department FROM gp_Department", conn);

                // Fill the DataSet
                adapter.Fill(dataSet, "Departments");

                // Make changes to the table
                //dataRow = dataSet.Tables["Departments"].NewRow();
                //dataRow["Department"] = "New Department";
                //dataSet.Tables["Departments"].Rows.Add(dataRow);
                foreach (DataRow dataRow in dataSet.Tables["Departments"].Rows)
                {
                    if (dataRow["Department"].ToString() == "New Department")
                    {
                        dataRow.Delete();
                    }
                }

                //// Submit the changes
                commandBuilder = new SqlCommandBuilder(adapter);
                adapter.Update(dataSet.Tables["Departments"]);
                // Make changes to the table


                // Store the DataSet in view state
                ViewState["DepartmentsDataSet"] = dataSet;
            }
            else
            {
                dataSet = (DataSet)ViewState["DepartmentsDataSet"];
            }

            // Initialize the adapter with a new command
            //adapter.SelectCommand = new SqlCommand(
            //"SELECT EmployeeId, Name, MobilePhone FROM gp_Employee", conn);
            //// Add the new table to the DataSet
            //adapter.Fill(dataSet, "Employees");
            //// Bind the grid to the DataSet
            departmentsGrid.DataSource = dataSet;
            //departmentsGrid.DataMember = "Employees";
            // Prepare the sort expression using the 
            // gridSortDirection and
            // gridSortExpression properties
            string sortExpression;
            if (gridSortDirection == SortDirection.Ascending)
            {
                sortExpression = gridSortExpression + " ASC";
            }
            else
            {
                sortExpression = gridSortExpression + " DESC";
            }
            // Sort the data
            dataSet.Tables["Departments"].DefaultView.Sort = sortExpression;
            // Bind the grid to the DataSet
            departmentsGrid.DataSource =
            dataSet.Tables["Departments"].DefaultView;


            departmentsGrid.DataBind();
        }

        protected void departmentsGrid_PageIndexChanging(object sender, GridViewPageEventArgs e)
        {
            // Retrieve the new page index
            int newPageIndex = e.NewPageIndex;
            // Set the new page index of the GridView
            departmentsGrid.PageIndex = newPageIndex;
            // Bind the grid to its data source again to update its
            // contents
            BindGrid();

        }

        protected void departmentsGrid_Sorting(object sender, GridViewSortEventArgs e)
        {
            // Retrieve the name of the clicked column (sort expression)
            string sortExpression = e.SortExpression;
            // Decide and save the new sort direction
            if (sortExpression == gridSortExpression)
            {
                if (gridSortDirection == SortDirection.Ascending)
                {
                    gridSortDirection = SortDirection.Descending;
                }
                else
                {
                    gridSortDirection = SortDirection.Ascending;
                }
            }
            else
            {
                gridSortDirection = SortDirection.Ascending;
            }
            // Save the new sort expression
            gridSortExpression = sortExpression;
            // Rebind the grid to its data source
            BindGrid();
        }


        private SortDirection gridSortDirection
        {
            get
            {
                // Initial state is Ascending
                if (ViewState["GridSortDirection"] == null)
                {
                    ViewState["GridSortDirection"] = SortDirection.Ascending;
                }
                // Return the state
                return (SortDirection)ViewState["GridSortDirection"];
            }
            set
            {
                ViewState["GridSortDirection"] = value;
            }
        }


        private string gridSortExpression
        {
            get
            {
                // Initial sort expression is DepartmentId
                if (ViewState["GridSortExpression"] == null)
                {
                    ViewState["GridSortExpression"] = "DepartmentId";
                }
                // Return the sort expression
                return (string)ViewState["GridSortExpression"];
            }
            set
            {
                ViewState["GridSortExpression"] = value;
            }
        }
    }
}




