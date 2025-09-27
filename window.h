#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QLabel>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineSeries>
#include <QChart>
#include <QChartView>
#include <QLineEdit>
#include <QListView>
#include <QTextEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QNetworkAccessManager>
#include <QUrl>
#include <QNetworkReply>
#include <QStandardItemModel>

class Window : public QWidget {
    Q_OBJECT
    public:
        explicit Window(QWidget *parent = 0);

    signals:

    private slots:
        void makeRequest();
        void parseReply(QNetworkReply* reply);
        void updateTextSelect(const QItemSelection &selected, const QItemSelection &deselected);

    private:
        QNetworkAccessManager* nam;

        // Central widget
        QWidget* centralWidget;
        QGridLayout* centralLayout;

        // General layout
        QHBoxLayout* generalLayout;
        QVBoxLayout* searchColumnLayout;
        QVBoxLayout* detailsColumnLayout;

        // Searchbar
        QFormLayout* urlLayout;
        QLabel* urlLabel;
        QLineEdit* urlEntry;
        QPushButton* requestButton;

        // Watchlist View/Model
        QListView* watchlistView;
        QStandardItemModel* watchlistModel;

        // Details toolbar TODO
        QLabel* detailsToolbar;

        // Item data
        QTextEdit* outputText;

        // Historical data chart
        QChart* dataChart;
        QChartView* chartView;
        QLineSeries* historicalData;

        // Tab and page Widgets
        QTabWidget* tabs;
        QWidget* searchPage;
        QWidget* watchlistPage;



};

#endif // WINDOW_H
