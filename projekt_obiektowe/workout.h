#ifndef WORKOUT_H
#define WORKOUT_H

#include <iostream>
#include <vector>
#include <limits>

class Menu;
    // Klasa służąca do pobierania danych o treningach od użytkownika
class Workout {
public:
    // Metoda zapewniająca, że użytkownik wprowadza liczbę całkowitą
static int getIntInput() {
        int choice;
        while (true) {

            if (std::cin >> choice) {
                break;
            } else {
                std::cout << "Nieprawidlowy wybor. Sprobuj ponownie." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        return choice;
    }

    // Metoda do pobierania od użytkownika liczbe serii i powtórzeń
    static void getSetsAndReps(const std::string& exercise, int& sets, int& reps) {
        unsigned int num_sets, num_reps;
        std::cout << "Podaj ilosc serii dla " << exercise << ": ";
        sets = getIntInput();
        std::cout << "Podaj ilosc powtorzen dla " << exercise << ": ";
        reps = getIntInput();
        std::cout << "Wybrane cwiczenie: " << exercise << ", Serii: " << sets << ", Powtorzen: " << reps << std::endl;
    }
    // Metoda do pobierania od użytkownika liczby serii i czas trwania 
        static void getSetsAndDuration(const std::string& exercise, int& sets, int& duration) {
        unsigned int num_sets, t_duration;
        std::cout << "Podaj ilosc serii dla " << exercise << ": ";
        sets = getIntInput();
        std::cout << "Podaj dlugosc serii dla " << exercise << ": ";
        duration = getIntInput();
        std::cout << "Wybrane cwiczenie: " << exercise << ", Serii: " << sets << ", Dlugosc: " << duration << " sec" << std::endl;
    }
};

#endif