#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>

#include "sort.h"


int ivector_length(int* v, int n)
{
  int sum;

  sum = 0;
  for (int i = 0; i < n; i++)
    sum += (v[i] < 0) ? -v[i] : v[i];

  return sum;
}

/*
 * insertion sort
 */
void insertion_sort(int** A, int n, int l, int r)
{ 
  int i;
  int* key;

  for (int j = l+1; j <= r; j++)
    {
      key = A[j];
      i = j - 1;

      while ((i >= l) && (ivector_length(A[i], n) > ivector_length(key, n)))
        {
	  A[i+1] = A[i];
	  i = i - 1;
	}

      A[i+1] = key;
    }
}

/*
*   TO IMPLEMENT: Improved Insertion Sort for problem 1.
*/
void insertion_sort_im(int** A, int n, int l, int r)
{ 
  int i =1;
  int key;
  //cout << " Running improved insertion sort algo" << endl;
  //cout << "A[i]" << ivector_length(A[0],n) << endl;
  //cout << "*Alen: " << ivector_length(*A,n) << endl;
 // cout << **A << endl;
  //calculate lengths of integer vector first
  

  //for (int i =1; i  < r; i++)
  for (int i =1; i<= r; i++){
    //key is some vector with length ivec_len(*A[i],n)
    key = ivector_length(A[i],n);
    //cout << "key" << key << endl;
    //cout << "*A: " << *A << endl;
    //cout << "A vectorlen: " << ivector_length(*A,n) << endl;
    int j = i-1;
    while( j>=l && ivector_length(A[j],n)> key){
      //swap
      A[j+1] = A[j];
      j = j-1;
    }
    *A[j+1] = key;

  }

  //cout << "Sorted? " << check_sorted(A,n, l, r) << endl;



}

/*
*   TO IMPLEMENT: Improved Merge Sort for problem 2.
*/
void merge_sort(int** A, int n, int p, int r)
{
  //check for base case
  if (r<1){
    return;
  }
  //cout << "ivector: " << ivector_length(*A, n)<< endl;
  //define length of left and right subarray
  int leftLen = ivector_length(*A,n)/2;
  int rightLen = ivector_length(*A,n)/2;
  //cout << "leftlen: " << leftLen << endl;
  // the new keyword allows for dynamic memory allocation and returns a pointer that points to the first element of allocated memory
  //define pointers that point to left and right subarrays
  //subarrays will store lengths of vectors in A[i]

  int** L = new int*[leftLen];  //int* L = new int[leftLen];
  int** R = new int*[rightLen];
  //split into left subarray
  for (int i =0; i<= leftLen-1;i ++){
    //L[i] = *A[n+i-1];
    *L[i] = ivector_length(A[i],n);
  }
  
  //split into right subarray
  for (int j = 0; j<= rightLen;j++){

    *R[j] = ivector_length(A[rightLen +j],n);
  }
  //assign sentenels
  *L[leftLen+1] = INFINITY;
  *R[rightLen+1] = INFINITY;
  int i, j = 1;

  //recursively sort subarrays
  merge_sort(L, n, p, r);
  merge_sort(R,n, p, r);

  //merge two subarrays together
  merge(A, L, R, r, leftLen, rightLen);


}

 void merge(int** A, int** L, int** R, int r, int leftLen, int rightLen){
  int i, j, k = 0;

  while( i< leftLen && j < rightLen){
    if (*L[i] < *R[j]){
      *A[k++] = *L[i++];

    }else {
      *A[k++] = *R[j++];
    }
  }

  //copy remaining items in L to A
  while(i< leftLen){
    *A[k++] = *L[i++];
  }
  
  //copy remaining itmes in R to A
  while(j<rightLen){
    *A[k++] = *R[j++];

  }



 }

/*
 * Simple function to check that our sorting algorithm did work
 * -> problem, if we find position, where the (i-1)-th element is 
 *    greater than the i-th element.
 */
bool check_sorted(int** A, int n, int l, int r)
{
  for (int i = l+1; i <= r; i++)
    if (ivector_length(A[i-1], n) > ivector_length(A[i], n))
      return false;
  return true;
}


/*
 * generate sorted/reverse/random arrays of type hw1type
 */
int** create_ivector(int n, int m)
{
  int** iv_array;

  iv_array = new int*[m];
  for (int i = 0; i < m; i++)
    iv_array[i] = new int[n];

  return iv_array;
}

void remove_ivector(int** iv_array, int m)
{
  for (int i = 0; i < m; i++)
    delete[] iv_array[i];
  delete[] iv_array;
}

int** create_sorted_ivector(int n, int m)
{
  int** iv_array;

  iv_array = create_ivector(n, m);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      iv_array[i][j] = (i+j)/n;

  return iv_array;
}

int** create_reverse_sorted_ivector(int n, int m)
{
  int** iv_array;

  iv_array = create_ivector(n, m);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      iv_array[i][j] = ((m-i)+j)/n;

  return iv_array;
}

int** create_random_ivector(int n, int m, bool small)
{
  random_generator rg;
  int** iv_array;

  iv_array = create_ivector(n, m);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      {
	rg >> iv_array[i][j];
	if (small)
	  iv_array[i][j] %= 100;
	else
	  iv_array[i][j] %= 65536;
      }

  return iv_array;
}

