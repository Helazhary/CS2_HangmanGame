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
    QString getchances(){return chances;}
private slots:

    void on_guess_clicked();

private:
    Ui::MainWindow *ui;
    QString letterguess="";
   QString chances="5";
   QString hangman="hangman";
   void handlechar(QString userguess);
   QString solve="-------";
   bool correct=false;

};
#endif // MAINWINDOW_H
