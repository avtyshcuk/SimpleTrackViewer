#ifndef BTATRACK_H
#define BTATRACK_H

#include "basetrack.h"

class BTATrack : public BaseTrack
{
public:
    BTATrack(Track track)
        : BaseTrack(track) { }

    QString title() const override
    {
        return QString("BTA track - ") + mTrack.mTrackName;
    }

    QString picture() const override
    {
        return QString("qrc:/bta.png");
    }
};


#endif // BTATRACK_H
