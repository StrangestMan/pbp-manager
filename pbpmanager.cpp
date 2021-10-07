#include "pbpmanager.h"
#include "ui_pbpmanager.h"
#include "pbp-functions.h"

pbpFunctions usrDoom;

pbpmanager::pbpmanager(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::pbpmanager)
{
    ui->setupUi(this);
}

pbpmanager::~pbpmanager()
{
    delete ui;
}


void pbpmanager::on_launchButton_pressed()
{
    usrDoom.launchScript(usrDoom);
}

void pbpmanager::on_scriptButton_pressed()
{
    usrDoom.makeScript(usrDoom);
}


void pbpmanager::on_checkBox_toggled(bool checked)
{
    usrDoom.bRespawningMonsters(checked);
}

void pbpmanager::on_checkBox_2_toggled(bool checked)
{
    usrDoom.bFastMonsters(checked);
}

void pbpmanager::on_checkBox_3_toggled(bool checked)
{
    usrDoom.bNoMonsters(checked);
}

void pbpmanager::on_checkBox_4_toggled(bool checked)
{
    usrDoom.bNoCheats(checked);
}


void pbpmanager::on_lineEdit_2_textEdited(const QString &arg1)
{
    usrDoom.sWadLocation(arg1.toStdString());
}


void pbpmanager::on_spinBox_2_valueChanged(int arg1)
{
    usrDoom.iMap(arg1);
}


void pbpmanager::on_comboBox_2_currentIndexChanged(int index)
{
    usrDoom.iDifficulty(index + 1);
}


void pbpmanager::on_comboBox_currentIndexChanged(int index)
{
    int compLevel = 17 - index;
    // skip over the unused TASDOOM compatability option
    if(compLevel < 7) {
        compLevel -= 1;
    }
    usrDoom.iCompLevel(compLevel);
}

