// error on line no 31 "value stored to "found" is never read ". 

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect (ui->pushButton,SIGNAL(clicked()),
            this,SLOT (btnFun()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::btnFun()
{
    QString emp_id[]={"101","102","103","104","105"};
    QString emp_name[]={"Ahmed","Ali","Usman","Zaviyar","Ibrahim"};
    QString desig[]={"CEO","Co.CEO","Manager","IT Employee","Clerk"};
    QString user= ui->lineEdit->text();
    bool found= false;
    for(int i=0;emp_id->length();i++)
    {
        if(user==emp_id[i]){
            found=true;
            QMessageBox::information(this, "Success!",
                                      "Employee_ID: " +emp_id[i]+
                                     ", Employee_Name: " +emp_name[i]+
                                     " , Designation :" +desig[i]);
            break;
        }
        if(!found){
            QMessageBox::information(this,"Error","Sorry Invalid Employee ID");

        }

    }
}

