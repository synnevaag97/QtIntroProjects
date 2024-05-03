import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Traffic Light")

    Rectangle {
        id: lights
        x: 50; y: 50
        width: 150; height: 250
        color: "darkGray"

            Rectangle {
                id: light1
                x:  25; y: 15
                width: 100; height: width
                radius: width / 2
                color: "black"
            }

            Rectangle {
                id: light2
                x: 25; y: 135
                width: 100; height: width
                radius: width/2
                color: "black"
            }


        states: [
                State {
                    name: "stop"
                    PropertyChanges { target: light1; color: "red"}
                    PropertyChanges { target: light2; color: "black"}
                },
                State {
                    name: "go"
                    PropertyChanges { target: light1; color: "black"}
                    PropertyChanges { target: light2; color: "green" }
                }
            ]

        MouseArea {
            anchors.fill: lights
            onClicked: lights.state = (lights.state === "stop" ? "go" : "stop")
        }

        transitions: [
            Transition {
                from: "stop"; to: "go"; reversible: true
                // from: "*"; to: "*"
                ColorAnimation { target: light1; properties: "color"; duration: 1000 }
                ColorAnimation { target: light2; properties: "color"; duration: 1000 }
            }
        ]
    }
}
