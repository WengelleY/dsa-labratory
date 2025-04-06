#include <iostream>
#include<string>
#define tax_rate 0.15
using namespace std;

int main()
{
    const float tax_const = 0.15;
    cout << "this program is designed to  analyze product sales and inventory for a store";
    cout << "this is reminder that c++ is a compiled language" << "\n";


   string products;
    int pro_cat;
    int  ini_inv ;
    float pro_pri;
    int item_sold;


    int ini_inv_new;





     cout << "enter a product name :" << "\n" ;

     cin >> products ;

     cout << "enter a product category :" << "\n" ;

     cin >> pro_cat ;

     if( pro_cat < 1 || pro_cat>5){
    cout<<"the number you have entered is not valid catagorey";
    return 1;

}


switch (pro_cat){
  case 1: cout << "category 1 electronics" << "\n";
  break;
  case 2 : cout <<"category 2 grocery" << "\n";
  break;
  case 3 : cout << "category 3 clothing"<< "\n";
  break;
  case 4 : cout<< "category 4 stationary"<< "\n";
  break;
  case 5 : cout << "category 5 miscellaneous"<< "\n";
  break;

  }



     cout << "enter an initial inventory quantity :" << "\n" ;

     cin >> ini_inv ;

     cout << "enter a product price :" << "\n" ;

     cin >> pro_pri ;

     cout << "enter numbers of item sold :" << "\n" ;

     cin >> item_sold ;

 int curr_inv {};
 float tot_Sale{};
     curr_inv = ini_inv - item_sold ;
      tot_Sale=item_sold*pro_pri;


     auto add_tot_sale = tot_Sale;
     decltype (ini_inv) add_ini_inv =ini_inv;





    string inv_stat{};
    inv_stat = (curr_inv < 10) ? "low inventory" : "sufficient";







    for(int i=1;i<=item_sold;i++){
         cout<< "item : " << i <<"\t" << pro_pri << "birr" <<  "\n";
    }

        cout << "pre processed tax rate =   " << tax_rate  << "\n";
        cout << "constant tax rate = " << tax_const  << "\n";
        cout << "product name =   " << products << "\n";
        cout << "product category  =  " << pro_cat <<  "\n";
        cout << "initial inventory  = " << ini_inv << "\n";
        cout << "product prices  =  " << pro_pri << "\n";
        cout << "items sold  =  " << item_sold <<  "\n";
        cout << "current inventory =  " << curr_inv <<  "\n";
        cout << "total sale  =  " << tot_Sale << "\n";
        cout << "inventory status  =  " << inv_stat << "\n";

        cout << "copy of total sale   = " << add_tot_sale <<  "\n";
        cout << "copy of initial inventory    =  "<<add_ini_inv <<  "\n";








    return 0;

}
