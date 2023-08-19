#ifndef CONFIG_H
#define CONFIG_H

#include <QObject>
#include <QVariantMap>

#include "global.h"

class Config : public QObject
{
    Q_OBJECT
public:
    explicit Config(QObject *parent = nullptr);

    void init();

    void reset();

private:
    QVariantMap data;
    friend class Model;
};

#endif // CONFIG_H
