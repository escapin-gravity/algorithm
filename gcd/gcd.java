package gcd;

import java.util.Scanner;

class GCD {

    public static int findGCD(int a, int b) {
        while (a != 0) {
            int temp = b;
            b = a;
            a = temp % b;
        }
        return b;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter two integers: ");
        int num1 = scanner.nextInt();
        int num2 = scanner.nextInt();

        int gcd = findGCD(num1, num2);
        System.out.println("The GCD of " + num1 + " and " + num2 + ": " + gcd);

        scanner.close();
    }
}
