import random
import math

# Constante de aceleração
ACELERATION_G = 9.81

# Definição das cores
RED = 0
GREEN = 1
BLUE = 2


def is_high_acceleration(acceleration):
    """Verifica se a aceleração é alta."""
    return acceleration > ACELERATION_G


def get_color_based_on_acceleration(acceleration):
    """Retorna a cor associada com base na aceleração."""
    if acceleration < ACELERATION_G:
        return GREEN  # Aceleração baixa
    elif acceleration == ACELERATION_G:
        return BLUE   # Aceleração igual à constante
    else:
        return RED    # Aceleração alta

# Definição de uma estrutura Pessoa


class Pessoa:
    def __init__(self, idade, nome, estatura):
        self.idade = idade
        self.nome = nome
        self.estatura = estatura

# Definição de um typedef para Livro


class Livro:
    def __init__(self, titulo, autor, ano_publicacao, preco):
        self.titulo = titulo
        self.autor = autor
        self.ano_publicacao = ano_publicacao
        self.preco = preco

# Variáveis de tipos diversos


serie = 12345
max32 = 4294967295
PI_F = 3.1415927
PI = 3.141592653589793
PI_DOUBLE = math.pi
projeto = "Ampliar Tecnologias"


def main():
    # Inicializando o gerador de números aleatórios
    random.seed()

    # Inicialização da variável do tipo enum cores
    colour = RED
    print(f"Cor selecionada: {colour}")

    # Inicialização da variável do tipo union
    u = {'numero': 42}
    print(f"Valor da union (numero): {u['numero']}")

    u['decimal'] = 3.14
    print(f"Valor da union (decimal): {u['decimal']:.2f}")

    u['letra'] = 'A'
    print(f"Valor da union (letra): {u['letra']}")

    # Inicialização da variável do tipo Pessoa
    pessoa = Pessoa(25, "João Silva", 1.75)
    print(f"Pessoa:\nIdade: {pessoa.idade}\nNome: {pessoa.nome}\nEstatura: {pessoa.estatura:.2f}")

    # Inicialização da variável do tipo Livro
    livro = Livro("O Guia do Mochileiro das Galáxias", "Douglas Adams", 1979, 29.90)
    print(f"Livro:\nTítulo: {livro.titulo}\nAutor: {livro.autor}\nAno de publicação: {livro.ano_publicacao}"
          f"Preço: {livro.preco:.2f}")

    # Trabalhando com variáveis de tipos diversos
    print(f"Número da série: {serie}")
    print(f"Valor máximo de 32 bits: {max32}")
    print(f"Valor de PI_F: {PI_F:.7f}")
    print(f"Valor de PI: {PI:.15f}")
    print(f"Valor de PI_DOUBLE: {PI_DOUBLE:.15f}")
    print(f"Projeto: {projeto}")

    # Trabalhando com a aceleração e cor
    acceleration = 12.5  # Exemplo de valor de aceleração

    if is_high_acceleration(acceleration):
        print(f"A aceleração de {acceleration:.2f} é alta.")
    else:
        print(f"A aceleração de {acceleration:.2f} não é alta.")

    color = get_color_based_on_acceleration(acceleration)

    if color == RED:
        print("A cor associada à aceleração é RED.")
    elif color == GREEN:
        print("A cor associada à aceleração é GREEN.")
    elif color == BLUE:
        print("A cor associada à aceleração é BLUE.")
    else:
        print("Cor desconhecida.")

    # Gerar e exibir 5 números aleatórios entre 0 e 99
    print("Números aleatórios:")
    for _ in range(5):
        random_number = random.randint(0, 99)
        print(random_number, end=" ")
    print()


if __name__ == "__main__":
    main()
