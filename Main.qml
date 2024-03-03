import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import CustomComponent 1.0

Window {
    width: 320
    height: 470
    visible: true
    minimumHeight: 470
    minimumWidth: 320
    title: qsTr("Calculator")
    color: "#202020"
    Rectangle {
        id: rect
        border.width: 5
        anchors.left: parent.left
        anchors.right: parent.right
        height: 50
        Text {
            CalcSystem {
                id: sys
                display: "0"
            }
            anchors.rightMargin: 10
            anchors.topMargin: 10
            font.pixelSize: 30
            anchors.right: parent.right
            id: field
            text: sys.display
            maximumLineCount: 19
        }
    }

    GridLayout {
        anchors.top: rect.bottom
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right

        columns: 4
        CalculatorButton {
            text: "%"
        }

        CalculatorButton {
            text: "CE"
        }
        CalculatorButton {
            text: "C"
        }
        CalculatorButton {
            text: "Back"
        }
        CalculatorButton {
            text: "1/x"
        }
        CalculatorButton {
            text: "X^2"
        }
        CalculatorButton {
            text: "root"
        }
        CalculatorButton {
            text: "/"
        }
        CalculatorButton {
            text: "7"
        }
        CalculatorButton {
            text: "8"
        }
        CalculatorButton {
            text: "9"
        }
        CalculatorButton {
            text: "*"
        }
        CalculatorButton {
            text: "4"
        }
        CalculatorButton {
            text: "5"
        }
        CalculatorButton {
            text: "6"
        }
        CalculatorButton {
            text: "-"
        }
        CalculatorButton {
            text: "1"
        }
        CalculatorButton {
            text: "2"
        }
        CalculatorButton {
            text: "3"
        }
        CalculatorButton {
            text: "+"
        }
        CalculatorButton {
            text: "+/-"
        }
        CalculatorButton {
            text: "0"
        }
        CalculatorButton {
            text: "."
        }
        CalculatorButton {
            text: "="
        }
    }

}
