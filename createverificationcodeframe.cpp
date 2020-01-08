/*创建验证码界面*/

#include "createverificationcodeframe.h"

#include <QFont>
#include <QDesktopWidget>
#include <QVBoxLayout>
#include <QFrame>
#include <QPushButton>
#include <QDebug>
#include <QPalette>
#include <QFont>
#include <QHBoxLayout>

#include <DApplication>
#include <DLabel>

CreateVerificationCodeFrame::CreateVerificationCodeFrame(QWidget *parent)
    : QMainWindow(parent)
    , m_copy(new CreateVerificationLabel)
{
   initUI();

  connect(m_bottomButton, &DPushButton::clicked, this, [=] {
          emit createverificationcodeBurronSignal();
          m_createVerificationLabel->hide();
          QCoreApplication::exit();
   });
}

CreateVerificationCodeFrame::~CreateVerificationCodeFrame()
{

}

//void CreateVerificationCodeFrame::paintEvent(QPaintEvent*)
//{
//    QPixmap m_pBg;
//    m_pBg.load(":/images/timg (1).jpeg");

//    QPainter painter(this);
//    painter.drawPixmap(0, 0, this->width(), this->height(), m_pBg);
//}

void CreateVerificationCodeFrame::initUI()
{
//    setWindowIcon(QIcon(":/images/hand.png"));
    setWindowTitle("我要求助");
    setFixedSize(360, 320);
    m_dSpinner = new DSpinner(this);
    m_dSpinner->start();
    m_dSpinner->resize(60, 60);
    m_dSpinner->move((this->width() - m_dSpinner->width())/ 2, 20);

    QFrame *content = new QFrame;
//    content->setStyleSheet("background: #F5F5F8");
    setCentralWidget(content);
    QDesktopWidget *pDesk = DApplication::desktop();
    this->move((pDesk->width() - this->width()) / 2, (pDesk->height() - this->height()) / 2);

    m_createVerificationLabel = new CreateVerificationLabel;

    m_promptLabel = new DLabel;
    m_promptLabel->setText("正在生成请求验证码，请稍候....");

    m_bottomButton = new DPushButton;
    m_bottomButton->setText("取消");
    QFont font2("宋体", 20, QFont::Thin);
    m_bottomButton->setFont(font2);
    m_bottomButton->setFixedSize(200, 50);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addStretch();
    mainLayout->addSpacing(30);
    mainLayout->addStretch();
    mainLayout->addWidget(m_promptLabel, 0, Qt::AlignCenter);
    mainLayout->addSpacing(50);
    mainLayout->addWidget(m_bottomButton, 0, Qt::AlignCenter);
    mainLayout->addStretch();

    content->setLayout(mainLayout);
    this->setWindowFlags(this->windowFlags()&~Qt::WindowMaximizeButtonHint);
}

