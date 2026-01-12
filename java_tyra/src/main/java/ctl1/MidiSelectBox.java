package ctl1;

import java.util.logging.Logger;

import javax.sound.midi.MidiDevice;
import javax.sound.midi.MidiSystem;
import javax.sound.midi.MidiUnavailableException;
import javax.sound.midi.Receiver;
import javax.swing.JComboBox;

class MidiSelectBox extends JComboBox<MidiDevice.Info> // implements IControlChannel
{
    private final Logger logger = Logger.getLogger(MidiSelectBox.class.getCanonicalName());
    private static final long serialVersionUID = 1L;

    public MidiSelectBox()
    {
        MidiDevice.Info[] midiDevices = MidiSystem.getMidiDeviceInfo();

        // try if midi device has output channel
        MidiDevice midiDevice = null;
        for (MidiDevice.Info info : midiDevices)
        {
            try
            {
                midiDevice = MidiSystem.getMidiDevice(info);
                midiDevice.open();
                final Receiver receiver = midiDevice.getReceiver();
                if (receiver != null)
                {
                    addItem(info);
                }
            } catch (MidiUnavailableException e)
            {
                logger.info(e.getMessage());
            } finally
            {
                midiDevice.close();
            }
        }
    }
}
