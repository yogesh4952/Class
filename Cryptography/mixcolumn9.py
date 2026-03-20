#implementation of mixed columns in AES

def gmul(a, b):
    p = 0
    for _ in range(8):
        if b & 1:
            p ^= a
        hi_bit_set = a & 0x80
        a = (a << 1) & 0xFF
        if hi_bit_set:
            a ^= 0x1B  # AES irreducible polynomial
        b >>= 1
    return p


# Mix one column (ENCRYPTION)
def mix_single_column(col):
    return [
        gmul(col[0], 2) ^ gmul(col[1], 3) ^ col[2] ^ col[3],
        col[0] ^ gmul(col[1], 2) ^ gmul(col[2], 3) ^ col[3],
        col[0] ^ col[1] ^ gmul(col[2], 2) ^ gmul(col[3], 3),
        gmul(col[0], 3) ^ col[1] ^ col[2] ^ gmul(col[3], 2)
    ]


# MixColumns for entire 4x4 state
def mix_columns(state):
    for c in range(4):
        column = [state[r][c] for r in range(4)]
        mixed = mix_single_column(column)
        for r in range(4):
            state[r][c] = mixed[r]
    return state


# Inverse Mix one column (DECRYPTION)
def inv_mix_single_column(col):
    return [
        gmul(col[0], 14) ^ gmul(col[1], 11) ^ gmul(col[2], 13) ^ gmul(col[3], 9),
        gmul(col[0], 9)  ^ gmul(col[1], 14) ^ gmul(col[2], 11) ^ gmul(col[3], 13),
        gmul(col[0], 13) ^ gmul(col[1], 9)  ^ gmul(col[2], 14) ^ gmul(col[3], 11),
        gmul(col[0], 11) ^ gmul(col[1], 13) ^ gmul(col[2], 9)  ^ gmul(col[3], 14)
    ]


# Inverse MixColumns for entire state
def inv_mix_columns(state):
    for c in range(4):
        column = [state[r][c] for r in range(4)]
        mixed = inv_mix_single_column(column)
        for r in range(4):
            state[r][c] = mixed[r]
    return state


# =========================================
# Example Test
# =========================================

def print_state(state, title):
    print(title)
    for row in state:
        print(["%02x" % x for x in row])
    print()


if __name__ == "__main__":
    # Example AES state matrix
    state = [
        [0xdb, 0x13, 0x53, 0x45],
        [0xf2, 0x0a, 0x22, 0x5c],
        [0x01, 0x01, 0x01, 0x01],
        [0xc6, 0xc6, 0xc6, 0xc6]
    ]

    print_state(state, "Original State:")

    mix_columns(state)
    print_state(state, "After MixColumns:")

    inv_mix_columns(state)
    print_state(state, "After Inverse MixColumns (Recovered):")