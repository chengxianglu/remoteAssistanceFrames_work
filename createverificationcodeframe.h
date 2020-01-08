#ifndef CREATEVERIFICATIONCODEFRAME_H
#define CREATEVERIFICATIONCODEFRAME_H

#include "createverificationlabel.h"
#include "createverificationlabel.h"

#include <QWidget>
#include <QTimer>

#include <QMainWindow>
#include <QPaintEvent>

#include <DLabel>
#include <DPushButton>
#include <DSpinner>

DWIDGET_USE_NAMESPACE

class CreateVerificationCodeFrame : public QMainWindow
{
    Q_OBJECT
public:
    explicit CreateVerificationCodeFrame(QWidget *parent = nullptr);
    ~CreateVerificationCodeFrame() override;
    void initUI();

signals:
    void createverificationcodeBurronSignal();

//protected:
//    void paintEvent(QPaintEvent*) override;

public slots:

private:
    CreateVerificationLabel* m_createVerificationLabel = nullptr;
    DLabel* m_promptLabel = nullptr;
    DPushButton* m_bottomButton = nullptr;
    DPushButton* m_copyButton = nullptr;
//    QTimer* m_time = nullptr;
    DLabel* m_imageLabel = nullptr;
    DSpinner* m_dSpinner = nullptr;
    CreateVerificationLabel* m_copy = nullptr;
};

#endif // CREATEVERIFICATIONCODEFRAME_H

