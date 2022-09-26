#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_guess_clicked()
{

if(chances.toInt() != 0 && solve!=hangman)
    {

//------------------input validation------------------------------
   letterguess= ui->charinput->text();
    ui->charinput->setText("");

   if(letterguess.length()>1)
       ui->updatex->setText("Please input only one letter");

     else if(letterguess=="")
        ui->updatex->setText("No letter inputted");

//-----------------correct or wrong guess check--------------------
   else
   {
                for (int i = 0; i < hangman.length(); i++)
                 {
                      if (hangman[i] == letterguess)
                         correct = true;
                 }
//------------------------correct guess--------------------------------
        if (correct == true)
        {
          ui->updatex->setText(letterguess+" is a correct guess!");
          correct=false;

          for (int i = 0; i < hangman.length(); i++)
           {
                if (hangman[i] == letterguess)
                   solve[i] = hangman[i];
                ui->displayword->setText(solve);
           }
          if(solve==hangman)
           {
               ui->updatex->setText("CONGRATS");
               ui->label->setText("YOU GUESSED THE WORD!");
               ui->chances->setText("");
           }

        }
//-------------------------------------wrong guess----------------------------
        else
           {
             int chancedown = chances.toInt();
             chancedown--;
             chances= QString::number(chancedown);
             if(chances.toInt()==0)
             {
                 ui->updatex->setText("Game Over");
                 ui->label->setText("out of chances");
                 ui->chances->setText("");
             }
                     else
                     {
                         ui->chances->setText(QString::number(chancedown));
                         ui->updatex->setText("Wrong guess, try again");
                     }
           }
    }


    }

}





