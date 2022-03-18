#include <iostream>

std::string IP_Address_Validation_IPv4 (std::string str) {
    bool coincidence = true;
    std::string partStr;
    int i = 0;
    int counter = 0;

    for (; i < str.length(); i++) {
        if (str[str.length()-1] == '.') {
            coincidence = false;
            break;
        }
        int xPartStr = 0;
        for (; i < str.length() && str[i] != '.'; i++) {
            if (str[i] < '0' || str[i] > '9') {
                coincidence = false;
                break;
            }
            partStr += str[i];
            xPartStr = xPartStr * 10 + str[i] - '0';
        }
        if (partStr.length() < 1 || xPartStr > 255 || partStr.length() == 2 && xPartStr < 10 ||
                partStr.length() == 3 && xPartStr < 100) {
            coincidence = false;
            break;
        }
        partStr = "";
        counter++;
    }
    return (coincidence && counter == 4 ? "Yes\n" : "No\n");
}

int main() {
    std::cout << "Input an IP address to check (IPv4)\n";
    std::string str;
    getline(std::cin, str);

    std::cout << IP_Address_Validation_IPv4 (str);
}
