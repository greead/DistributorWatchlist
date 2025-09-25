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
#include <QListWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QNetworkAccessManager>
#include <QUrl>
#include <QNetworkReply>

class Window : public QWidget {
    Q_OBJECT
    public:
        explicit Window(QWidget *parent = 0);

    signals:

    private slots:
        void makeRequest();
        void parseReply(QNetworkReply* reply);

    private:
        QNetworkAccessManager* nam;

        // General layout
        QHBoxLayout* generalLayout;
        QVBoxLayout* searchColumnLayout;
        QVBoxLayout* detailsColumnLayout;

        // Searchbar
        QFormLayout* urlLayout;
        QLabel* urlLabel;
        QLineEdit* urlEntry;
        QPushButton* requestButton;

        // Results list
        QListWidget* resultsList;

        // Details toolbar TODO
        QLabel* detailsToolbar;

        // Item data
        QTextEdit* outputText;

        // Historical data chart
        QChart* dataChart;
        QChartView* chartView;
        QLineSeries* historicalData;

};

#endif // WINDOW_H
