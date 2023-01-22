#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_PBSave_clicked();

    void Save();

//    void on_RBAutoSave_toggled(bool checked);

    void on_SBFontSize_valueChanged(int arg1);

    void on_fontComboBox_currentFontChanged(const QFont &f);

    void on_PBBold_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
