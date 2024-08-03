class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age


def main():
    # Criação e inicialização do objeto Person
    person = Person("John Doe", 30)

    # Impressão dos dados da pessoa
    print(f"Name: {person.name}, Age: {person.age}")


if __name__ == "__main__":
    main()
