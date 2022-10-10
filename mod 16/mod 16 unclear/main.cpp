#include <iostream>

int main() {
    enum WindowStyle {
        HasMaxButton = 1,
        HasMinButton = 2,
        HasCloseButton = 4
    };
// Создаём окно с кнопками «свернуть» и «закрыть»:
    int allButtons = HasMinButton | HasCloseButton; // включил флажки «свернуть» HasMinButton и «закрыть»HasCloseButton
    allButtons |= HasMaxButton;
    allButtons &= (~HasCloseButton);
    //allButtons &= (~HasMinButton);// выключил флажек HasCloseButton«закрыть».
// Если окно имеет кнопку «развернуть»:
    if(allButtons & HasMaxButton)
    {
        std::cout << "Fail" << std::endl;
    }
// Если окно имеет кнопку «свернуть»:
    if(allButtons & HasMinButton)
    {
        std::cout << "Has min button" << std::endl;
    }
// Если окно имеет кнопку «свернуть» и кнопку «закрыть»:
    if ((allButtons & HasMinButton) && (allButtons & HasCloseButton)) // У меня в данном случае если хоть 1 из HasMinButton HasCloseButton верно то и все условие верно
    {
        std::cout << "Has min and close buttons" << std::endl;
    }
    return 0;
}
