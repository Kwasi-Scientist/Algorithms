#include <cstring>
#include <iostream>
#include <limits.h>
#include <algorithm>

#include "dynprog.h"

using namespace std;


/*
Questions and comments 
1.) is align x wokring? unable to pring "is diag" when Pnm is diag
2.) how should X and X' compare? How do we know output is correct?
3.) how to implement bottom up 
    -solving all subproblems and combining 
    -isolate subproblem solve multiple times
    
*/





/*
 * Bottom up implementation of Smith-Waterman algorithm
 */
void SW_bottomUp(char* X, char* Y, char** P, int** H, int n, int m){
    /*n is index for X string 
      m is index for Y string 
      H is the table that stores the point values
      P is the table that holds the direction
    */

   // must add memoized step
   //init p1 p2 p3 
   int p1;
   int p2;
   int p3;

   //init the diagonal, up, and left directions
//    const char* diag = "diag";
//    const char* up = "up";
//    const char* left = "left";
    char diag = 'd';
    char up = 'u';
    char left ='l';
   //char* diag_p = &diag;
   //char* up_p = &up;
   //char* left_p = &left;
	
   //iter in range n
   for (int i =0; i<=n;i++){
       //init H and i rows to zero
       H[i][0] = 0;
       P[i][0] = 0;
   }
   //iter through l
   for (int j = 0; j<=m;j++){
       //init j columns of H and P to zerp
       H[0][j] = 0;
       P[0][j] = 0;
   }
   //iter through i 
   for(int i=1; i<=n;i++){
       for(int j=1; j<=m;j++){
           //if x[i] == y[j]
           if (X[i] == Y[j]){
                p1 = H[i-1][j-1]+2;       
           } else {
                p1=H[i-1][j-1]-1; 
           }
           //set p2 p3 and H[i,j] to max
           p2 =H[i-1][j]-1;
           p3=H[i][j-1]-1;
           // if else chain to make sure p1 p2 p3 are not less than zero
        //    if (p1 < 0){
        //        p1 = 0;
        //    }
        //    if (p2 < 0){
        //        p2 = 0;
        //    }
        //    if (p3 < 0){
        //        p3 = 0;
        //    }
           H[i][j] = std::max({0,p1,p2,p3});
           //if h < 0 change h to zero
        //    if (H[i][j] < 0){
        //        //change to zerp
        //        H[i][j] = 0;
        //    }
           //test
           //cout << "H: max " << H[i][j] <<endl;
           if(H[i][j] == p1){
               P[i][j] == diag; // H[i-1][j-1]; //*diag;  //diagonal
               //test 
               //cout << "diag" << typeid(diag).name() == typeid(P[i][j]).name() << endl;
               //cout<< "p1" << p1 << endl;
               //cout << "P: " << P[i][j] << endl; 
           } else if (H[i][j]==p2) {
               P[i][j] = up; //H[i-1][j]; //*up; //up
               //cout << "P: " << P[i][j] << endl; 
           } else{
               P[i][j] = left;  // H[i][j-1];  //*left; //left
               //cout << "P: " << P[i][j] << endl; 
               /*here we have the dereferenced left_p
               which reads as 'the value pointed to by left_p ( which points to the memory adress of "left")
               */
           }
       }// end if
   }//end if 
  

   return;
   //return H, P;
}




//make a struct called direction to create pointers to the direction
//this way all functions have access

//  struct Direction{
//    const char* diag = "diag";
//    const char* up = "up";
//    const char* left = "left";
    
//  }




/*
 * Top-down with memoization implementation of Smith-Waterman algorithm
 */
void memoized_SW(char* X, char* Y, char** P, int** H, int n, int m){

    //start from botttom right and move outwirds
    //use examples from the lecture slides to make sure your code is working
    //top down should be a recurive call of the function
    //check if corner right values have been computed if not compute
    //set up base case
        // n = m =0



    /*n is index for X string 
      m is index for Y string 
      H is the table that stores the point values
      P is the table that holds the direction
    */
    //init p1 p2 p3
    int p1; 
    int p2;
    int p3;

    // cout << "n: " << n <<endl;
    // cout << "m: " << m << endl;
    // cout<<"Hnm: " <<H[n][m] << endl;

    //establish base case
    //Anytime n or m == 0 H[n][m] is 0
    //this will init the first row and colum to be zero
    if (n ==0 || m==0){
        H[n][m] == 0;
        return; 
    }

    if (H[n-1][m] == 0){
        memoized_SW(X, Y, P, H, n-1, m);
    }
    if (H[n][m-1]== 0){
        memoized_SW(X,Y,P, H, n, m-1);
    }
    if (H[n-1][m-1]){
        memoized_SW(X,Y,P,H,n-1,m-1);
    }

    //if x == y 
    //check if calculated vcalue in table
    if (X[n] == Y[m]){
        //if H[n][m] != null
        
        //check matrix to see if already calculated
        p1 = H[n-1][m-1] +2;
    } else {
            p1=H[n-1][m-1]-1; 
            }
         //set p2 p3 and H[i,j] to max
        p2 =H[n-1][m]-1;
        p3=H[n][m-1]-1;
        H[n][m] = std::max({0,p1,p2,p3});
    
 
    return;


}

/*
 * Auxilary recursive function of top-down with memoization implementation of Smith-Waterman algorithm
 */
void memoized_SW_AUX(char* X, char* Y, char** P, int** H, int n, int m){
    


	
}

/*
 * Print X'
 */
void print_Seq_Align_X(char* X, char** P, int n, int m){
//    const char* diag = "diag";
//    const char* up = "up";
//    const char* left = "left";

    //if n or m == 0 return
    if (n ==0 || m==0){
        return;
    }
    char diag = 'd';
    char up = 'u';
    char left ='l';
//    char* diag_p = &diag;
//    char* up_p = &up;
//    char* left_p = &left;
    //cout<< "*diag: " <<*diag <<endl;
    // cout << "n: " << n << endl;
    // cout << "m: " << m << endl;
    // cout << "pnm: " << P[n][m] <<endl;
    // cout << "Hnm: " << H[n][m] << endl;
   // cout<< "Xn: " << X[0] << endl;
    if (P[n][m] ==diag){
        print_Seq_Align_X(X, P, n-1, m-1);
        //cout << "is diag: " << endl;
        cout << X[n];
    } else if (P[n][m] ==left){//*left
        print_Seq_Align_X(X,P,n,m-1);
        cout <<"-";
    }else {
        print_Seq_Align_X(X,P,n-1,m);
        // program is crashing because ther eis no X[-1]
        //if n or m == 0 return
        //cout << " n: " << n << endl;
        cout<< X[n];
    }
    
    return;
	
}

/*
 * Print Y'
 */
void print_Seq_Align_Y(char* Y, char** P, int n, int m){
//    const char* diag = "diag";
//    const char* up = "up";
//    const char* left = "left";

    //if n or m== 0 return
    if( n==0 || m==0){
        return;
    }
    char diag = 'd';
    char up = 'u';
    char left ='l';
//    char* diag_p = &diag;
//    char* up_p = &up;
//    char* left_p = &left;
	if (P[n][m] ==diag){
        print_Seq_Align_Y(Y, P, n-1, m-1);
        cout << Y[n];
    } else if (P[n][m] == left){
        print_Seq_Align_Y(Y,P,n,m-1);
        cout <<"-";
    }else {
        print_Seq_Align_Y(Y,P,n-1,m);
        cout<< Y[n];
    }
    return;
}
