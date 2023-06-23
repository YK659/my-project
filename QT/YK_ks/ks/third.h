#ifndef THIRD_H
#define THIRD_H

#include <QMainWindow>

namespace Ui {
class third;
}

class third : public QMainWindow
{
    Q_OBJECT

public:
    explicit third(QWidget *parent = nullptr);
    ~third();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::third *ui;
};

#endif // THIRD_H
