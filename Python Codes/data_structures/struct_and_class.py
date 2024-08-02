class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age
        

def main():
    # Criação de um objeto da classe Person
    p = Person("John Doe", 30)

    print(f"Name: {p.name}, Age: {p.age}")
    

if __name__ == "__main__":
    main()
