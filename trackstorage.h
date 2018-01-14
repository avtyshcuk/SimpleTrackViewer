#ifndef TRACKSTORAGE_H
#define TRACKSTORAGE_H

#include <QList>
#include <QString>
#include <QByteArray>

#include "trackfactory.h"

class TrackStorage
{
public:

    TrackStorage() {
        mTrackList.reserve(MAX_STORAGE_SIZE);
        for (int i = 0; i < MAX_STORAGE_SIZE; ++i) {
            QStringList names({"Master of Puppets", "Fade to Black", "Nothing else Matters"});
            mTrackList << TrackFactory::createTrack(Track(i, names.at(qrand() % names.size()),
                                                          qrand() % 2 ? Track::TrackType::USB : Track::TrackType::BTA));
        }
    }

    QList<TrackFactory::TrackPtr> trackList() const { return mTrackList; }
    void setIsPlayingTrack(int index, bool isPlaying) { mTrackList.at(index)->setIsPlaying(isPlaying); }

private:
    QList<TrackFactory::TrackPtr> mTrackList;
    const int MAX_STORAGE_SIZE = 1000;
};

#endif // TRACKSTORAGE_H
