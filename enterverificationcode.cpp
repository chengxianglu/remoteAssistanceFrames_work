/*输入验证码界面*/

#include "enterverificationcode.h"

#include <QDesktopWidget>
#include <QVBoxLayout>
#include <QDebug>
#include <QThread>
#include <QIcon>
#include <QString>
#include <QFile>

#include <DApplication>

EnterVerificationCode::EnterVerificationCode(QWidget *parent)
    : QMainWindow(parent)
    , m_textEdit(new DTextEdit)
    , m_connectFaildFrame(new ConnectFaildFrame)
    , m_connectingFrame(new ConnectingFrame)
    , m_assistingFrame(new AssistingFrame)
{
    setWindowIcon(QIcon(":/images/theme.png"));
    m_time = new QTimer;

    initUI();

    connect(m_time, &QTimer::timeout, [=] {
        judgeVerification();
        m_time->stop();
    });
    connect(m_cancelButton, &DPushButton::clicked,
            this, [=] {
        m_time->start(5000);
        m_connectingFrame->show();
        this->hide();
    });

    connect(m_assistingFrame, &AssistingFrame::hideAssisting,
            this, [=] {
        emit clickKillTransitsignal();
        qDebug() << "中转信号已发送";
    });

    connect(m_connectFaildFrame, &ConnectFaildFrame::returnMainFrameConnectfaileSignals,
            this, &EnterVerificationCode::clickConnectFaildCancelsignal);
    connect(m_connectingFrame, &ConnectingFrame::clickCancelButtonSignal,
            this, &EnterVerificationCode::clickConnectingCancelsignal);
}

void EnterVerificationCode::paintEvent(QPaintEvent* Event)
{
    QPixmap m_pBg;
    m_pBg.load(":/images/theme.png");

    QPainter painter;
    painter.begin(this);
    painter.drawPixmap(20, 20, this->width(), this->height(), m_pBg);
}

void EnterVerificationCode::initUI()
{
//    setWindowIcon(QIcon(":/images/theme.png"));
    setWindowTitle("帮助别人");
    setFixedSize(360, 320); 

    QFrame *content = new QFrame;
    content->setStyleSheet("background: #F5F5F8");
    setCentralWidget(content);

    QDesktopWidget *pDesk = DApplication::desktop();
    this->move((pDesk->width() - this->width()) / 2, (pDesk->height() - this->height()) / 2);

    m_textEdit->setStyleSheet("background-color : white");
    QFont font1("宋体", 20, QFont::Thin);
    m_textEdit->setFont(font1);
    m_textEdit->setGeometry(0, 0, 300, 40);
//    m_textEdit->setMaximumSize(500, 90);
//    m_textEdit->resize(300, 30);
    m_textEdit->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
    if (m_textEdit->toPlainText().length() > 6) {
        m_textEdit->setFocusPolicy(Qt::NoFocus);
    }

    m_promptLabel = new PromptLabel;
    m_promptLabel->setContentsMargins(30, 166, 30, 114);

    m_cancelButton = new DPushButton("取消");
    QFont font("宋体", 20, QFont::Thin);
    m_cancelButton->setFont(font);
    m_cancelButton->setFixedSize(200, 50);
    connect(m_cancelButton, &DPushButton::clicked, this, [=] {
        emit hideEnterVerificationFramesignal();
        m_time->stop();
    });

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addSpacing(100);
    mainLayout->addWidget(m_textEdit, 0, Qt::AlignTop | Qt::AlignCenter);
    mainLayout->addSpacing(30);
    mainLayout->addWidget(m_promptLabel, 0, Qt::AlignCenter);
    mainLayout->addSpacing(50);
    mainLayout->addWidget(m_cancelButton, 0, Qt::AlignCenter);
    mainLayout->addStretch();

    content->setLayout(mainLayout);
    this->setWindowFlags(this->windowFlags()&~Qt::WindowMaximizeButtonHint);
}

void EnterVerificationCode::judgeVerification()
{
    QFile file("/home/chengxianglu/yanzhengma.txt");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug()<<"open fail!";
        return;
    }

    QByteArray t = file.readAll();
    QString m_string;
    QString m_str;
    m_string.append(t);

    QString::iterator iter;
    for (iter = m_string.begin(); iter != m_string.end()-1; ++iter) {
        qDebug()<< "读出的文件内容1是：" << *iter ;
        m_str.append(*iter);
    }
    qDebug() << "读出的文件内容2是：" << m_str;

    file.close();

    QString getEditStr = m_textEdit->toPlainText();
    if(getEditStr == m_str &&
       getEditStr.length() == m_str.length()) {
        m_cancelButton->setText("连接");

        m_assistingFrame->show();
        m_connectingFrame->hide();
    } else {
        m_connectFaildFrame->show();
        this->hide();
        m_connectingFrame->hide();
        qDebug() << "验证码错误";
    }
}

void EnterVerificationCode::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        disconnect(m_cancelButton, &DPushButton::clicked, this,
                   &EnterVerificationCode::hideEnterVerificationFramesignal);

        if(m_textEdit->toPlainText() != "")
        {
            m_cancelButton->setText("连接");
        }
    }
}


