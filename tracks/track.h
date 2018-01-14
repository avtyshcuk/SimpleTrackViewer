#ifndef TRACK_H
#define TRACK_H

#include <QString>

struct Track {
    enum TrackType {
        USB = 0,
        BTA
    };

    Track(int trackId, const QString &trackName, TrackType trackType)
        : mTrackId(trackId)
        , mTrackName(trackName)
        , mTrackType(trackType)
        , mIsCurrentlyPlaying(false)
    {

    }

    int mTrackId;
    QString mTrackName;
    TrackType mTrackType;
    bool mIsCurrentlyPlaying;
    QByteArray mTrackPicture; // at the moment not used field
};

#endif // TRACK_H
