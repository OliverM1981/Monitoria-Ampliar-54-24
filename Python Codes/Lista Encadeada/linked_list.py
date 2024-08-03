import random


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


def create_node(data):
    return Node(data)


def insert_at_head(head, data):
    new_node = create_node(data)
    new_node.next = head[0]
    head[0] = new_node


def remove_node(head, data):
    current = head[0]
    prev = None

    while current is not None:
        if current.data == data:
            if prev is None:
                # Removing the head node
                head[0] = current.next
            else:
                prev.next = current.next
            del current
            print(f"Elemento {data} removido.")
            return

        prev = current
        current = current.next

    print(f"Elemento {data} não encontrado.")


def print_list(head):
    current = head[0]
    while current is not None:
        print(f"{current.data} -> ", end='')
        current = current.next
    print("NULL")


def print_menu_and_list(head):
    if head[0] is not None:
        print("Lista: ")
        print_list(head)
        print("\n1. Inserir na lista\n2. Remover da lista\n3. Sair\nEscolha uma opção: ", end='')
    else:
        print("\n1. Inserir na lista\n3. Sair\nEscolha uma opção: ", end='')


def handle_choice_1(head):
    """Handle choice 1: insert a new number into the list."""
    data = random.randint(0, 99)
    insert_at_head(head, data)
    print(f"Número {data} inserido na lista.")


def handle_choice_2(head):
    """Handle choice 2: remove a number from the list."""
    if head[0] is None:
        print("A lista está vazia, não há elementos para remover.")
        return

    try:
        data = int(input("Digite o número a ser removido: "))
        remove_node(head, data)
    except ValueError:
        print("Entrada inválida. Por favor, insira um número.")


def handle_choice_3(head):
    """Handle choice 3: clear the list and exit."""
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
            handle_choice_1(head)
        elif choice == 2:
            handle_choice_2(head)
        elif choice == 3:
            handle_choice_3(head)
            break
        else:
            print("Opção inválida.")


if __name__ == "__main__":
    main()
