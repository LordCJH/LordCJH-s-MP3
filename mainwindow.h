#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QMediaMetaData>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QMediaPlayer *ply;  //播放器
    QMediaPlaylist *plist;  //播放列表

private slots:
    void showProcess(qint64 process);   //将播放进度以进度条的方式显示
    void changeProcess(int process);    //改变播放进度
    void MusicChanged(QMediaContent media);

    void on_play_pushButton_clicked();
    void on_next_pushButton_clicked();
    void on_prev_pushButton_clicked();
    void on_volumSlider_sliderMoved(int position);
    void on_playbackmodepushButton_clicked();
    void on_volsw_pushButton_clicked();
};

#endif // MAINWINDOW_H
