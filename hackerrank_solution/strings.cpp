#include <iostream>
#include <string>
using namespace std;

int main() {
	// Complete the program
    string first;
    string second;
    getline(cin,first);
    getline(cin,second);
    
    string third = first + second;
    cout << first.size()<<" "<<second.size()<<endl;
    
    cout<<third<<endl;
    char c = first[0];
    first[0] = second[0];
    second[0] = c;
    cout <<first <<" "<<second<<endl;
  
    return 0;
}
