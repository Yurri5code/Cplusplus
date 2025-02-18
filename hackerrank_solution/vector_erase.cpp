#include <iostream>
#include <vector>

int main() {
    size_t t(0);
    std::cin>>t;
    std::vector <int> array(t,0);
    for(int i = 0;i<t;i++) {
        std::cin>>array[i];
    }
    //create the variable for x
    int x(0),pos_x = 0;
    std::cin>>x;
    //erase the value of x
    array.erase(array.begin()+(x-1));
    //create the variables a et b
    int a(0),b(0);
    std::cin >> a>>b;
    //erase the value from a to b
    if (a >= 0 && b >= a && b <= array.size()) {
        array.erase(array.begin() + (a-1), array.begin() + (b -1));
    }
    t = array.size();
    std::cout <<"size = "<<t;
    for(int i = 0;i < t;i++) {
        std::cout << "arr["<<i+1<<"] = "<<array[i]<<std::endl;
    }
    return 0;
}
