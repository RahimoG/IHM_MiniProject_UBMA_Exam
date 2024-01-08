#include "regester.h"
#include "ui_regester.h"
#include "welcomep.h"

const int DB_SIZE = 100;
extern int nextTuple;
extern QString fName[DB_SIZE];
extern QString lName[DB_SIZE];
extern QString Email[DB_SIZE];
extern QString matricule[DB_SIZE];
extern QString Pass[DB_SIZE];
extern int LogedInUserID;

Regester::Regester(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Regester)
{
    ui->setupUi(this);
    ui->eye_off->hide();
    ui->eye_on->hide();
}

Regester::~Regester()
{
    delete ui;
}

void Regester::on_loginBtn_clicked()
{
    bool exist = false;
    ui->remarque->setStyleSheet("color: #a63a3a;");
    if(ui->name->text() == "")
    {
        ui->name->setStyleSheet("border:2px solid transparent; border-bottom-color:#a63a3a;");
        ui->remarque->setText("Warning : Name is required !");
    }
    else{
        // valide name:
        ui->name->setStyleSheet("background-color: transparent");

        if(ui->surname->text() == "")
        {
            ui->surname->setStyleSheet("border:2px solid transparent; border-bottom-color:#a63a3a;");
            ui->remarque->setText("Warning : Surname is required !");
        }
        else{
            // valid surname
            ui->surname->setStyleSheet("background-color: transparent");

            static QRegularExpression exp("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$");
            if(exp.match(ui->email->text()).hasMatch())
            {
                // email valid
                ui->email->setStyleSheet("background-color: transparent");

                if(ui->password->text() == ""){
                    ui->password->setStyleSheet("border:2px solid transparent; border-bottom-color:#a63a3a;");
                    ui->remarque->setText("Warning : Password is required !");

                }
                else{
                    // password valid
                    ui->password->setStyleSheet("background-color: transparent");

                    static QRegularExpression exp("20((2[0-3])|(1[0-9]))[0-9]{8,8}");
                    if(exp.match(ui->matricule->text()).hasMatch()){
                           for(int i=0; i<DB_SIZE; i++)
                           {
                               if(ui->matricule->text() == matricule[i])
                                   exist = true;
                           }
                           if(exist)
                           {
                               ui->matricule->setStyleSheet("border:2px solid transparent; border-bottom-color:#a63a3a;");
                               ui->remarque->setText("Warning : This registration number is alredy token !");
                           }else{
                               // matricule valide
                               ui->matricule->setStyleSheet("background-color: transparent");

                               ui->remarque->setStyleSheet("color: #41af5d;");
                               ui->remarque->setText("Account created succesfuly");
                               /// add tuple in DB :

                               fName[nextTuple] = ui->name->text();
                               lName[nextTuple] = ui->surname->text();
                               Email[nextTuple] = ui->email->text();
                               matricule[nextTuple] = ui->matricule->text();
                               Pass[nextTuple] = ui->password->text();
                               nextTuple++;

                           }
                    }else{
                        ui->email->setStyleSheet("border:2px solid transparent; border-bottom-color:#a63a3a;");
                        ui->remarque->setText("Warning : Regestration number is  not valid ! must be [YearBac + RegistrationNumBac] exp : 202134046102");
                    }

                }
            }else{
                ui->email->setStyleSheet("border:2px solid transparent; border-bottom-color:#a63a3a;");
                ui->remarque->setText("Warning : email is not valid ! must be aaaaa@bbbb.cc");
            }
        }
    }
}


void Regester::on_closeBtn_clicked()
{
    this->close();
}


void Regester::on_singupBtn_clicked()
{
    WelcomeP *login = new WelcomeP();
    login->show();
    this->hide();
}

bool eyeShow = false;
void Regester::on_eye_off_clicked()
{
    ui->password->setEchoMode(QLineEdit::Normal);
    ui->eye_off->hide();
    ui->eye_on->show();
    eyeShow = true;
}


void Regester::on_eye_on_clicked()
{
    ui->password->setEchoMode(QLineEdit::Password);
    ui->eye_off->show();
    ui->eye_on->hide();
    eyeShow = false;
}


void Regester::on_password_textChanged(const QString &arg1)
{
    if(!eyeShow)
    {
        ui->eye_off->show();
        eyeShow = false;
    }
    else {
        ui->eye_on->show();
        eyeShow = true;
    }
}


void Regester::on_loginBtn__clicked()
{
    bool exist = false;
    ui->remarque->setStyleSheet("color: #a63a3a;");
    if(ui->name->text() == "")
    {
        ui->name->setStyleSheet("border:2px solid transparent; border-bottom-color:#a63a3a;");
        ui->remarque->setText("Warning : Name is required !");
    }
    else{
        // valide name:
        ui->name->setStyleSheet("background-color: transparent");

        if(ui->surname->text() == "")
        {
            ui->surname->setStyleSheet("border:2px solid transparent; border-bottom-color:#a63a3a;");
            ui->remarque->setText("Warning : Surname is required !");
        }
        else{
            // valid surname
            ui->surname->setStyleSheet("background-color: transparent");

            static QRegularExpression exp("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$");
            if(exp.match(ui->email->text()).hasMatch())
            {
                // email valid
                ui->email->setStyleSheet("background-color: transparent");

                if(ui->password->text() == ""){
                    ui->password->setStyleSheet("border:2px solid transparent; border-bottom-color:#a63a3a;");
                    ui->remarque->setText("Warning : Password is required !");

                }
                else{
                    // password valid
                    ui->password->setStyleSheet("background-color: transparent");

                    static QRegularExpression exp("20((2[0-3])|(1[0-9]))[0-9]{8,8}");
                    if(exp.match(ui->matricule->text()).hasMatch()){
                           for(int i=0; i<DB_SIZE; i++)
                           {
                               if(ui->matricule->text() == matricule[i])
                                   exist = true;
                           }
                           if(exist)
                           {
                               ui->matricule->setStyleSheet("border:2px solid transparent; border-bottom-color:#a63a3a;");
                               ui->remarque->setText("Warning : This registration number is alredy token !");
                           }else{
                               // matricule valide
                               ui->matricule->setStyleSheet("background-color: transparent");

                               if(ui->terms->isChecked())
                               {
                                   ui->remarque->setStyleSheet("color: #41af5d;");
                                   ui->remarque->setText("Account created succesfuly");
                                   /// add tuple in DB :

                                   fName[nextTuple] = ui->name->text();
                                   lName[nextTuple] = ui->surname->text();
                                   Email[nextTuple] = ui->email->text();
                                   matricule[nextTuple] = ui->matricule->text();
                                   Pass[nextTuple] = ui->password->text();
                                   nextTuple++;

                                   LogedInUserID = nextTuple - 1;

                                   hide();
                                   exam = new Exam(this);
                                   exam->show();

                               }else{

                                   ui->remarque->setText("Warning : You must accept terms and conditions");
                               }
                           }
                    }else{
                        ui->email->setStyleSheet("border:2px solid transparent; border-bottom-color:#a63a3a;");
                        ui->remarque->setText("Warning : Regestration number is  not valid ! \nmust be [YearBac + RegistrationNumBac] exp : 202134046102");
                    }

                }
            }else{
                ui->email->setStyleSheet("border:2px solid transparent; border-bottom-color:#a63a3a;");
                ui->remarque->setText("Warning : email is not valid ! must be aaaaa@bbbb.cc");
            }
        }
    }
}


void Regester::on_helpBtn_clicked()
{
    help = new Help(this);
    help->show();
}

