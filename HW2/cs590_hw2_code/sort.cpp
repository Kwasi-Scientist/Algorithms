#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

#include "sort.h"

/* 
 * HW 2 part
 */
int string_compare(char* s1, char *s2)
{ 
/*
 * We assume that s1 and s2 are non-null pointers
 */
  int i;

  i = 0;
  while ((s1[i] != 0) && (s2[i] != 0) && (s1[i] == s2[i]))
    i++;

  if (s1[i] == s2[i])
    return 0;
  else
    {
      if (s1[i] < s2[i])
	return -1;
      else
	return 1;
    }
} /*>>>*/

void insertion_sort(char** A, int l, int r)
{ 
  int i;
  char* key;

  for (int j = l+1; j <= r; j++)
    {
      key = A[j];
      i = j - 1;

      while ((i >= l) && (string_compare(A[i], key) > 0))
        {
	  A[i+1] = A[i];
	  i = i - 1;
	}

      A[i+1] = key;
    }
}

void insertion_sort_digit(char** A, int* A_len, int l, int r, int d)
{
  //sort by the character at position d
  //find len of each string as A_len to ensure position d exists
  int i;
  char* key;
  
  
  int key_len;

  char Aid;
  char k_d;
  for(int j =l+1; j<=r; j++){
    key = A[j];     // a string within the char array
      //the dth char of char A[j]
    key_len = A_len[j];  //len of A[j]

    //std::cout << "key[d]: " << key[d] << " " <<  "Alen: " << A_len[j] << std::endl;    
    //std::cout << "compare K_d: " << string_compare(&A[j+1][d],key_d) << std::endl;
    

    //update i
    i = j-1;    // &&(string_compare(A[j][d],key_d)>0)
    Aid = (A_len[i]<d)?0:A[i][d];
    //find if len of A[i] <d and set to 0 if true otherwise leave it alone
    k_d  =(key_len<d)? 0:key[d];
    // if (A_len[i]<d){
    //   key[d] = 0;
    // } else {
    //   key[d] = key[d];
    // }
    
    //std::cout << "A[i]: " << A[i] << std::endl;
    //&&(string_compare(A[i][d],key_d)>0)
    //while((i>=l) && (string_compare(A[i],key)>0) ){
    while((i>=l) && (Aid > k_d) ){
      //update A_len

      A_len[i+1] = A_len[i];

      //swap
      A[i+1] = A[i];
      i= i-1;

      if (i >=l){
        Aid = (A_len[i]<d)?0:A[i][d];
      }
      
      
     // if(A_len[j] <d )
    }
    //update A_len
    A_len[i+1] = key_len;

    A[i+1]=key;

  }
  //std::cout << "sorted?: " << check_sorted(A, l, r) << std::endl;
}

void counting_sort_digit(char** A, int* A_len, char** B, int* B_len, int n, int d)
{
  //create new array C
  int C[256];
  //C = new char* [n];
  for (int i =0; i< 256;i++){
    C[i] = 0;
    //check c
    //std::cout << "C[i]: " << C[i] << std::endl;
  }
  
  for (int j =0; j< n;j++){
    if(A_len[j]>=d){
      //update c
      C[A[j][d]] = C[A[j][d]]+1 ;
    } else {
      C[0] = C[0]+1;
    }

    
    //Check
    //std::cout<< "C[A[j]]" << C[*A[j]] << std::endl;
  } //c[i] now contains the number of elements equal to i
  for(int i=0;i<256;i++){
    C[i] = C[i] + C[i-1];
  } //C[i] now contains the number of elements less than or equal to i
  for (int j=n-1; j>=0;j--){
    //if the length of B[]
    //std::cout << "Blen" << B_len[j] << std::endl;
    if(B_len[j]>=d){
     // std::cout << "B_len: " << B_len[j] << std::endl;
     //std::cout << "a[j][d] " << A[j][d] << std::endl;
     //std::cout << "c[a[j][d] " << C[A[j][d]] << std::endl;
     //update blen
     B_len[C[A[j][d]]-1] = A_len[j];
     //std::cout <<"B_len" << B_len[j] << std::endl;
     B[C[A[j][d]]-1] = A[j];
    
      //decrement c value
      C[A[j][d]] = C[A[j][d]]-1;
    } 
    
    
  }
  //std::cout << "B end: " << B << std::endl;
  
}

void radix_sort_is(char** A, int* A_len, int n, int m)
{ 
  for (int i=m-1; i>=0; i--){
    //insertion_sort(A, i, m);
    insertion_sort_digit(A,A_len,0, n-1, i);

  }

}

void radix_sort_cs(char** A, int* A_len, int n, int m)
{ 
  char** B;
  int* B_len;
  B = new char* [n];
  B_len = new int[n];
  char** tempA;
  char** tempB;
  int* tempA_len;
  int* tempB_len;
  tempA = A;
  tempB= B;
  tempA_len = A_len;
  tempB_len = B_len;

  for (int i=m-1;i>=0; i--){
    //counting_sort_digit(tempA, tempA_len, tempB, tempB_len, n, i);
    counting_sort_digit(tempA, tempA_len, tempB, tempB_len, n-1, i);
  }

}

/*
 * Simple function to check that our sorting algorithm did work
 * -> problem, if we find position, where the (i-1)-th element is 
 *    greater than the i-th element.
 */
bool check_sorted(char** A, int l, int r)
{
  for (int i = l+1; i < r; i++)
    if (string_compare(A[i-1],A[i]) > 0)
      return false;
  return true;
}
