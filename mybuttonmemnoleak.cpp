#include "mybuttonmemnoleak.h"

MyButtonMemNoLeak::MyButtonMemNoLeak(QWidget *parent) : QPushButton(parent)
{

}

MyButtonMemNoLeak::~MyButtonMemNoLeak()
{
    qDebug()<<"mybutton is broken";
}
