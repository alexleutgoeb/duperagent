#ifndef CONFIG_H
#define CONFIG_H

#include <QGlobalStatic>
#include <QtQml/QJSValue>

#include "qpm.h"

class QQmlEngine;

namespace com { namespace cutehacks { namespace duperagent {

class Config
{
public:
    Config();
    void init(QQmlEngine *);
    void setOptions(const QJSValue&);

private:
    bool m_doneInit;
    bool m_noCache;
    QString m_cachePath;
    qint64 m_maxCacheSize;
};

Q_GLOBAL_STATIC(Config, getConfig)

} } }

#endif // CONFIG_H
