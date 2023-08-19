#include "config.h"

Config::Config(QObject *parent) : QObject(parent)
{

}

void Config::init()
{
    this->data[AGE_STRING] = 18;
    this->data[NAME_STRING] = "hywing";
    this->data[SEX_STRING] = "man";
}

void Config::reset()
{
    this->data[AGE_STRING] = 0;
    this->data[NAME_STRING] = "";
    this->data[SEX_STRING] = "";
}
