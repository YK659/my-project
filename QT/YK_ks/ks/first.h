#ifndef FIRST_H
#define FIRST_H

#include <QMainWindow>

namespace Ui {
class first;
}

class first : public QMainWindow
{
    Q_OBJECT

public:
    explicit first(QWidget *parent = nullptr);
    ~first();

private:
    Ui::first *ui;
};

#endif // FIRST_H
