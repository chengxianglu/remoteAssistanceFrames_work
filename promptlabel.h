#ifndef PROMPTLABEL_H
#define PROMPTLABEL_H

#include <QMainWindow>
#include <QLabel>

class PromptLabel : public QLabel
{
    Q_OBJECT
public:
    explicit PromptLabel(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // PROMPTLABEL_H
