def func(number: int) -> bool:
    if number < 0:
        raise ValueError("number must not be negative")
    return number & (number - 1) == 0


if __name__ == "__main__":
    a = int(input("Enter number: "))

    print(func(a))
