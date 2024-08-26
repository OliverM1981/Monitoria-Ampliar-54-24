MAX = 5


class Stack:
    def __init__(self):
        self.items = []
        self.top = -1

    def is_empty(self):
        return self.top == -1

    def is_full(self):
        return self.top == MAX - 1

    def push(self, value):
        if self.is_full():
            print("Stack is full")
            return False
        self.top += 1
        if len(self.items) <= self.top:
            self.items.append(value)
        else:
            self.items[self.top] = value
        return True

    def pop(self):
        if self.is_empty():
            print("Stack is empty")
            return None, False
        value = self.items[self.top]
        self.top -= 1
        return value, True

    def print_stack(self):
        if self.is_empty():
            print("Stack is empty")
            return
        print("Stack:", end=" ")
        for i in range(self.top, -1, -1):
            print(self.items[i], end=" ")
        print()


def main():
    stack = Stack()

    stack.push(10)
    stack.push(20)
    stack.push(30)
    stack.push(40)
    stack.push(50)

    stack.print_stack()

    value, success = stack.pop()
    if success:
        print(f"Popped: {value}")

    stack.print_stack()


if __name__ == "__main__":
    main()
