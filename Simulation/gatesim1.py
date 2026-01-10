#!/usr/bin/env python3
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
    output_label.config(bg="#2ecc71" if result else "#e74c3c") # Modern Green/Red
    draw_gate_schematic(gate, a, b, result)

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

def draw_gate_schematic(gate, a, b, res):
    canvas.delete("all")
    color_a = "#2ecc71" if a else "black"
    color_b = "#2ecc71" if b else "black"
    color_out = "#2ecc71" if res else "black"
    
    # Input Lines
    canvas.create_line(20, 40, 70, 40, fill=color_a, width=3) # Line A
    canvas.create_text(10, 40, text="A")
    
    if gate != "NOT":
        canvas.create_line(20, 80, 70, 80, fill=color_b, width=3) # Line B
        canvas.create_text(10, 80, text="B")

    # Draw Gate Shapes
    if gate == "AND" or gate == "NAND":
        canvas.create_rectangle(70, 30, 120, 90, width=2)
        canvas.create_arc(95, 30, 145, 90, start=-90, extent=180, width=2)
        if gate == "NAND":
            canvas.create_oval(145, 55, 155, 65, width=2)
            canvas.create_line(155, 60, 200, 60, fill=color_out, width=3)
        else:
            canvas.create_line(145, 60, 200, 60, fill=color_out, width=3)

    elif gate == "OR" or gate == "NOR":
        canvas.create_arc(40, 30, 80, 90, start=-90, extent=180, style='arc', width=2)
        canvas.create_arc(40, 30, 140, 90, start=-90, extent=180, style='arc', width=2)
        canvas.create_line(70, 30, 90, 30, width=2)
        canvas.create_line(70, 90, 90, 90, width=2)
        if gate == "NOR":
            canvas.create_oval(140, 55, 150, 65, width=2)
            canvas.create_line(150, 60, 200, 60, fill=color_out, width=3)
        else:
            canvas.create_line(140, 60, 200, 60, fill=color_out, width=3)

    elif gate == "NOT":
        canvas.create_polygon(70, 30, 70, 90, 130, 60, fill="", outline="black", width=2)
        canvas.create_oval(130, 55, 140, 65, width=2)
        canvas.create_line(140, 60, 200, 60, fill=color_out, width=3)
    
    elif gate == "XOR" or gate == "XNOR":
        canvas.create_arc(30, 30, 70, 90, start=-90, extent=180, style='arc', width=2)
        canvas.create_arc(40, 30, 80, 90, start=-90, extent=180, style='arc', width=2)
        canvas.create_arc(40, 30, 140, 90, start=-90, extent=180, style='arc', width=2)
        if gate == "XNOR":
            canvas.create_oval(140, 55, 150, 65, width=2)
            canvas.create_line(150, 60, 200, 60, fill=color_out, width=3)
        else:
            canvas.create_line(140, 60, 200, 60, fill=color_out, width=3)

    canvas.create_text(220, 60, text="OUT")

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
root.geometry("750x800")

# Info Label
info_label = tk.Label(root, text="Name: Yogesh Shah\nRoll No: 22\nSubject: Simulation and Modeling", 
                      font=("Arial", 10, "bold"), justify='right', padx=10)
info_label.place(relx=1.0, rely=0.0, anchor='ne', y=10)

# Main Container
main_frame = tk.Frame(root)
main_frame.pack(fill="both", expand=True, padx=10, pady=(70, 10))

# Inputs
input_frame = tk.LabelFrame(main_frame, text="Step 1: Set Inputs", padx=10, pady=10)
input_frame.pack(fill="x", pady=5)

A, B = tk.IntVar(value=0), tk.IntVar(value=0)
tk.Button(input_frame, text="Toggle A", command=lambda: toggle(A)).grid(row=0, column=0)
tk.Label(input_frame, textvariable=A, font=("Arial",12, "bold")).grid(row=0, column=1, padx=20)
tk.Button(input_frame, text="Toggle B", command=lambda: toggle(B)).grid(row=0, column=2)
tk.Label(input_frame, textvariable=B, font=("Arial",12, "bold")).grid(row=0, column=3, padx=20)

# Gate Selection
gate_frame = tk.LabelFrame(main_frame, text="Step 2: Select Gate", padx=10, pady=10)
gate_frame.pack(fill="x", pady=5)

gate_var = tk.StringVar(value="AND")
gate_menu = ttk.Combobox(gate_frame, textvariable=gate_var, state="readonly", 
                         values=["AND","OR","NOT","NAND","NOR","XOR","XNOR"])
gate_menu.pack(side="left", padx=10)
description = tk.StringVar()
tk.Label(gate_frame, textvariable=description, font=("Arial",9, "italic")).pack(side="left")
gate_menu.bind("<<ComboboxSelected>>", gate_info)

# Visualization and Output
viz_frame = tk.LabelFrame(main_frame, text="Simulation Visualizer", padx=10, pady=10)
viz_frame.pack(fill="x", pady=5)

canvas = tk.Canvas(viz_frame, width=250, height=120, bg="white", highlightthickness=1)
canvas.pack(side="left", padx=20)

output_var = tk.IntVar()
output_label = tk.Label(viz_frame, textvariable=output_var, font=("Arial",40), width=4, bg="red", fg="white")
output_label.pack(side="right", padx=20)

# Truth Table
table_frame = tk.LabelFrame(main_frame, text="Truth Table Reference")
table_frame.pack(fill="both", expand=True, pady=5)

table = ttk.Treeview(table_frame, columns=("A","B","Output"), show="headings", height=5)
for col in ("A","B","Output"):
    table.heading(col, text=col)
    table.column(col, anchor="center")
table.pack(fill="both", expand=True)

gate_info()
root.mainloop()