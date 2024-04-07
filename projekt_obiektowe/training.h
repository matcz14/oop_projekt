#ifndef TRAINING_H
#define TRAINING_H

#include <iostream>

class Training {

private:
    std::string exercise;
    int sets;
    int reps_or_duration;

public:    
    // Konstruktor tworzący obiekty klasy Training, przyjmuje nazwę ćwiczenia, ilość serii oraz w zależności od typu ćwiczenia liczbę powtórzeń lub czas trwania serii
 Training(const std::string& exercise, int sets, int reps_or_duration)
        : exercise(exercise), sets(sets), reps_or_duration(reps_or_duration) {}
    // gettery
    std::string getExercise() const { return exercise; }
    int getSets() const { return sets; }
    int getRepsOrDuration() const { return reps_or_duration; }
    // Metoda do wpisywania obiektów klasy Training za pomocą strumienia wyjściowego, przeciążenie operatora '<<'
    // zapisuje nazwę ćwiczenia, ilość serii oraz liczbę powtórzeń bądź czas trwania
    friend std::ostream& operator<<(std::ostream& os, const Training& training) {
        os << "Cwiczenie: " << training.getExercise() << ", Sets: " << training.getSets() << " x ";
        os << (training.getExercise() == "Cardio" ? "Duration" : "Reps") << ": " << training.getRepsOrDuration() << std::endl;
        return os;
    }
};

#endif 