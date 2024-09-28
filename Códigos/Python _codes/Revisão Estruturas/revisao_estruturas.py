import random
import sys
import locale

sys.stdout.reconfigure(encoding='utf-8')

# Definições constantes
ACELERATION_G = 9.81
PI = 3.141592653589793

# Definição de enum com um dicionário
CORES = {
    'RED': 0,
    'GREEN': 1,
    'BLUE': 2
}

# Função para verificar se a aceleração é alta
def is_high_acceleration(acceleration):
    return acceleration > ACELERATION_G

# Função para retornar a cor associada com base na aceleração
def get_color_based_on_acceleration(acceleration):
    if acceleration < ACELERATION_G:
        return 'GREEN'  # Aceleração baixa associada à cor GREEN
    elif acceleration == ACELERATION_G:
        return 'BLUE'   # Aceleração igual à constante associada à cor BLUE
    else:
        return 'RED'    # Aceleração alta associada à cor RED

# Definição da union usando uma classe
class Union:
    def __init__(self):
        self.numero = None
        self.decimal = None
        self.letra = None

# Definição da struct pessoa usando uma classe
class Pessoa:
    def __init__(self, idade, nome, estatura):
        self.idade = idade
        self.nome = nome
        self.estatura = estatura

# Definição da struct Livro usando uma classe
class Livro:
    def __init__(self, titulo, autor, ano_publicacao, preco):
        self.titulo = titulo
        self.autor = autor
        self.ano_publicacao = ano_publicacao
        self.preco = preco

# Definição de variáveis
serie = 12345
max32 = 4294967295
PI_F = 3.1415927
projeto = "Ampliar Tecnologias"

# Configurações de localidade (equivalente ao setlocale)
locale.setlocale(locale.LC_ALL, 'pt_BR.UTF-8')

# Uso das variáveis e classes
colours = CORES['RED']
print(f"Cor selecionada: {colours}")

u = Union()
u.numero = 42
print(f"Valor da union (numero): {u.numero}")

u.decimal = 3.14
print(f"Valor da union (decimal): {u.decimal:.2f}")

u.letra = 'A'
print(f"Valor da union (letra): {u.letra}")

# Instância da struct pessoa
pessoa = Pessoa(25, "João Silva", 1.75)
print(f"Pessoa:\nIdade: {pessoa.idade}\nNome: {pessoa.nome}\nEstatura: {pessoa.estatura:.2f}")

# Instância da struct Livro
livro1 = Livro("O Guia do Mochileiro das Galáxias", "Douglas Adams", 1979, 29.90)
print(f"Livro:\nTítulo: {livro1.titulo}\nAutor: {livro1.autor}\nAno de publicação: {livro1.ano_publicacao}\nPreço: {livro1.preco:.2f}")

# Exibição de outras variáveis
print(f"Número da série: {serie}")
print(f"Valor máximo de 32 bits: {max32}")
print(f"Valor de PI_F: {PI_F:.7f}")
print(f"Valor de PI: {PI:.15f}")
print(f"Projeto: {projeto}")

# Verificando aceleração
acceleration = 12.5
if is_high_acceleration(acceleration):
    print(f"A aceleração de {acceleration:.2f} é alta.")
else:
    print(f"A aceleração de {acceleration:.2f} não é alta.")

# Cor associada à aceleração
color = get_color_based_on_acceleration(acceleration)

if color == 'RED':
    print("A cor associada à aceleração é RED.")
elif color == 'GREEN':
    print("A cor associada à aceleração é GREEN.")
elif color == 'BLUE':
    print("A cor associada à aceleração é BLUE.")
else:
    print("Cor desconhecida.")

# Gerando números aleatórios
print("Números aleatórios:")
for _ in range(5):
    random_number = random.randint(0, 99)  # Número aleatório entre 0 e 99
    print(random_number, end=' ')
print()