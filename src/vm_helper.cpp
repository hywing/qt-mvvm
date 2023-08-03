#include "vm_helper.h"
#include "view_model.h"
#include <QWidget>

VMHelper::VMHelper(QObject *parent) : QObject(parent)
{

}

VMHelper::~VMHelper()
{

}

VMHelper *VMHelper::getInstance()
{
    static VMHelper instance;
    return &instance;
}

void VMHelper::init()
{
    if (m_vm == nullptr)
    {
        m_vm = new ViewModel(this);
        m_vm->init();
        m_vm->bind();
    }
}

void VMHelper::show()
{
    m_vm->show();
}

IViewModel *VMHelper::getVM()
{
    return  m_vm;
}
