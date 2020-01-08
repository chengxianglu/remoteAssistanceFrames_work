#include "promptlabel.h"

PromptLabel::PromptLabel(QWidget *parent) : QLabel(parent)
{
    this->setFixedSize(316, 45);
    this->setText("请在上方输入你想帮助的人提供给你的验证码，"
                  "完成后点击连接开始"
                  "协助对方");

    this->setWordWrap(true);
    this->setAlignment(Qt::AlignTop | Qt::AlignCenter);
    QPalette m_pe;
    m_pe.setColor(QPalette::WindowText,Qt::gray);
    this->setPalette(m_pe);

    QFont font("宋体", 12, QFont::Thin);
    this->setFont(font);
}
