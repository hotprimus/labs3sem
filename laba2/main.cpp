#include <QApplication>
#include "UI/UI.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    UI window;
    window.show();
    return app.exec();
}
