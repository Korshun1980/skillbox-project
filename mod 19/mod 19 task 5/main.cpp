#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream sector;
    std::string directory;
    std::string dir1;
    std::string dir2 = ".txt";
    int sectorNumber = 1;
    int pointPlayers = 0;
    int pointViewers = 0;
    int movide;
    bool remoteSectors[13];
    for (int i = 0; i < 13; ++i){
        remoteSectors[i] = true;
    }
    while (true) {
        std::cout << "Spin the top!\n";
        std::cin >> movide;
        sectorNumber = sectorNumber + (movide)%13;
        if(sectorNumber>13) sectorNumber-=13;

        while (!remoteSectors[sectorNumber-1]){
            sectorNumber++;
            if(sectorNumber>13) sectorNumber-=13;
        }
        remoteSectors[sectorNumber-1] = false;
        std::cout << "Sector " << sectorNumber << "\n";

        dir1 = std::to_string(sectorNumber);

        directory = "C:\\Users\\korsh\\skillbox-project\\mod 19\\mod 19 task 5\\Questions and answers\\Questions ";
        directory += dir1;
        directory += dir2;

        sector.open(directory);
        while (!(sector.is_open())) {
            std::cout << "ERROR!!! Input valid directory\n";
            getline(std::cin, directory);
            sector.open(directory);
        }
        std::string questions;
        while (!sector.eof()) {
            sector >> questions;
            std::cout << questions << " ";
        }
        std::cout << "\n";
        sector.close();

        std::cout << "Your answer: \n";
        std::string answer;
        std::cin >> answer;

        directory = "C:\\Users\\korsh\\skillbox-project\\mod 19\\mod 19 task 5\\Questions and answers\\answers ";
        directory += dir1;
        directory += dir2;

        sector.open(directory);
        while (!(sector.is_open())) {
            std::cout << "ERROR!!! Input valid directory\n";
            getline(std::cin, directory);
            sector.open(directory);
        }
        std::string correctAnswer;
        sector >> correctAnswer;
        sector.close();

        if (answer == correctAnswer) {
            pointPlayers++;
            std::cout << "Correct!!! +1 point for players\nScore " << pointPlayers << " : " << pointViewers << "\n";
            if (pointPlayers == 6) {
                std::cout << "Players won!!!\n";
                return 0;
            }
        } else {
            pointViewers++;
            std::cout << "Wrong answer!!! +1 point for viewers\nScore " << pointPlayers << " : " << pointViewers << "\n";
            if (pointViewers == 6) {
                std::cout << "Viewers won!!!\n";
                return 0;
            }
        }
    }
}
