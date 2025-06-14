#include<iostream>
using namespace std ;
template <typename first, typename second >
void add (first a , second b){
    cout << a + b << "\n";
}
int main ()
{
    int a = 45;
    double b= 15.5 ;
    add(a,b);
    return 0;
      
}