#ifndef I_VIEW_H
#define I_VIEW_H

#include <QWidget>

class IView
{
public:
    virtual void init() = 0;

    virtual void refresh() = 0;
};

#endif // I_VIEW_H
