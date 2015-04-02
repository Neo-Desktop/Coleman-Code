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

/*********************************************************************
 * Glacier Point Project - Address Book Page
 * Date: 6/10/2014
 * By: Amrit Panesar - 77260
 *********************************************************************/

namespace GlacierPoint
{
    public partial class AddressBook : System.Web.UI.Page
    {
        protected void employeeDetails_ItemUpdated(object sender, DetailsViewUpdatedEventArgs e)
        {
            grid.DataBind();
        }

        protected void employeeDetails_ItemInserted(object sender, DetailsViewInsertedEventArgs e)
        {
            grid.DataBind();
        }

        protected void employeeDetails_ItemDeleted(object sender, DetailsViewDeletedEventArgs e)
        {
            grid.DataBind();
        }

        protected void addEmployeeButton_Click(object sender, EventArgs e)
        {
            employeeDetails.ChangeMode(DetailsViewMode.Insert);
        }
    }


}




