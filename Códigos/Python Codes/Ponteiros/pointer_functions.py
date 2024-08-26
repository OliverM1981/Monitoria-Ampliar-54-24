def greet():
    print("Hello!")


def farewell():
    print("Goodbye!")


def main():
    func_dict = {
        'greet': greet,
        'farewell': farewell
    }

    func_name = 'greet'
    func_dict[func_name]()  # Chama a função greet

    func_name = 'farewell'
    func_dict[func_name]()  # Chama a função farewell


if __name__ == "__main__":
    main()
