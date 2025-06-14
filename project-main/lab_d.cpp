#include <iostream>

using namespace std;

int add (int a ,int b){
    return a +b ;
}
double add (double x , double y){
    return x + y;
}
int add (int a , int b , int c){
    return a + b + c ;
 }
int main()
{
    cout << add(3,4,5) << "\n";
    cout << add(3.14,3.14)<<"\n";
    cout << add (7,8)<< "\n";
    return 0;
}