#ifndef ENTERVERIFICATIONCODE_H
#define ENTERVERIFICATIONCODE_H

#include "promptlabel.h"
#include "connectfaildframe.h"
#include "connectingframe.h"
#include "assistingframe.h"

#include <QWidget>
#include <QMouseEvent>
#include <QTimer>
#include <QMainWindow>
#include <QPaintEvent>

#include <DTextEdit>
#include <DPushButton>

DWIDGET_USE_NAMESPACE

class EnterVerificationCode : public QMainWindow
{
    Q_OBJECT

    friend ConnectingFrame;
public:
    explicit EnterVerificationCode(QWidget *parent = nullptr);
    void initUI();

signals:
    void hideEnterVerificationFramesignal();
    void clickKillTransitsignal(); //点击断开的中转信号
    void clickConnectFaildCancelsignal(); //中转信号
    void clickConnectingCancelsignal();

public slots:
    void judgeVerification();

protected:
    void mousePressEvent(QMouseEvent* e) override;//yanzhengyanzhengma

    void paintEvent(QPaintEvent* Event) override;

private:
    DTextEdit* m_textEdit = nullptr;
    PromptLabel* m_promptLabel = nullptr;
    DPushButton* m_cancelButton = nullptr;
    ConnectFaildFrame* m_connectFaildFrame = nullptr;
    ConnectingFrame* m_connectingFrame = nullptr;
    AssistingFrame* m_assistingFrame = nullptr;
    QTimer* m_time = nullptr;
//    QString flag = "取消";
};

#endif // ENTERVERIFICATIONCODE_H
