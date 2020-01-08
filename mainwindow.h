#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "enterverificationcode.h"
#include "createverificationcodeframe.h"
#include "connectingframe.h"
#include "assistingframe.h"
#include "connectfaildframe.h"

#include <QTimer>
#include <QPushButton>
#include <QPaintEvent>

#include <DPushButton>
#include <DMainWindow>

DWIDGET_USE_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initUI();

//protected:
//    void paintEvent(QPaintEvent*) override;

signals:

public slots:
    void showCreateVerificationCode();
    void showEnterVerificationCode();

    void createVerificationcodeClickbottom();
    void timeoutShowCopyFrame();
//    void hideConnectingFrame();
    void hideAssistingFrameslots();
    void enterVerificationcodeClick();

private:
    DPushButton* m_askHelpButton = nullptr;
    DPushButton* m_helpOtherButton = nullptr;

    EnterVerificationCode* m_enterVerificationCode = nullptr;
    CreateVerificationCodeFrame* m_createVerificationFrame = nullptr;
    QTimer* m_time = nullptr;
    CreateVerificationLabel* m_createVerificationLabelFrame = nullptr;
    ConnectingFrame* m_connectingFrame = nullptr;  //---------------
    AssistingFrame* m_assistingFrame = nullptr;
    ConnectFaildFrame* m_connectFaildFrame = nullptr;
};

#endif // MAINWINDOW_H
