#include "assistingframe.h"

#include <QFrame>
#include <QDesktopWidget>
#include <QApplication>
#include <QVBoxLayout>
#include <QDebug>
#include <QSystemTrayIcon>

#include <DLabel>

AssistingFrame::AssistingFrame(QWidget *parent)
    : QMainWindow(parent)
{
    initUI();
    connect(m_retryButton, &DPushButton::clicked, this, [=] {
        emit hideAssisting();
        this->hide();
        qDebug() << "求助信号已发送";
        minMuneclickedSlots();

    });
}

void AssistingFrame::minMuneclickedSlots()
{
    //隐藏程序主窗口
    this->hide();
    QSystemTrayIcon* mSysTrayIcon = new QSystemTrayIcon(this);
    QIcon icon = QIcon(":/images/heart.png");
    mSysTrayIcon->setIcon(icon);
    mSysTrayIcon->setToolTip(QObject::trUtf8("测试系统托盘图标"));
    mSysTrayIcon->show();
}

void AssistingFrame::initUI()
{
//    setWindowIcon(QIcon(":/images/hand.png"));
    setWindowTitle("帮助别人");
    setFixedSize(360, 320);

    QFrame *content = new QFrame;

    setCentralWidget(content);
    QDesktopWidget *pDesk = QApplication::desktop();
    this->move((pDesk->width() - this->width()) / 2, (pDesk->height() - this->height()) / 2);

    DLabel* titleLabel = new DLabel("您正在进行远成协助");
    QFont font("宋体", 20, QFont::Thin);
    titleLabel->setFont(font);

    DLabel* m_promptLabel = new DLabel;
    m_promptLabel->adjustSize();
    m_promptLabel->setGeometry(QRect(328, 240, 329, 27*4));
    m_promptLabel->setWordWrap(true);
    m_promptLabel->setAlignment(Qt::AlignTop | Qt::AlignCenter);
    QPalette m_pe;
    m_pe.setColor(QPalette::WindowText,Qt::gray);
    m_promptLabel->setPalette(m_pe);
    QFont font1("宋体", 12, QFont::Thin);
    m_promptLabel->setFont(font1);
    m_promptLabel->setAlignment(Qt::AlignCenter);
    m_promptLabel->setText("当前已经有一个连接会话，如果您想建立"
                           "新的连接，请先断开");

    m_retryButton = new DPushButton("断开");
    QFont font2("宋体", 20, QFont::Thin);
    m_retryButton->setFont(font);
    m_retryButton->setFixedSize(200, 50);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addSpacing(40);
    mainLayout->addWidget(titleLabel, 0, Qt::AlignTop | Qt::AlignCenter);
    mainLayout->addSpacing(40);
    mainLayout->addWidget(m_promptLabel, 0, Qt::AlignCenter);
    mainLayout->addSpacing(60);
    mainLayout->addWidget(m_retryButton, 0, Qt::AlignCenter);
    mainLayout->addStretch();

    content->setLayout(mainLayout);
    this->setWindowFlags(this->windowFlags()&~Qt::WindowMaximizeButtonHint);
}
