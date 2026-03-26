import numpy as np
from scipy.special import erfinv
from tabulate import tabulate

def load_random_numbers(filename, quantity):
    numbers = []
    try:
        with open(filename, 'r') as file:
            for line in file:
                if len(numbers) >= quantity:
                    break
                clean_line = line.strip()
                if not clean_line:
                    continue
                try:
                    numbers.append(float(clean_line))
                except ValueError:
                    print(f"Skipping invalid line: {clean_line}")
    except FileNotFoundError:
        print(f"Error: File '{filename}' not found.")
        return []
        
    if len(numbers) < quantity:
        print(f"Warning: only {len(numbers)} numbers were read from the file.")
    return numbers

def autocorrelation_test(numbers, lag, alpha):
    n = len(numbers)
    # Using the standard autocorrelation coefficient formula
    numbers = np.array(numbers)
    mean = np.mean(numbers)
    
    # Calculate rho (Autocorrelation)
    numerator = sum((numbers[i] - mean) * (numbers[i + lag] - mean) for i in range(n - lag))
    denominator = sum((numbers[i] - mean) ** 2 for i in range(n))
    rho = numerator / denominator
    
    # Standard Z-score calculation
    # For large N, Rho is approximately normal with variance 1/N
    z_stat = rho * np.sqrt(n)
    
    # Critical Value for two-tailed test
    # Z_alpha/2 logic
    z_critical = np.sqrt(2) * erfinv(1 - alpha)
    
    # Logic: If Z-stat > Critical Value, there IS significant correlation (Reject Randomness)
    status = "Rejected (Not Random)" if abs(z_stat) > z_critical else "Accepted (Random)"
    
    return status, rho, z_stat, z_critical

if __name__ == "__main__":
    file_path = input("Enter the filename: ")
    try:
        qty = int(input("How many numbers to read? "))
        k_lag = int(input("Enter the lag (k): "))
        sig_level = float(input("Enter significance level (e.g., 0.05): "))
        
        data = load_random_numbers(file_path, qty)
        
        if len(data) >= k_lag + 1:
            res, r, z0, z_crit = autocorrelation_test(data, k_lag, sig_level)
            
            table_data = [
                ["Metric", "Value"],
                ["Mean", np.mean(data)],
                ["Autocorrelation (Rho)", f"{r:.4f}"],
                ["Z-Statistic", f"{z0:.4f}"],
                ["Critical Z", f"{z_crit:.4f}"],
                ["Test Result", res]
            ]
            print("\n" + tabulate(table_data, headers="firstrow", tablefmt="grid"))
        else:
            print("Insufficient data for the chosen lag.")
    except ValueError:
        print("Invalid input. Please enter numerical values for quantity, lag, and alpha.")