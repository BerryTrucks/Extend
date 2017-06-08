/*
 * Copyright (c) 2013-2015 BlackBerry Limited.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ApplicationUI_HPP_
#define ApplicationUI_HPP_

#include <QObject>
#include <src/HeadlessCommunication/HeadlessCommunication.h>

namespace bb {
    namespace cascades {
        class LocaleHandler;
    }
    namespace system {
        class InvokeManager;
    }
}

class QTranslator;

/*!
 * @brief Application UI object
 *
 * Use this object to create and init app UI, to create context objects, to register the new meta types etc.
 */
class ApplicationUI: public QObject
{
    Q_OBJECT
public:
    ApplicationUI();
    virtual ~ApplicationUI() { }

    Q_INVOKABLE void sendToHl(QString message);
    Q_INVOKABLE void shutdown();

private slots:
    void onReceivedData(QString);
    void onSystemLanguageChanged();

private:
    QTranslator* translator;
    bb::cascades::LocaleHandler* localeHandler;
    bb::system::InvokeManager* invokeManager;

    HeadlessCommunication* headlessCommunication;
};

#endif /* ApplicationUI_HPP_ */