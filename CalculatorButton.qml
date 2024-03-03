import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts

Button {
    Layout.fillWidth: true
    Layout.fillHeight: true
    Layout.preferredWidth: 100
    Layout.preferredHeight: 50
    background: Rectangle {
        color: "#323232"
        radius: 5
    }
    contentItem: Text {
        text: parent.text
        font.pixelSize: 17
        color: "#F2F2F2"
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
    }
    onClicked: {
        sys.slotButtonClicked(this.text)
    }
}
