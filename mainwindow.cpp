#include "mainwindow.h"
#include "createverificationcodeframe.h"
#include "createverificationlabel.h"

#include <QFrame>
#include <QPalette>
#include <QVBoxLayout>
#include <QDebug>
#include <QMainWindow>
#include <QFont>

#include <DLabel>
//#include <DFrame>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_enterVerificationCode(new EnterVerificationCode)
    , m_createVerificationLabelFrame(new CreateVerificationLabel)
    , m_createVerificationFrame(new CreateVerificationCodeFrame)
    , m_connectingFrame(new ConnectingFrame)
    , m_assistingFrame(new AssistingFrame)
{
    initUI();

    m_time = new QTimer(this);
    connect(m_createVerificationFrame,
            &CreateVerificationCodeFrame::createverificationcodeBurronSignal,
            this, &MainWindow::createVerificationcodeClickbottom);
    connect(m_enterVerificationCode, &EnterVerificationCode::hideEnterVerificationFramesignal,
            this, &MainWindow::enterVerificationcodeClick);
    connect(m_time, &QTimer::timeout, [=] {
       timeoutShowCopyFrame();
    });

    //我要求助弹框
    connect(m_askHelpButton, &DPushButton::clicked, this, [=] {
            showCreateVerificationCode();
            m_time->start(2000);
    });
    //点帮助别人弹出输入验证码
    connect(m_helpOtherButton, &DPushButton::clicked,
            this, &MainWindow::showEnterVerificationCode);
//    connect(m_connectingFrame, &ConnectingFrame::clickCancelButtonSignal,
//            this, &MainWindow::hideConnectingFrame);
    connect(m_enterVerificationCode, &EnterVerificationCode::clickKillTransitsignal,
            this, &MainWindow::hideAssistingFrameslots);
    connect(m_enterVerificationCode, &EnterVerificationCode::clickConnectFaildCancelsignal,
            this, [=] {
        this->show();
    });
    connect(m_enterVerificationCode, &EnterVerificationCode::clickConnectingCancelsignal,
            this, [=] {
        this->show();
    });
}

MainWindow::~MainWindow()
{
    if(m_time != nullptr)
       {
           delete m_time;
           m_time = nullptr;
       }
}

void MainWindow::initUI()
{   
    setWindowTitle("远程协助");
    setFixedSize(360, 320);
//    setStyleSheet("background: #F5F5F8");
    QFont font1("Microsoft YaHei", 12, 75);
    this->setFont(font1);

    QFrame *content = new QFrame;
    content->setStyleSheet("background: #F5F5F8");
    setCentralWidget(content);

    DLabel* m_themeImage = new DLabel;
    m_themeImage->resize(40, 40);
    m_themeImage->setAlignment(Qt::AlignCenter);
    m_themeImage->setText("This is pixmap");
    m_themeImage->setPixmap(QPixmap(":/images/theme.png"));

    DLabel* m_hintText = new DLabel;
    m_hintText->adjustSize();
    m_hintText->setGeometry(QRect(328, 240, 329, 27*4));
    m_hintText->setWordWrap(true);
    m_hintText->setAlignment(Qt::AlignTop);
    QPalette m_pe;
    m_pe.setColor(QPalette::WindowText,Qt::gray);
    m_hintText->setPalette(m_pe);
    QFont font("宋体", 12, QFont::Thin);
    m_hintText->setFont(font);
    m_hintText->setAlignment(Qt::AlignCenter);
    m_hintText->setText("This is text");
    m_hintText->setText("这是由deepin团队开发的远程协助应用，如果您在使用的过程中遇到了"
                      "困难，或者有人求助于您，请点击下方的我要求助或帮助别人");

    m_askHelpButton = new DPushButton("我要求助");
    m_askHelpButton->setMinimumSize(150, 16);
//    m_askHelpButton->setStyleSheet("background-color: white;");
    QFont font2("宋体", 12, QFont::Thin);
    m_askHelpButton->setFont(font2);
    m_askHelpButton->setIcon(QIcon(":/images/hand.png"));
    m_helpOtherButton = new DPushButton("帮助别人");
    m_helpOtherButton->setMinimumSize(150, 16);
    QFont font3("宋体", 12, QFont::Thin);
    m_helpOtherButton->setFont(font3);
    m_helpOtherButton->setIcon(QIcon(":/images/heart.png"));

    QVBoxLayout *mainLayout =new QVBoxLayout;
    mainLayout->addWidget(m_themeImage, 0, Qt::AlignTop | Qt::AlignCenter);
    mainLayout->addSpacing(20);
    mainLayout->addWidget(m_hintText, 0, Qt::AlignCenter);
    mainLayout->addStretch();
    mainLayout->addWidget(m_askHelpButton, 0, Qt::AlignCenter);
    mainLayout->addSpacing(7);
    mainLayout->addWidget(m_helpOtherButton, 0, Qt::AlignCenter);
    mainLayout->addStretch();

    content->setLayout(mainLayout);
    this->setWindowFlags(this->windowFlags()&~Qt::WindowMaximizeButtonHint);
}

//void MainWindow::paintEvent(QPaintEvent*)
//{
//    QPixmap m_pBg;
//    m_pBg.load(":/images/timg (1).jpeg");

//    QPainter painter(this);
//    painter.drawPixmap(0, 0, this->width(), this->height(), m_pBg);
//}

// 显示第二个界面创建验证码界面
void MainWindow::showCreateVerificationCode()
{
    m_createVerificationFrame->show();
    this->hide();
    qDebug() << "生成验证码";
}

//创建第二个输入验证码界面
void MainWindow::showEnterVerificationCode()
{
    m_enterVerificationCode->show();
    this->hide();
    qDebug() << "输入验证码";
}

//点击取消按钮返回主界面
void MainWindow::createVerificationcodeClickbottom()
{
    m_createVerificationFrame->hide();
    this->show();
    qDebug() << "生成验证码界面";
}

void MainWindow::timeoutShowCopyFrame()
{
    m_createVerificationLabelFrame->show();
    m_createVerificationFrame->hide();
    this->hide();
    m_time->stop();
}

//void MainWindow::hideConnectingFrame()
//{
//    m_connectingFrame->hide();
//    this->show();
//    qDebug() << "zhuyemiana";
//}

void MainWindow::hideAssistingFrameslots()
{
    this->show();
}

void MainWindow::enterVerificationcodeClick()
{
    m_enterVerificationCode->hide();
    this->hide();
}


