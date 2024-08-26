import random


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


def create_node(data):
    return Node(data)


def push(top, data):
    new_node = create_node(data)
    new_node.next = top[0]
    top[0] = new_node


def pop(top):
    if top[0] is None:
        print("A pilha está vazia, não há elementos para remover.")
        return

    top[0] = top[0].next
    print("Elemento removido do topo da pilha.")


def print_stack(top):
    current = top[0]
    while current is not None:
        print(f"{current.data} -> ", end='')
        current = current.next
    print("NULL")


def print_menu_and_stack(top):
    if top[0] is not None:
        print("Pilha Dinâmica: ", end='')
        print_stack(top)
    print("\n1. Inserir na pilha\n2. Remover da pilha\n3. Sair\nEscolha uma opção: ", end='')


def main():
    top = [None]  # Inicializa o topo da pilha
    while True:
        print_menu_and_stack(top)
        try:
            choice = int(input())
        except ValueError:
            print("Entrada inválida. Por favor, insira um número.")
            continue

        if choice == 1:
            data = random.randint(0, 99)
            push(top, data)
            print(f"Número {data} inserido na pilha.")
        elif choice == 2:
            pop(top)
        elif choice == 3:
            # Libera a memória alocada para a pilha
            while top[0] is not None:
                top[0] = top[0].next
            break
        else:
            print("Opção inválida.")


if __name__ == "__main__":
    main()
