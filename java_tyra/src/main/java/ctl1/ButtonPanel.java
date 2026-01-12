package ctl1;

import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.util.logging.Logger;

public class ButtonPanel extends BorderPanel
{
    private static final long serialVersionUID = 1L;
    private final Logger logger = Logger.getLogger(ButtonPanel.class.getCanonicalName());

    public ButtonPanel(final IControlChannel controlChannel, IButtonActivator buttonActivator)
    {
        super("Activator");

        setLayout(new GridBagLayout());
        gc.reset();
        gc.fill = GridBagConstraints.NONE;

        for (EButtons ebutton : EButtons.values())
        {
            add(new MidiButton(ebutton, controlChannel, buttonActivator), gc.stepRight());
        }
    }
}
