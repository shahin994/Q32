#include <iostream>
#include <string>
#include <cctype>

int calculatePasswordStrength(const std::string& password) {
    int strength = 0;
    int length = password.length();
    int numCount = 0;
    int specialCharCount = 0;
    int uppercaseCount = 0;
    int lowercaseCount = 0;

    for (char c : password) {
        if (isdigit(c)) {
            numCount++;
        } else if (isalpha(c)) {
            if (isupper(c)) {
                uppercaseCount++;
            } else {
                lowercaseCount++;
            }
        } else {
            specialCharCount++;
        }
    }

    if (length >= 6) strength += 20;
    if (numCount > 0) strength += 20;
    if (specialCharCount > 0) strength += 20;
    if (uppercaseCount > 0) strength += 20;
    if (lowercaseCount > 0) strength += 20;

    return strength;
}

int main() {
    std::string password;
    std::cout << "Enter your password: ";
    std::cin >> password;

    int strength = calculatePasswordStrength(password);
    std::cout << "Password strength: " << strength << "%" << std::endl;

    return 0;
}