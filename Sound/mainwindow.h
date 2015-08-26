#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "playsound.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_startButton_clicked();
    void on_volumnBar_sliderMoved(int position);
    void setProcessBar();

    void on_pushStop_clicked();

    void on_pushFile_clicked();

    void on_listItem_cellDoubleClicked(int row, int column);

    void on_listItem_cellClicked(int row, int column);

private:
    Ui::MainWindow *ui;
    PlaySound playSound;
    int i;

};

#endif // MAINWINDOW_H
