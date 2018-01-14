#include "trackmodel.h"

TrackModel::TrackModel(QObject *parent)
    : QAbstractListModel(parent)
    , mPlayingIndex(0)
{
    mTrackStorage.setIsPlayingTrack(mPlayingIndex, true);
}

int TrackModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return mTrackStorage.trackList().size();
}

QVariant TrackModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) {
        return QVariant();
    }

    switch (role) {
    case TrackRoles::Title:
        return mTrackStorage.trackList().at(index.row())->title();
    case TrackRoles::Picture:
        return mTrackStorage.trackList().at(index.row())->picture();
    case TrackRoles::IsPlaying:
        return mTrackStorage.trackList().at(index.row())->isPlaying();
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> TrackModel::roleNames() const
{
    QHash<int, QByteArray> roleNames;

    roleNames[TrackRoles::Title] = "title";
    roleNames[TrackRoles::Picture] = "picture";
    roleNames[TrackRoles::IsPlaying] = "isPlaying";

    return roleNames;
}

void TrackModel::play(int trackIndex)
{
    mTrackStorage.setIsPlayingTrack(mPlayingIndex, false);
    emit dataChanged(createIndex(mPlayingIndex, mPlayingIndex), createIndex(mPlayingIndex, mPlayingIndex));

    mPlayingIndex = trackIndex;
    mTrackStorage.setIsPlayingTrack(mPlayingIndex, true);
    emit dataChanged(createIndex(trackIndex, trackIndex), createIndex(trackIndex, trackIndex));
}
