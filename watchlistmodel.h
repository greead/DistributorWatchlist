#ifndef WATCHLISTMODEL_H
#define WATCHLISTMODEL_H

#include <QAbstractTableModel>

class WatchlistModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit WatchlistModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
};

#endif // WATCHLISTMODEL_H
