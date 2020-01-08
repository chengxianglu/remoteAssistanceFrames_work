#include "connectingframe.h"

#include <QDesktopWidget>
#include <QVBoxLayout>
#include <QDebug>

#include <DApplication>

ConnectingFrame::ConnectingFrame(QWidget *parent)
    : QMainWindow(parent)
    , m_canceButton(new DPushButton)
{
    initUI();
    connect(m_canceButton, &DPushButton::clicked, this, [=] {
          emit clickCancelButtonSignal();
          this->hide();
    });
}

void ConnectingFrame::initUI()
{
//    setWindowIcon(QIcon(":/images/hand.png"));
    setWindowTitle("帮助别人");
    setFixedSize(360, 320);
    m_dSpinner = new DSpinner(this);
    m_dSpinner->start();
    m_dSpinner->resize(60, 60);
    m_dSpinner->move((this->width() - m_dSpinner->width())/ 2, 20);

    QFrame *content = new QFrame;

    setCentralWidget(content);
    QDesktopWidget *pDesk = DApplication::desktop();
    this->move((pDesk->width() - this->width()) / 2, (pDesk->height() - this->height()) / 2);

    m_promptLabel = new DLabel;
    m_promptLabel->setText("正在建立连接，请稍候....");
    m_promptLabel->setAlignment(Qt::AlignCenter);
    QFont font("宋体", 12, QFont::Thin);
    m_promptLabel->setFont(font);

    m_canceButton->setText("取消");
    QFont font1("宋体", 20, QFont::Thin);
    m_canceButton->setFont(font1);
    m_canceButton->setFixedSize(200, 50);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addStretch();
    mainLayout->addSpacing(50);
    mainLayout->addWidget(m_promptLabel, 0, Qt::AlignCenter);
    mainLayout->addSpacing(80);
    mainLayout->addWidget(m_canceButton, 0, Qt::AlignCenter);
    mainLayout->addStretch();

    content->setLayout(mainLayout);
    this->setWindowFlags(this->windowFlags()&~Qt::WindowMaximizeButtonHint);
}
