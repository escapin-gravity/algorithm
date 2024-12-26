#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1, num2;
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    int res = gcd(num1, num2);
    printf("The GCD of %d and %d: %d\n", num1, num2, res);

    return 0;
}
