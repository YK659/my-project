#ifndef SECOND_H
#define SECOND_H

#include <QMainWindow>

namespace Ui {
class second;
}

class second : public QMainWindow
{
    Q_OBJECT

public:
    explicit second(QWidget *parent = nullptr);
    ~second();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::second *ui;
    int n;
};

#endif // SECOND_H
