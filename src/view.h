#ifndef VIEW_H
#define VIEW_H

#include "i_view.h"

class QLineEdit;

class View : public QWidget, public IView
{
    Q_OBJECT

public:
    View(QWidget *parent = nullptr);

    ~View() override;

    void init() override;

    void refresh() override;

public slots:
    void onUpdateName(const QString &name);

    void onUpdateSex(const QString &sex);

    void onUpdateAge(int age);

    void onUpdateView();

signals:
    void changeName(const QString &name);
    void changeSex(const QString &sex);
    void changeAge(int age);
    void reset();

private:
    QLineEdit *m_name;
    QLineEdit *m_sex;
    QLineEdit *m_age;

    QList<QLineEdit *> m_list;
};
#endif // VIEW_H
