#include <iostream>
#include <cmath>
using namespace std ;
 

namespace old {
    void print (double number)
    { 
        cout << "you have enetered " << number << "\n";
    }

}

namespace up  {
    void print (double number){
        cout << "your rounded number " << round (number) << "\n";
    }
}
int main (){
    old::print (89.98);
    up::print (89.98);
    return 0;
}


