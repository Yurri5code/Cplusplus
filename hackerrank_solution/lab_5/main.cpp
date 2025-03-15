#include <iostream>
#include <string>
#include <limits>
#include "class_file.h"


int main() {
    // Persona me;
    // me.getAllInfo();
    // me.showInfoPerson();
    // Candidat claude;
    // claude.getInfoCandidat();
    // claude.showAllInfo();
    // Student claude;
    // claude.getInforStudent();
    // claude.showAllInfo();
    // Teacher claude;
    // claude.getAllInfo();
    // claude.showAllInfo();

    std::cout << "Put the number of persons: ";
    int n = 0;
    std::cin >> n;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::vector<Persona> persons(n);

    std::cout << "Put the information of " << n << " persons\n";
    for (int i = 0; i < n; ++i) {
        persons[i].getAllInfo();
    }

    std::cout << "Information of all " << n << " persons\n";
    for (const auto& person : persons) {
        person.showInfoPerson();
    }

    std::string personName;
    std::cout << "Put the name of the person to look for: ";
    std::getline(std::cin, personName);

    if (Persona::lookForPerson(persons, personName)) {
        std::cout << "The name is found\n";
    } else {
        std::cout << "The name is not found\n";
    }

    std::cout<<"let look for by age\n";
    std::cout <<"put the age :";
    int age(0);
    std::cin>>age;
    Persona::lookByAge(persons,age);
    return 0;
}
