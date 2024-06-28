#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void handleTimeOut();
    virtual void timerEvent(QTimerEvent *event);
    ~MainWindow();

private slots:
    void on_conBt_clicked();

    void on_canBt_clicked();

private:
    Ui::MainWindow *ui;
    int myTimerId;
};
#endif // MAINWINDOW_H
