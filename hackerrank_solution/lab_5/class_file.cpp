//
// Created by claude delcroix on 08/03/2025.
//

#include "class_file.h"
#include <iostream>
#include <limits>
#include <string>

Persona::Persona() {
    age = 0;
    ID = 0;
    gender = '0';
}

Persona::Persona(const std::string& nameP,const int ageP,const char genderD,const std::string& roleP,const std::string& placeP,const std::string& dateBeginP,const int IDP) {
    name = nameP;
    age = ageP;
    gender = genderD;
    role = roleP;
    place = placeP;
    dateBegin = dateBeginP;
    ID = IDP;
}

int Persona::createID() const {
    return (age + gender)*1111;
}


void Persona::getAllInfo() {
    std::cout <<"Put your name :";
    std::getline(std::cin,name);
    std::cout << "Your age: ";
    std::cin >> age;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Your gender (m/f): ";
    std::cin >> gender;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout<<"your role in the work :";
    std::getline(std::cin,role);
    std::cout<<"your place of work :";
    std::getline(std::cin,place);
    std::cout<<"your date when you started working :";
    std::getline(std::cin,dateBegin);
    ID = createID();
    std::cout <<"your ID : "<<ID<<std::endl;
}

void Persona::showInfoPerson() const {
    std::cout <<"Your name : "<<name<<std::endl;
    std::cout<<"your age : "<<age<<std::endl;
    std::cout <<"your gender(m/f) : "<<gender<<std::endl;
    std::cout<<"your role in the work : "<<role<<std::endl;
    std::cout<<"your place of work : "<<place<<std::endl;
    std::cout<<"your date when you started working : "<<dateBegin<<std::endl;
    std::cout <<"your ID : "<<ID<<std::endl;
}


bool Persona::lookForPerson(const std::vector<Persona>& persons, const std::string& name) {
    for (const auto& person : persons) {
        if (person.name == name) {
            return true;
        }
    }
    return false;
}

void Persona::lookByAge(const std::vector<Persona> &persons, const int &age) {
    for(const auto& person : persons) {
        if(person.age == age) {
            std::cout<<"this name is founded : "<<person.name<<std::endl;
        }
    }
}



//here start information for Candidat
Candidat::Candidat() = default;

Candidat::Candidat(const std::string& nameC,const  std::string& dateBirth,const std::string& facultetC,const int ageC) {
    name = nameC;
    dateBirthDay = dateBirth;
    facultet = facultetC;
    age = ageC;
}

void Candidat::getInfoCandidat() {
    std::cout<<"put your name :";
    std::getline(std::cin,name);
    std::cout <<"put your birth day :";
    std::getline(std::cin,dateBirthDay);
    std::cout<<"put the name of your faculty :";
    std::getline(std::cin,facultet);
    std::cout<<"your name :";
    std::cin >>age;
}

void Candidat::showAllInfo() const {
    std::cout<<"Your name : "<<name<<std::endl;
    std::cout<<"Your birth day : "<<dateBirthDay<<std::endl;
    std::cout<<"the name of your faculty : "<<facultet<<std::endl;
    std::cout <<"your age : "<<age<<std::endl;
}

//classe Student
Student::Student() : year(0),age(0) {

}

Student::Student(const std::string &nameC, const std::string &dateBirth, const std::string &facultetS,const int yearS,const int ageC) {
    name = nameC;
    dateBirthDay = dateBirth;
    facultet = facultetS;
    year = yearS;
    age = ageC;
}

void Student::getInforStudent() {
    std::cout <<"Put your name :";
    std::getline(std::cin,name);
    std::cout<<"put your birth day :";
    std::getline(std::cin,dateBirthDay);
    std::cout<<"put your facultet :";
    std::getline(std::cin,facultet);
    std::cout<<"your course  : ";
    std::cin>>year;
    std::cout<<"your age";
    std::cin >> age;
}


void Student::showAllInfo() const {
    std::cout<<"your name : "<<name<<std::endl;
    std::cout<<"your birth day : "<<dateBirthDay<<std::endl;
    std::cout<<"your facultet : "<<facultet<<std::endl;
    std::cout<<"your course : "<<year;
    year == 1 ? std::cout<<" year"<<std::endl : std::cout<<" years"<<std::endl;
    std::cout <<"your age : "<<age<<std::endl;
}

Teacher::Teacher():stage(false),age(0) {

}

Teacher::Teacher(const std::string &nameT, const std::string &daybirth, const std::string &facultetT, const std::string &functionP, bool isStage, int ageT) {
    name = nameT;
    dayBirthDay = daybirth;
    facultet = facultetT;
    function = functionP;
    stage = isStage;
    age = ageT;
}

void Teacher::getAllInfo() {
    std::cout <<"Put your name :";
    std::getline(std::cin,name);
    std::cout<<"put your birth day :";
    std::getline(std::cin,dayBirthDay);
    std::cout<<"put your facultet :";
    std::getline(std::cin,facultet);
    std::cout <<"your function :";
    std::getline(std::cin,function);
    std::cout<<"are you in stage (true/false)  : ";
    ;
    std::cin >> std::boolalpha >> stage;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignorer le reste de la ligne

    std::cout << "Your age: ";
    std::cin >> age;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}

void Teacher::showAllInfo() const{
    std::cout<<"your name : Mister "<<name<<std::endl;
    std::cout<<"your birth day : "<<dayBirthDay<<std::endl;
    std::cout<<"your facultet : "<<facultet<<std::endl;
    std::cout<<"your function : "<<function<<std::endl;
    stage == true?std::cout<<"you are in stage\n":std::cout<<"you're not in stage \n";
    std::cout <<"your age : "<<age<<std::endl;
}


