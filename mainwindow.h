#ifndef DANMAKUWIDGET_H
#define DANMAKUWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPropertyAnimation>
#include <QTimer>
#include <QRandomGenerator>

class DanmakuWidget : public QWidget {
    Q_OBJECT

public:
    explicit DanmakuWidget(QWidget *parent = nullptr);

private slots:
    void addDanmaku();
};

#endif // DANMAKUWIDGET_H
