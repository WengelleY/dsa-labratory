#include <iostream>
using namespace std;
 struct student {
    string name ;
    string id ;
    int class_ ;
};
int main()
{
    student pl;
    pl.name = "abebe";
    pl.class_= 3;
    pl.id = "ugr/2244/4356";
    cout << pl.name << "\n";
    cout << pl.class_ << "\n";
    cout << pl.id << "\n";


    return 0;
}

