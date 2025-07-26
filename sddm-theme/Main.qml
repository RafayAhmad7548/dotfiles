/***********************************************************************/


import QtQuick 2.0

import SddmComponents 2.0


Rectangle {
    color: "black"

    TextConstants { id: textConstants }

    Connections {
        target: sddm

        onLoginSucceeded: {
            password.borderColor = "green"
            password.focusColor = "green"
            password.hoverColor = "green"
        }

        onLoginFailed: {
            password.borderColor = "red"
            password.focusColor = "red"
            password.hoverColor = "red"
        }
    }

    Background {
        anchors.fill: parent
        source: config.background
        fillMode: Image.PreserveAspectCrop
        // x: geometry.x; y: geometry.y; width: geometry.width; height:geometry.height
        onStatusChanged: {
            if (status == Image.Error && source != config.defaultBackground) {
                source = config.defaultBackground
            }
        }
    }


    // BG
    // Image {
    //     source: "/home/rafayahmad/Pictures/bgs/1.png"
    //     anchors.fill: parent
    // }
    

    // Time Label
    Rectangle {
        width: 400
        height: 300
        anchors.centerIn: parent
        color: "transparent"
        anchors.verticalCenterOffset: -150

        Text {
            id: timeLabel
            text: formattedTime
            font.pixelSize: 100
            anchors.centerIn: parent
            color: "#F4DA7D"
        }


        Timer {
            interval: 1000  // Update every second
            running: true
            repeat: true
            onTriggered: {
                var date = new Date();
                var hours = date.getHours();
                var minutes = date.getMinutes();

                hours = hours % 12
                hours = hours ? hours : 12

                // Format the time as HH:MM:SS
                timeLabel.text = 
                    (hours < 10 ? "0" : "") + hours + "\n" +
                    (minutes < 10 ? "0" : "") + minutes
            }
        }

        Component.onCompleted: {
            interval: 1000  // Update every second
            running: true
            repeat: true
            onTriggered: {
                var date = new Date();
                var hours = date.getHours();
                var minutes = date.getMinutes();

                hours = hours % 12
                hours = hours ? hours : 12

                // Format the time as HH:MM:SS
                timeLabel.text = 
                    (hours < 10 ? "0" : "") + hours + "\n" +
                    (minutes < 10 ? "0" : "") + minutes
            }
        }

    }

    Rectangle {
        id: archlinux
        anchors.centerIn: parent
        height: 200
        width: 600
        // anchors.verticalCenterOffset: height * 2 / 3
        anchors.verticalCenterOffset: 100
        color: "transparent"

        Column {
            id: mainColumn
            anchors.centerIn: parent
            width: parent.width
            spacing: 20

            TextBox {
                id: name
                anchors.horizontalCenter: parent.horizontalCenter
                width: parent.width * 0.6; height: archlinux.height / 4

                color: "transparent"
                font.pixelSize: 16
                font.family: "HackNerdFont"
                borderColor: "#F4DA7D"
                focusColor: "#F4DA7D"
                hoverColor: "#F4DA7D"
                textColor: "white"
                radius: 50

                text: userModel.lastUser
                KeyNavigation.backtab: session; KeyNavigation.tab: password

                Keys.onPressed: {
                    if (event.key === Qt.Key_Return || event.key === Qt.Key_Enter) {
                        sddm.login(name.text, password.text, session.index)
                        event.accepted = true
                    }
                }
            }
            PasswordBox {
                id: password
                anchors.horizontalCenter: parent.horizontalCenter
                width: parent.width * 0.6; height: archlinux.height / 4

                font.pixelSize: 16
                color: "transparent"
                borderColor: "#F4DA7D"
                focusColor: "#F4DA7D"
                hoverColor: "#F4DA7D"
                textColor: "white"
                radius: 50

                focus: true
                Timer {
                    interval: 200
                    running: true
                    onTriggered: password.forceActiveFocus()
                }

                KeyNavigation.backtab: name; KeyNavigation.tab: rebootButton

                Keys.onPressed: {
                    if (event.key === Qt.Key_Return || event.key === Qt.Key_Enter) {
                        sddm.login(name.text, password.text, session.index)
                        event.accepted = true
                        
                    }
                }
            }
            
        }
    }
    
    // Session
    Rectangle {
        x: 50
        y: 975
        width: 225
        height: 75
        // spacing: 25
        color: "transparent"
        border.color: "#F4DA7D"
        border.width: 3
        radius: 50

        Text {
            id: lblSession
            text: textConstants.session
            verticalAlignment: Text.AlignVCenter
            color: "white"
            wrapMode: TextEdit.WordWrap
            font.bold: true
            font.pixelSize: 18
            font.family: "HackNerdFont"
            anchors.centerIn: parent
            anchors.horizontalCenterOffset: -60
        }

        ComboBox {
            id: session
            width: 100
            height: 25
            font.pixelSize: 14
            font.family: "HackNerdFont"
            anchors.centerIn: parent
            anchors.horizontalCenterOffset: 40

            arrowIcon: "angle-down.png"

            model: sessionModel
            index: sessionModel.lastIndex

            KeyNavigation.backtab: shutdownButton; KeyNavigation.tab: name
        }
    }
    
    // Buttons
    Rectangle {
        x: 1670
        y: 975
        width: 200
        height: 75
        color: "transparent"
        border.color: "#F4DA7D"
        border.width: 3
        radius: 50

        FocusScope{
            id: focusReboot
            width: 40
            height: 40
            anchors.centerIn: parent
            anchors.horizontalCenterOffset: -40

            ImageButton {
                id: rebootButton
                source: "reboot.png"
                anchors.fill: parent

                onFocusChanged: {
                    if (rebootButton.focus) {
                        rebootButton.opacity = 1.0
                    }
                }

                onClicked: sddm.reboot()
                KeyNavigation.backtab: password; KeyNavigation.tab: shutdownButton
            }

        }
        FocusScope{
            id: focusShutdown
            width: 40
            height: 40
            anchors.centerIn: parent
            anchors.horizontalCenterOffset: 40
            ImageButton {
                id: shutdownButton
                source: "shutdown.png"
                anchors.fill: parent
                // opacity: 1.0

                onFocusChanged: {
                    if (shutdownButton.focus) {
                        shutdownButton.opacity = 1.0
                    }
                }

                onClicked: sddm.powerOff()
                KeyNavigation.backtab: rebootButton; KeyNavigation.tab: session
            }
        }
        // Button {
        //     id: shutdownButton
        //     
        //     width: 40
        //     height: 40
        //     text: ""
        //     color: "black"
        //     activeColor: "transparent"
        //     pressedColor: "transparent"
        //     borderColor: "transparent"
        //     anchors.centerIn: parent
        //     anchors.horizontalCenterOffset: 40
        //
        //     Image {
        //         source: "shutdown.png"
        //         fillMode: Image.PreserveAspectFit
        //         anchors.fill: parent
        //     }
        //
        //     onClicked: sddm.powerOff()
        //
        //     KeyNavigation.backtab: loginButton; KeyNavigation.tab: rebootButton
        // }

        // Button {
        //     id: rebootButton
        //     text: ""
        //     width: 40
        //     height: 40
        //     color: "black"
        //     activeColor: "transparent"
        //     pressedColor: "transparent"
        //     borderColor: "transparent"
        //     anchors.centerIn: parent
        //     anchors.horizontalCenterOffset: -40
        //
        //     Image {
        //         source: "reboot.png"
        //         fillMode: Image.PreserveAspectFit
        //         anchors.fill: parent
        //     }
        //
        //     onClicked: sddm.reboot()
        //
        //     KeyNavigation.backtab: shutdownButton; KeyNavigation.tab: name
        // }
    }



    Component.onCompleted: {
        if (name.text == "")
            name.focus = true
        else
            password.focus = true
    }
}
