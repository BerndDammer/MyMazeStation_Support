package logging;

import java.io.IOException;
import java.util.logging.ConsoleHandler;
import java.util.logging.FileHandler;
import java.util.logging.Formatter;
import java.util.logging.Level;
import java.util.logging.LogManager;
import java.util.logging.Logger;

public class InternalLogging
{
    private static final String ROOT_LOGGER_NAME = "";
    private static final Level LEVEL = Level.INFO;

    private InternalLogging()
    {
        // static class only
    }

    public static void init()
    {
        LogManager.getLogManager().reset();
        Logger rootLogger = LogManager.getLogManager().getLogger(ROOT_LOGGER_NAME);
        rootLogger.setLevel(LEVEL);
        FileHandler fh = null;
        Formatter sf;
        ConsoleHandler ch = new ConsoleHandler();
        ch.setLevel(LEVEL);
        sf = new S2Formatter();
        ch.setFormatter(sf);
        rootLogger.addHandler(ch);
        try
        {
            fh = new FileHandler("ctl1.log", false);
        } catch (SecurityException | IOException e)
        {
            e.printStackTrace();
            return;
        }
        sf = new S2Formatter();
        fh.setFormatter(sf);
        fh.setLevel(LEVEL);
        rootLogger.addHandler(fh);
        Logger.getLogger("sun").setLevel(Level.INFO);
    }
}
