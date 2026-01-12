package ctl1;

import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.util.logging.Logger;

import javax.sound.midi.Receiver;
import javax.swing.JLabel;

import ctl1.help.MyGC;

public class ConnectPanel extends BorderPanel implements IControlChannel
{
    private static final long serialVersionUID = 1L;
    private final Logger logger = Logger.getLogger(ConnectPanel.class.getCanonicalName());

    private final MidiSelectBox midiSelectBox = new MidiSelectBox();
    private final MidiOpener midiOpener = new MidiOpener(midiSelectBox);

    public ConnectPanel()
    {
        super("Connections");
        final MyGC gc = new MyGC();

        setLayout(new GridBagLayout());
        gc.reset();
        gc.fill = GridBagConstraints.HORIZONTAL;

        add(new JLabel("Audio", JLabel.CENTER), gc);
        gc.nextRow();

        add(new JLabel("Midi", JLabel.CENTER), gc);
        gc.nextRow();

        add(midiSelectBox, gc);
        gc.nextRow();

        add(midiOpener, gc);
        gc.nextRow();
    }

    @Override
    public Receiver getControl()
    {
        return midiOpener.getControl();
    }
}
