#ifndef PLAYSOUND_H
#define PLAYSOUND_H
#include <QString>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QWidget>

class PlaySound:QWidget
{
private:
    //创建媒体
    //QMediaPlayer *player=new QMediaPlayer;
    //QMediaPlaylist *playList=new QMediaPlaylist;
    QMediaPlayer player;
    QMediaPlaylist playList;
    int current_num;
    QStringList file_list;

public:
    PlaySound();
    void beginToPlay();
    void setFileList(QStringList );
    void setIndex(int,int);

    QMediaPlayer* getPlayer()
    {
        return &player;
    }

    void setVolumn(int position)
    {
        player.setVolume(position);
    }
};

#endif // PLAYSOUND_H
