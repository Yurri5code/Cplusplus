//
// Created by claude delcroix on 08/03/2025.
//

#ifndef CLASS_FILE_H
#define CLASS_FILE_H
#include <string>
#include <vector>


class Persona {
private:
    std::string name;
    int age{};
    char gender{};
    std::string role;
    std::string place;
    std::string dateBegin;
    int ID{};

public:
    Persona();
    Persona(const std::string& nameP,int ageP,char genderD,const std::string& roleP,const std::string& placeP,const std::string& dateBeginP,int IDP);
    void getAllInfo();
    [[nodiscard]] int createID() const;
    void showInfoPerson() const;

    static bool lookForPerson(const std::vector<Persona>& persons, const std::string& name);
    static void lookByAge(const std::vector<Persona>& persons,const int& age);
};

class Candidat {
private:
    std::string name;
    std::string dateBirthDay;
    std::string facultet;
    int age = 0;
public:
    Candidat();
    Candidat(const std::string& nameC,const std::string& dateBirth,const std::string& facultetC,int ageC);
    void getInfoCandidat() ;
    void showAllInfo() const;
};

class Student {
private:
    std::string name;
    std::string dateBirthDay;
    std::string facultet;
    int year;
    int age;
public:
    Student();
    Student(const std::string& nameC,const std::string& dateBirth,const std::string& facultetS,int yearS,int ageC);
    void getInforStudent();
    void showAllInfo()const;
};


class Teacher {
private:
    std::string name;
    std::string dayBirthDay;
    std::string facultet;
    std::string function;
    bool stage;
    int age;
public:
    Teacher();
    Teacher(const std::string& nameT,const std::string& daybirth,const std::string& facultetT,const std::string &functionP,bool isStage,int ageT);
    void getAllInfo();
    void showAllInfo()const;
};

#endif //CLASS_FILE_H
