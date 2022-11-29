def func(a: int) -> int:
    if a < 0:
        raise ValueError("Input value must be a positive integer")
    elif isinstance(a, float):
        raise TypeError("Input value must be a 'int' type")
    return bin(a).count("1")


if __name__ == "__main__":
    a = int(input("Enter number: "))

    print(func(a))
