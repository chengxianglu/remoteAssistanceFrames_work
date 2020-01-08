/*成功复制界面*/

#include "copyverificationsuccessframe.h"

#include <QFrame>
#include <QVBoxLayout>
#include <QDesktopWidget>
#include <QApplication>

#include <DLabel>

CopyVerificationSuccessFrame::CopyVerificationSuccessFrame(QWidget *parent)
    : QMainWindow(parent)
{
    initUI();

    connect(m_copyButton, &DPushButton::clicked, this, [=] {
        this->hide();
    });
}

void CopyVerificationSuccessFrame::initUI()
{
//    setWindowIcon(QIcon(":/images/hand.png"));
    setWindowTitle("我要求助");
    setFixedSize(360, 320);

    QFrame *content = new QFrame;
    content->setStyleSheet("background: #F5F5F8");
    setCentralWidget(content);
    QDesktopWidget *pDesk = QApplication::desktop();
    this->move((pDesk->width() - this->width()) / 2, (pDesk->height() - this->height()) / 2);

    DLabel* m_successCopyLabel = new DLabel("成功复制到粘贴板");
    QFont font1("宋体", 20, QFont::Thin);
    m_successCopyLabel->setFont(font1);


    DLabel* m_promptLabel = new DLabel;
    m_promptLabel->setWordWrap(true);
    m_promptLabel->setAlignment(Qt::AlignTop | Qt::AlignCenter);
    QPalette m_pe;
    m_pe.setColor(QPalette::WindowText,Qt::gray);
    m_promptLabel->setPalette(m_pe);
    QFont font("宋体", 12, QFont::Thin);
    m_promptLabel->setFont(font);
    m_promptLabel->setAlignment(Qt::AlignCenter);
    m_promptLabel->setText("正在等待连接，请稍后...."
                           "连接成功后，此界面会自动隐藏到任务栏");

    m_copyButton = new DPushButton("复制");
    QFont font2("宋体", 20, QFont::Thin);
    m_copyButton->setFont(font2);
    m_copyButton->setFixedSize(200, 50);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addStretch(80);
    mainLayout->addWidget(m_successCopyLabel, 0, Qt::AlignTop | Qt::AlignCenter);
    mainLayout->addSpacing(30);
    mainLayout->addWidget(m_promptLabel, 0, Qt::AlignCenter);
    mainLayout->addSpacing(50);
    mainLayout->addWidget(m_copyButton, 0, Qt::AlignCenter);
    mainLayout->addStretch();

    content->setLayout(mainLayout);
    this->setWindowFlags(this->windowFlags()&~Qt::WindowMaximizeButtonHint);
}
