#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <cctype> 

class BaseConversion {
public:
    std::string baseConversion(int num, int base) {
        if (num == 0) {
            return "0";
        }

        const std::string digits = "0123456789ABCDEF";
        std::string result;

        while (num != 0) {
            result = digits[static_cast<size_t>(num % base)] + result;
            num /= base;
        }

        return result;
    }

    int toDecimal(const std::string& num, int base) {
        const std::string digits = "0123456789ABCDEF";
        int result = 0;

        for (std::string::size_type i = 0; i < num.size(); ++i) {
            char upperChar = static_cast<char>(toupper(static_cast<unsigned char>(num[num.size() - 1 - i])));
            size_t index = digits.find(upperChar);
            if (index == std::string::npos) {
                throw std::invalid_argument("Invalid character in input number.");
            }
            result += static_cast<int>(index) * static_cast<int>(pow(base, static_cast<int>(i)));
        }

        return result;
    }
};

int main() {
    BaseConversion converter;

    std::cout << "===========================================\n";
    std::cout << std::left << std::setw(10) << "Decimal" 
              << std::setw(10) << "Base" 
              << std::setw(10) << "Converted" << '\n';
    std::cout << "===========================================\n";

    std::cout << std::left << std::setw(10) << 3
              << std::setw(10) << 2
              << std::setw(10) << converter.baseConversion(3, 2) << '\n';

    std::cout << std::left << std::setw(10) << 10
              << std::setw(10) << 2
              << std::setw(10) << converter.baseConversion(10, 2) << '\n';

    std::cout << std::left << std::setw(10) << 166
              << std::setw(10) << 16
              << std::setw(10) << converter.baseConversion(166, 16) << '\n';

    std::cout << std::left << std::setw(10) << 166
              << std::setw(10) << 11
              << std::setw(10) << converter.baseConversion(166, 11) << '\n';

    std::cout << std::left << std::setw(10) << 100000
              << std::setw(10) << 16
              << std::setw(10) << converter.baseConversion(100000, 16) << '\n';

    std::cout << "===========================================\n";
    std::cout << std::left << std::setw(10) << "Value"
              << std::setw(10) << "Base"
              << std::setw(10) << "Decimal" << '\n';
    std::cout << "===========================================\n";

    std::cout << std::left << std::setw(10) << "11"
              << std::setw(10) << 2
              << std::setw(10) << converter.toDecimal("11", 2) << '\n';

    std::cout << std::left << std::setw(10) << "1010"
              << std::setw(10) << 2
              << std::setw(10) << converter.toDecimal("1010", 2) << '\n';

    std::cout << std::left << std::setw(10) << "A6"
              << std::setw(10) << 16
              << std::setw(10) << converter.toDecimal("A6", 16) << '\n';

    std::cout << std::left << std::setw(10) << "142"
              << std::setw(10) << 11
              << std::setw(10) << converter.toDecimal("142", 11) << '\n';

    std::cout << std::left << std::setw(10) << "186A0"
              << std::setw(10) << 16
              << std::setw(10) << converter.toDecimal("186A0", 16) << '\n';

    std::cout << std::left << std::setw(10) << "0"
              << std::setw(10) << 16
              << std::setw(10) << converter.toDecimal("0", 16) << '\n';

    std::cout << "===========================================\n";

    return 0;
}
