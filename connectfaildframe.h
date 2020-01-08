#ifndef CONNECTFAILDFRAME_H
#define CONNECTFAILDFRAME_H

#include <QMainWindow>

#include <DPushButton>

DWIDGET_USE_NAMESPACE

class ConnectFaildFrame : public QMainWindow
{
    Q_OBJECT
public:
    explicit ConnectFaildFrame(QWidget *parent = nullptr);
    void initUI();

signals:
    void returnMainFrameConnectfaileSignals();

public slots:

private:
    DPushButton* m_retryButton = nullptr;
};

#endif // CONNECTFAILDFRAME_H
