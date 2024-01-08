#ifndef NOTE_CONSULT_H
#define NOTE_CONSULT_H

#include <QMainWindow>
#include <QDesktopServices>
#include <QUrl>
#include "help.h"
namespace Ui {
class Note_Consult;
}

class Note_Consult : public QMainWindow
{
    Q_OBJECT

public:
    explicit Note_Consult(QWidget *parent = nullptr);
    ~Note_Consult();

private slots:
    void on_corectionBtn_clicked();

    void on_closeBtn_clicked();

    void on_finBtn_clicked();

    void on_helpBtn_clicked();

private:
    Ui::Note_Consult *ui;
    Help *help;
};

#endif // NOTE_CONSULT_H
