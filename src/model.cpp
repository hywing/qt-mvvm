#include "model.h"
#include "config.h"

Model::Model(QObject *parent) : QObject(parent), m_config(new Config(this))
{

}

void Model::init()
{
    m_config->init();
    m_age = m_config->data[AGE_STRING].toInt();
    m_sex = m_config->data[SEX_STRING].toString();
    m_name = m_config->data[NAME_STRING].toString();
    emit this->updateView();
}

void Model::reset()
{
    m_config->reset();
    m_age = m_config->data[AGE_STRING].toInt();
    m_sex = m_config->data[SEX_STRING].toString();
    m_name = m_config->data[NAME_STRING].toString();
    emit this->updateView();
}

void Model::onReset()
{
    this->reset();
}

void Model::onChangeName(const QString &name)
{
    this->setName(name);
}

void Model::onChangeSex(const QString &sex)
{
    this->setSex(sex);
}

void Model::onChangeAge(int age)
{
    this->setAge(age);
}

QString Model::getName() const
{
    return m_name;
}

void Model::setName(const QString &name)
{
    m_name = name;
    m_config->data["name"] = name;
}

QString Model::getSex() const
{
    return m_sex;
}

void Model::setSex(const QString &sex)
{
    m_sex = sex;
    m_config->data["sex"] = sex;
}

int Model::getAge() const
{
    return m_age;
}

void Model::setAge(int age)
{
    m_age = age;
    m_config->data["age"] = age;
}
