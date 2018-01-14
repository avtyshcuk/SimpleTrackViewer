#ifndef BASETRACK_H
#define BASETRACK_H

#include "track.h"

struct Track;

class BaseTrack
{
public:
    BaseTrack(Track track)
        : mTrack(track) { }

    virtual ~BaseTrack() { }

    virtual QString title() const = 0;
    virtual QString picture() const = 0;
    virtual bool isPlaying() const { return mTrack.mIsCurrentlyPlaying; }

    void setIsPlaying(bool isPlaying) { mTrack.mIsCurrentlyPlaying = isPlaying; }

protected:
    Track mTrack;
};

#endif // BASETRACK_H
