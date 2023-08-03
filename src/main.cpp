#include "app_manager.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auto instance = AppManager::getIntance();
    instance->init();
    instance->show();
    return a.exec();
}
