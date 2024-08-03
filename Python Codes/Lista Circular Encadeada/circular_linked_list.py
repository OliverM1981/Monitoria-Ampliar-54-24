import random


class Node:
    def __init__(self, data):
        self.data = data
        self.next = self  # Circular reference


def create_node(data):
    return Node(data)


def insert_at_head(head, data):
    new_node = create_node(data)
    if head is None:
        head = new_node
    else:
        tail = head
        while tail.next != head:
            tail = tail.next
        new_node.next = head
        tail.next = new_node
        head = new_node
    return head


def remove_node(head, data):
    if head is None:
        print("A lista está vazia.")
        return head

    current = head
    prev = None

    while True:
        if current.data == data:
            if prev is None:  # Removing head
                head = remove_head(head)
            else:
                prev.next = current.next
            print(f"Elemento {data} removido.")
            return head
        prev = current
        current = current.next
        if current == head:
            break

    print(f"Elemento {data} não encontrado.")
    return head


def remove_head(head):
    if head is None:
        return None

    tail = head
    while tail.next != head:
        tail = tail.next

    if head.next == head:  # Only one node in the list
        return None

    new_head = head.next
    tail.next = new_head
    return new_head


def is_list_empty(head):
    return head is None


def print_list(head):
    if is_list_empty(head):
        print("A lista está vazia.")
        return

    current = head
    while True:
        print(f"{current.data} -> ", end='')
        current = current.next
        if current == head:
            break
    print("(head)")


def print_menu_and_list(head):
    print_menu()
    if head is not None:
        print("Lista: ", end='')
        print_list(head)


def print_menu():
    print("\n1. Inserir na lista\n2. Remover da lista\n3. Sair\nEscolha uma opção: ", end='')


def generate_random_data(min_value=0, max_value=99):
    return random.randint(min_value, max_value)


def handle_insert(head):
    data = generate_random_data()
    head = insert_at_head(head, data)
    print(f"Número {data} inserido na lista.")
    return head


def handle_remove(head):
    if head is None:
        print("A lista está vazia, não é possível remover elementos.")
    else:
        data = int(input("Digite o número a ser removido: "))
        head = remove_node(head, data)
    return head


def handle_exit(head):
    while head is not None:
        next_node = head.next
        del head
        head = next_node


def main():
    head = None
    while True:
        print_menu_and_list(head)
        choice = int(input())

        if choice == 1:
            head = handle_insert(head)
        elif choice == 2:
            head = handle_remove(head)
        elif choice == 3:
            handle_exit(head)
            break
        else:
            print("Opção inválida.")


if __name__ == "__main__":
    main()
