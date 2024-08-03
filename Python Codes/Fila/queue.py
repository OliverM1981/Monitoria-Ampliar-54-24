class Fila:
    MAX = 5

    def __init__(self):
        self.itens = [0] * Fila.MAX
        self.frente = 0
        self.tras = -1

    def fila_vazia(self):
        return self.tras < self.frente

    def fila_cheia(self):
        return self.tras == Fila.MAX - 1

    def enfileirar(self, valor):
        if self.fila_cheia():
            print("Fila cheia")
            return False
        self.tras += 1
        self.itens[self.tras] = valor
        return True

    def desenfileirar(self):
        if self.fila_vazia():
            print("Fila vazia")
            return None
        valor = self.itens[self.frente]
        self.frente += 1
        return valor

    def imprimir_fila(self):
        if self.fila_vazia():
            print("Fila está vazia")
            return
        print("Fila: ", end='')
        for i in range(self.frente, self.tras + 1):
            print(self.itens[i], end=' ')
        print()
        


if __name__ == "__main__":
    fila = Fila()

    fila.enfileirar(10)
    fila.enfileirar(20)
    fila.enfileirar(30)
    fila.enfileirar(40)
    fila.enfileirar(50)

    fila.imprimir_fila()

    valor = fila.desenfileirar()
    if valor is not None:
        print(f"Desenfileirado: {valor}")

    fila.imprimir_fila()
