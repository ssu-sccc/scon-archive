#include "testlib.h"
#include <iostream>
 
using namespace std;
 
int main(int argc, char* argv[]){
   registerGen(argc, argv, 1);
   int a, b, max=500;
   
   do{
       a=rnd.next(0, max);
       b=rnd.next(0, max);
   }while((a+b)%3 != 0 && a+b>=3);
   //3의 배수가 될때까지 반복
   
   cout << a << ' ' << b << endl;
 
   return 0;
}