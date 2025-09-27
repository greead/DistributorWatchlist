#include "window.h"

#include <QApplication>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

Window::Window(QWidget *parent): QWidget{parent} {
    // Set window size
    setFixedSize(800, 600);

    //////////// NETWORKING ////////////
    // Create and connect NAM
    nam = new QNetworkAccessManager{this};
    connect(nam, SIGNAL(finished(QNetworkReply*)), this, SLOT(parseReply(QNetworkReply*)));

    //////////// DATABASE ////////////
    // TODO

    //////////// CENTRAL LAYOUT ////////////
    // Set up central layout
    centralLayout = new QGridLayout{this};

    // Set up tabs
    tabs = new QTabWidget{};
    centralLayout->addWidget(tabs);

    // Set up pages
    searchPage = new QWidget{};
    watchlistPage = new QWidget{};
    tabs->addTab(searchPage, "Search");
    tabs->addTab(watchlistPage, "Watchlist");

    //////////// SEARCH PAGE ////////////
    // Create general hbox
    generalLayout = new QHBoxLayout{};
    searchPage->setLayout(generalLayout);

    // Create search column vbox
    searchColumnLayout = new QVBoxLayout{};
    generalLayout->addLayout(searchColumnLayout);

    // Create details column vbox
    detailsColumnLayout = new QVBoxLayout{};
    generalLayout->addLayout(detailsColumnLayout);

    //////////// SEARCH BAR ////////////
    // Create search box form
    urlLayout = new QFormLayout{};
    searchColumnLayout->addLayout(urlLayout);

    // Create search box
    urlLabel = new QLabel{"URL:"};
    urlEntry = new QLineEdit{"https://pokeapi.co/api/v2/pokemon/ditto"};
    urlLayout->addRow(urlLabel, urlEntry);

    // Create request button
    requestButton = new QPushButton{"Send Request"};
    searchColumnLayout->addWidget(requestButton);

    // Send request on button press
    connect(requestButton, SIGNAL(clicked()), this, SLOT(makeRequest()));

    //////////// LIST VIEW ////////////
    // Create watchlist model
    watchlistModel = new QStandardItemModel{0, 1};

    // Create watchlist view
    watchlistView = new QListView{};
    watchlistView->setModel(watchlistModel);
    searchColumnLayout->addWidget(watchlistView);
    connect(watchlistView->selectionModel(), &QItemSelectionModel::selectionChanged, this, &Window::updateTextSelect);

    //////////// TOOLBAR ////////////
    // Create toolbar
    detailsToolbar = new QLabel{"WATCHLIST ITEM DETAILS"};
    detailsColumnLayout->addWidget(detailsToolbar);

    //////////// DETAILS PANE ////////////
    // Create output textbox
    outputText = new QTextEdit{};
    detailsColumnLayout->addWidget(outputText);

    //////////// CHARTS ////////////
    // Create historical data chart
    dataChart = new QChart{};
    historicalData = new QLineSeries{};

    // Dummy data
    *historicalData << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);
    dataChart->addSeries(historicalData);
    chartView = new QChartView{dataChart};
    detailsColumnLayout->addWidget(chartView);



}

void Window::makeRequest() {
    nam->get(QNetworkRequest{QUrl{urlEntry->text()}});
}

void Window::parseReply(QNetworkReply* reply) {
    QJsonDocument jsonDoc = QJsonDocument::fromJson(reply->readAll());
    QJsonObject jsonObj = jsonDoc.object();
    for (auto it = jsonObj.begin(); it != jsonObj.end(); it++) {
        auto item = new QStandardItem{it.key()};
        item->setData(jsonObj.value(it.key()).toJson());
        watchlistModel->appendRow(item);
    }
    // Add items to a model
    outputText->setText(jsonDoc.toJson());


}

void Window::updateTextSelect(const QItemSelection &selected, const QItemSelection &deselected) {
    for(auto idx : selected.indexes()) {
        QStandardItem* item = watchlistModel->itemFromIndex(idx);
        outputText->setText(item->data().toString());
    }
}
