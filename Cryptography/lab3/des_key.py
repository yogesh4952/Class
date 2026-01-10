def apply_permutation(data,permutation_table):
    return ''.join(data[i - 1] for i in permutation_table)

def left_shift(data, amount):
    return data[amount:] + data[:amount]

Permutated_Choice_1 = [
    57,49,41,33,25,17,9,
    1,58,50,42,34,26,18,
    10,2,59,51,43,35,27,
    19,11,3,60,52,44,36,
    63,55,47,39,31,23,15,
    7,62,54,46,38,30,22,
    14,6,61,53,45,37,29,
    21,13,5,28,20,12,4
]


Permutated_Choice_2 = [
    14,17,11,24,1,5,
    3,28,15,6,21,10,
    23,19,12,4,26,8,
    16,7,27,20,13,2,
    41,52,31,37,47,55,
    30,40,51,45,33,48,
    44,49,39,56,34,53,
    46,42,50,36,29,32
]

shifts_for_each_rounds = [
    1, 1, 2, 2,
    2, 2, 2, 2,
    1, 2, 2, 2,
    2, 2, 2, 1
]



def generate_subkeys(key):
    key_binary = format(int(key, 16), '064b' )
    key_permuted = apply_permutation(key_binary, Permutated_Choice_1)
    
    c = [key_permuted[i] for i in range(28)]
    d = [key_permuted[i] for i in range(28, 56)]
    
    subkeys = []
    for i in range(16):
        shift_amount = shifts_for_each_rounds[i]
        c = left_shift(c, shift_amount)
        d = left_shift(d, shift_amount)
        subkey_halves = c + d
        subkey = apply_permutation(subkey_halves, Permutated_Choice_2)
        subkeys.append(subkey)
    return subkeys


if __name__ == "__main__":
    des_key = "1234567890abcdef"
    subkeys = generate_subkeys(des_key)
    
    for i, subkey in enumerate(subkeys):
        print(f"Subkey {i + 1}: {subkey}")