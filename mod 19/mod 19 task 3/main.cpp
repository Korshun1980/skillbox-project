#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream worksheet;
    std::vector<std::string> nameVec;
    std::vector<std::string> surnameVec;
    std::vector<int> moneyVec;
    std::vector<std::string> dateVec;

    std::string name;
    std::string surname;
    int money;
    std::string date;
    int sum = 0;
    int moneyMax = 0;
    std::string nameMax;
    std::string surnameMax;

    std::string directory;
    std::cout << "Input directory\n";
    //getline(std::cin, directory);
    directory = "C:\\Users\\korsh\\skillbox-project\\mod 19\\mod 19 task 3\\worksheet.txt";
    worksheet.open(directory);
    while (!(worksheet.is_open())) {
        std::cout << "ERROR!!! Input valid directory\n";
        getline(std::cin, directory);
    }

    while (!worksheet.eof()){
        worksheet >> name >> surname >> money >> date;
        nameVec.push_back(name);
        surnameVec.push_back(surname);
        moneyVec.push_back(money);
        dateVec.push_back(date);
        sum += money;
        if (money > moneyMax) {
            moneyMax = money;
            nameMax = name;
            surnameMax = surname;
        }
    }
        std::cout << sum << "\n" << nameMax << " " << surnameMax << " " << moneyMax << "\n";

    return 0;
}
