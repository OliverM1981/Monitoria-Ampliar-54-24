def main():
    rows = 3
    cols = 3

    # Criação e inicialização da matriz
    matrix = [[i * cols + j + 1 for j in range(cols)] for i in range(rows)]

    # Impressão da matriz
    for row in matrix:
        for value in row:
            print(value, end=" ")
        print()
        

if __name__ == "__main__":
    main()
