/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package project4;

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
import javax.swing.JSlider;
import javax.swing.JTextField;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;

/**
 *
 * @author 77260
 */
public class SwingSuspendResume extends JPanel implements Runnable {

  private static final String[] symbolList = { "|", "/", "-", "\\", "|", "/",
      "-", "\\" };

  private Thread runThread;

  private JTextField symbolTF;

  public SwingSuspendResume() {
    symbolTF = new JTextField();
    symbolTF.setEditable(false);
    symbolTF.setFont(new Font("Monospaced", Font.BOLD, 26));
    symbolTF.setHorizontalAlignment(JTextField.CENTER);

    final JButton suspendB = new JButton("Suspend");
    final JButton resumeB = new JButton("Resume");
    final JSlider jSlider1 = new javax.swing.JSlider();
    final JButton jButton1 = new JButton("Reverse");

    suspendB.addActionListener(new ActionListener() {
        @Override
      public void actionPerformed(ActionEvent e) {
        suspendNow();
      }
    });

    resumeB.addActionListener(new ActionListener() {
        @Override
      public void actionPerformed(ActionEvent e) {
        resumeNow();
      }
    });
    
    jSlider1.addChangeListener(new ChangeListener() {
        @Override
        public void stateChanged(ChangeEvent ce)
        {
            changeval(jSlider1.getValue());
        }
    });
    
    jButton1.addActionListener(new ActionListener() {
        @Override
      public void actionPerformed(ActionEvent e) {
        toggle();
      }
    });
    
    JPanel innerStackP = new JPanel();
    innerStackP.setLayout(new GridLayout(0, 1, 4, 4));
    innerStackP.add(symbolTF);
    innerStackP.add(suspendB);
    innerStackP.add(resumeB);
    innerStackP.add(jSlider1);
    innerStackP.add(jButton1);

    this.setLayout(new FlowLayout(FlowLayout.CENTER));
    this.add(innerStackP);
  }
  
    private void changeval(int value) {
        sleepcount = (value *2);
        //System.out.println(value);
    }
    private void toggle() {
        if (toggle)
        {
            toggle = false;
        } else {
            toggle = true;
        }
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

  public int sleepcount = 200;
  public boolean toggle = false;
    @Override
  public void run() {
    try {
      // Store this for the suspendNow() and
      // resumeNow() methods to use.
      runThread = Thread.currentThread();
      int count = 0;

      while (true) {
        // each time through, show the next symbol
        symbolTF.setText(symbolList[count % symbolList.length]);
        Thread.sleep(sleepcount);
        if (toggle)
        {
            if (count == 0)
            { count = 2147483647; }
            count--;
        } else {
            if (count == 2147483647)
            { count = 0; }
            count++;
        }
      }
    } catch (InterruptedException x) {
      // ignore
    } finally {
      // make sure that the reference to it is also lost.
      runThread = null;
    }
  }

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

