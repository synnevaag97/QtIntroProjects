import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
            id: container
            anchors.fill: parent
            onStateChanged:console.log("state -> "+state)

        Rectangle {
            id: rect1;
            color: "blue";
            width: 100;
            height: 100;
            Text{anchors.centerIn: parent; text: "Rect1"}
        }
        Rectangle {
            id: rect2;
            anchors.left: rect1.right; anchors.leftMargin: 5;
            color: "red";
            width: 100;
            height: 100;
            Text{anchors.centerIn: parent; text: "Rect2"}
        }
        Rectangle {
            id: rect3;
            anchors.left: rect1.right; anchors.top: rect1.bottom;
            color: "green";
            width: 100;
            height: 100;
            Text{anchors.centerIn: parent; text: "Rect3"}
        }

        MouseArea { id: mouseArea;
                    anchors.fill: parent;
                    onClicked: parent.state = (parent.state === "reanchored" ? "" : "reanchored")
        }
        states: State {
                name: "reanchored"
                AnchorChanges {
                    target: rect2 // The item to change anchors on.
                    anchors.left: undefined  //remove the left anchor
                    anchors.top: rect3.bottom
                }
            }

        transitions:
            Transition {
                AnchorAnimation {}  //animates any AnchorChanges in the corresponding state change
            }

    }
}
