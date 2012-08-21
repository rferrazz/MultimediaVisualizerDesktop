// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import QmlSharing 1.0

Rectangle {
    width: 800
    height: 600
    color: "black"
    focus: true
    property bool reciving: false

    function switchFullScreen(){
        if(mainWindow.fullScreen){
            console.log("going normal:"+ mainWindow.fullScreen)
            mainWindow.showNormal();
        }else{
            console.log("going fullscreen");
            mainWindow.showFullScreen();
        }
    }

    ImageSharingClient{
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
            switchFullScreen();
        }
    }

    Keys.onPressed: {
        if(event.key == Qt.Key_F11){
            switchFullScreen();
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
