package ctl1.util;

import java.awt.Dimension;
import java.awt.Window;

public class Util
{
	public static void centerFrame(Window window)
	{
		Dimension screenSize = window.getToolkit().getScreenSize();
		int sparex, sparey;
		sparex = screenSize.width - window.getWidth();
		sparey = screenSize.height - window.getHeight();
		window.setLocation(sparex / 2, sparey / 2);
	}

}
