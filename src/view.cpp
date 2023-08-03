#include "view.h"
#include "vm_helper.h"
#include <QLabel>
#include <QLineEdit>

View::View(QWidget *parent)
    : QWidget(parent)
{
}

View::~View()
{
}

void View::init()
{
    auto func = [&](const QString &item, int num) -> QLineEdit * {
        auto label = new QLabel(this);
        label->setText(item);
        label->setGeometry(10, 20 * num, 60, 20);
        auto *edit = new QLineEdit(this);
        edit->setGeometry(90, 20 * num, 60, 20);
        return edit;
    };

    m_list.clear();
    auto i = 0;
    m_list << func("Name :", ++i);
    m_list << func("Sex :", ++i);
    m_list << func("Age :", ++i);

    // update view
    auto vm = VMHelper::getInstance()->getVM();
    m_list.at(0)->setText(vm->property("name").toString());
    m_list.at(1)->setText(vm->property("sex").toString());
    m_list.at(2)->setText(vm->property("age").toString());

    // bind func to update model
    connect(m_list.at(0), &QLineEdit::returnPressed, this, [&]() {
        emit this->changeName(m_list.at(0)->text());
    });
    connect(m_list.at(1), &QLineEdit::returnPressed, this, [&]() {
        emit this->changeSex(m_list.at(1)->text());
    });
    connect(m_list.at(2), &QLineEdit::returnPressed, this, [&]() {
        emit this->changeAge(m_list.at(2)->text().toInt());
    });
    setMinimumSize(800, 480);
}

void View::refresh()
{
    auto vm = VMHelper::getInstance()->getVM();
    m_list.at(0)->setText(vm->property("name").toString());
    m_list.at(1)->setText(vm->property("sex").toString());
    m_list.at(2)->setText(vm->property("age").toString());
}

void View::onUpdateName(const QString &name)
{
    m_list.at(0)->setText(name);
}

void View::onUpdateSex(const QString &sex)
{
    m_list.at(1)->setText(sex);
}

void View::onUpdateAge(int age)
{
    m_list.at(2)->setText(QString::number(age));
}

void View::onUpdateView()
{
    this->refresh();
}

