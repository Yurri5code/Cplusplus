#include <iostream>
#include <vector>
#include "class_file.h"


void searchByAge(const std::vector<Persona*>& person,const int minAge,const int maxAge) {
    std::cout <<"\n the person of range of age : "<<minAge<<"->"<<maxAge<<std::endl;
    for(const auto& persons : person) {
        if(persons->calculateAge() >= minAge && persons->calculateAge() <= maxAge) {
            persons->showInfoPerson();
            std::cout <<"-----------------------------------------------------------------------\n";
        }
    }
}


int main() {
    // Persona *claude = new Candidat();
    // claude->getAllInfo();
    // claude->showInfoPerson();
    // Persona* student = new  Student();
    // student->getAllInfo();
    // // student->showInfoPerson();
    // Persona* teacher = new Teacher();
    // teacher->getAllInfo();
    // teacher->showInfoPerson();
    //
    // // delete claude;
    // // delete student;
    // delete teacher;
    std::cout <<"Put the number of candidat :";
    std::vector<Persona*> person;
    int nbr_candidat = 0;
    std::cin >>nbr_candidat;
    for(int i = 0;i < nbr_candidat;i++) {
        std::cout <<"please put the information of Candidate number "<<i+1<<" : "<<std::endl;
        person.push_back(new Candidat());
        person[i]->getAllInfo();
    }
    std::cout <<"Put the number of student :";
    int nbr_student = 0,j = 0;
    std::cin >>nbr_student;
    for(int i = nbr_candidat - 1;i < (nbr_student + nbr_candidat);i++) {
        std::cout <<"please put the information of Student number "<<j+1 <<" : "<<std::endl;
        person.push_back(new Student());
        person[i]->getAllInfo();
        j++;
    }
    std::cout <<"Put the number of teacher :";
    int nbr_teacher = 0;
    j = 0;
    std::cin >> nbr_teacher;
    for(int i = nbr_candidat+nbr_student - 1;i <  (nbr_candidat + nbr_student+ nbr_teacher);i++) {
        std::cout <<"please put the information of Candidate number "<<j+1<<" : "<<std::endl;
        person.push_back(new Teacher());
        person[i]->getAllInfo();
        j++;
    }
    int minAge = 0,maxAge = 0;
    std::cout<<"Enter the min Age :";
    std::cin >> minAge;
    std::cout <<"Enter the max Age :";
    std::cin >> maxAge;

    searchByAge(person,minAge,maxAge);

    for(auto & i : person) {
        delete i;
        i = nullptr;
    }
    return 0;
}
