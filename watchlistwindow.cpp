#include "watchlistwindow.h"

WatchlistWindow::WatchlistWindow(QWidget *parent)
    : QWidget{parent}
{
    testButton = new QPushButton("TEST", this);
    testButton->show();
}
