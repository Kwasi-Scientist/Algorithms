
#include <iostream>
#include <cstdlib>
using namespace std; 

//implementing memoized fibonnaci function
//init list F which will save all fib values
int F[50];

void init_F(){
for (int i =0;i<50; i++){
    F[i] = -1;
}
}
//init all values in F to be -1

int dynamic_Fibonacci(int n){
    //base case
    if (F[n] <0){
        if (n ==0){
            F[n] == 0;
            //return 0;
    } else if (n ==1){
        F[n] == 1;
        //return 1;
    } else {
        F[n] = abs(dynamic_Fibonacci(n-1)) + abs(dynamic_Fibonacci(n-2));
        }
    }
    return F[n];
}

int main(){
    init_F();
    int f;
    f = dynamic_Fibonacci(15);
    std::cout << f<< std::endl;
    return 0; 
}