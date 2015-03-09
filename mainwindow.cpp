#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_browserButton_pressed()
{
    // Set the working directory
    operator1.set_dir(ui->pathEdit->text());
}

void MainWindow::on_getButton_pressed()
{
    ui->oldNameEdit->clear();

    // Call file operator to get a list of filenames
    QStringList list=operator1.get_files_info();

    // Update UI with the information
    int numberOfFiles=list.size();
    int i;
    for(i=0;i<numberOfFiles;i++)
    {
        ui->oldNameEdit->append(list.at(i));
    }
    QString text="Total: " + QString::number(numberOfFiles);
    ui->oldTotalEdit->setText(text);
}

void MainWindow::on_renameButton_pressed()
{
    // Call file operator to rename files
    operator1.rename_files();
}

void MainWindow::on_newNameEdit_textChanged()
{
    // Get new filenames from UI
    QString newNames=ui->newNameEdit->toPlainText();

    // Update file operator
    int numberOfNewNames=operator1.get_new_filenames(newNames);

    // Update UI
    QString text="Total: " + QString::number(numberOfNewNames);
    ui->newTotalEdit->setText(text);

}
