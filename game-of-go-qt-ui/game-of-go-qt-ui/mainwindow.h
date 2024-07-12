#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "socket.h"
#include <QMainWindow>
#include <QStackedWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    static MainWindow *instance;
public:
    static MainWindow *getInstance();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void swap(QWidget *widget);
    void next(QWidget *widget);
    void previous();

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::MainWindow *ui;
    Socket *socket;
    QStackedWidget *stackedWidget;

signals:
    void matchSetUp();
    void matchSetUp(QString opponent);

private slots:
    void onMessageReceived(QString msgtype, QString payload);
};
#endif // MAINWINDOW_H
