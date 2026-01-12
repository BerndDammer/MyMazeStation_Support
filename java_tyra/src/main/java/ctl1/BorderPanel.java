package ctl1;

import java.awt.GridBagLayout;

import javax.swing.JPanel;
import javax.swing.border.BevelBorder;
import javax.swing.border.Border;
import javax.swing.border.CompoundBorder;
import javax.swing.border.TitledBorder;

import ctl1.help.MyGC;

public class BorderPanel extends JPanel
{
    /**
     * 
     */
    private static final long serialVersionUID = 1L;
    protected final MyGC gc = new MyGC();

    public BorderPanel(String groupName)
    {
        setLayout(new GridBagLayout());

        final Border o1 = new BevelBorder(BevelBorder.RAISED);
        final Border i1 = new BevelBorder(BevelBorder.LOWERED);
        final Border b1 = new CompoundBorder(o1, i1);
        final TitledBorder tb = new TitledBorder(b1, groupName);
        setBorder(tb);
    }

}
