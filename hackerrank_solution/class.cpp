#include <iostream>
#include <sstream>
#include <string>
using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/

class Student {
private:
    int st_age;
    string st_first_name;
    string st_last_name;
    int st_standard;

public:
    Student() : st_age(0), st_standard(0) {

    }
    void set_age(const int age) {
        st_age = age;
    }

    void set_standard(const int standard) {
        st_standard = standard;
    }

    void set_first_name(const string& name) {
        st_first_name = name;
    }

    void set_last_name(const string& lastName) {
        st_last_name = lastName;
    }

    int get_age() {
        return st_age;
    }

    string get_last_name() {
        return st_last_name;
    }

    string get_first_name() {
        return st_first_name;
    }

    int get_standard() {
        return st_standard;
    }

    string to_string() {
        const string x = std::to_string(st_age);
        const string y = std::to_string(st_standard);
        const string s =  x + "," + st_first_name+","+st_last_name+"," + y;

        return s;
    }
};

int main() {
    int age, standard;
    string first_name, last_name;

    cin >> age >> first_name >> last_name >> standard;

    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);

    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();

    return 0;
}

//une autre methode de resolution du document 

#include <iostream>
#include <sstream>
using namespace std;

class Student{
    private:
    int age;
    string first_name;
    string last_name;
    int standard;
    public:
    int get_age() { return age;}
    void set_age(int age){ this->age = age;}
    string get_first_name(){ return first_name;}
    void set_first_name(string name) { this->first_name = name;}
    string get_last_name() { return last_name;}
    void set_last_name(string lastname) {this->last_name =lastname;}
    int get_standard() { return standard;}
    void set_standard(int standard) {this->standard =standard;}
    string to_string(){
        stringstream ss;
        ss<<age << ","<< first_name << ","<< last_name<< ","<< standard;
        return ss.str();
    }
};

int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
}
