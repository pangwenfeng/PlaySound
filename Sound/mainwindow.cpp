#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QComboBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->volumnBar->setValue(50);
    ui->progressBarMusic->setValue(0);
    ui->listItem->setEditTriggers(QAbstractItemView::EditKeyPressed);
    //ui->listItem->setRowCount(2);
    //ui->listItem->setColumnCount(2);
    //ui->listItem->setItem(0,0,new QTableWidgetItem("Pang"));
    connect(playSound.getPlayer(), SIGNAL(positionChanged(qint64)),
            this, SLOT(setProcessBar()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    //playSound.setFileList("Try");
    playSound.beginToPlay();
}

void MainWindow::on_volumnBar_sliderMoved(int position)
{
    playSound.setVolumn(position);
}

void MainWindow::setProcessBar()
{
    QMediaPlayer* temp=playSound.getPlayer();
    //qDebug()<<temp->duration()<<"Processing"<<"\n";
    int sound_duration=static_cast<int>(temp->duration());
    int sound_position=static_cast<int>(temp->position());
    ui->progressBarMusic->setRange(0,sound_duration);
    ui->progressBarMusic->setValue(sound_position);
}

void MainWindow::on_pushStop_clicked()
{
    QMediaPlayer *temp=playSound.getPlayer();
    static bool statue=true;
    if(statue==true)
    {
        ui->pushStop->setText("RESUME");
        temp->pause();
        statue=false;
    }
    else
    {
        statue=true;
        ui->pushStop->setText("STOP");
        temp->play();
    }
}

void MainWindow::on_pushFile_clicked()
{
    //QString initialName=QDir::homePath();//返回一个用户的全路径
    //qDebug()<<QDir::homePath();
    QString initialName="C:/Users/Public/Music/Sample Music";
    QStringList pathList=QFileDialog::getOpenFileNames(this, "选择文件", initialName, NULL);
    //ui->listItem->setRowCount(pathList.size());
    ui->listItem->clear();
    ui->listItem->setRowCount(0);
    ui->listItem->setColumnCount(3);
    signalMapper=new QSignalMapper();
    for(int i=0; i<pathList.size(); ++i)
    {
        QString path=QDir::toNativeSeparators(pathList.at(i)); //把斜杠转化成反斜杠
        if(!path.isEmpty())
        {
           // mediaList->addMedia(QUrl::fromLocalFile(path));//加入到播放列表
            QString fileName=path.split("\\").last();//用斜杠分开，取最后一个名字
            int rownum=ui->listItem->rowCount();
            ui->listItem->insertRow(rownum);//为整个table插入一行行号为rownum，也就是说一首歌的信息占据一行的位置
            ui->listItem->setItem(rownum, 0, new QTableWidgetItem(fileName.split(".").front()));
            //ui->listItem->setItem(rownum, 1, new QTableWidgetItem(fileName.split(".").last()));
            //ui->listItem->setItem(rownum,2,new QTableWidgetItem(path));

            //QVector<QComboBox*>a;
            QComboBox *comBox = new QComboBox();
            comBox->addItem("LOVE");
            comBox->addItem("DISLIKE");
            ui->listItem->setCellWidget(rownum,1,comBox);
            connect(comBox,SIGNAL(activated(int)),signalMapper,SLOT(map()));
            signalMapper->setMapping(comBox,rownum);

            //ui->listItem->item(rownum,1)->setFlags(Qt::NoItemFlags);
            //ui->listItem->item(rownum,2)->setFlags(Qt::NoItemFlags);
        }
    }
    connect(signalMapper,SIGNAL(mapped(int)),this,SLOT(processCombox(int)));
    playSound.setFileList(pathList);
}

void MainWindow::on_listItem_cellDoubleClicked(int row, int column)
{
    //playSound.setFileList();
    playSound.setIndex(row,column);
}

void MainWindow::on_listItem_cellClicked(int row, int column)
{
    qDebug()<<"click me";
//    if(true)
//    {
//        QWidget * widget=ui->listItem->cellWidget(row,0);//获得widget
//        QComboBox *combox=(QComboBox*)widget;//强制转化为QComboBox
//        QString string=combox->currentText();
//        qDebug()<<string;
    //    }
}

void MainWindow::processCombox(int row_num)
{
    //qDebug()<<"current click is: "<<row_num;
    QTableWidgetItem *item=ui->listItem->item(row_num,0);
    item->setBackgroundColor(QColor(255,0,0));
    ui->listItem->setItem(row_num,0,item);
    //delete item;
}
