#ifndef WELCOMEP_H
#define WELCOMEP_H

#include <QMainWindow>
#include <QRegularExpression>
#include "exam.h"
#include "regester.h"
#include "help.h"
QT_BEGIN_NAMESPACE
namespace Ui { class WelcomeP; }
QT_END_NAMESPACE

class WelcomeP : public QMainWindow
{
    Q_OBJECT

public:
    WelcomeP(QWidget *parent = nullptr);
    ~WelcomeP();

private slots:
    void on_password_textChanged(const QString &arg1);



    void on_eye_off_clicked();

    void on_eye_on_clicked();

    void on_loginBtn_clicked();

    void on_closeBtn_clicked();

    void on_singupBtn_clicked();

    void on_helpBtn_clicked();

private:
    Ui::WelcomeP *ui;
    Exam *exam;
    Regester *reg;
    Help *help;
};
#endif // WELCOMEP_H
