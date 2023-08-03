#ifndef MODEL_H
#define MODEL_H

#include "i_model.h"

class Config;

class Model : public QObject, public IModel
{
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName)
    Q_PROPERTY(QString sex READ getSex WRITE setSex)
    Q_PROPERTY(int age READ getAge WRITE setAge)
public:
    explicit Model(QObject *parent = nullptr);

    void init() override;

    void reset() override;

public slots:
    void onChangeName(const QString &name);

    void onChangeSex(const QString &sex);

    void onChangeAge(int age);

protected:
    QString getName() const;
    void setName(const QString &name);

    QString getSex() const;
    void setSex(const QString &sex);

    int getAge() const;
    void setAge(int age);

signals:
    void updateName(const QString &name);
    void updateSex(const QString &sex);
    void updateAge(int age);
    void updateView();

private:
    QString m_name;
    QString m_sex;
    int m_age;
    Config *m_config;
};

#endif // MODEL_H
