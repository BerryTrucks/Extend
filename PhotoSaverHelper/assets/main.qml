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

import bb.cascades 1.3

Page {
    Container {
        TextField {
            id: textField
            text: "Message"
        }
        Button {
            text: "Send To HL"
            onClicked: { app.sendToHl(textField.text) }
        }
        
        Container {
            layout: StackLayout { orientation: LayoutOrientation.LeftToRight }
            topPadding: ui.du(50)
            Button {
                text: qsTr("Print log to Hub") + Retranslate.onLocaleOrLanguageChanged
                onClicked: { app.sendToHl("LOG_TO_HUB"); }
            }
            Button {
                text: qsTr("Shutdown") + Retranslate.onLocaleOrLanguageChanged
                onClicked: { app.shutdown(); }
            }
        }
    }
}
