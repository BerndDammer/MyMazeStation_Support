package ctl1;

import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;

import javax.swing.JFrame;

import ctl1.util.Util;

public class JFrame2 extends JFrame implements WindowListener
{
    /**
     * 
     */
    private static final long serialVersionUID = 1L;
    private static final boolean MAX = false;

    public JFrame2()
    {
        addWindowListener(this);
    }

    @Override
    public void windowActivated(WindowEvent e)
    {
    }

    @Override
    public void windowClosed(WindowEvent e)
    {
    }

    @Override
    public void windowClosing(WindowEvent e)
    {
        System.exit(0);
    }

    @Override
    public void windowDeactivated(WindowEvent e)
    {
    }

    @Override
    public void windowDeiconified(WindowEvent e)
    {
    }

    @Override
    public void windowIconified(WindowEvent e)
    {
    }

    @Override
    public void windowOpened(WindowEvent e)
    {
    }

    @Override
    public void setVisible(boolean on)
    {
        if (on)
        {
            pack();
            if (MAX)
            {
                setUndecorated(true);
                setLocation(0, 0);
                setExtendedState(MAXIMIZED_BOTH);
            } else
            {
                Util.centerFrame(this);
            }
        }
        super.setVisible(on);
    }
}
