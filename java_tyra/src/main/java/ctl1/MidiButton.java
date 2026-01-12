package ctl1;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.logging.Logger;

import javax.swing.JToggleButton;

class MidiButton extends JToggleButton implements ActionListener
{
    private static final Logger logger = Logger.getLogger(MidiButton.class.getCanonicalName());

    private static final long serialVersionUID = 1L;
    private final EButtons midiCode;
    private final IButtonActivator buttonActivator;
    private final IControlChannel controlChannel;

    MidiButton(final EButtons midiCode, final IControlChannel controlChannel, final IButtonActivator buttonActivator)
    {
        this.midiCode = midiCode;
        this.buttonActivator = buttonActivator;
        this.controlChannel = controlChannel;

        setText(midiCode.name());
        addActionListener(this);
    }

    @Override
    public void actionPerformed(ActionEvent e)
    {
        buttonActivator.activeButton(midiCode, isSelected(), controlChannel);
        logger.info("" + isSelected());
    }
}
