#ifndef MENU_H
#define MENU_H


#include <iostream>
#include "workout.h"
#include "training.h"
#include "textFileManager.h"

class Menu {
public:
    // Wirtualna metoda do wyświetlania poszczególnych menu przez przesłonięcie w dalszych częściach kodu
    virtual void display() const = 0;
    // Wirtualna metoda do przetwarzania input użytkownika
    virtual Menu* processInput() = 0;
    // Wirtualny destruktor do usuwania obiektów klas dziedziczących (submenu) przez wskaźnik na obiekt klasy bazowej
    virtual ~Menu() {}

    // Metoda zapewniająca, że użytkownik wprowadza liczbę całkowitą
    static int getIntInput() {
        int choice;
        while (true) {
            std::cout << "Wybor: ";
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

};
    // Klasa podmenu dziedzicząca z klasy Menu
class PushUpsSubMenu : public Menu {
private:
    // Wskaźnik parentMenu wskazujący na menu nadrzędne i umożliwiający powrót gdy wskaźnik ustawiony będzie na menu główne
    Menu* parentMenu;
    // Wektor w którym przechowywane bedą utworzone przez użytkownika obiekty klasy Training 
    std::vector<Training>& trainings;
public:
    // Konstruktor z listą inicjalizacyjną, przyjmuje wskaźnik do parentMenu i referencje trainings
    PushUpsSubMenu(Menu* parentMenu, std::vector<Training>& trainings) : parentMenu(parentMenu), trainings(trainings) {}

    // Nadpisanie metody display() dla tego podmenu 
    void display() const override {
        std::cout << std::endl;
        std::cout << "Submenu: Push-ups" << std::endl;
        std::cout << "1. Basic Push-ups" << std::endl;
        std::cout << "2. Wide Push-ups" << std::endl;
        std::cout << "3. Diamond Push-ups" << std::endl;
        std::cout << "4. Pike Push-ups" << std::endl;
        std::cout << "0. Powrot do menu glownego" << std::endl;
        std::cout << "------------------------------------------------------------------------------ " << std::endl;
    }
    // Metoda przyjmująca wybór od użytkownika 
    //  używając metody z klasy Workout pobiera od użytkownika dane, następnie tworzy obiekt klasy Trening i dodaje go do wektora trainings
    Menu* processInput() override {
        int choice = Menu::getIntInput();
        
        switch (choice) {
            case 1:
            {
                int sets, reps;
                Workout::getSetsAndReps("Basic Push-ups", sets, reps);
                Training training("Basic Push-ups", sets, reps);
                trainings.push_back(training);
            }    
                break;
            case 2:
            {
                int sets, reps;
                Workout::getSetsAndReps("Wide Push-ups", sets, reps);
                Training training("Wide Push-ups", sets, reps);
                trainings.push_back(training);
            }    
                break;
            case 3:
            {
                int sets, reps;
                Workout::getSetsAndReps("Diamond Push-ups", sets, reps);
                Training training("Diamond Push-ups", sets, reps);
                trainings.push_back(training);
            }    
                break;
            case 4:
            {
                int sets, reps;
                Workout::getSetsAndReps("Pike Push-ups", sets, reps);
                Training training("Pike Push-ups", sets, reps);
                trainings.push_back(training);
            }
                break;
            // wybór '0' przenosi użytkownika spowrotem do menu głównego         
            case 0:
                return parentMenu;
            default:
                std::cout << "Nieprawidlowy wybor. Sprobuj ponownie." << std::endl;
        }
        // return this zwraca wskaźnik na bieżący obiekt (menu w którym obecnie znajduje się użytkownik)
        // gwarantuje to że po utworzeniu obiektu klasy trening i dodaniu go do wektora użytkownik pozostaje 
        // w bieżącym menu i może dokonać dodatkowych wyborów
        return this;
    }


};
    // Klasa podmenu dziedzicząca z klasy Menu
class CoreExercisesSubMenu : public Menu {
private:
    // Wskaźnik parentMenu wskazujący na menu nadrzędne i umożliwiający powrót gdy wskaźnik ustawiony będzie na menu główne
    Menu* parentMenu;
    // Wektor w którym przechowywane bedą utworzone przez użytkownika obiekty klasy Training
    std::vector<Training>& trainings;
public:
    // Konstruktor z listą inicjalizacyjną, przyjmuje wskaźnik do parentMenu i referencje trainings
    CoreExercisesSubMenu(Menu* parentMenu, std::vector<Training>& trainings) : parentMenu(parentMenu), trainings(trainings) {}

    // Nadpisanie metody display() dla tego podmenu
    void display() const override {
        std::cout << std::endl;
        std::cout << "Submenu: Core Exercises" << std::endl << std::endl;
        std::cout << "1. Crunches" << std::endl;
        std::cout << "2. Plank" << std::endl;
        std::cout << "3. Hollow Body Hold" << std::endl;
        std::cout << "4. Russian Twists" << std::endl;
        std::cout << "0. Powrot do menu glownego" << std::endl;
        std::cout << "------------------------------------------------------------------------------ " << std::endl;
    }

    // Metoda przyjmująca wybór od użytkownika 
    //  używając metody z klasy Workout pobiera od użytkownika dane, następnie tworzy obiekt klasy Trening i dodaje go do wektora trainings
    Menu* processInput() override {
        int choice = Menu::getIntInput();
        
        switch (choice) {
            case 1:
            {
                int sets, reps;
                Workout::getSetsAndReps("Crunches", sets, reps);
                Training training("Crunches", sets, reps);
                trainings.push_back(training);
            }    
                break;
            case 2:
            {
                int sets, duration;
                Workout::getSetsAndDuration("Plank", sets, duration);
                Training training("Plank", sets, duration);
                trainings.push_back(training);
            }
                break;
            case 3:
            {
                int sets, duration;
                Workout::getSetsAndDuration("Hollow Body Hold", sets, duration);
                Training training("Hollow Body Hold", sets, duration);
                trainings.push_back(training);
            }
                break;
            case 4:
            {
                int sets, reps;
                Workout::getSetsAndReps("Russian Twists", sets, reps);
                Training training("Russian Twists", sets, reps);
                trainings.push_back(training);
            }    
                break;
            // wybór '0' przenosi użytkownika spowrotem do menu głównego        
            case 0:
                return parentMenu;
            default:
                std::cout << "Nieprawidlowy wybor. Sprobuj ponownie." << std::endl;
        }
        // return this zwraca wskaźnik na bieżący obiekt (menu w którym obecnie znajduje się użytkownik)
        // gwarantuje to że po utworzeniu obiektu klasy trening i dodaniu go do wektora użytkownik pozostaje 
        // w bieżącym menu i może dokonać dodatkowych wyborów
        return this;
    }


};
    // Klasa podmenu dziedzicząca z klasy Menu
class LegsExercisesSubMenu : public Menu {
private:
    // Wskaźnik parentMenu wskazujący na menu nadrzędne i umożliwiający powrót gdy wskaźnik ustawiony będzie na menu główne
    Menu* parentMenu;
    // Wektor w którym przechowywane bedą utworzone przez użytkownika obiekty klasy Training
    std::vector<Training>& trainings;
public:
    // Konstruktor z listą inicjalizacyjną, przyjmuje wskaźnik do parentMenu i referencje trainings
    LegsExercisesSubMenu(Menu* parentMenu, std::vector<Training>& trainings) : parentMenu(parentMenu), trainings(trainings) {}

    // Nadpisanie metody display() dla tego podmenu
    void display() const override {
        std::cout << std::endl;
        std::cout << "Submenu: Legs Exercises" << std::endl << std:: endl;
        std::cout << "1. Squats" << std::endl;
        std::cout << "2. Lunges" << std::endl;
        std::cout << "3. Calf Raises" << std::endl;
        std::cout << "4. Bulgarian Split Squats" << std::endl;
        std::cout << "5. Single Leg Squats" << std::endl;
        std::cout << "6. Reverse Nordic Curls" << std::endl;
        std::cout << "0. Powrot do menu glownego" << std::endl;
        std::cout << "------------------------------------------------------------------------------ " << std::endl;
    }
    // Metoda przyjmująca wybór od użytkownika 
    //  używając metody z klasy Workout pobiera od użytkownika dane, następnie tworzy obiekt klasy Trening i dodaje go do wektora trainings
    Menu* processInput() override {
        int choice = Menu::getIntInput();

        switch (choice) {
            case 1:
            {
                int sets, reps;
                Workout::getSetsAndReps("Squats", sets, reps);
                Training training("Squats", sets, reps);
                trainings.push_back(training);
            }
                break;
            case 2:
            {
                int sets, reps;
                Workout::getSetsAndReps("Lunges", sets, reps);
                Training training("Lunges", sets, reps);
                trainings.push_back(training);
            }
                break;
            case 3:
            {
                int sets, reps;
                Workout::getSetsAndReps("Calf Raises", sets, reps);
                Training training("Calf Raises", sets, reps);
                trainings.push_back(training);
            }    
                break;    
            case 4:
            {
                int sets, reps;
                Workout::getSetsAndReps("Bulgarian Split Squat", sets, reps);
                Training training("Bulgarian Split Squat", sets, reps);   
                trainings.push_back(training);
            }    
                break;
            case 5:
            {
                int sets, reps;
                Workout::getSetsAndReps("Single Leg Squats", sets, reps);
                Training training("Single Leg Squats", sets, reps);
                trainings.push_back(training);
            }
                break;
            case 6:
            {
                int sets, reps;
                Workout::getSetsAndReps("Reverse Nordic Curls", sets, reps);
                Training training("Reverse Nordic Curls", sets, reps);
                trainings.push_back(training);
            }
                break;
            // wybór '0' przenosi użytkownika spowrotem do menu głównego        
            case 0:
                return parentMenu;
            default:
                std::cout << "Nieprawidlowy wybor. Sprobuj ponownie." << std::endl;
        }
        // return this zwraca wskaźnik na bieżący obiekt (menu w którym obecnie znajduje się użytkownik)
        // gwarantuje to że po utworzeniu obiektu klasy trening i dodaniu go do wektora użytkownik pozostaje 
        // w bieżącym menu i może dokonać dodatkowych wyborów
        return this;
    }


};

    // Klasa do obsługi menu głównego dziedzicząca po klasie Menu
class MainMenu : public Menu {
private:
    // Wektor w którym przechowywane bedą utworzone przez użytkownika obiekty klasy Training
    std::vector<Training> trainings;

public:
MainMenu() : Menu(), trainings() {}

    void display() const override {

        

            std::cout << std::endl;
            std::cout << "                      |------------ Menu ------------| " << std::endl;
            std::cout << std::endl;
            std::cout << "Nawiguj po menu wpisujac odpowiednie cyfry" << std::endl;
            std::cout << "Niektore z wyborow przenosza uzytkownika do podmenu gdzie nalezy sprecyzowac wybor" << std::endl;
            std::cout << "\n------ Dodaj cwiczenia z dostepnych na liscie ------ " << std::endl;
            std::cout << std::endl; std::cout << std::endl;
            std::cout << "1. Pull-ups " << std::endl;
            std::cout << "2. Chin-ups " << std::endl;
            std::cout << "3. Push-ups (do wyboru) " << std::endl;
            std::cout << "4. Dips " << std::endl;
            std::cout << "5. Core exercises (do wyboru) " << std::endl;
            std::cout << "6. Legs exercises (do wyboru)" << std::endl;
            std::cout << "7. Cardio " << std::endl;
            std::cout << "0. Zapis i wyjscie z programu" << std::endl;
            std::cout << "------------------------------------------------------------------------------ " << std::endl;
    }

    // Metoda przyjmująca wybór od użytkownika, użytkownik może wybrać z listy, bądź przejść do pod menu (wybór:'3', '5', '6') gdzie dokonuje kolejnego wyboru
    //  używając metody z klasy Workout pobiera od użytkownika dane, następnie tworzy obiekt klasy Trening i dodaje go do wektora trainings
    Menu* processInput() override {
        int choice = Menu::getIntInput();
        
        switch (choice) {
            case 1:
            {
                int sets, reps;
                Workout::getSetsAndReps("Pull-ups", sets, reps);
                Training training("Pull-ups", sets, reps);
                trainings.push_back(training);
            }    
                break;
            case 2:
            {
                int sets, reps;
                Workout::getSetsAndReps("Chin-ups", sets, reps);
                Training training("Chin-ups", sets, reps);
                trainings.push_back(training);
            }    
                break;
            case 3:
                return new PushUpsSubMenu(this, trainings);
            case 4:
            {
                int sets, reps;
                Workout::getSetsAndReps("Dips", sets, reps);
                Training training("Dips", sets, reps);
                trainings.push_back(training);
            }    
                break;
            case 5:
                return new CoreExercisesSubMenu(this, trainings);
            case 6:
                return new LegsExercisesSubMenu(this, trainings);
            case 7:
            {
                int sets, duration;
                Workout::getSetsAndDuration("Cardio", sets, duration);
                Training training("Cardio", sets, duration);
                trainings.push_back(training);
            }    
                break;               
            // Wybór '0' prosi o podanie przez użytkownika krótkiej notaki podsumuwującej, tworzy zmienną typu note, wczytuje tekst od użytkownika
            // następnie metoda klasy TextFileManager saveTrainingSession zapisuje obiekty przechowywane w wektorze trainings do pliku .txt
            // return nullptr zwraca pusty wskaźnik i tym kończy prace programu
            case 0:
              {
                std::cout << "Wprowadz notatke po treningu: ";
                std::string note;
                std::cin.ignore();
                std::getline(std::cin, note);
                TextFileManager::saveTrainingSession(trainings, note);
                std::cout << "Zamykanie programu..." << std::endl;
                return nullptr;
            }
            default:
                std::cout << "Nieprawidlowy wybor. Sprobuj ponownie." << std::endl;
        }
        // return this zwraca wskaźnik na bieżący obiekt (menu w którym obecnie znajduje się użytkownik)
        // gwarantuje to że po utworzeniu obiektu klasy trening i dodaniu go do wektora użytkownik pozostaje 
        // w bieżącym menu i może dokonać dodatkowych wyborów
        return this;
    }
};

#endif 