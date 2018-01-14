#ifndef TRACKMODEL_H
#define TRACKMODEL_H

#include <QAbstractListModel>

#include "trackstorage.h"

class TrackModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit TrackModel(QObject *parent = 0);

    enum TrackRoles
    {
        Title = 0,
        Picture,
        IsPlaying
    };

    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;

    Q_INVOKABLE void play(int trackIndex);

private:
    TrackStorage mTrackStorage;
    int mPlayingIndex;
};

#endif // TRACKMODEL_H
