#include <iostream>
#include <fstream>
#include <string>

bool dateCheck (std::string date) {
    if (date.size() != 10 || date[2] != '.' || date[5] != '.') return false;
    date[2] = '0';
    date[5] = '0';
    for (int i = 0; i < 10; ++i) {
         if (date[i] < '0' || date[i] > '9') return false;
    }
    int day = std::stoi(date.substr(0, 2));
    int month = std::stoi(date.substr(3, 2));
    int year = std::stoi(date.substr(6, 4));
    if ((day > 0 && day < 32) && (month > 0 && month < 13) && (year > 0 && year < 10000)) {
        return true;
    }
    return false;
}

int main() {
    std::string name;
    std::string surname;
    std::string date = "01.01.0001";
    int amount = 0;
    std::ofstream worksheet("C:\\Users\\korsh\\skillbox-project\\mod 20\\mod 20 task 1\\worksheet.txt", std::ios::app);
    if (!(worksheet.is_open())){
        std::cout << "ERROR!!! Input valid directory\n";
        return 0;
    }
    std::cout << "Input name, surname, date and amount (through a space): ";
    std::cin >> name >> surname >> date >> amount;

    while (!dateCheck(date)) {
        std::cout << "ERROR!!! Input valid date! (DD.MM.YYYY)\n";
        std::cin >> date;
    }
    worksheet << "\n" << name << ' ' << surname << ' ' << date << ' ' << amount << "\n";
    worksheet.close();

    return 0;
}