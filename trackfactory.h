#ifndef TRACKFACTORY_H
#define TRACKFACTORY_H

#include <memory>

#include "tracks/usbtrack.h"
#include "tracks/btatrack.h"

class TrackFactory
{
public:
    using TrackPtr = std::shared_ptr<BaseTrack>;

    static TrackPtr createTrack(Track track)
    {
        switch (track.mTrackType) {
        case Track::TrackType::USB:
            return std::make_shared<USBTrack>(track);
            break;
        case Track::TrackType::BTA:
            return std::make_shared<BTATrack>(track);
            break;
        default:
            return std::make_shared<USBTrack>(track);
            break;
        }
    }
};

#endif // TRACKFACTORY_H
