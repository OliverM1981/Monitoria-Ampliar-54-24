import random


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


def create_node(data):
    return Node(data)


def enqueue(front, rear, data):
    new_node = create_node(data)
    if rear[0] is None:
        # Se a fila está vazia
        front[0] = new_node
        rear[0] = new_node
    else:
        # Adiciona no final da fila
        rear[0].next = new_node
        rear[0] = new_node


def dequeue(front, rear):
    if front[0] is None:
        print("A fila está vazia, não há elementos para remover.")
        return

    front[0] = front[0].next

    if front[0] is None:
        # Se a fila ficou vazia, o rear também deve ser None
        rear[0] = None

    print("Elemento removido do início da fila.")


def print_queue(front):
    current = front[0]
    while current is not None:
        print(f"{current.data} -> ", end='')
        current = current.next
    print("NULL")


def print_menu_and_queue(front):
    if front[0] is not None:
        print("Fila Dinâmica: ", end='')
        print_queue(front)
    print("\n1. Inserir na fila\n2. Remover da fila\n3. Sair\nEscolha uma opção: ", end='')


def main():
    front = [None]  # Início da fila
    rear = [None]   # Final da fila

    while True:
        print_menu_and_queue(front)
        choice = int(input())

        if choice == 1:
            data = random.randint(0, 99)
            enqueue(front, rear, data)
            print(f"Número {data} enfileirado.")
        elif choice == 2:
            dequeue(front, rear)
        elif choice == 3:
            # Libera a memória alocada para a fila
            while front[0] is not None:
                front[0] = front[0].next
            break
        else:
            print("Opção inválida.")


if __name__ == "__main__":
    main()
