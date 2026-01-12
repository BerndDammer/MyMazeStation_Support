package ctl1;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.logging.Logger;

import javax.sound.midi.MidiDevice;
import javax.sound.midi.MidiSystem;
import javax.sound.midi.MidiUnavailableException;
import javax.sound.midi.Receiver;
import javax.swing.JToggleButton;

public class MidiOpener extends JToggleButton implements ActionListener, IControlChannel
{
    private static final long serialVersionUID = 1L;
    private static final Logger logger = Logger.getLogger(MidiOpener.class.getCanonicalName());
    private Receiver receiver = null;
    private MidiDevice midiDevice = null;

    private final MidiSelectBox midiSelectBox;

    public MidiOpener(MidiSelectBox midiSelectBox)
    {
        this.midiSelectBox = midiSelectBox;
        setText("Open Midi");
        addActionListener(this);
    }

    @Override
    public void actionPerformed(ActionEvent ae)
    {
        if (isSelected())
        {
            midiSelectBox.setEditable(false);
            midiSelectBox.setEnabled(false);

            final MidiDevice.Info midiDeviceInfo = midiSelectBox.getItemAt(midiSelectBox.getSelectedIndex());
            try
            {
                midiDevice = MidiSystem.getMidiDevice(midiDeviceInfo);
                midiDevice.open();
                receiver = midiDevice.getReceiver();

            } catch (MidiUnavailableException e)
            {
                // TODO Auto-generated catch block
                logger.warning(e.getMessage());
                setSelected(false);
            }

        } else
        {
            midiDevice.close();
            midiSelectBox.setEditable(true);
            midiSelectBox.setEnabled(true);
        }
    }

    @Override
    public Receiver getControl()
    {
        if (receiver == null)
        {
            logger.info("null receiver requested");
        }
        return receiver;
    }
}
