// Copyright 2015 Cutehacks AS. All rights reserved.
// License can be found in the LICENSE file.

#include <QtCore/QObject>
#include <QtQml/QJSValue>

#include "qpm.h"

class QQmlEngine;
class QJsEngine;

QPM_BEGIN_NAMESPACE(com, cutehacks, duperagent)

class Request : public QObject
{
    Q_OBJECT

public:
    Request(QQmlEngine *engine, QObject *parent = 0);

    Q_INVOKABLE QJSValue get(const QJSValue&,
                              const QJSValue& = QJSValue(),
                              const QJSValue& = QJSValue()) const;
    Q_INVOKABLE QJSValue head(const QJSValue&,
                              const QJSValue& = QJSValue(),
                              const QJSValue& = QJSValue()) const;
    Q_INVOKABLE QJSValue del(const QJSValue&,
                              const QJSValue& = QJSValue()) const;
    Q_INVOKABLE QJSValue patch(const QJSValue&,
                              const QJSValue& = QJSValue(),
                              const QJSValue& = QJSValue()) const;
    Q_INVOKABLE QJSValue post(const QJSValue&,
                              const QJSValue& = QJSValue(),
                              const QJSValue& = QJSValue()) const;
    Q_INVOKABLE QJSValue put(const QJSValue&,
                              const QJSValue& = QJSValue(),
                              const QJSValue& = QJSValue()) const;

private:
    QQmlEngine *m_engine;
};

static QObject *request_provider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(scriptEngine)
    return new Request(engine);
}

QPM_END_NAMESPACE(com, cutehacks, duperagent)