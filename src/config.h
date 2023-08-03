#ifndef CONFIG_H
#define CONFIG_H

#include <QObject>
#include <QVariantMap>

class Config : public QObject
{
    Q_OBJECT
public:
    explicit Config(QObject *parent = nullptr);

    void init();

    void reset();

private:
    QVariantMap m_map;
};

#endif // CONFIG_H
