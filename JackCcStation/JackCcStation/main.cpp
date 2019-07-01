#include <QApplication>
#include <QString>
#include <QTextCodec>
#include "dialog.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Dialog  dlg;

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB2312"));

    if (dlg.exec() == QDialog::Accepted)
    {
        w.show();
        return a.exec();
    }
    return 0;
}
