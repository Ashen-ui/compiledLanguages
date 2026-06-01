#include <iostream>
#include <iomanip>
#include <limits>

struct Student {
    std::string name;
    int age;
    double average;

    void display() const {
        std::cout << "  Name    : " << name << "\n";
        std::cout << "  Age     : " << age;
        if (age >= 18) {
            std::cout << " (adult)";
        } else {
            std::cout << " (minor)";
        }
        std::cout << "\n";
        std::cout << "  Average : " << std::fixed << std::setprecision(2)
                  << average << "/20\n";
    }
};

int readInt(const char* prompt, int min, int max) {
    int val;
    std::cout << prompt;
    while (!(std::cin >> val) || val < min || val > max) {
        std::cout << "Wrong, try again: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    return val;
}

double readDouble(const char* prompt, double min, double max) {
    double val;
    std::cout << prompt;
    while (!(std::cin >> val) || val < min || val > max) {
        std::cout << "Wrong, try again: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    return val;
}

int main() {
    const int N = 5;
    Student stu[N];

    for (int i = 0; i < N; i++) {
        std::cout << "\nStudent " << i + 1 << "\n";
        std::cout << "Name    : ";
        std::cin >> stu[i].name;
        stu[i].age     = readInt("Age     : ", 0, 150);
        stu[i].average = readDouble("Average : ", 0.0, 20.0);
    }

    std::cout << "\n List of students\n";
    double total = 0;
    for (int i = 0; i < N; i++) {
        std::cout << "\nStudent " << i + 1 << ":\n";
        stu[i].display();
        total += stu[i].average;
    }

    std::cout << "\n Promotion Average\n  "
              << std::fixed << std::setprecision(2) << total / N << "/20\n";

    int best = 0;
    for (int i = 1; i < N; i++) {
        if (stu[i].average > stu[best].average) {
            best = i;
        }
    }
    std::cout << "\nBest Student\n";
    stu[best].display();

    return 0;
}