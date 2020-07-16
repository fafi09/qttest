#ifndef MYBUTTONMEMNOLEAK_H
#define MYBUTTONMEMNOLEAK_H

#include <QPushButton>
#include <QDebug>

class MyButtonMemNoLeak : public QPushButton
{
    Q_OBJECT
public:
    explicit MyButtonMemNoLeak(QWidget *parent = nullptr);
    ~MyButtonMemNoLeak();

signals:

};

#endif // MYBUTTONMEMNOLEAK_H
