package base_conversion;

class BaseConversion {

    private String baseConversion(int num, int n) {
        if (num == 0) {
            return "0";
        }

        String digits = "0123456789ABCDEF";
        StringBuilder sb = new StringBuilder();

        while (num != 0) {
            sb.append(digits.charAt(num % n));
            num /= n;
        }

        return sb.reverse().toString();
    }

    private int toDecimal(String num, int n) {
        int result = 0;
        String digits = "0123456789ABCDEF";

        for (int i = 0; i < num.length(); i++) {
            int digitValue = digits.indexOf(num.charAt(num.length() - 1 - i));
            result += digitValue * Math.pow(n, i);
        }

        return result;
    }

    public static void main(String[] args) {
        BaseConversion converter = new BaseConversion();

        System.out.println("===========================================");
        System.out.printf("%-10s %-10s %-10s\n", "Decimal", "Base", "Converted");
        System.out.println("===========================================");

        System.out.printf("%-10d %-10d %-10s\n", 3, 2, converter.baseConversion(3, 2));
        System.out.printf("%-10d %-10d %-10s\n", 10, 2, converter.baseConversion(10, 2));
        System.out.printf("%-10d %-10d %-10s\n", 166, 16, converter.baseConversion(166, 16));
        System.out.printf("%-10d %-10d %-10s\n", 166, 11, converter.baseConversion(166, 11));
        System.out.printf("%-10d %-10d %-10s\n", 100000, 16, converter.baseConversion(100000, 16));

        System.out.println("===========================================");
        System.out.printf("%-10s %-10s %-10s\n", "Value", "Base", "Decimal");
        System.out.println("===========================================");

        System.out.printf("%-10s %-10d %-10d\n", "11", 2, converter.toDecimal("11", 2));
        System.out.printf("%-10s %-10d %-10d\n", "1010", 2, converter.toDecimal("1010", 2));
        System.out.printf("%-10s %-10d %-10d\n", "A6", 16, converter.toDecimal("A6", 16));
        System.out.printf("%-10s %-10d %-10d\n", "142", 11, converter.toDecimal("142", 11));
        System.out.printf("%-10s %-10d %-10d\n", "186A0", 16, converter.toDecimal("186A0", 16));
        System.out.printf("%-10s %-10d %-10d\n", "0", 16, converter.toDecimal("0", 16));

        System.out.println("===========================================");
    }
}
