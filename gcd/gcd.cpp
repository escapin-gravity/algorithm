#include <iostream>

int gcd(int a, int b) {
    while (a != 0) { 
        int temp = b;
        b = a;
        a = temp % a;
    }
    return b;
}

int main() {
    int num1, num2;

    std::cout << "Enter two integers: ";
    std::cin >> num1 >> num2;

    int result = gcd(num1, num2);
    std::cout << "The GCD of " << num1 << " and " << num2 << ": " << result << std::endl;

    return 0;
}
