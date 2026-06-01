#include <iostream>
#include <string>
#include <iomanip>

int main() {
    std::string name;
    int age;
    float grade;

    std::cout << "What is your name ?" << std::endl;
    std::cin >> name;

    std::cout << "How old are you ?" << std::endl;
    std::cin >> age;

    std::cout << "What's your average grade ? (floatpoint)" << std::endl;
    std::cin >> grade;

    std::cout << "Hello " << name
              << ", you're " << age
              << " years old and your average grade of "
              << std::fixed << std::setprecision(2) << grade
              << " will be used for ai training ! be happy before the end !"
              << std::endl;

    return 0;
}