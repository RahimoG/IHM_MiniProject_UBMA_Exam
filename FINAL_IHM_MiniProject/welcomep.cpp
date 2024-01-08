#include "welcomep.h"
#include "ui_welcomep.h"

/// SIMPLE LOCAL BDD :
///
///

const int DB_SIZE = 100;
int nextTuple = 0;
QString fName[DB_SIZE];
QString lName[DB_SIZE];
QString Email[DB_SIZE];
QString matricule[DB_SIZE];
QString Pass[DB_SIZE];
int LogedInUserID;


///


WelcomeP::WelcomeP(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WelcomeP)
{
    ui->setupUi(this);
    ui->eye_off->hide();
    ui->eye_on->hide();

    /// my first tuple in BD
    fName[nextTuple] = "BIROUK";
    lName[nextTuple] = "Mohamed Abderrahmane";
    Email[nextTuple] = "wadoudbirouk9@gmail.com";
    matricule[nextTuple] = "202134046102";
    Pass[nextTuple] = "rahimo";
    nextTuple++;
    //Tuple 02
    fName[nextTuple] = "SMIRA";
    lName[nextTuple] = "Anis";
    Email[nextTuple] = "smiraanis45@gmail.com";
    matricule[nextTuple] = "202134037954";
    Pass[nextTuple] = "anis";
    nextTuple++;
    //Tuple 03
    fName[nextTuple] = "SADAT";
    lName[nextTuple] = "Litissia";
    Email[nextTuple] = "sadatLitissia@gmail.com";
    matricule[nextTuple] = "202134046102";
    Pass[nextTuple] = "lity";
    nextTuple++;


}

WelcomeP::~WelcomeP()
{
    delete ui;
}

bool eyeShow2 = false;
void WelcomeP::on_password_textChanged(const QString &arg1)
{
    if(!eyeShow2)
    {
        ui->eye_off->show();
        eyeShow2 = false;
    }
    else {
        ui->eye_on->show();
        eyeShow2 = true;
    }
}

void WelcomeP::on_eye_off_clicked()
{
    ui->password->setEchoMode(QLineEdit::Normal);
    ui->eye_off->hide();
    ui->eye_on->show();
    eyeShow2 = true;
}


void WelcomeP::on_eye_on_clicked()
{
    ui->password->setEchoMode(QLineEdit::Password);
    ui->eye_off->show();
    ui->eye_on->hide();
    eyeShow2 = false;
}


void WelcomeP::on_loginBtn_clicked()
{
    bool exist = false;
    // regex to check that the ID is a number;
    static QRegularExpression exp("[0-9]{12,12}");
    if(exp.match(ui->matricule->text()).hasMatch())
    {
        //matricule form valide
        for(int i=0; i<nextTuple; i++)
        {
            if(ui->matricule->text()==matricule[i])
            { // matricule exist
                exist = true;
                ui->matricule->setStyleSheet("background-color: transparent");
                if(ui->password->text()!=Pass[i])
                {   // pass false
                    ui->password->setStyleSheet("border:2px solid transparent;border-bottom-color:#a63a3a;");
                    ui->remarque->setText("Warning : The password of \" "+ matricule[i] +" \" is wrong.");
                }else{ //password true
                    ui->password->setStyleSheet("background-color: transparent");
                    ui->remarque->setStyleSheet("color: #41af5d;");
                    ui->remarque->setText("Connected Succesfully");
                    LogedInUserID = i;

                    hide();
                    exam = new Exam(this);
                    exam->show();

                }
            }
        }
    }
    else{
        ui->remarque->setStyleSheet("color: #a63a3a;");
        ui->remarque->setText("The registration number is not valid!");
    }
    if(!exist)
    {
        ui->matricule->setStyleSheet("border:2px solid transparent;border-bottom-color:#a63a3a;");
        ui->remarque->setText("Warning : Username doesn't exist.");
    }

}


void WelcomeP::on_closeBtn_clicked()
{
    this->close();
}


void WelcomeP::on_singupBtn_clicked()
{
    reg = new Regester(this);
    hide();
    reg->show();
}


void WelcomeP::on_helpBtn_clicked()
{
    help = new Help(this);
    help->show();
}

