/******************************************************************************
 *     Project: Project 2                                                     *
 *  Class Name: MenuDialog                                                    *
 *      Author: Amrit Panesar <apanesar@coleman.edu>                          *
 *  Created On: Nov 21, 2012                                                  *
 *       Hours: X.XX Hours                                                    *
 *     Purpose: TODO: Write purpose here.                                     *
 ******************************************************************************/

package project2;

/**
 *
 * @author Amrit Panesar <apanesar@coleman.edu>
 */
public class MenuDialog {
    private int index;
    private String title;
    private String menu;

    public MenuDialog() {
    }

    public MenuDialog(int index, String title, String menu) {
        this.index = index;
        this.title = title;
        this.menu = menu;
    }

    public int getIndex() {
        return index;
    }

    public void setIndex(int index) {
        this.index = index;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getMenu() {
        return menu;
    }

    public void setMenu(String menu) {
        this.menu = menu;
    }
    
    @Override
    public String toString()
    {
        return this.menu;
    }
    
}
