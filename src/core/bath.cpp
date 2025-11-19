#include "bath.h"
#include <QVariant>
#include <QVariantMap>
#include <QMetaProperty>
#include <QMetaObject>

Bath::Bath(QObject *parent) : QObject(parent)
{

}

QVariantMap Bath::serialize() const
{
    QVariantMap map;
    const QMetaObject* meta = metaObject();
    for(auto i = meta->propertyOffset(); i < meta->propertyCount(); ++i)
    {
        auto prop = meta->property(i);
        map[prop.name()] = property(prop.name());
    }
    return map;
}

void Bath::deserialize(Bath &bath, const QVariant &variant)
{
    const auto map = variant.toMap();
    const QMetaObject* meta = metaObject();
    for(auto i = meta->propertyOffset(); i < meta->propertyCount(); ++i)
    {
        auto prop = meta->property(i);
        if(map.contains(prop.name()))
            setProperty(prop.name(), map[prop.name()]);
    }
}
