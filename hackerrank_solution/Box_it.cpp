#include <iostream>

using namespace std;


class Box {
private:
    int l;
    int b;
    int h;

public:
    Box() {
        l = 0;
        b = 0;
        h = 0;
    }

    Box(const int& length, const int& breadth, const int& height) {
        l = length;
        b = breadth;
        h = height;
    }

    Box(const Box& copy) {
        l = copy.getLength();
        h = copy.getHeight();
        b = copy.getBreadth();
    }

    int getLength() const {
        return l;
    }

    int getBreadth() const {
        return b;
    }

    int getHeight() const {
        return h;
    }

    long long CalculateVolume() const {
        return static_cast<long long>(l)*b*h;
    }


    friend ostream& operator<<(ostream& out, const Box& box) {
        out << box.l << " " << box.b << " " << box.h ;
        return out;
    }


    bool operator<(const Box& other) const {
        if (l < other.l) return true;
        if (l == other.l && b < other.b) return true;
        if (l == other.l && b == other.b && h < other.h) return true;
        return false;
    }


};

void check2()
{
    int n;
    cin>>n;
    Box temp;
    for(int i=0;i<n;i++)
    {
        int type;
        cin>>type;
        if(type ==1)
        {
            cout<<temp<<endl;
        }
        if(type == 2)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            temp=NewBox;
            cout<<temp<<endl;
        }
        if(type==3)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            if(NewBox<temp)
            {
                cout<<"Lesser\n";
            }
            else
            {
                cout<<"Greater\n";
            }
        }
        if(type==4)
        {
            cout<<temp.CalculateVolume()<<endl;
        }
        if(type==5)
        {
            const Box& NewBox(temp);
            cout<<NewBox<<endl;
        }

    }
}

int main()
{
    check2();
}
