#ifndef ASSISTINGFRAME_H
#define ASSISTINGFRAME_H

#include <QMainWindow>

#include <DMainWindow>
#include <DPushButton>

DWIDGET_USE_NAMESPACE

class AssistingFrame : public QMainWindow
{
    Q_OBJECT
public:
    explicit AssistingFrame(QWidget *parent = nullptr);
    void initUI();

signals:
    void hideAssisting();

public slots:
    void minMuneclickedSlots();

private:
    DPushButton* m_retryButton = nullptr;
};

#endif // ASSISTINGFRAME_H
