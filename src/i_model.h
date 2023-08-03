#ifndef I_MODEL_H
#define I_MODEL_H

#include <QObject>

class IModel
{
public:
    virtual void init() = 0;

    virtual void reset() = 0;
};

#endif // I_MODEL_H
