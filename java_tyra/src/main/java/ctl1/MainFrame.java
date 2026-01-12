package ctl1;

import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.util.logging.Logger;

import javax.swing.JPanel;
import javax.swing.SwingUtilities;

import ctl1.help.MyGC;

public class MainFrame extends JFrame2 implements Runnable
{
    private static final long serialVersionUID = 1L;
    private final Logger logger = Logger.getLogger(this.getClass().getCanonicalName());
    private final MyGC gc = new MyGC();
    private final ButtonWorker buttonWorker = new ButtonWorker();


    // ---------------------GUI_Elements
    public MainFrame()
    {
        logger.info("Starting");
        SwingUtilities.invokeLater(this);
    }

    private class myPanel extends JPanel
    {
        private static final long serialVersionUID = 1L;
        private final ConnectPanel connectPanel = new ConnectPanel();
        myPanel()
        {
            setLayout(new GridBagLayout());
            // GridBagConstraints gc = new GridBagConstraints();
            gc.reset();

            gc.fill = GridBagConstraints.BOTH;
            add( new PlaceHolder(), gc);

            gc.nextRow();
            gc.fill = GridBagConstraints.NONE;
            add( new ButtonPanel(connectPanel, buttonWorker), gc);
            
            gc.gridx = 1;
            gc.gridy = 0;
            gc.gridwidth = 1;
            gc.gridheight = 2;
            gc.fill = GridBagConstraints.VERTICAL;

            add( connectPanel, gc );
            
        }
    }

    @Override
    public void run()
    {
        setContentPane(new myPanel());
        setTitle("ctl1");
        setVisible(true);
    }
}
