#include <QListWidgetItem>
#include <QIcon>
#include <QRandomGenerator>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*
     * connect QListWidget signals
     */

    // currentItemChanged
    connect(ui->listWidget, &QListWidget::currentItemChanged
            , [this] (QListWidgetItem *current, QListWidgetItem *previous) {
        if (current && previous)
            ui->plainTextEdit->appendPlainText(tr("%1 -> %2").arg(previous->text()).arg(current->text()));
    });

    // currentRowCHanged
    connect(ui->listWidget, &QListWidget::currentRowChanged, [this] (int currentRow) {
        ui->plainTextEdit->appendPlainText(tr("current row = %1").arg(currentRow));
    });

    // currentTextChanged
    // note that its not change text for edit
    connect(ui->listWidget, &QListWidget::currentTextChanged, [this] (const QString &currentText) {
        ui->plainTextEdit->appendPlainText(tr("current text -> %1").arg(currentText));
    });

    // itemActivated
    // double click ot enter key press
    connect(ui->listWidget, &QListWidget::itemActivated, [this] (QListWidgetItem *item) {
        ui->plainTextEdit->appendPlainText(tr("active -> %1").arg(item->text()));
    });

    // itemChanged
    // text, icon, etc changed
    connect(ui->listWidget, &QListWidget::itemChanged, [this] (QListWidgetItem *item) {
        ui->plainTextEdit->appendPlainText(tr("item changed -> %1").arg(item->text()));
    });

    // itemClicked
    connect(ui->listWidget, &QListWidget::itemClicked, [this] (QListWidgetItem *item) {
        ui->plainTextEdit->appendPlainText(tr("%1 clicked").arg(item->text()));
    });

    // itemDoubleClicked
    connect(ui->listWidget, &QListWidget::itemDoubleClicked, [this] (QListWidgetItem *item) {
        ui->plainTextEdit->appendPlainText(tr("%1 double clicked").arg(item->text()));
    });

    // itemEntered
    connect(ui->listWidget, &QListWidget::itemEntered, [this] (QListWidgetItem *item) {
        ui->plainTextEdit->appendPlainText(tr("%1 entered").arg(item->text()));
    });

    // itemPressed
    connect(ui->listWidget, &QListWidget::itemPressed, [this] (QListWidgetItem *item) {
        ui->plainTextEdit->appendPlainText(tr("%1 pressed").arg(item->text()));
    });

    // itemSelectionCHanged
    connect(ui->listWidget, &QListWidget::itemSelectionChanged, [this] () {
        ui->plainTextEdit->appendPlainText(tr("item selection changed"));
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    // add list items
    for (int i = 0; i < 100; ++i) {
        QColor foreColor(randColorValue(), randColorValue(), randColorValue());
        QColor backColor(randColorValue(), randColorValue(), randColorValue());
        QIcon icon(QString(":/icons/%1.png").arg(i % 5 + 1));
        QListWidgetItem* item = new QListWidgetItem(icon, tr("item%1").arg(i));
        item->setForeground(QBrush(foreColor));
        item->setBackground(QBrush(backColor));
        item->setFlags(item->flags() | Qt::ItemIsEditable); // set editable
        ui->listWidget->addItem(item);
    }
}

void MainWindow::on_pushButtonIconChange_clicked()
{
    // change item icon
    QListWidgetItem* item = ui->listWidget->currentItem();
    if (item) {
        QIcon icon(":/icons/6.png");
        item->setIcon(icon);
    }
}

void MainWindow::on_pushButtonViewMode_clicked()
{
    // view mode change
    QListView::ViewMode vm = ui->listWidget->viewMode();
    switch (vm) {
    case QListView::ListMode:
        ui->listWidget->setViewMode(QListView::IconMode);
        break;

    case QListView::IconMode:
        ui->listWidget->setViewMode(QListView::ListMode);
        break;

    default:
        break;
    }
}
