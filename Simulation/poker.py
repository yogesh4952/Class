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
        digits = str(num).replace('.', '')[:5]
        counts[tuple(sorted(digits))] += 1
    
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
    conclusion = f"P-value ({p_val:.4f}) > α ({alpha}) → Random" if result == "Accepted" else f"P-value ({p_val:.4f}) < α ({alpha}) → Not Random"
    
    out.delete(1.0, tk.END)
    out.insert(tk.END, f"Chi-square: {chi2_stat:.4f}\nP-value: {p_val:.4f}\nResult: {result}\n\n{conclusion}")

# GUI
root = tk.Tk()
root.title("Poker Test")
root.geometry("400x500")

f = tk.Frame(root)
f.pack(pady=10)

tk.Label(f, text="Name").grid(row=0, column=0); tk.Entry(f).grid(row=0, column=1)
tk.Label(f, text="Roll").grid(row=1, column=0); tk.Entry(f).grid(row=1, column=1)
tk.Label(f, text="Subject").grid(row=2, column=0); tk.Entry(f).grid(row=2, column=1)

tk.Button(f, text="Select File", command=choose).grid(row=3, column=0, columnspan=2, pady=5)
file_label = tk.Label(f, text="No file", fg="blue")
file_label.grid(row=4, column=0, columnspan=2)

tk.Label(f, text="Quantity").grid(row=5, column=0); entry_qty = tk.Entry(f); entry_qty.grid(row=5, column=1)
tk.Label(f, text="Alpha").grid(row=6, column=0); entry_alpha = tk.Entry(f); entry_alpha.grid(row=6, column=1)

tk.Button(f, text="Run Test", command=run).grid(row=7, column=0, columnspan=2, pady=10)

out = tk.Text(f, height=10, width=45)
out.grid(row=8, column=0, columnspan=2)

root.mainloop()