def main():
    var = 10
    ptr = var

    print(f"Valor de var: {ptr}")  # Acessa o valor de var através de ptr
    ptr = 20  # Modifica o valor de var através de ptr
    var = ptr  # Atualiza var com o novo valor de ptr
    print(f"Novo valor de var: {var}")
    

if __name__ == "__main__":
    main()
