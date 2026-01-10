import sys 
from PyQt5.QtWidgets import (
    QApplication, QWidget, QLabel, QPushButton,
    QVBoxLayout, QHBoxLayout, QComboBox, QMessageBox
)
from PyQt5.QtGui import QPainter, QPen
from PyQt5.QtCore import Qt

def AND(a, b): return a & b
def OR(a, b): return a | b
def XOR(a, b): return a ^ b

class GateCanvas(QWidget):
    def paintEvent(self, event):
        painter = QPainter(self)
        pen = QPen(Qt.black, 2)
        painter.setPen(pen)

        # AND gate symbol
        painter.drawLine(20, 30, 60, 30)
        painter.drawLine(20, 60, 60, 60)
        painter.drawArc(40, 20, 40, 50, -90 * 16, 180 * 16)
        painter.drawLine(80, 45, 110, 45)

class LogicApp(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Logic Gates Simulator (PyQt)")
        self.setGeometry(100, 100, 500, 400)

        self.a = 0
        self.b = 0

        self.gate = QComboBox()
        self.gate.addItems(["AND", "OR", "XOR", "Half Adder"])

        self.result = QLabel("Output: 0")
        self.result.setAlignment(Qt.AlignCenter)

        btnA = QPushButton("Toggle A")
        btnB = QPushButton("Toggle B")
        btnCalc = QPushButton("Calculate")
        btnQuiz = QPushButton("Quiz Mode")

        btnA.clicked.connect(self.toggleA)
        btnB.clicked.connect(self.toggleB)
        btnCalc.clicked.connect(self.calculate)
        btnQuiz.clicked.connect(self.quiz)

        layout = QVBoxLayout()
        layout.addWidget(self.gate)
        layout.addWidget(btnA)
        layout.addWidget(btnB)
        layout.addWidget(btnCalc)
        layout.addWidget(self.result)
        layout.addWidget(btnQuiz)

        self.canvas = GateCanvas()
        layout.addWidget(self.canvas)

        self.setLayout(layout)

    def toggleA(self):
        self.a ^= 1

    def toggleB(self):
        self.b ^= 1

    def calculate(self):
        g = self.gate.currentText()
        if g == "AND":
            r = AND(self.a, self.b)
            self.result.setText(f"Output: {r}")
        elif g == "OR":
            r = OR(self.a, self.b)
            self.result.setText(f"Output: {r}")
        elif g == "XOR":
            r = XOR(self.a, self.b)
            self.result.setText(f"Output: {r}")
        elif g == "Half Adder":
            s = XOR(self.a, self.b)
            c = AND(self.a, self.b)
            self.result.setText(f"Sum: {s}, Carry: {c}")

    def quiz(self):
        q = QMessageBox.question(
            self, "Quiz",
            "What is the output of AND gate when A=1, B=1?",
            QMessageBox.Yes | QMessageBox.No
        )
        if q == QMessageBox.Yes:
            QMessageBox.information(self, "Correct", "Correct Answer!")
        else:
            QMessageBox.warning(self, "Wrong", "Correct answer is 1")

app = QApplication(sys.argv)
window = LogicApp()
window.show()
sys.exit(app.exec_())