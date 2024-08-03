def main():
    var = 10
    ptr = [var]  # Simula um ponteiro para var usando uma lista com um único elemento
    ptr_to_ptr = [ptr]  # Simula um ponteiro para o ponteiro usando uma lista com um único elemento

    # Acessa o valor de var através de dois ponteiros
    print(f"Valor de var: {ptr_to_ptr[0][0]}")


if __name__ == "__main__":
    main()
