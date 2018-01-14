#ifndef USBTRACK_H
#define USBTRACK_H

#include "basetrack.h"

class USBTrack : public BaseTrack
{
public:
    USBTrack(Track track)
        : BaseTrack(track) { }

    QString title() const override
    {
        return QString("USB track - ") + mTrack.mTrackName;
    }

    QString picture() const override
    {
        return QString("qrc:/usb.png");
    }
};

#endif // USBTRACK_H
