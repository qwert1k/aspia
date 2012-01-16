/*
 * PROJECT:         Aspia
 * FILE:            aspia/info/hw.c
 * LICENSE:         LGPL (GNU Lesser General Public License)
 * PROGRAMMERS:     Dmitry Chapyshev (dmitry@aspia.ru)
 */

#include "../main.h"
#include "driver.h"


VOID
HW_MediaDevicesInfo(VOID)
{
    WAVEOUTCAPS waveOutputPaps;
    UINT DevsNum, i;
    INT Index;

    DebugStartReceiving();

    IoAddIcon(IDI_AUDIO);
    IoAddIcon(IDI_MICROPHONE);

    DevsNum = waveOutGetNumDevs();
    if (DevsNum > 0)
    {
        for (i = 0; i < DevsNum; i++)
        {
            if (waveOutGetDevCaps(i,
                                  &waveOutputPaps,
                                  sizeof(waveOutputPaps)) != MMSYSERR_NOERROR)
            {
                continue;
            }

            Index = IoAddItem(0, 0, waveOutputPaps.szPname);
        }
    }

    DebugEndReceiving();
}

VOID
HW_MediaACodecsInfo(VOID)
{
    DebugStartReceiving();

    IoAddIcon(IDI_AUDIO);

    DebugEndReceiving();
}

VOID
HW_MediaVCodecsInfo(VOID)
{
    DebugStartReceiving();

    IoAddIcon(IDI_AUDIO);

    DebugEndReceiving();
}

VOID
HW_MediaMCIInfo(VOID)
{
    DebugStartReceiving();

    IoAddIcon(IDI_AUDIO);

    DebugEndReceiving();
}
