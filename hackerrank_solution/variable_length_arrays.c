#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int rows(0),q(0);
    cin >>rows>>q;
    
    int** array = new int*[rows];
    for(int i = 0;i < rows;i++){
        int k(0);
        cin>>k;
        array[i] = new int[k];
        for(int j = 0;j < k;j++){
            cin >> array[i][j];
        }
    }
    
    int rowA = 0,colA = 0;
    
    for(int i = 0;i < q;i++){
        cin >> rowA>>colA;
        cout << array[rowA][colA]<<endl;
    }
    
    delete[]array;
    
    return 0;
}
