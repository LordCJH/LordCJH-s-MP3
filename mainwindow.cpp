#include "mainwindow.h"
#include "ui_mainwindow.h"

int slider_flag = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->volumSlider->setMaximum(100);
    ui->volumSlider->setValue(50);


    ply = new QMediaPlayer(this);
    plist = new QMediaPlaylist;


    connect(ply,SIGNAL(positionChanged(qint64)),this,SLOT(showProcess(qint64)));
    connect(ui->pSlider,SIGNAL(sliderMoved(int)),this,SLOT(changeProcess(int)));

    connect(ply,SIGNAL(currentMediaChanged(QMediaContent)),this,SLOT(MusicChanged(QMediaContent)));

    plist->setCurrentIndex(0);      //设置播放音乐的位置
    plist->setPlaybackMode(QMediaPlaylist::Random); //设置播放方式：随机播放
    plist->addMedia(QUrl("./songs/Coda(小田和奏) - Fighting Gold.mp3"));   //将音乐加入音乐列表
    plist->addMedia(QUrl("./songs/XX：me - escape(TV size).mp3"));   //将音乐加入音乐列表
    plist->addMedia(QUrl("./songs/后弦 - 香江边上.mp3"));   //将音乐加入音乐列表
    ply->setPlaylist(plist);    //设置播放器的播放列表
    ply->playlist()->setPlaybackMode(QMediaPlaylist::Loop);
    ply->setVolume(ui->volumSlider->value());

}

MainWindow::~MainWindow()
{
    delete ui;
}

/*////////////////////////////////////////////////////////////////////*/
/*////////////////////////////各种槽函数////////////////////////////////*/
/*/////////////////////////////////////////////////////////////////////*/
/*播放进度改变槽函数
 *音乐在播放过程中每隔一段时间会触发一次positionChanged(qint64)信号
*/
void MainWindow::showProcess(qint64 process){
//    if (slider_flag == 1) {
//        slider_flag = 0;
//        return ;
//    }
    ui->pSlider->setMaximum(ply->duration() / 100);
    ui->pSlider->setValue(process / 100);

    if (((ply->duration() / 1000) % 60) >= 10) {
        ui->totoltime_label->setText(QString::number(((ply->duration() / 1000) / 60), 10) + ":" + QString::number(((ply->duration() / 1000) % 60), 10));
    } else {
        ui->totoltime_label->setText(QString::number(((ply->duration() / 1000) / 60), 10) + ":0" + QString::number(((ply->duration() / 1000) % 60), 10));
    }
    if (((ply->position() / 1000) % 60) >= 10) {
        ui->curtime_label->setText(QString::number(((ply->position() / 1000) / 60), 10) + ":" + QString::number(((ply->position() / 1000) % 60), 10));
    }else {
        ui->curtime_label->setText(QString::number(((ply->position() / 1000) / 60), 10) + ":0" + QString::number(((ply->position() / 1000) % 60), 10));
    }

//    ply->setPosition((ply->position() % 100) * 100);
//    qDebug() << ply->metaData(QMediaMetaData::Author);
    qDebug() << "dura" << ply->duration() << "value" << process << "position" << ply->position();
}

/*进度条拖动槽函数
 *
 */
void MainWindow::changeProcess(int process){
    ply->setPosition(process * 100);
    if (((ply->position() / 1000) % 60) >= 10) {
        ui->curtime_label->setText(QString::number(((ply->position() / 1000) / 60), 10) + ":" + QString::number(((ply->position() / 1000) % 60), 10));
    }else {
        ui->curtime_label->setText(QString::number(((ply->position() / 1000) / 60), 10) + ":0" + QString::number(((ply->position() / 1000) % 60), 10));
    }
    qDebug() << process << ply->position();
    slider_flag = 1;
}

/*音量条滑动槽函数
 *
 */
void MainWindow::on_volumSlider_sliderMoved(int position)
{
    ply->setVolume(ui->volumSlider->value());
}

/*切换歌曲槽函数
 *
*/
void MainWindow::MusicChanged(QMediaContent media) {
    qDebug() << "music change";
}

/*(播放/暂停)按钮槽函数
 *
*/
void MainWindow::on_play_pushButton_clicked()
{
    static int flag = 0;

    if (flag == 0) {
        flag = 1;
        ui->play_pushButton->setStyleSheet("QPushButton {border:3px solid red;border-radius:35px;background:url(:/pausebutton.png) no-repeat;background-position: center;}");
        ply->play();        //播放音乐
    } else if (flag == 1) {
        flag = 0;
        ply->pause();
        ui->play_pushButton->setStyleSheet("QPushButton {border:3px solid red;border-radius:35px;background:url(:/playbutton.png) no-repeat;background-position: center;}");
    }
}

void MainWindow::on_next_pushButton_clicked()
{
    plist->next();
//    qDebug() << ply->duration();
}

void MainWindow::on_prev_pushButton_clicked()
{
    plist->previous();
}


void MainWindow::on_playbackmodepushButton_clicked()
{
    static int flag = 0;
    if (flag == 0) {
        flag = 1;
        ply->playlist()->setPlaybackMode(QMediaPlaylist::Loop);
        ui->playbackmodepushButton->setStyleSheet("QPushButton {border:1px solid white;background-image:url(:/loop4.png) no-repeat;background-position:center;}");
    } else if (flag == 1) {
        flag = 2;
        ply->playlist()->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
        ui->playbackmodepushButton->setStyleSheet("QPushButton {border:1px solid white;background-image:url(:/itemloop.png) no-repeat;background-position:center;}");
    } else if (flag == 2) {
        flag = 0;
        ply->playlist()->setPlaybackMode(QMediaPlaylist::Random);
        ui->playbackmodepushButton->setStyleSheet("QPushButton {border:1px solid white;background-image:url(:/random.png) no-repeat;background-position:center;}");
    }
}

void MainWindow::on_volsw_pushButton_clicked()
{
    static int flag = 0;
    static int vol;
    if (flag == 0) {
        flag = 1;
        vol = ply->volume();
        ply->setVolume(0);
        ui->volsw_pushButton->setStyleSheet("QPushButton {border:1px solid white;background-image:url(:/noVol.png) no-repeat;background-position:center;}");
    } else if (flag == 1) {
        flag = 0;
        ply->setVolume(vol);
        ui->volsw_pushButton->setStyleSheet("QPushButton {border:1px solid white;background-image:url(:/VolOn.png) no-repeat;background-position:center;}");
    }
}
