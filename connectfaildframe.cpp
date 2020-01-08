#include "connectfaildframe.h"

#include <QFrame>
#include <QDesktopWidget>
#include <QApplication>
#include <QVBoxLayout>

#include <DLabel>

ConnectFaildFrame::ConnectFaildFrame(QWidget *parent)
    : QMainWindow(parent)
{
    initUI();
    connect(m_retryButton, &DPushButton::clicked,
            this, [=] {
        emit returnMainFrameConnectfaileSignals();
        this->hide();
    });
}

void ConnectFaildFrame::initUI()
{
//    setWindowIcon(QIcon(":/images/hand.png"));
    setWindowTitle("帮助别人");
    setFixedSize(360, 320);

    QFrame *content = new QFrame;

    setCentralWidget(content);
    QDesktopWidget *pDesk = QApplication::desktop();
    this->move((pDesk->width() - this->width()) / 2, (pDesk->height() - this->height()) / 2);

    DLabel* titleLabel = new DLabel("连接失败");
    QFont font("宋体", 20, QFont::Thin);
    titleLabel->setFont(font);
    QPalette m_pe1;
    m_pe1.setColor(QPalette::WindowText,Qt:: red);
    titleLabel->setPalette(m_pe1);

    DLabel* m_promptLabel = new DLabel;
    m_promptLabel->setText("网络连接不是很稳定，"
                           "点击重试按钮再次尝试连接");
    m_promptLabel->setWordWrap(true);
    m_promptLabel->setAlignment(Qt::AlignTop | Qt::AlignCenter);
    QPalette m_pe;
    m_pe.setColor(QPalette::WindowText,Qt::gray);
    m_promptLabel->setPalette(m_pe);
    QFont font1("宋体", 12, QFont::Thin);
    m_promptLabel->setFont(font1);

    m_retryButton = new DPushButton("取消");
    QFont font2("宋体", 20, QFont::Thin);
    m_retryButton->setFont(font);
    m_retryButton->setFixedSize(200, 50);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addSpacing(60);
    mainLayout->addWidget(titleLabel, 0, Qt::AlignTop | Qt::AlignCenter);
    mainLayout->addSpacing(40);
    mainLayout->addWidget(m_promptLabel, 0, Qt::AlignCenter);
    mainLayout->addSpacing(60);
    mainLayout->addWidget(m_retryButton, 0, Qt::AlignCenter);
    mainLayout->addStretch();

    content->setLayout(mainLayout);
    this->setWindowFlags(this->windowFlags()&~Qt::WindowMaximizeButtonHint);
}
