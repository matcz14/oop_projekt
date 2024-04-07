#ifndef TEXTFILEMANAGER_H
#define TEXTFILEMANAGER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include "training.h"

    // Klasa do obsługi pliku tekstowego
class TextFileManager {
public:
    // Metoda do zapisywania sesji treningowych, przyjmuje referencje do obiektów wektora Training i do zmiennej note
    static void saveTrainingSession(const std::vector<Training>& trainings, const std::string& note) {
        std::ofstream file("dziennik_treningowy.txt", std::ios::app);

        // Blok kodu odpowiedzialny za dodawanie dzisiejszej daty do zapisywanych sesji treningowych
        if (file.is_open()) {
            std::time_t t = std::time(nullptr);
            std::tm tm = *std::localtime(&t);
            file << "Trening (" << (1900 + tm.tm_year) << '-' << (1 + tm.tm_mon) << '-' << tm.tm_mday << ")" << std::endl;

            // Pętla for iteruje przez obiekty Training w wektorze trainings i zapisuje je do pliku, wykorzystano przeciążenie operatora '<<' zdefiniowane w klasie Training
            for (const Training& training : trainings) {
                file << training;
                
            }

            file << "Notatka po treningu: " << note << std::endl;
            file << "------------------------------------------------------------------" << std::endl;

            std::cout << "Sesja treningowa zostala zapisana do pliku." << std::endl;
            file.close();
        } else {
            std::cout << "Nie mozna otworzyc pliku do zapisu." << std::endl;
        }
    }
};

#endif
