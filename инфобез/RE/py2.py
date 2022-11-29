def func(a: int, b: int) -> str:
    if a < 0 or b < 0:
        raise ValueError("the value of both inputs must be positive")

    a_binary = str(bin(a))[2:]
    b_binary = str(bin(b))[2:]

    max_len = max(len(a_binary), len(b_binary))

    return "0b" + "".join(
        str(int(char_a != char_b))
        for char_a, char_b in zip(a_binary.zfill(max_len), b_binary.zfill(max_len))
    )


if __name__ == "__main__":
    a, b = map(int, input("Enter two numbers: ").split())

    print(func(a, b))
