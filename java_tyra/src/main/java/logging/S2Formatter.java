package logging;

import java.util.logging.Formatter;
import java.util.logging.LogRecord;

public class S2Formatter extends Formatter
{
    public S2Formatter()
    {
    }

    @Override
    public String format(LogRecord record)
    {
        final String result = String.format("%7s %d %s\n", record.getLevel(), record.getMillis(), record.getMessage());
        return result;
    }
}
