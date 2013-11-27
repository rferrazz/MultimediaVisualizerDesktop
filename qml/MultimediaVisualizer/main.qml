// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick.Window 2.1
import QtQuick 2.1
import ImageReciver 1.0

Window{
    id: mainWindow

    title: "Multimedia Visualizer"
    visible: true

    minimumWidth: 800
    minimumHeight: 600

    width: 800
    height: 600

    function switchFullScreen(){
        if(visibility !== Qt.WindowFullScreen){
            visibility = Qt.WindowFullScreen
        }else{
            visibility = Qt.WindowMaximized
        }
    }

    Rectangle {
        color: "black"
        anchors.fill: parent
        focus: true
        property bool reciving: false

        ImageReciver{
            anchors.fill: parent
            onStartReciving: {
                reciving = true
            }
            onImageReady: {
                reciving = false
            }
        }
        Rectangle{
            id: blackRect
            color: "black"
            anchors.fill: parent
            opacity: 0
        }
        MouseArea{
            id: mouse
            anchors.fill: parent
            onDoubleClicked: {
                mainWindow.switchFullScreen();
            }
        }

        Keys.onPressed: {
            if(event.key == Qt.Key_F11){
                mainWindow.switchFullScreen();
            }
        }

        states: [
            State {
                name: "recivingState"
                when: reciving
                PropertyChanges {
                    target: blackRect
                    opacity: 1
                }
            }
        ]
        transitions: [
            Transition {
                from: ""
                to: "recivingState"
                reversible: true
                NumberAnimation { target: blackRect; property: "opacity"; duration: 500 }
            }
        ]
    }
}
