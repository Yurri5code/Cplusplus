//
// Created by claude delcroix on 15/03/2025.
//

#ifndef CLASS_FILE_H
#define CLASS_FILE_H
#include <string>



class Persona {
protected:
    std::string name;
    char gender{};
    std::string address;
    int years;
    int month;
    int day;

public:
    Persona();
    virtual ~Persona() = default;

    virtual  void getAllInfo() = 0;
    virtual void showInfoPerson() = 0;
    [[nodiscard]] int calculateAge() const;
};

class Candidat : public Persona {
protected:
    std::string faculty;

public:
    Candidat();
    Candidat(const std::string& nameC,char genderC,const std::string& addressC,const  std::string& facultyC,int yearC,int monthC,int dayC);
    Candidat(const Candidat& candidat);

    void getAllInfo() override;
    void showInfoPerson() override;
    ~Candidat() override;
};

class Student : public Persona {
protected:
    int yearsClass;
    std::string faculty;

public:
    Student();
    Student(const std::string& nameC,char genderC,const std::string& addressC,const  std::string& facultyC,int dayC,int monthC,int yearC,int yearsCll);
    Student(const Student& student);
    void getAllInfo() override;
    void showInfoPerson() override;
};

class Teacher : public Persona {
protected:
    std::string function;
    std::string faculty;
    bool isInStage;

public:
    Teacher();
    Teacher(const std::string& nameC,char genderC,const std::string& addressC,const  std::string& facultyC,const std::string & functionC,bool stage,int dayC,int monthC,int yearC);
    void getAllInfo() override;
    void showInfoPerson() override;
};

#endif //CLASS_FILE_H
