def main():
    n = 5

    # Inicializa uma lista com "n" elementos
    arr = [i + 1 for i in range(n)]

    # Redimensiona a lista para 10 elementos
    arr.extend([i + 1 for i in range(n, 10)])

    # Imprime os valores da lista
    for value in arr:
        print(value, end=" ")
    print()
    

if __name__ == "__main__":
    main()
