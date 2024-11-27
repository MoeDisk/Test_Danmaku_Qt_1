#include "mainwindow.h"

DanmakuWidget::DanmakuWidget(QWidget *parent)
    : QWidget(parent) {
    // 设置窗口无边框、透明、置顶
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setAttribute(Qt::WA_TransparentForMouseEvents); // 鼠标穿透窗口
    resize(1920, 1080); // 弹幕窗口的大小

    // 定时器用于生成弹幕
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &DanmakuWidget::addDanmaku);
    timer->start(1000); // 每隔 1 秒生成一条弹幕
}

void DanmakuWidget::addDanmaku() {
    // 创建一个 QLabel 用于显示弹幕
    QLabel *label = new QLabel(this);
    QString text = QString::fromUtf8("弹幕内容 #%1").arg(QRandomGenerator::global()->bounded(1000));
    label->setText(text);
    label->setStyleSheet("color: black; font-size: 18px;");
    label->adjustSize();

    // 随机选择弹幕的垂直位置
    int yPos = QRandomGenerator::global()->bounded(height() - label->height());
    label->move(width(), yPos);
    label->show();

    // 创建动画，让弹幕从右向左移动
    QPropertyAnimation *animation = new QPropertyAnimation(label, "pos");
    animation->setDuration(5000); // 动画持续时间 5 秒
    animation->setStartValue(QPoint(width(), yPos));
    animation->setEndValue(QPoint(-label->width(), yPos));

    // 动画结束后销毁 QLabel
    connect(animation, &QPropertyAnimation::finished, label, &QLabel::deleteLater);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}
