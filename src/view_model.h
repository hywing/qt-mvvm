#ifndef VIEWMODEL_H
#define VIEWMODEL_H

#include "i_view_model.h"

class Model;
class View;

class ViewModel : public QObject, public IViewModel
{
    Q_OBJECT
public:
    explicit ViewModel(QObject *parent = nullptr);

    ~ViewModel() override;

    void init() override;

    void bind() override;

    QVariant property(const QString &name) const override;

    void show() override;

protected:
    Model *m_model;
    View *m_view;
};

#endif // VIEWMODEL_H
