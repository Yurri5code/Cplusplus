#include <iostream>
#include <set>

int main()
{
    int query{0};
    std::cin>>query;
    std::set<int> set_x;
    for(int i = 0;i < query;i++) {
        int x(0),y(0);
        std::cin>>x;
        std::cin>>y;
        if(x == 1) {
            set_x.insert(y);
        }else if(x == 2) {
            set_x.erase(y);
        }else {
            if(set_x.find(y) != set_x.end()) {
                std::cout<<"Yes\n";
            }else {
                std::cout<<"No\n";
            }
        }
    }
    return 0;
}
