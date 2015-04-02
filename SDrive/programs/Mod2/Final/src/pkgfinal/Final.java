/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package pkgfinal;

import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;

/**
 *
 * @author 77260
 */
public class Final extends JPanel implements Runnable  {

    /**
     * @param args the command line arguments
     */
private static int count = 2;

  private Thread runThread;

  private JTextField symbolTF;
  private JTextField symbolALRM;
  private JPanel innerStackP = new JPanel();
  public Final() {
    symbolTF = new JTextField();
    symbolTF.setEditable(false);
    symbolTF.setFont(new Font("Monospaced", Font.BOLD, 26));
    symbolTF.setHorizontalAlignment(JTextField.CENTER);

    final JButton suspendB = new JButton("Suspend");
    final JButton resumeB = new JButton("Resume");

    suspendB.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent e) {
        suspendNow();
      }
    });

    resumeB.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent e) {
        resumeNow();
      }
    });
    symbolALRM = new JTextField();
    symbolALRM.setText("ALARM");
    symbolALRM.setEditable(false);
    symbolALRM.setFont(new Font("Monospaced", Font.BOLD, 26));
    symbolALRM.setForeground(Color.red);
    symbolALRM.setHorizontalAlignment(JTextField.CENTER);

    innerStackP.setLayout(new GridLayout(0, 1, 3, 3));
    innerStackP.add(symbolTF);
    innerStackP.add(suspendB);
    innerStackP.add(resumeB);

    this.setLayout(new FlowLayout(FlowLayout.CENTER));
    this.add(innerStackP);
  }

  private void suspendNow() {
    if (runThread != null) { // avoid NullPointerException
      runThread.suspend();
    }
  }

  private void resumeNow() {
    if (runThread != null) { // avoid NullPointerException
      runThread.resume();
    }
  }

  public void run() {
    try {
      // Store this for the suspendNow() and
      // resumeNow() methods to use.
      runThread = Thread.currentThread();

      while (true) {
        // each time through, show the next symbol
        symbolTF.setText(""+count);
        Thread.sleep(1000);
        if (count <= 0)
        {
            innerStackP.add(symbolALRM);
            Thread.sleep(500);
            innerStackP.updateUI();
            suspendNow();
            innerStackP.remove(symbolALRM);
            Thread.sleep(500);
            innerStackP.updateUI();
            count = 60;
        }
        count--;
      }
    } catch (InterruptedException x) {
      // ignore
    } finally {
      // make sure that the reference to it is also lost.
      runThread = null;
    }
  }

  public static void main(String[] args) {
    Final vsr = new Final();
    Thread t = new Thread(vsr);
    t.start();
    
    JFrame f = new JFrame();
    f.setContentPane(vsr);
    f.setSize(320, 200);
    f.setVisible(true);
    f.addWindowListener(new WindowAdapter() {
      public void windowClosing(WindowEvent e) {
        System.exit(0);
      }
    });
  }
}
