#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRandomGenerator>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QListWidgetItem;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButtonIconChange_clicked();

    void on_pushButtonViewMode_clicked();

private:
    Ui::MainWindow *ui;
    int randColorValue() { return QRandomGenerator::global()->generate() % 256; }
};
#endif // MAINWINDOW_H
