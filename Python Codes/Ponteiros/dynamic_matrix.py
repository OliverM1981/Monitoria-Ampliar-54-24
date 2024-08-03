def main():
    rows = 3
    cols = 3

    # Alocação e inicialização da matriz
    matrix = [[0] * cols for _ in range(rows)]

    # Inicialização da matriz
    for i in range(rows):
        for j in range(cols):
            matrix[i][j] = i * cols + j + 1

    # Impressão da matriz
    for row in matrix:
        print(" ".join(map(str, row)))


if __name__ == "__main__":
    main()
