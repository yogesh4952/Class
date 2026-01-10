import sys
from PyQt5.QtWidgets import (
    QApplication, QWidget, QLabel, QPushButton,
    QVBoxLayout, QHBoxLayout, QComboBox, QFrame, QGroupBox
)
from PyQt5.QtCore import Qt

# Logic Operation Helper
def logic_op(op, a, b):
    if op == "AND": return a & b
    elif op == "OR": return a | b
    elif op == "XOR": return a ^ b
    return 0

class FourGateCircuit(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("4-Gate Logic Chain Simulator")
        self.setGeometry(100, 100, 700, 700)
        
        # State variables for 5 manual inputs
        self.inputs = {'A': 0, 'B': 0, 'C': 0, 'D': 0, 'E': 0}
        self.init_ui()

    def init_ui(self):
        layout = QVBoxLayout()

        # --- SECTION 1: INITIAL TWO GATES (Parallel) ---
        initial_layout = QHBoxLayout()
        
        # Gate 1 Box
        self.g1_sel = self.create_gate_box(initial_layout, "GATE 1", ['A', 'B'])
        # Gate 2 Box
        self.g2_sel = self.create_gate_box(initial_layout, "GATE 2", ['C', 'D'])
        
        layout.addLayout(initial_layout)

        # --- SECTION 2: INTERMEDIATE GATE (Gate 3) ---
        g3_group = QGroupBox("GATE 3 (Combines Gate 1 & Gate 2)")
        g3_layout = QVBoxLayout()
        self.g3_sel = QComboBox()
        self.g3_sel.addItems(["AND", "OR", "XOR"])
        self.g3_sel.currentIndexChanged.connect(self.calculate)
        g3_layout.addWidget(self.g3_sel)
        g3_group.setLayout(g3_layout)
        layout.addWidget(g3_group)

        # --- SECTION 3: FINAL GATE (Gate 4) ---
        g4_group = QGroupBox("GATE 4 (Combines Gate 3 & Input E)")
        g4_layout = QVBoxLayout()
        self.g4_sel = QComboBox()
        self.g4_sel.addItems(["AND", "OR", "XOR"])
        self.g4_sel.currentIndexChanged.connect(self.calculate)
        g4_layout.addWidget(self.g4_sel)
        
        # Final manual input E
        self.btn_e = QPushButton("Input E: 0")
        self.btn_e.clicked.connect(lambda: self.toggle('E', self.btn_e))
        g4_layout.addWidget(self.btn_e)
        
        g4_group.setLayout(g4_layout)
        layout.addWidget(g4_group)

        # --- SECTION 4: DISPLAY RESULTS ---
        self.res_label = QLabel("FINAL OUTPUT: 0")
        self.res_label.setAlignment(Qt.AlignCenter)
        self.res_label.setStyleSheet("font-size: 28px; font-weight: bold; padding: 20px; background-color: #eee; border-radius: 10px;")
        layout.addWidget(self.res_label)

        self.setLayout(layout)
        self.calculate()

    def create_gate_box(self, parent_layout, title, input_names):
        group = QGroupBox(title)
        vbox = QVBoxLayout()
        
        sel = QComboBox()
        sel.addItems(["AND", "OR", "XOR"])
        sel.currentIndexChanged.connect(self.calculate)
        vbox.addWidget(sel)

        for name in input_names:
            btn = QPushButton(f"Input {name}: 0")
            btn.clicked.connect(lambda checked, n=name, b=btn: self.toggle(n, b))
            vbox.addWidget(btn)
            
        group.setLayout(vbox)
        parent_layout.addWidget(group)
        return sel

    def toggle(self, key, btn):
        self.inputs[key] ^= 1
        btn.setText(f"Input {key}: {self.inputs[key]}")
        self.calculate()

    def calculate(self):
        # 1. Calculate Gate 1 & 2
        out1 = logic_op(self.g1_sel.currentText(), self.inputs['A'], self.inputs['B'])
        out2 = logic_op(self.g2_sel.currentText(), self.inputs['C'], self.inputs['D'])
        
        # 2. Calculate Gate 3 (Connects Gate 1 and 2)
        out3 = logic_op(self.g3_sel.currentText(), out1, out2)
        
        # 3. Calculate Gate 4 (Connects Gate 3 and Input E)
        final_out = logic_op(self.g4_sel.currentText(), out3, self.inputs['E'])
        
        # Update Display
        self.res_label.setText(f"FINAL OUTPUT: {final_out}")
        color = "#2ecc71" if final_out == 1 else "#e74c3c"
        self.res_label.setStyleSheet(f"font-size: 28px; font-weight: bold; padding: 20px; color: white; background-color: {color}; border-radius: 10px;")

if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = FourGateCircuit()
    window.show()
    sys.exit(app.exec_())