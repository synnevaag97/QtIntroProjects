import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        id: button
        width: 100; height: 100
        color: "black"

        MouseArea {
            anchors.fill: parent
            /*
            // Need to enable hoverEnable to get mouse position also when we are not clicking the mouse.
            // Making use able to use onEntered and onExited.
            hoverEnabled: true
            onEntered: console.log("mouse entered the area")
            onExited: console.log("mouse left the area")
            */

            //onClicked: console.log("area clicked")
            //onDoubleClicked: console.log("area double clicked")
            //onPressed: console.log("Mouse pressing.")
            onPressAndHold: console.log("Mouse pressing.")
            onReleased: console.log("Mouse relased.")
        }
    }
}

/*
Mouse events signals that can have callback functions.
    canceled
    clicked
    doubleClicked
    entered
    exited
    positionChanged
    pressAndHold
    pressed
    released


*/
