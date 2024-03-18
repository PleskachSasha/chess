import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    id: window
    width: 1000
    height: 1000
    minimumHeight: 500
    minimumWidth: 500
    visible: true

    Rectangle {
        id: board
        color: "#A52A2A"
        width: parent.width
        height: parent.height

        function createCell(row, column) {
            return Rectangle {
                width: board.width / 10
                height: board.height / 10
                color: (row + column) % 2 ? "#8B4513" : "#654321"
                Text {
                    anchors.centerIn: parent
                    font.pixelSize: 32
                    text: row > 0 && row < 9 && column > 0 && column < 9 ? String.fromCharCode(64 + column) + (9 - row) : ""
                }
            }
        }

        Row {
            x: 0; y: 0
            Repeater {
                model: 10
                Item {
                    width: board.width / 10
                    height: board.height / 10
                    Column {
                        spacing: 0
                        Repeater {
                            model: 10
                            Item {
                                width: board.width / 10
                                height: board.height / 10
                                createCell(index, modelData)
                            }
                        }
                    }
                }
            }
        }
    }
}
