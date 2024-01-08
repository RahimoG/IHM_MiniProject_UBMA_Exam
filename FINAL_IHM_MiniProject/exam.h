#ifndef EXAM_H
#define EXAM_H

#include <QMainWindow>
#include "note_consult.h"
#include "help.h"
#include <QMessageBox>

namespace Ui {
class Exam;
}

class Exam : public QMainWindow
{
    Q_OBJECT

public:
    explicit Exam(QWidget *parent = nullptr);
    ~Exam();

private slots:
    void on_startBtn_clicked();

    void on_validerBtn_clicked();

    void on_closeBtn_clicked();

    void on_closeBtn_2_clicked();

    void on_helpBtn_2_clicked();

    void on_helpBtn_clicked();

private:
    Ui::Exam *ui;
    Note_Consult *noteP;
    Help *help;
};

#endif // EXAM_H
