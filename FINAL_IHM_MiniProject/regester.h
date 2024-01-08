#ifndef REGESTER_H
#define REGESTER_H

#include <QMainWindow>
#include "exam.h"
#include "help.h"
namespace Ui {
class Regester;
}

class Regester : public QMainWindow
{
    Q_OBJECT

public:
    explicit Regester(QWidget *parent = nullptr);
    ~Regester();

private slots:
    void on_loginBtn_clicked();

    void on_closeBtn_clicked();

    void on_singupBtn_clicked();

    void on_eye_off_clicked();

    void on_eye_on_clicked();

    void on_password_textChanged(const QString &arg1);

    void on_loginBtn__clicked();

    void on_helpBtn_clicked();

private:
    Ui::Regester *ui;
    Exam *exam;
    Help *help;
};

#endif // REGESTER_H
