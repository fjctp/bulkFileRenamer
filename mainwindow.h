#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "fileoperator.h"

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
    void on_browserButton_pressed();

    void on_getButton_pressed();

    void on_renameButton_pressed();

    void on_newNameEdit_textChanged();

private:
    Ui::MainWindow *ui;
    fileOperator operator1;
};

#endif // MAINWINDOW_H
