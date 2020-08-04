#include "basictransceiver.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BasicTransceiver w;
//    w.setWindowIcon(QIcon(":/images/paper-plane.png"));
//    w.setWindowTitle(QStringLiteral("Lilin"));
    w.show();

    return a.exec();
}
