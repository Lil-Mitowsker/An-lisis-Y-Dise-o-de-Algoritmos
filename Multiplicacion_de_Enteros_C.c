#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void multiply_primary_algorithm(const char *num1, const char *num2, char *result) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int *a = (int *)malloc(len1 * sizeof(int));
    int *b = (int *)malloc(len2 * sizeof(int));
    int *res = (int *)calloc(len1 + len2, sizeof(int));
    
    // Convertir caracteres a números en orden inverso
    for (int i = 0; i < len1; i++) a[i] = num1[len1 - 1 - i] - '0';
    for (int i = 0; i < len2; i++) b[i] = num2[len2 - 1 - i] - '0';
    
    // Multiplicar dígito por dígito
    for (int i = 0; i < len1; i++) {
        int carry = 0;
        for (int j = 0; j < len2; j++) {
            int temp = a[i] * b[j] + res[i + j] + carry;
            carry = temp / 10;
            res[i + j] = temp % 10;
        }
        res[i + len2] = carry;
    }
    
    // Encontrar el fin del número (omitir ceros a la izquierda)
    int idx = len1 + len2 - 1;
    while (idx > 0 && res[idx] == 0) idx--;
    
    // Convertir resultado a cadena
    int pos = 0;
    for (; idx >= 0; idx--) result[pos++] = res[idx] + '0';
    result[pos] = '\0';
    
    free(a);
    free(b);
    free(res);
}

int main() {
    char num1[] = "12345678";
    char num2[] = "87654321";
    char result[100] = {0};
    
    multiply_primary_algorithm(num1, num2, result);
    printf("%s * %s = %s\n", num1, num2, result);
    
    return 0;
}