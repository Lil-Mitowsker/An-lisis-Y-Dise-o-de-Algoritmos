def multiply_primary_algorithm(num1, num2):
    # Convertir cadenas a listas de enteros en orden inverso
    a = list(map(int, num1))[::-1]
    b = list(map(int, num2))[::-1]
    
    # Inicializar arreglo de resultado con ceros
    result = [0] * (len(a) + len(b))
    
    # Multiplicar dígito por dígito
    for i in range(len(a)):
        carry = 0
        for j in range(len(b)):
            temp = a[i] * b[j] + result[i + j] + carry
            carry = temp // 10
            result[i + j] = temp % 10
        result[i + len(b)] = carry
    
    # Eliminar ceros a la izquierda
    while len(result) > 1 and result[-1] == 0:
        result.pop()
    
    # Convertir a cadena en orden correcto
    return ''.join(map(str, result[::-1]))

# Pruebas con números de n dígitos (n potencia de 2)
test_cases = [
    ("12", "13"),      # n=2
    ("1234", "5678"),  # n=4
    ("12345678", "87654321")  # n=8
]

for num1, num2 in test_cases:
    print(f"{num1} * {num2} = {multiply_primary_algorithm(num1, num2)}")