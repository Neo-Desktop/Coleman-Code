/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package project4;

import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import javax.swing.JFrame;

/**
 *
 * @author 77260
 */
public class Project4 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        SwingSuspendResume vsr = new SwingSuspendResume();
        Thread t = new Thread(vsr);
        t.start();

        JFrame f = new JFrame();
        f.setContentPane(vsr);
        f.setSize(320, 200);
        f.setVisible(true);
        f.addWindowListener(new WindowAdapter() {
            @Override
          public void windowClosing(WindowEvent e) {
            System.exit(0);
          }
        });
    }
}
