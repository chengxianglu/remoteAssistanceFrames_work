#ifndef CONNECTINGFRAME_H
#define CONNECTINGFRAME_H

#include <DMainWindow>
#include <DLabel>
#include <DPushButton>
#include <DSpinner>

DWIDGET_USE_NAMESPACE

class ConnectingFrame : public QMainWindow
{
    Q_OBJECT

public:
    explicit ConnectingFrame(QWidget *parent = nullptr);
    void initUI();

signals:
    void clickCancelButtonSignal();

public slots:

private:
    DLabel* m_imageLabel = nullptr;
    DLabel* m_promptLabel = nullptr;
    DPushButton* m_canceButton = nullptr;
    DSpinner* m_dSpinner = nullptr;
};

#endif // CONNECTINGFRAME_H
