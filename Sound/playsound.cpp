#include "playsound.h"
#include <QApplication>
#include <QDebug>

PlaySound::PlaySound()
{
    //connect(&player, SIGNAL(duartionChanged(qint64)),
    //        this, SLOT(PlaySound::setProcessBar()));
    player.setVolume(50);
}

void PlaySound::beginToPlay( )
{
//    if(player !=NULL)
//    {
//        delete player;
//    }
//    player =new QMediaPlayer;
    if(!playList.isEmpty())
    {
        playList.setCurrentIndex(1);
        player.setPlaylist(&playList);
        //player.setVolume(50);
        //播放器开始播放列表中的歌曲
        player.play();
    }
}

void PlaySound::setFileList(QStringList file_list)
{
    this->file_list=file_list;
    playList.clear();
    for(int ii=0;ii<this->file_list.size();ii++)
    {
        playList.addMedia(QUrl::fromLocalFile(this->file_list.at(ii)));
    }
//   playList.addMedia(
//       QUrl::fromLocalFile("C:\\Users\\Public\\Music\\Sample Music\\Sleep Away.mp3"));
//   playList.addMedia(
//       QUrl::fromLocalFile("C:\\Users\\Public\\Music\\Sample Music\\Kalimba.mp3"));

}

void PlaySound::setIndex(int row, int col)
{
    if(!playList.isEmpty())
    {
       player.setPlaylist(&playList);
    }
    player.stop();
    playList.setCurrentIndex(row);
    player.play();
}



