#ifndef CREATEVERIFICATIONLABEL_H
#define CREATEVERIFICATIONLABEL_H

#include "copyverificationsuccessframe.h"

#include <QMainWindow>
#include <QLabel>
#include <QTimer>
#include <QList>

#include <DLabel>
#include <DPushButton>

DWIDGET_USE_NAMESPACE

class CreateVerificationLabel : public QMainWindow
{
    Q_OBJECT
public:
    explicit CreateVerificationLabel(QWidget *parent = nullptr);
    ~CreateVerificationLabel();

    void initUI();
    void connection();

signals:

public slots:
    void showCopysuccessframeSlots();

private:
    QList<QString> m_list;
    QString str;
    DLabel* m_verrificationCodeLabel;
    DLabel* m_prompLabel;
    DPushButton* m_copyButton;
    CopyVerificationSuccessFrame* m_copySuccessFrame = nullptr;
};

#endif // CREATEVERIFICATIONLABEL_H
