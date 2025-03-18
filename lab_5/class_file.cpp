//
// Created by claude delcroix on 15/03/2025.
//

#include "class_file.h"
#include <iostream>
#include <limits>
#include <ctime>

Persona::Persona() {
    month = 0;
    years = 0;
    day = 0;
}


int Persona::calculateAge() const {
    // Получаем текущую дату
    const std::time_t t = std::time(nullptr);
    const std::tm* now = std::localtime(&t);

    const int currentYear = now->tm_year + 1900;
    const int currentMonth = now->tm_mon + 1;
    const int currentDay = now->tm_mday;

    int age = currentYear - years;
    if (currentMonth < month || (currentMonth == month && currentDay < day)) {
        age--;
    }
    return age;
}


//constructor Candidat
Candidat::Candidat() = default;


Candidat::Candidat(const std::string& nameC,const char genderC,const std::string& addressC,const std::string& facultyC,const int yearC,const int monthC,const int dayC) {
    name = nameC;
    gender = genderC;
    address = addressC;
    faculty = facultyC;
    day = dayC;
    month = monthC;
    years = yearC;
}

Candidat::Candidat(const Candidat &candidat)  : Persona(candidat) {
    name = candidat.name;
    gender = candidat.gender;
    address = candidat.address;
    faculty = candidat.faculty;
    day = candidat.day;
    month = candidat.month;
    years = candidat.years;
}

//entrer les informations du candidat
void Candidat::getAllInfo() {
    std::cout <<"Put your name :";
    std::getline(std::cin,name);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout <<"Your gender (m/f): ";
    std::cin >> gender;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout<<"Put your address : ";
    std::getline(std::cin,address);
    std::cout <<"Put your faculty : ";
    std::getline(std::cin,faculty);
    std::cout <<"enter your birthday \n";
    std::cout <<"Day :";
    std::cin >>day;
    std::cout <<"Month :";
    std::cin >>month;
    std::cout<<"Years :";
    std::cin>>years;
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}

void Candidat::showInfoPerson() {
    std::cout<<"Your name : "<<name<<std::endl;
    std::cout<<"Your age : "<<calculateAge()<<std::endl;
    std::cout<<"Your birthDay : "<<day<<"/"<<month<<"/"<<years<<std::endl;
    std::cout <<"Your gender : "<<gender<<std::endl;
    std::cout <<"Your address : "<<address<<std::endl;
    std::cout <<"Your faculty : "<<faculty<<std::endl;
}

Candidat::~Candidat() = default;


//la classe Student
Student::Student() {
    yearsClass = 0;
}

Student::Student(const std::string &nameC,const char genderC, const std::string &addressC,const std::string &facultyC,const int dayC,const int monthC,const int yearC, const int yearsCll) {
    name = nameC;
    gender = genderC;
    address = addressC;
    faculty = facultyC;
    day =dayC;
    month = monthC;
    years = yearC;
    yearsClass = yearsCll;
}

Student::Student(const Student &student) : Persona(student) {
    name = student.name;
    gender = student.gender;
    address = student.address;
    faculty = student.faculty;
    day = student.day;
    month = student.month;
    years = student.years;
    yearsClass = student.yearsClass;
}

void Student::getAllInfo() {
    std::cout <<"Put your name :";
    std::getline(std::cin,name);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout <<"Your gender (m/f): ";
    std::cin >> gender;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout<<"Put your address : ";
    std::getline(std::cin,address);
    std::cout <<"Put your faculty : ";
    std::getline(std::cin,faculty);
    std::cout <<"enter your birthday \n";
    std::cout <<"Day :";
    std::cin >>day;
    std::cout <<"Month :";
    std::cin >>month;
    std::cout<<"Years :";
    std::cin>>years;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout<<"Put your Faculty :";
    std::getline(std::cin,faculty);
    std::cout<<"Put your years of study  :";
    std::cin>>yearsClass;
}

void Student::showInfoPerson() {
    std::cout<<"Your name : "<<name<<std::endl;
    std::cout<<"Your age : "<<calculateAge()<<std::endl;
    std::cout<<"Your birthDay : "<<day<<"/"<<month<<"/"<<years<<std::endl;
    std::cout <<"Your gender : "<<gender<<std::endl;
    std::cout <<"Your address : "<<address<<std::endl;
    std::cout <<"Your faculty : "<<faculty<<std::endl;
    std::cout <<"Your years :"<<yearsClass<<std::endl;
}

//the class Teacher

Teacher::Teacher() {
    isInStage = false;
}

Teacher::Teacher(const std::string &nameC,const char genderC, const std::string &addressC,const std::string& facultyC,const std::string &functionC,const bool stage,const int dayC,const int monthC,const int yearC) {
    name = nameC;
    gender = genderC;
    address = addressC;
    faculty = facultyC;
    day = dayC;
    month = monthC;
    years = yearC;
    function = functionC;
    isInStage = stage;
}

void Teacher::getAllInfo() {
    std::cout <<"Put your name :";
    std::getline(std::cin,name);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout <<"Your gender (m/f): ";
    std::cin >> gender;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout<<"Put your address : ";
    std::getline(std::cin,address);
    std::cout <<"Put your faculty : ";
    std::getline(std::cin,faculty);
    std::cout <<"enter your birthday \n";
    std::cout <<"Day :";
    std::cin >>day;
    std::cout <<"Month :";
    std::cin >>month;
    std::cout<<"Years :";
    std::cin>>years;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout<<"Put your Faculty :";
    std::getline(std::cin,faculty);
    std::cout<<"Put your function  :";
    std::getline(std::cin,function);
    std::cout <<"Are you in stage :";
    std::cin >>std::boolalpha>>isInStage;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}

void Teacher::showInfoPerson() {
    std::cout<<"Your name : "<<name<<std::endl;
    std::cout<<"Your age : "<<calculateAge()<<std::endl;
    std::cout<<"Your birthDay : "<<day<<"/"<<month<<"/"<<years<<std::endl;
    std::cout <<"Your gender : "<<gender<<std::endl;
    std::cout <<"Your address : "<<address<<std::endl;
    std::cout <<"Your faculty : "<<faculty<<std::endl;
    std::cout <<"Your function : "<<function<<std::endl;
    if(isInStage == true) {
        std::cout<<"The teacher is in stage \n";
    }else {
        std::cout<<"The teacher is not in stage\n";
    }
}


