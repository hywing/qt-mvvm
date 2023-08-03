#ifndef I_VIEW_MODEL_H
#define I_VIEW_MODEL_H

#include "i_view.h"
#include <QVariant>

class IViewModel
{
public:
    virtual void init() = 0;

    virtual void bind() = 0;

    virtual QVariant property(const QString &name) const = 0;

    virtual void show() = 0;
};

#endif // I_VIEW_MODEL_H
