import random


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None


def create_node(data):
    return Node(data)


def insert_at_head(head, data):
    new_node = create_node(data)
    new_node.next = head[0]
    if head[0] is not None:
        head[0].prev = new_node
    head[0] = new_node


def remove_node(head, data):
    current = head[0]

    if current is None:
        print("A lista está vazia.")
        return

    while current is not None and current.data != data:
        current = current.next

    if current is None:
        print(f"Elemento {data} não encontrado.")
        return

    if current.prev is not None:
        current.prev.next = current.next
    else:
        head[0] = current.next

    if current.next is not None:
        current.next.prev = current.prev

    del current
    print(f"Elemento {data} removido.")


def print_list(head):
    current = head[0]
    while current is not None:
        print(f"{current.data} <-> ", end='')
        current = current.next
    print("NULL")


def print_menu_and_list(head):
    if head[0] is not None:
        print("Lista: ", end='')
        print_list(head)
    print("\n1. Inserir na lista\n2. Remover da lista\n3. Sair\nEscolha uma opção: ", end='')


def handle_insert(head):
    data = random.randint(0, 99)
    insert_at_head(head, data)
    print(f"Número {data} inserido na lista.")


def handle_remove(head):
    if head[0] is None:
        print("A lista está vazia, não é possível remover elementos.")
        return

    try:
        data = int(input("Digite o número a ser removido: "))
        remove_node(head, data)
    except ValueError:
        print("Entrada inválida. Por favor, insira um número.")


def handle_exit(head):
    while head[0] is not None:
        head[0] = head[0].next


def main():
    head = [None]
    while True:
        print_menu_and_list(head)
        try:
            choice = int(input())
        except ValueError:
            print("Entrada inválida. Por favor, insira um número.")
            continue

        if choice == 1:
            handle_insert(head)
        elif choice == 2:
            handle_remove(head)
        elif choice == 3:
            handle_exit(head)
            break
        else:
            print("Opção inválida.")


if __name__ == "__main__":
    main()
