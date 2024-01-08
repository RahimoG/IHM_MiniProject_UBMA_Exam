#include "exam.h"
#include "ui_exam.h"


const int DB_SIZE = 100;
//extern int nextTuple;
extern QString fName[DB_SIZE];
extern QString lName[DB_SIZE];
extern QString Email[DB_SIZE];
extern QString matricule[DB_SIZE];
extern QString Pass[DB_SIZE];
extern int LogedInUserID;


//
double note = 0;


Exam::Exam(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Exam)
{
    ui->setupUi(this);
    ui->examFrame->hide();
}

Exam::~Exam()
{
    delete ui;
}

void Exam::on_startBtn_clicked()
{
    if(ui->IacceptCheck->isChecked())
    {
        ui->examPlaningFrame->hide();
        ui->left->hide();
        ui->rightHeaderName->setText("<html><head/><body><p align=\"right\">Name : "+ fName[LogedInUserID] +"</p></body></html>");
        ui->rightHeaderSurname->setText("<html><head/><body><p align=\"right\">Surname : "+ lName[LogedInUserID] +"</p></body></html>");
        ui->examFrame->show();
    }
    else{
        ui->remarque->setStyleSheet("color: #a63a3a;");
        ui->remarque->setText("You have to accept.");
    }
}


void Exam::on_validerBtn_clicked()
{
    note = 0;
    //Exo 01
    //Q1   2,3
    if(ui->E1Q1C2Check->isChecked())
    {
        note += 0.5;
    }
    if(ui->E1Q1C3Check->isChecked())
    {
        note += 0.5;
    }
    if(ui->E1Q1C1Check->isChecked() && (ui->E1Q1C3Check->isChecked() || ui->E1Q1C2Check->isChecked()))
    {
        note -= 0.5;
    }

    //Q2   3
    if(ui->E1Q2C3Check->isChecked())
    {
        note += 1;
    }
    if(ui->E1Q2C1Check->isChecked() && ui->E1Q2C3Check->isChecked())
    {
        note -= 0.5;
    }
    if(ui->E1Q2C2Check->isChecked() && ui->E1Q2C3Check->isChecked())
    {
        note -= 0.5;
    }
    //Q3    2
    if(ui->E1Q3C2Check->isChecked())
    {
        note += 1;
    }
    if(ui->E1Q3C1Check->isChecked() && ui->E1Q3C2Check->isChecked())
    {
        note -= 0.5;
    }
    if(ui->E1Q3C3Check->isChecked() && ui->E1Q3C2Check->isChecked())
    {
        note -= 0.5;
    }
    //Q4     2
    if(ui->E1Q4C2Check->isChecked())
    {
        note += 1;
    }
    if(ui->E1Q4C1Check->isChecked() && ui->E1Q4C2Check->isChecked())
    {
        note -= 0.5;
    }
    if(ui->E1Q4C3Check->isChecked() && ui->E1Q4C2Check->isChecked())
    {
        note -= 0.5;
    }
    //Q5    2
    if(ui->E1Q5C2Check->isChecked())
    {
        note += 1;
    }
    if(ui->E1Q5C1Check->isChecked() && ui->E1Q5C2Check->isChecked())
    {
        note -= 0.5;
    }
    if(ui->E1Q5C3Check->isChecked() && ui->E1Q5C2Check->isChecked())
    {
        note -= 0.5;
    }
    //Exo 02
    // yes
    if(ui->E2Q1C1->isChecked())
    {
        note += 1;
    }
    // no
    if(ui->E2Q2C2->isChecked())
    {
        note += 1;
    }
    //Exo 03
    //Q1    3
    if(ui->E3Q1C3Check->isChecked())
    {
        note += 1;
    }
    if(ui->E3Q1C1Check->isChecked() && ui->E3Q1C3Check->isChecked())
    {
        note -= 0.5;
    }
    if(ui->E3Q1C2Check->isChecked() && ui->E3Q1C3Check->isChecked())
    {
        note -= 0.5;
    }
    //Q2     none
    if((!ui->E3Q2C1Check->isChecked()) && (!ui->E3Q2C2Check->isChecked()) && (!ui->E3Q2C3Check->isChecked()))
    {
        note += 1;
    }
    //Q3     1
    if(ui->E3Q3C1Check->isChecked())
    {
        note += 1;
    }
    if(ui->E3Q3C3Check->isChecked() && ui->E3Q3C1Check->isChecked())
    {
        note -= 0.5;
    }
    if(ui->E3Q3C2Check->isChecked() && ui->E3Q3C1Check->isChecked())
    {
        note -= 0.5;
    }
    //Q4     3
    if(ui->E3Q4C3Check->isChecked())
    {
        note += 1;
    }
    if(ui->E3Q4C1Check->isChecked() && ui->E3Q4C3Check->isChecked())
    {
        note -= 0.5;
    }
    if(ui->E3Q4C2Check->isChecked() && ui->E3Q4C3Check->isChecked())
    {
        note -= 0.5;
    }
    //Exo 04
    //yes
    if(ui->E4Q1C1->isChecked())
    {
        note += 1;
    }
    // yes
    if(ui->E4Q2C1->isChecked())
    {
        note += 1;
    }
    // yes
    if(ui->E4Q3C1->isChecked())
    {
        note += 1;
    }
    //Exo 05
    //Q1   2
    if(ui->E5Q1C2Check->isChecked())
    {
        note += 1;
    }
    if(ui->E5Q1C1Check->isChecked() && ui->E5Q1C2Check->isChecked())
    {
        note -= 0.5;
    }
    if(ui->E5Q1C3Check->isChecked() && ui->E5Q1C2Check->isChecked())
    {
        note -= 0.5;
    }
    //Q2     3
    if(ui->E5Q2C3Check->isChecked())
    {
        note += 1;
    }
    if(ui->E5Q2C1Check->isChecked() && ui->E5Q2C3Check->isChecked())
    {
        note -= 0.5;
    }
    if(ui->E5Q2C2Check->isChecked() && ui->E5Q2C3Check->isChecked())
    {
        note -= 0.5;
    }
    //Q3      2
    if(ui->E5Q3C2Check->isChecked())
    {
        note += 1;
    }
    if(ui->E5Q3C1Check->isChecked() && ui->E5Q3C2Check->isChecked())
    {
        note -= 0.5;
    }
    if(ui->E5Q3C3Check->isChecked() && ui->E5Q3C2Check->isChecked())
    {
        note -= 0.5;
    }
    //Q4    2
    if(ui->E5Q4C2Check->isChecked())
    {
        note += 1;
    }
    if(ui->E5Q4C1Check->isChecked() && ui->E5Q4C2Check->isChecked())
    {
        note -= 0.5;
    }
    if(ui->E5Q4C3Check->isChecked() && ui->E5Q4C2Check->isChecked())
    {
        note -= 0.5;
    }
    //Exo 06
    //yes
    if(ui->E6Q1C1->isChecked())
    {
        note += 1;
    }
    //yes
    if(ui->E6Q2C1->isChecked())
    {
        note += 1;
    }
    int reply = QMessageBox::warning(this, "Warning", "Are you sure you want to validate your information?, once you have validated it you will no longer be able to modify it subsequently",
                                             QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        hide();
        noteP = new Note_Consult(this);
        noteP->show();
    }
}


void Exam::on_closeBtn_clicked()
{
    this->close();
}


void Exam::on_closeBtn_2_clicked()
{
    this->close();
}


void Exam::on_helpBtn_2_clicked()
{
    help = new Help(this);
    help->show();
}


void Exam::on_helpBtn_clicked()
{
    help = new Help(this);
    help->show();
}

