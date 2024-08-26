def to_uppercase(s):
    """Converts a string to uppercase manually."""
    result = []
    for char in s:
        if 'a' <= char <= 'z':  # Verifica se o caractere está entre 'a' e 'z'
            # Converte o caractere para maiúscula
            result.append(chr(ord(char) - (ord('a') - ord('A'))))
        else:
            result.append(char)
    return ''.join(result)


def main():
    text = "hello, world!"
    uppercase_text = to_uppercase(text)
    print(f"Uppercase: {uppercase_text}")


if __name__ == "__main__":
    main()
