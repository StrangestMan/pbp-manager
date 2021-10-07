#ifndef PBPMANAGER_H
#define PBPMANAGER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class pbpmanager; }
QT_END_NAMESPACE

class pbpmanager : public QMainWindow
{
    Q_OBJECT

public:
    pbpmanager(QWidget *parent = nullptr);
    ~pbpmanager();

private slots:
    void on_checkBox_toggled(bool checked);

    void on_launchButton_pressed();

    void on_scriptButton_pressed();

    void on_checkBox_2_toggled(bool checked);

    void on_checkBox_3_toggled(bool checked);

    void on_checkBox_4_toggled(bool checked);

    void on_lineEdit_2_textEdited(const QString &arg1);

    void on_spinBox_2_valueChanged(int arg1);

    void on_comboBox_2_currentIndexChanged(int index);

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::pbpmanager *ui;
};
#endif // PBPMANAGER_H
