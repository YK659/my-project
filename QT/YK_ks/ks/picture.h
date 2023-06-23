#ifndef PICTURE_H
#define PICTURE_H

#include <QMainWindow>

namespace Ui {
class picture;
}

class picture : public QMainWindow
{
    Q_OBJECT

public:
    explicit picture(QWidget *parent = nullptr);
    ~picture();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::picture *ui;
    QStringList str;
    int i;
    QString s,n;
};

#endif // PICTURE_H
