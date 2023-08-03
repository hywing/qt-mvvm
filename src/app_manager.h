#ifndef APPMANAGER_H
#define APPMANAGER_H

#include <QObject>

class AppManager : public QObject
{
    Q_OBJECT
private:
    explicit AppManager(QObject *parent = nullptr);

    ~AppManager() override;

public:
    static AppManager *getIntance();

    void init();

    void show();
};

#endif // APPMANAGER_H
