/***********************************************************************/


import QtQuick 2.0

import SddmComponents 2.0


Rectangle {
    width: 640
    height: 480
    color: "black"

    TextConstants { id: textConstants }

    Connections {
        target: sddm

        onLoginSucceeded: {
            errorMessage.color = "steelblue"
            errorMessage.text = textConstants.loginSucceeded
        }

        onLoginFailed: {
            errorMessage.color = "red"
            errorMessage.text = textConstants.loginFailed
        }
    }

    Repeater {
        model: screenModel
        Background {
            x: geometry.x; y: geometry.y; width: geometry.width; height:geometry.height
            source: config.background
            fillMode: Image.Tile
            onStatusChanged: {
                if (status == Image.Error && source != config.defaultBackground) {
                    source = config.defaultBackground
                }
            }
        }
    }

    Rectangle {
        property variant geometry: screenModel.geometry(screenModel.primary)
        x: geometry.x; y: geometry.y; width: geometry.width; height: geometry.height
        color: "transparent"
        transformOrigin: Item.Top

        Rectangle {
            width: 300
            height: 300
            radius: 200
            anchors.centerIn: parent
            anchors.verticalCenterOffset: -300
            color: "black"

            // border.color: "#1793d1"
            border.color: "white"
            border.width: 5
            Image {
                id: archlogo
                width: 175
                height: 175
                anchors.centerIn: parent
                anchors.verticalCenterOffset: -10
                fillMode: Image.PreserveAspectFit
                transformOrigin: Item.Center
                source: "archlinux.png"
            }    
        }
        

        Rectangle {
            id: archlinux
            anchors.centerIn: parent
            height: 200
            width: 600
            // anchors.verticalCenterOffset: height * 2 / 3
            anchors.verticalCenterOffset: 100
            color: "#0C0C0C"
            border.color: "#1793d1"
            border.width: 5
            radius: 50

            Column {
                id: mainColumn
                anchors.centerIn: parent
                width: parent.width * 0.9
                spacing: 20

                Row {
                    width: parent.width
                    spacing: Math.round(archlinux.height / 70)
                    Text {
                        id: lblName
                        width: parent.width * 0.20; height: archlinux.height / 4
                        color: "white"
                        text: textConstants.userName
                        verticalAlignment: Text.AlignVCenter
                        font.bold: true
                        font.pixelSize: 18
                        font.family: "HackNerdFont"
                        
                    }

                    TextBox {
                        id: name
                        width: parent.width * 0.8; height: archlinux.height / 4
                        text: userModel.lastUser
                        font.pixelSize: 16
                        radius: 50
                        font.family: "HackNerdFont"

                        KeyNavigation.backtab: rebootButton; KeyNavigation.tab: password

                        Keys.onPressed: {
                            if (event.key === Qt.Key_Return || event.key === Qt.Key_Enter) {
                                sddm.login(name.text, password.text, session.index)
                                event.accepted = true
                            }
                        }
                    }
                }

                Row {
                    width: parent.width
                    spacing : Math.round(archlinux.height / 70)
                    Text {
                        id: lblPassword
                        width: parent.width * 0.2; height: archlinux.height / 4
                        color: "white"
                        text: textConstants.password
                        verticalAlignment: Text.AlignVCenter
                        font.bold: true
                        font.pixelSize: 18
                        font.family: "HackNerdFont"
                    }

                    PasswordBox {
                        id: password
                        width: parent.width * 0.8; height: archlinux.height / 4
                        font.pixelSize: 16
                        radius: 50
                        tooltipBG: "lightgrey"
                        focus: true
                        Timer {
                            interval: 200
                            running: true
                            onTriggered: password.forceActiveFocus()
                        }

                        KeyNavigation.backtab: name; KeyNavigation.tab: session

                        Keys.onPressed: {
                            if (event.key === Qt.Key_Return || event.key === Qt.Key_Enter) {
                                sddm.login(name.text, password.text, session.index)
                                event.accepted = true
                            }
                        }
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
        color: "black"
        border.color: "#1793d1"
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

            KeyNavigation.backtab: password; KeyNavigation.tab: layoutBox
        }
    }
    
    // Buttons
    Rectangle {
        x: 1670
        y: 975
        width: 200
        height: 75
        color: "black"
        border.color: "#1793d1"
        border.width: 3
        radius: 50


        Button {
            id: shutdownButton
            
            width: 40
            height: 40
            text: ""
            color: "black"
            anchors.centerIn: parent
            anchors.horizontalCenterOffset: 40

            Image {
                source: "shutdown.png"
                fillMode: Image.PreserveAspectFit
                anchors.fill: parent
            }

            onClicked: sddm.powerOff()

            KeyNavigation.backtab: loginButton; KeyNavigation.tab: rebootButton
        }

        Button {
            id: rebootButton
            text: ""
            width: 40
            height: 40
            color: "black"
            anchors.centerIn: parent
            anchors.horizontalCenterOffset: -40

            Image {
                source: "reboot.png"
                fillMode: Image.PreserveAspectFit
                anchors.fill: parent
            }

            onClicked: sddm.reboot()

            KeyNavigation.backtab: shutdownButton; KeyNavigation.tab: name
        }
    }



    Component.onCompleted: {
        if (name.text == "")
            name.focus = true
        else
            password.focus = true
    }
}
