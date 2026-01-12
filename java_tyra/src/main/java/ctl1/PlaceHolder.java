package ctl1;

import java.awt.Dimension;

public class PlaceHolder extends BorderPanel
{
    private static final long serialVersionUID = 1L;

    public PlaceHolder()
    {
        super("Spacer");
        setPreferredSize(new Dimension(300, 120));
    }
}
