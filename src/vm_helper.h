#ifndef VMHELPER_H
#define VMHELPER_H

#include "i_view_model.h"

class VMHelper : public QObject
{
    Q_OBJECT
private:
    explicit VMHelper(QObject *parent = nullptr);

    ~VMHelper() override;

public:
    static VMHelper *getInstance();

    void init();

    void show();

    IViewModel *getVM();

private:
    IViewModel *m_vm;
};

#endif // VMHELPER_H
