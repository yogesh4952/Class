import tkinter as tk
from tkinter import messagebox, filedialog
import numpy as np
from scipy.stats import chi2

# Default file (empty initially)
DEFAULT_FILE = ""

# ------------------ Logic ------------------ #
def load_random_numbers(filename, quantity):
    numbers = []
    try:
        with open(filename, 'r') as file:
            while len(numbers) < quantity:
                line = file.readline().strip()
                if line:
                    try:
                        numbers.append(float(line))
                    except:
                        pass
                if not line:
                    break
    except:
        messagebox.showerror("Error", "File not found!")
    return numbers

def gap_test(numbers, alpha, low, high):
    gaps = []
    gap = 0
    in_range = False

    for number in numbers:
        if low <= number <= high:
            if in_range:
                gaps.append(gap)
                gap = 0
            in_range = True
        else:
            if in_range:
                gap += 1

    k = len(gaps)
    mean_gap = np.mean(gaps) if k > 0 else 0
    chi_square_stat = (k - mean_gap) ** 2 / mean_gap if mean_gap != 0 else 0
    p_value = 1 - chi2.cdf(chi_square_stat, df=k-1) if k > 1 else 0

    result = "Accepted" if p_value > alpha else "Rejected"
    return result, k, mean_gap, chi_square_stat, p_value

# ------------------ File Picker ------------------ #
def choose_file():
    global DEFAULT_FILE
    file = filedialog.askopenfilename(title="Select Random Number File")
    if file:
        DEFAULT_FILE = file
        file_label.config(text=f"File: {file.split('/')[-1]}")

# ------------------ Run ------------------ #
def run_test():
    if DEFAULT_FILE == "":
        messagebox.showerror("Error", "Please select a file first!")
        return

    # Hidden fields
    name = entry_name.get()
    roll = entry_roll.get()
    subject = entry_subject.get()

    try:
        quantity = int(entry_quantity.get())
        low = float(entry_low.get())
        high = float(entry_high.get())
        alpha = float(entry_alpha.get())
    except:
        messagebox.showerror("Error", "Invalid input!")
        return

    numbers = load_random_numbers(DEFAULT_FILE, quantity)

    if len(numbers) < quantity:
        messagebox.showwarning("Warning", "Not enough data!")
        return

    result, k, mean_gap, chi_square_stat, p_value = gap_test(numbers, alpha, low, high)

    # Conclusion
    if result == "Accepted":
        conclusion = (
            "The p-value is greater than alpha, so the null hypothesis is accepted. "
            "Hence, the given random numbers are sufficiently random."
        )
    else:
        conclusion = (
            "The p-value is less than alpha, so the null hypothesis is rejected. "
            "Hence, the given random numbers are not random."
        )

    output_text.delete("1.0", tk.END)
    output_text.insert(tk.END,
        f"Number of Gaps: {k}\n"
        f"Mean Gap: {mean_gap}\n"
        f"Chi-square Statistic: {chi_square_stat}\n"
        f"P-value: {p_value}\n"
        f"Result: {result}\n\n"
        f"Conclusion:\n{conclusion}"
    )

# ------------------ GUI ------------------ #
root = tk.Tk()
root.title("Gap Test GUI")
root.geometry("450x600")

frame = tk.Frame(root)
frame.place(relx=0.5, rely=0.5, anchor="center")

# Name, Roll, Subject
tk.Label(frame, text="Name").grid(row=0, column=0, pady=5)
entry_name = tk.Entry(frame, justify="center")
entry_name.grid(row=0, column=1, pady=5)

tk.Label(frame, text="Roll").grid(row=1, column=0, pady=5)
entry_roll = tk.Entry(frame, justify="center")
entry_roll.grid(row=1, column=1, pady=5)

tk.Label(frame, text="Subject").grid(row=2, column=0, pady=5)
entry_subject = tk.Entry(frame, justify="center")
entry_subject.grid(row=2, column=1, pady=5)

# File Picker
tk.Button(frame, text="Select File", command=choose_file).grid(row=3, column=0, columnspan=2, pady=10)
file_label = tk.Label(frame, text="No file selected", fg="blue")
file_label.grid(row=4, column=0, columnspan=2)

# Inputs
tk.Label(frame, text="Quantity").grid(row=5, column=0, pady=5)
entry_quantity = tk.Entry(frame, justify="center")
entry_quantity.grid(row=5, column=1, pady=5)

tk.Label(frame, text="Lower Bound").grid(row=6, column=0, pady=5)
entry_low = tk.Entry(frame, justify="center")
entry_low.grid(row=6, column=1, pady=5)

tk.Label(frame, text="Upper Bound").grid(row=7, column=0, pady=5)
entry_high = tk.Entry(frame, justify="center")
entry_high.grid(row=7, column=1, pady=5)

tk.Label(frame, text="Alpha").grid(row=8, column=0, pady=5)
entry_alpha = tk.Entry(frame, justify="center")
entry_alpha.grid(row=8, column=1, pady=5)

# Button
tk.Button(frame, text="Run Test", command=run_test).grid(row=9, column=0, columnspan=2, pady=10)

# Output
output_text = tk.Text(frame, height=12, width=50)
output_text.grid(row=10, column=0, columnspan=2, pady=10)

root.mainloop()