
#include <iostream>
#include "menu.h"


int main() {
    // Tworzenie obiektu klasy MainMenu
    MainMenu mainMenu;
    // Tworzenie wskaznika currentMenu typu klasy bazowej Menu, poczatkowo wskazuje on na obiekt mainMenu
    // pozwala na przemiesczanie sie po menu
    Menu* currentMenu = &mainMenu;
    // Pętla while działająca dopóki currentMenu nie bedzie wskaźnikiem pustym
    // każdy obieg pętli wskaźnik currentMenu ustawione jest na aktualne menu i jest ono wyświetlane metodą display()
    while (currentMenu != nullptr) {
        currentMenu->display();
    // Metoda processInput() bieżącego menu przetwarza input użytkownika
    // metoda ta może zwrócić wskaźnik na kolejne menu, wtedy currentMenu ustawione zostaje na nowe menu
    // jeśli metoda zwróci nullptr pętla while zostaje przerwana
        currentMenu = currentMenu->processInput();
    }

    return 0;
}