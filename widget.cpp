#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    /*
     *对于父窗口(主窗口)，坐标系统相对于屏幕
     *原点：相对于屏幕左上角
     *x:往右递增
     * y:往下递增
     */
     move(300,100);

     /*
      *子窗口，坐标系统相对于父窗口
      *原点：相对于窗口空白区域左上角(不包括边框)
      * x:往右递增
      * y:往下递增
      */
     QPushButton *bb1 = new QPushButton(this);
     bb1->setText("btnOrdinate");
     bb1->move(0,0);
     bb1->resize(200,50);

     QPushButton *bb2 = new QPushButton(bb1);
     bb2->setText("@^@");
     bb2->move(10,10);



    b1.setText("confirm");
    b1.setParent(this);
    b1.move(100,100);

    b2 = new QPushButton(this);
    b2->setText("cancel");
    b2->move(100,200);

    b3.setText("switch to subwin");
    b3.setParent(this);
    b3.move(50,50);


    //subw.show();
    /*
     * 自定义槽函数
     * 信号与槽必须都没有返回值
     */
    connect(&b1, &QPushButton::released, this, &Widget::b1Slot);

    connect(b2, &QPushButton::released, this, &Widget::b1Slot);
    connect(b2, &QPushButton::released, &b1, &QPushButton::hide);

    connect(&b3,&QPushButton::released, this, &Widget::subSlot);

    //connect(&subw, &SubWidget::mySignal, this, &Widget::mainSlot);

    //处理重载带参数的信号
    //void (SubWidget::*pMySignal)() = &SubWidget::mySignal;
    //connect(&subw, pMySignal, this, &Widget::mainSlot);


    //void (SubWidget::*pMySignalParam)(int, QString) = &SubWidget::mySignal;
    //connect(&subw, pMySignalParam, this, &Widget::dealSlot);

    //qt4的方法槽函数必须有slots修饰
    //SIGNAL SLOT 将函数名字->字符串 不进行错误检查
    connect(&subw, SIGNAL(mySignal()), this, SLOT(mainSlot()));

    connect(&subw, SIGNAL(mySignal(int, QString)), this, SLOT(dealSlot(int, QString)));


    //lamda表达式，匿名函数对象
    //c++11新特性，项目文件： CONFIG += C++11
    //qt配合信号使用很方便
    QPushButton *b4 = new QPushButton(this);
    b4->setText("lamda");
    b4->move(150,150);

    int a = 10, b = 12;
    connect(b4, &QPushButton::clicked,
            //=:把外部所有局部变量，类中所有成员以值进行传递
            // 默认局部变量为只读，不能再lamda表达式中修改，加入mutable关键字可修改
            // this:类中所有成员以值进行传递
            // & :把外部所有局部变量，引用符号
            [=](bool isCheck) mutable
            //[b4,a,b]()
    {
        b4->setText("lamda expression");
        qDebug()<<"1111111";
        qDebug()<<a<<b;
        a = 13;
        qDebug()<<a<<b;
        qDebug()<<isCheck;
    });

    //测试控件是否需要手动的内存管理
    //1）指定父对象后 2）直接或间接继承于QObject
    //子对象如果是动态分配空间的new，不需要手动释放delete，系统会自动释放
    MyButtonMemNoLeak *btnLeak = new MyButtonMemNoLeak(this);
    btnLeak->setText("btnNoleak");
    btnLeak->move(300,100);
}

void Widget::dealSlot(int i, QString str)
{
    qDebug() << i << str;
}


void Widget::mainSlot()
{
    show();
    subw.hide();
}
void Widget::subSlot()
{
    hide();
    subw.show();
}

void Widget::b1Slot()
{
    b2->setText("cancel not");
}

Widget::~Widget()
{
}

