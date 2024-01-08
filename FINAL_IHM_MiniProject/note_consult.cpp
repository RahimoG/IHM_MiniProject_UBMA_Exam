#include "note_consult.h"
#include "ui_note_consult.h"

extern double note;

Note_Consult::Note_Consult(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Note_Consult)
{
    ui->setupUi(this);

    ui->note->setText("<html><head/><body><p align=\"center\">"+ QString::number(note) +"/20</p></body></html>");
}

Note_Consult::~Note_Consult()
{
    delete ui;
}


void Note_Consult::on_corectionBtn_clicked()
{
    QDesktopServices::openUrl(QUrl::fromLocalFile("../FINAL_IHM_Assets/CorrectionExam.pdf"));
}


void Note_Consult::on_closeBtn_clicked()
{
    this->close();
}


void Note_Consult::on_finBtn_clicked()
{
    this->close();
}


void Note_Consult::on_helpBtn_clicked()
{
    help = new Help(this);
    help->show();
}

