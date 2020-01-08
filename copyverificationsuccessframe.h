#ifndef COPYVERIFICATIONSUCCESSFRAME_H
#define COPYVERIFICATIONSUCCESSFRAME_H

#include <QMainWindow>

#include <QMainWindow>
#include <DPushButton>

DWIDGET_USE_NAMESPACE

class CopyVerificationSuccessFrame : public QMainWindow
{
    Q_OBJECT
public:
    explicit CopyVerificationSuccessFrame(QWidget *parent = nullptr);
    void initUI();
signals:

public slots:

private:
    DPushButton* m_copyButton = nullptr;
};

#endif // COPYVERIFICATIONSUCCESSFRAME_H
