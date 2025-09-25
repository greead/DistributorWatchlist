#ifndef WATCHLISTWINDOW_H
#define WATCHLISTWINDOW_H

#include <QWidget>
#include <QPushButton>

class WatchlistWindow : public QWidget
{
    Q_OBJECT
public:
    explicit WatchlistWindow(QWidget *parent = nullptr);

private:
    QPushButton* testButton;

signals:
};

#endif // WATCHLISTWINDOW_H
