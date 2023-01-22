#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Archetype Toolkit");
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Save(){
    // Get the text from the text edit box
    QString textContents;
    textContents = ui->textEdit->toPlainText();

    // get the File Name
    QString fileName;
    fileName = ui->PTEFileName->toPlainText();

    QString fileExt;
    fileExt = ui->doctypeComboBox->currentText();

    // Create the save file
    std::ofstream saveFile(fileName.toStdString() + fileExt.toStdString());

    //check if file was successfully opened for writing
    if (saveFile.is_open())
    {
        std::cout << "Save file opened for writing" << std::endl;

        saveFile << textContents.toStdString() << "\n";
        saveFile.close();
    }
    else std::cout << "Problem with opening file" << std::endl;
}


void MainWindow::on_PBSave_clicked()
{
    Save();
    std::time_t tResult = std::time(nullptr);
    std::cout << "file saved @ " << std::asctime(std::localtime(&tResult)) << std::endl;
}





//void MainWindow::on_RBAutoSave_toggled(bool checked)
//{

//}


void MainWindow::on_SBFontSize_valueChanged(int arg1)
{
    int fontSize = arg1;
    std::cout << "font size set to " << arg1 << std::endl;
    ui->textEdit->setFontPointSize(fontSize);
}


void MainWindow::on_fontComboBox_currentFontChanged(const QFont &f)
{
    ui->textEdit->setFont(f);
}

// fix me (!)
void MainWindow::on_PBBold_clicked()
{
    int currentWeight = ui->textEdit->fontWeight();
    int boldWeight = currentWeight * 2;
    ui->textEdit->setFontWeight(boldWeight);
}

