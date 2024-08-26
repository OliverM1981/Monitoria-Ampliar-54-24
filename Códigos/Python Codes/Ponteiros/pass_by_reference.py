def swap(a, b):
    return b, a


def main():
    x = 10
    y = 20
    x, y = swap(x, y)
    print(f"x: {x}, y: {y}")


if __name__ == "__main__":
    main()
