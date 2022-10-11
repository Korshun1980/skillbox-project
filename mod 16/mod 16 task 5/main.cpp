#include <string>
#include <sstream>
#include <iostream>

enum switches
{
    allPower = 1, // общий выключатель
    allConnector = 2, // выключатель всех розеток
    LightHouse = 4, // освещение внутри
    LightsOutside = 8, // освещение снаружи
    Heaters = 16, // отопление дома
    WaterPipeHeating = 32, // обогрев трубы
    Conditioner = 64 // кондиционер
};

int electricalPanel = (allPower | allConnector);

int switching (short switchAutomatic, bool onOff) {
    if (onOff) {
        electricalPanel |= switchAutomatic;
    } else electricalPanel &= (~switchAutomatic);
}

int main() {
    short kelvinsMax = 5000;
    short kelvinsMin = 2700;
    double kelvinsStep = (kelvinsMax - kelvinsMin) / 5;
    for (short day = 0; day < 2; ++day) {
        short kelvins = kelvinsMax;
        for (short time = 14; time < 24; ++time) {
            std::string sensorReadings;
            std::cout << "\nTime is now: " << time << ":00\n";
            std::cout
                    << "Input with a space\n(the temperature outside, the temperature inside,\n"
                       "is there movement outside, is the light on in the house):\n";
            getline(std::cin, sensorReadings);
            //std::cout << sensorReadings << "!!!!!!!!!!!!\n";

            std::string buffer;
            buffer = sensorReadings;
            std::stringstream bufferStream;
            bufferStream << buffer;

            short tempOut;
            short tempIn;
            std::string movet;
            std::string lightingHome;

            bufferStream >> tempOut >> tempIn >> movet >> lightingHome;

            if (tempOut < 0 && !(electricalPanel & WaterPipeHeating)) {
                switching(WaterPipeHeating, true);
                std::cout << "Water pipe heating on\n";
            }
            if (tempOut > 5 && (electricalPanel & WaterPipeHeating)) {
                switching(WaterPipeHeating, false);
                std::cout << "Water pipe heating off\n";
            }
            bool checkbox = ((time > 16 || time < 5) && movet == "yes");
            if (checkbox && !(electricalPanel & LightsOutside)) {
                switching(LightsOutside, true);
                std::cout << "Lights out side on\n";
            }
            if (!checkbox && (electricalPanel & LightsOutside)){
                switching(LightsOutside, false);
                std::cout << "Lights out side off\n";
            }
            if (tempIn < 22 && !(electricalPanel & Heaters)) {
                switching(Heaters, true);
                std::cout << "Heaters on\n";
            }
            if (tempIn >= 25 && (electricalPanel & Heaters)) {
                switching(Heaters, false);
                std::cout << "Heaters off\n";
            }
            if (tempIn >= 30 && !(electricalPanel & Conditioner)) {
                switching(Conditioner, true);
                std::cout << "Conditioner on\n";
            }
            if (tempIn <= 25 && (electricalPanel & Conditioner)) {
                switching(Conditioner, false);
                std::cout << "Conditioner off\n";
            }
            switching(LightHouse, lightingHome == "on");

            if (time >= 16 && time <= 20) {
                kelvins -= kelvinsStep;            }

            if (electricalPanel & LightHouse) {
                std::cout << "Light in the house on: " << kelvins << " kelvins\n";
            }
        }
    }
    return 0;
}
