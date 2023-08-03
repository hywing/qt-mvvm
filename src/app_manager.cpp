#include "app_manager.h"
#include "vm_helper.h"

AppManager::AppManager(QObject *parent) : QObject(parent)
{

}

AppManager::~AppManager()
{

}

AppManager *AppManager::getIntance()
{
    static AppManager instance;
    return &instance;
}

void AppManager::init()
{
    VMHelper::getInstance()->init();
}

void AppManager::show()
{
    VMHelper::getInstance()->show();
}
