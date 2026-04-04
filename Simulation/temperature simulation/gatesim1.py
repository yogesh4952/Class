import tkinter as tk
from tkinter import ttk

# ---------------- Logic Functions ----------------
def logic_result(a, b, gate):
    if gate == "AND": return a & b
    if gate == "OR": return a | b
    if gate == "NOT": return ~a & 1
    if gate == "NAND": return ~(a & b) & 1
    if gate == "NOR": return ~(a | b) & 1
    if gate == "XOR": return a ^ b
    if gate == "XNOR": return ~(a ^ b) & 1

# ---------------- GUI Functions ----------------
def toggle(var):
    var.set(1 if var.get() == 0 else 0)
    calculate()

def calculate():
    a = A.get()
    b = B.get()
    gate = gate_var.get()

    if gate == "NOT":
        result = logic_result(a, 0, gate)
    else:
        result = logic_result(a, b, gate)

    output_var.set(result)
    output_label.config(bg="green" if result else "red")

def generate_truth_table():
    table.delete(*table.get_children())
    gate = gate_var.get()

    combos = [(0,0),(0,1),(1,0),(1,1)]
    for a, b in combos:
        if gate == "NOT":
            r = logic_result(a, 0, gate)
            table.insert("", "end", values=(a, "-", r))
        else:
            r = logic_result(a, b, gate)
            table.insert("", "end", values=(a, b, r))

def gate_info(event=None):
    info = {
        "AND": "Output is 1 only if both inputs are 1",
        "OR": "Output is 1 if any input is 1",
        "NOT": "Output is inverse of input A",
        "NAND": "Inverse of AND gate",
        "NOR": "Inverse of OR gate",
        "XOR": "Output is 1 if inputs are different",
        "XNOR": "Output is 1 if inputs are same"
    }
    description.set(info.get(gate_var.get(), ""))
    generate_truth_table()
    calculate()

# ---------------- GUI Layout ----------------
root = tk.Tk()
root.title("Logic Gates Simulator")
root.geometry("700x500")

# Top Header
top_frame = tk.Frame(root)
top_frame.pack(fill="x", padx=10, pady=5)

name_label = tk.Label(
    top_frame,
    text="Yogesh Shah | CSIT 5th | Roll No: 22",
    font=("Arial", 10, "bold")
)
name_label.pack(side="right")

# Input Frame
frame = tk.LabelFrame(root, text="Inputs", padx=10, pady=10)
frame.pack(fill="x", padx=10, pady=5)

A = tk.IntVar(value=0)
B = tk.IntVar(value=0)

tk.Button(frame, text="Toggle A", width=10, command=lambda: toggle(A)).grid(row=0, column=0)
tk.Label(frame, textvariable=A, font=("Arial",14)).grid(row=0, column=1)

tk.Button(frame, text="Toggle B", width=10, command=lambda: toggle(B)).grid(row=0, column=2)
tk.Label(frame, textvariable=B, font=("Arial",14)).grid(row=0, column=3)

# Gate Selection
gate_frame = tk.LabelFrame(root, text="Logic Gate", padx=10, pady=10)
gate_frame.pack(fill="x", padx=10, pady=5)

gate_var = tk.StringVar(value="AND")
gate_menu = ttk.Combobox(
    gate_frame,
    textvariable=gate_var,
    values=["AND","OR","NOT","NAND","NOR","XOR","XNOR"]
)
gate_menu.pack()
gate_menu.bind("<<ComboboxSelected>>", gate_info)

# Output
output_frame = tk.LabelFrame(root, text="Output (LED)", padx=10, pady=10)
output_frame.pack(fill="x", padx=10, pady=5)

output_var = tk.IntVar()
output_label = tk.Label(
    output_frame,
    textvariable=output_var,
    font=("Arial",30),
    width=5,
    bg="red",
    fg="white"
)
output_label.pack()

# Description
desc_frame = tk.LabelFrame(root, text="Gate Description")
desc_frame.pack(fill="x", padx=10, pady=5)

description = tk.StringVar()
tk.Label(desc_frame, textvariable=description, font=("Arial",10)).pack()

# Truth Table
table_frame = tk.LabelFrame(root, text="Truth Table")
table_frame.pack(fill="both", expand=True, padx=10, pady=5)

table = ttk.Treeview(table_frame, columns=("A","B","Output"), show="headings")
table.heading("A", text="A")
table.heading("B", text="B")
table.heading("Output", text="Output")
table.pack(fill="both", expand=True)

gate_info()
root.mainloop()