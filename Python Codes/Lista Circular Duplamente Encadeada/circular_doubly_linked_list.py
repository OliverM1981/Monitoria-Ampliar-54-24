import random

class Node:
    def __init__(self, data):
        self.data = data
        self.next = self
        self.prev = self

def create_node(data):
    return Node(data)

def insert_at_head(head, data):
    new_node = create_node(data)
    if head is None:
        head = new_node
    else:
        last = head.prev
        new_node.next = head
        new_node.prev = last
        last.next = new_node
        head.prev = new_node
        head = new_node
    return head

def remove_node(head, data):
    if head is None:
        print("A lista está vazia.")
        return head

    current = head
    while True:
        if current.data == data:
            if current.next == current:  # only one node
                head = None
            else:
                current.prev.next = current.next
                current.next.prev = current.prev
                if current == head:
                    head = current.next
            print(f"Elemento {data} removido.")
            return head
        current = current.next
        if current == head:
            break

    print(f"Elemento {data} não encontrado.")
    return head

def print_list(head):
    if head is None:
        print("A lista está vazia.")
        return

    current = head
    while True:
        print(f"{current.data} <-> ", end='')
        current = current.next
        if current == head:
            break
    print("(head)")
    

def print_menu(head):
    if head is not None:
        print("Lista: ", end='')
        print_list(head)
        print("\n1. Inserir na lista\n2. Remover da lista\n3. Sair\nEscolha uma opção: ", end='')
    else:
        print("\n1. Inserir na lista\n3. Sair\nEscolha uma opção: ", end='')

def handle_insert(head):
    data = random.randint(0, 99)
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
    if head is not None:
        current = head
        while True:
            next_node = current.next
            del current
            current = next_node
            if current == head:
                break

def main():
    head = None
    while True:
        print_menu(head)
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
