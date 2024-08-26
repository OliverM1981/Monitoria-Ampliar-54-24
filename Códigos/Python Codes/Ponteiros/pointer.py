def main():
    var = 10
    # Em Python, não usamos ponteiros. Podemos manipular a variável diretamente.
    ptr = var

    print(f"Valor de var: {ptr}")  # Acessa o valor diretamente
    ptr = 20  # Modifica o valor de var através da variável
    print(f"Novo valor de var: {ptr}")


if __name__ == "__main__":
    main()
