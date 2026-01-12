package ctl1;

public enum EButtons
{
    B0(48),
    B1(50),
    B2(52),
    B3(53),
    B4(55),
    B5(57),
    B6(59),
    B7(60);

    private final int midiCode;

    private EButtons(int i)
    {
        midiCode = i;
    }

    public int getMidiCode()
    {
        return midiCode;
    }
}
