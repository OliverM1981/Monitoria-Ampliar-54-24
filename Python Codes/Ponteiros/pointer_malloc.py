def main():
    n = 5

    # Inicializa uma lista com "n" elementos
    arr = [0] * n

    # Preenche a lista com valores de 1 a "n"
    for i in range(n):
        arr[i] = i + 1

    # Imprime os valores da lista
    for value in arr:
        print(value, end=" ")
    print()


if __name__ == "__main__":
    main()
