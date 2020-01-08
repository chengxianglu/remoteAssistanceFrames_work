/*复制验证码界面*/

#include "createverificationlabel.h"

#include <QTime>
#include <QDebug>
#include <QLabel>
#include <QList>
#include <QVBoxLayout>
#include <QDesktopWidget>
#include <QClipboard>
#include <QFile>

#include <DApplication>

CreateVerificationLabel::CreateVerificationLabel(QWidget *parent)
    : QMainWindow(parent)
    , m_copySuccessFrame(new CopyVerificationSuccessFrame)
{
    initUI();
    connection();
}

CreateVerificationLabel::~CreateVerificationLabel()
{
}

void CreateVerificationLabel::initUI()
{
//    setWindowIcon(QIcon(":/images/hand.png"));
    setWindowTitle("我要求助");
    setFixedSize(360, 320);

    QFrame *content = new QFrame;
    content->setStyleSheet("background: #F5F5F8");
    setCentralWidget(content);
    QDesktopWidget *pDesk = DApplication::desktop();
    this->move((pDesk->width() - this->width()) / 2, (pDesk->height() - this->height()) / 2);

    m_verrificationCodeLabel = new DLabel;
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    QString s;
    for(int i=0; i<6; i++)
    {
        int m_rand =qrand()%10;
        s = QString::number(m_rand);
        m_list << s;
    }
    str = m_list.join("");
    m_verrificationCodeLabel->setText(str);
    QFont font1("宋体", 50, QFont::Thin);
    m_verrificationCodeLabel->setFont(font1);


    m_prompLabel =new DLabel;
    m_prompLabel->adjustSize();
    m_prompLabel->setGeometry(QRect(328, 240, 329, 27*4));
    m_prompLabel->setWordWrap(true);
    m_prompLabel->setAlignment(Qt::AlignTop);
    QPalette m_pe;
    m_pe.setColor(QPalette::WindowText,Qt::gray);
    m_prompLabel->setPalette(m_pe);
    QFont font("宋体", 12, QFont::Thin);
    m_prompLabel->setFont(font);
    m_prompLabel->setAlignment(Qt::AlignCenter);
    m_prompLabel->setText("This is text");
    m_prompLabel->setText("要开始共享您的桌面，请将上面的验证码提供非协助您的人员，"
                           "他们输入验证码后，您的共享会话会立即开始");

    m_copyButton = new DPushButton("复制");
    QFont font2("宋体", 20, QFont::Thin);
    m_copyButton->setFont(font2);
    m_copyButton->setFixedSize(200, 50);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addStretch(80);
    mainLayout->addWidget(m_verrificationCodeLabel, 0, Qt::AlignTop | Qt::AlignCenter);
    mainLayout->addSpacing(30);
    mainLayout->addWidget(m_prompLabel, 0, Qt::AlignCenter);
    mainLayout->addSpacing(50);
    mainLayout->addWidget(m_copyButton, 0, Qt::AlignCenter);
    mainLayout->addStretch();

    content->setLayout(mainLayout);
    this->setWindowFlags(this->windowFlags()&~Qt::WindowMaximizeButtonHint);
}

void CreateVerificationLabel::connection()
{
    connect(m_copyButton, &DPushButton::clicked, this, [=] {
        showCopysuccessframeSlots();
//        QString source = ui->textEdit_code->toPlainText();
        QClipboard* clipboard = QApplication::clipboard();   //获取系统剪贴板指针
//        QString originalText = clipboard->text();         //获取剪贴板上文本信息
        clipboard->setText(str);
        QString originalText = clipboard->text();  //设置剪贴板内容</span>
        qDebug() << "剪切板内容" << originalText;

        QFile file("/home/chengxianglu/yanzhengma.txt");

        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            qDebug()<<"open fail!";
            return;
        }

        QTextStream out(&file);
        out<< str <<endl;//往文件写入字符串test
        out.flush();
        file.close();
    });

}

void CreateVerificationLabel::showCopysuccessframeSlots()
{
    m_copySuccessFrame->show();
    this->hide();
}
