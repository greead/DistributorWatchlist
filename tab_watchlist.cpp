#include "tab_watchlist.h"
#include "watchlistmodel.h"

#include <QTableView>
#include <QPushButton>

tab_watchlist::tab_watchlist(QWidget *parent): QWidget{parent} {
    QTableView* table = new QTableView(this);
    WatchlistModel* model = new WatchlistModel();
    table->setModel(model);
    table->show();
}
