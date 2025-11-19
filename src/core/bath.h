#ifndef BATH_H
#define BATH_H

#include <QString>
#include <QObject>

class Bath : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name MEMBER m_name)
    Q_PROPERTY(quint32 duration MEMBER m_duration)
    Q_PROPERTY(Agitation agitation MEMBER m_agitation)
    Q_PROPERTY(bool notifyBeforeEnd MEMBER m_notifyBeforeEnd)

public:
    enum class Agitation{Every30s, Every60s, Stand };
    Q_ENUM(Agitation)

    Bath(QObject* parent = nullptr);
    QVariantMap serialize() const;
    void deserialize(Bath& bath, const QVariant& variant);

private:
    QString m_name;
    quint32 m_duration;
    Agitation m_agitation;
    bool m_notifyBeforeEnd;
};

#endif // BATH_H
