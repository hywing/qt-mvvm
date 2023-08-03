#include "model.h"
#include "config.h"

Model::Model(QObject *parent) : QObject(parent), m_config(new Config(this))
{

}

void Model::init()
{
    m_config->init();
}

void Model::reset()
{
    m_config->reset();
}

void Model::onChangeName(const QString &name)
{
    m_name = name;
}

void Model::onChangeSex(const QString &sex)
{
    m_sex = sex;
}

void Model::onChangeAge(int age)
{
    m_age = age;
}

QString Model::getName() const
{
    return m_name;
}

void Model::setName(const QString &name)
{
    m_name = name;
}

QString Model::getSex() const
{
    return m_sex;
}

void Model::setSex(const QString &sex)
{
    m_sex = sex;
}

int Model::getAge() const
{
    return m_age;
}

void Model::setAge(int age)
{
    m_age = age;
}
