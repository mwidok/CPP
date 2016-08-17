#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>
#include <stringhandler.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    StringHandler* setHandler();

private slots:
    void on_invert_btn_clicked();

    void on_asciiValue_btn_clicked();

    void on_asciiSum_btn_clicked();

    void on_palindrome_btn_clicked();

    void on_vowel_btn_clicked();

    void on_signSearch_btn_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
