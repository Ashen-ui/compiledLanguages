#include <iostream>;
#include <string>;

int main() {
	std::string name;
	std::cout << "What's your name" << std::endl;
	std::cin >> name;

	std::cout << "Hi " << name << " !" << std::endl;

	int age = 19;

	std::cout << "You are " << age << " years old" << std::endl;
	
	return 0;
}
