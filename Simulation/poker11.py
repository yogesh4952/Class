import tkinter as tk
from tkinter import filedialog, messagebox
import itertools
from scipy.stats import chi2

DEFAULT_FILE = ""

def load_numbers(filename, qty):
    nums = []
    try:
        with open(filename) as f:
            while len(nums) < qty:
                line = f.readline().strip()
                if line:
                    try:
                        nums.append(float(line))
                    except:
                        pass
                if not line: break
    except:
        messagebox.showerror("Error", "File not found!")
    return nums

def poker_test(nums, alpha):
    n = len(nums)
    counts = {comb: 0 for comb in itertools.combinations_with_replacement('0123456789', 5)}
    
    for num in nums:
        digits = str(round(num, 6)).replace('0.', '').replace('.', '')
        digits = (digits + '00000')[:5]
        key = tuple(sorted(digits))
        if key in counts:
            counts[key] += 1
        else:
            counts[key] = 1
    
    exp = n / len(counts)
    chi2_stat = sum((c - exp)**2 / exp for c in counts.values())
    p_val = 1 - chi2.cdf(chi2_stat, len(counts)-1)
    return "Accepted" if p_val > alpha else "Rejected", chi2_stat, p_val

def choose():
    global DEFAULT_FILE
    f = filedialog.askopenfilename()
    if f:
        DEFAULT_FILE = f
        file_label.config(text=f"File: {f.split('/')[-1]}")

def run():
    if not DEFAULT_FILE:
        messagebox.showerror("Error", "Select file first!")
        return
    try:
        qty, alpha = int(entry_qty.get()), float(entry_alpha.get())
    except:
        messagebox.showerror("Error", "Invalid input!")
        return
    
    nums = load_numbers(DEFAULT_FILE, qty)
    if len(nums) < qty:
        messagebox.showwarning("Warning", "Not enough data!")
        return
    
    result, chi2_stat, p_val = poker_test(nums, alpha)
    conclusion = (
        f"P-value ({p_val:.4f}) > α ({alpha}) → Numbers are Random"
        if result == "Accepted"
        else f"P-value ({p_val:.4f}) < α ({alpha}) → Numbers are Not Random"
    )
    
    out.delete(1.0, tk.END)
    out.insert(tk.END,
        f"Chi-square Statistic : {chi2_stat:.4f}\n"
        f"P-value              : {p_val:.4f}\n"
        f"Result               : {result}\n\n"
        f"Conclusion:\n{conclusion}"
    )

# GUI
root = tk.Tk()
root.title("Poker Test")
root.geometry("400x520")

f = tk.Frame(root)
f.pack(pady=10)

tk.Label(f, text="Name").grid(row=0, column=0, pady=4)
entry_name = tk.Entry(f, justify="center")
entry_name.grid(row=0, column=1, pady=4)

tk.Label(f, text="Roll").grid(row=1, column=0, pady=4)
entry_roll = tk.Entry(f, justify="center")
entry_roll.grid(row=1, column=1, pady=4)

tk.Label(f, text="Subject").grid(row=2, column=0, pady=4)
entry_subject = tk.Entry(f, justify="center")
entry_subject.grid(row=2, column=1, pady=4)

tk.Button(f, text="Select File", command=choose).grid(row=3, column=0, columnspan=2, pady=8)
file_label = tk.Label(f, text="No file selected", fg="blue")
file_label.grid(row=4, column=0, columnspan=2)

tk.Label(f, text="Quantity").grid(row=5, column=0, pady=4)
entry_qty = tk.Entry(f, justify="center")
entry_qty.grid(row=5, column=1, pady=4)

tk.Label(f, text="Alpha").grid(row=6, column=0, pady=4)
entry_alpha = tk.Entry(f, justify="center")
entry_alpha.grid(row=6, column=1, pady=4)

tk.Button(f, text="Run Test", command=run).grid(row=7, column=0, columnspan=2, pady=10)

out = tk.Text(f, height=10, width=45)
out.grid(row=8, column=0, columnspan=2)

root.mainloop()