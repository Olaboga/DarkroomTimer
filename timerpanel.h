#ifndef TIMERPANEL_H
#define TIMERPANEL_H

#include <QWidget>
#include <qaudiooutput.h>
#include <qboxlayout.h>
#include <qframe.h>
#include <qmediaplayer.h>

class TimerPanel : public QFrame
{
    Q_OBJECT
public:
    explicit TimerPanel(QWidget *parent = nullptr);
    explicit TimerPanel(QString panelName, QWidget* parent = nullptr);

public slots:
    void startTimer();

signals:
    void timerDone();

private:
    QVBoxLayout* m_layout;
    QMediaPlayer* m_beepPlayer;
    QAudioOutput* m_audioOutput;
};

#endif // TIMERPANEL_H
