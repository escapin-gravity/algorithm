#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* base_conversion(int num, int n) {
    char* digit = "0123456789ABCDEF";
    char* li = (char*)malloc(100 * sizeof(char));
    if (li == NULL) return NULL;

    int idx = 0;
    if (num == 0) {
        li[idx++] = '0';
    } else {
        while (num != 0) {
            li[idx++] = digit[num % n];
            num /= n;
        }
    }

    li[idx] = '\0';
    int left = 0, right = idx - 1;
    while (left < right) {
        char temp = li[left];
        li[left] = li[right];
        li[right] = temp;
        left++;
        right--;
    }

    return li;
}

int to_decimal(const char* str, int base) {
    int result = 0, power = 1;
    size_t len = strlen(str);  
    for (size_t i = len; i > 0; i--) {
        char c = (char)toupper((unsigned char)str[i - 1]); 
        int value = (c >= '0' && c <= '9') ? c - '0' : c - 'A' + 10;
        result += value * power;
        power *= base;
    }
    return result;
}

int main() {
    printf("============================================================\n");
    printf("%-10s %-10s %-10s %-10s\n", "Decimal", "Base", "Converted", "Reverted");
    printf("============================================================\n");

    char* result1 = base_conversion(11, 2);
    if (result1 != NULL) {
        printf("%-10d %-10d %-10s %-10d\n", 11, 2, result1, to_decimal(result1, 2));
        free(result1);
    }

    char* result2 = base_conversion(10, 2);
    if (result2 != NULL) {
        printf("%-10d %-10d %-10s %-10d\n", 10, 2, result2, to_decimal(result2, 2));
        free(result2);
    }

    char* result3 = base_conversion(166, 13);
    if (result3 != NULL) {
        printf("%-10d %-10d %-10s %-10d\n", 166, 13, result3, to_decimal(result3, 13));
        free(result3);
    }

    char* result4 = base_conversion(17, 16);
    if (result4 != NULL) {
        printf("%-10d %-10d %-10s %-10d\n", 17, 16, result4, to_decimal(result4, 16));
        free(result4);
    }

    printf("============================================================\n");

    return 0;
}
