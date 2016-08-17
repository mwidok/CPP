#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stringhandler.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;

}
/*
 * Reading the user's input and initiating the StringHandler.
 */
StringHandler* MainWindow::setHandler()
{

    QString qtext = ui->input_text->text();
    string text = qtext.toStdString();
    StringHandler* p_sh = new StringHandler(text, text.size());
    return p_sh;
}

/*
 * Processing the inversion if the respective button is clicked.
 */
void MainWindow::on_invert_btn_clicked()
{

    StringHandler* pt_sh = setHandler();
    ui->output_label->setText(QString::fromStdString(pt_sh->reverse()));
    delete pt_sh;

}

/*
 * Processing the ACII values calculation if the respective button is clicked.
 */
void MainWindow::on_asciiValue_btn_clicked()
{
    StringHandler* pt_sh = setHandler();
    ui->output_label->setText(QString::fromStdString(pt_sh->returnASCII()));
    ui->output_label->QWidget::adjustSize();
    delete pt_sh;
}

/*
 * Processing the ASCII sum calculation if the respective button is clicked.
 */
void MainWindow::on_asciiSum_btn_clicked()
{
    StringHandler* pt_sh = setHandler();
    ui->output_label->setText(QString::fromStdString(pt_sh->returnASCIISum()));
    delete pt_sh;
}

/*
 * Processing the palindrome check if the respective button is clicked.
 */
void MainWindow::on_palindrome_btn_clicked()
{
    StringHandler* pt_sh = setHandler();
    ui->output_label->setText(QString::fromStdString(pt_sh->isPalindrom()));
    delete pt_sh;
}

/*
 * Processing the vowel counts if the respective button is clicked.
 */
void MainWindow::on_vowel_btn_clicked()
{
    StringHandler* pt_sh = setHandler();
    ui->output_label->setText(QString::fromStdString(pt_sh->printVowels()));
    delete pt_sh;
}

/*
 * Processing the sign search if the respective button is clicked.
 */
void MainWindow::on_signSearch_btn_clicked()
{

    QInputDialog* dialog = new QInputDialog();
    QString qtext;
    dialog->show();
    dialog->setModal(true);

    bool ok;
    qtext = dialog->getText(0, "Character search", "Enter character: ", QLineEdit::Normal,
                            "", &ok);


        if(qtext.size()>1)
        {
            qtext.truncate(1);
        }
        if(ok)
        {

            char c = qtext.toStdString().at(0);
            StringHandler* pt_sh = setHandler();
            ui->output_label->setText(QString::fromStdString(pt_sh->signSearch(c)));
            delete pt_sh;
        }
        else
        {
            dialog->close();
        }


    delete dialog;

}
