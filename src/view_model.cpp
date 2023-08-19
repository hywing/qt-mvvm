#include "view_model.h"
#include "model.h"
#include "view.h"

ViewModel::ViewModel(QObject *parent) : QObject(parent), m_model(new Model(this)), m_view(new View)
{

}

ViewModel::~ViewModel()
{

}

void ViewModel::init()
{
    if(m_model) {
        m_model->init();
    }
    if(m_view) {
        m_view->init();
    }
}

void ViewModel::bind()
{
    auto view = static_cast<View *>(m_view);
    auto model = static_cast<Model *>(m_model);

    // view to model
    connect(view, &View::changeName, model, &Model::onChangeName);
    connect(view, &View::changeSex, model, &Model::onChangeSex);
    connect(view, &View::changeAge, model, &Model::onChangeAge);
    connect(view, &View::reset, model, &Model::onReset);

    // model to view
    connect(model, &Model::updateName, view, &View::onUpdateName);
    connect(model, &Model::updateSex, view, &View::onUpdateSex);
    connect(model, &Model::updateAge, view, &View::onUpdateAge);
    connect(model, &Model::updateView, view, &View::onUpdateView);
}

QVariant ViewModel::property(const QString &name) const
{
    return m_model->property(name.toLocal8Bit());
}

void ViewModel::show()
{
    m_view->show();
}
