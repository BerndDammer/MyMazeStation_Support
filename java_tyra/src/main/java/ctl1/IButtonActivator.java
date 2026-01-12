package ctl1;

import java.util.logging.Logger;

import javax.sound.midi.InvalidMidiDataException;
import javax.sound.midi.ShortMessage;

public interface IButtonActivator
{
    static final Logger logger = Logger.getLogger(IButtonActivator.class.getCanonicalName());

    default void activeButton(EButtons button, boolean enable, IControlChannel channel)
    {
        try
        {
            final ShortMessage shortMessage = new ShortMessage( //
                    enable ? ShortMessage.NOTE_ON : ShortMessage.NOTE_OFF, //
                    1, button.getMidiCode(), //
                    enable ? 127 : 0);

            channel.getControl().send(shortMessage, System.currentTimeMillis());

        } catch (InvalidMidiDataException e)
        {
            logger.warning(e.getMessage());
        }
    }
}
