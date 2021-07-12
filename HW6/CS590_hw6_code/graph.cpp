#include "graph.h"
#include <list>
#include <iostream>
#include <limits.h>
#include <algorithm>
#include <cmath>

using namespace std;

/*
 * constructor/destructor
 */
graph::graph(int n)
{ /*<<<*/
  no_vert = (n > 0) ? n : 1;

/*
 * allocate adjacency matrix
 */
  m_edge = new int*[no_vert];
  for (int i = 0; i < no_vert; i++)
    m_edge[i] = new int[no_vert];

  initialize();
} /*>>>*/

graph::~graph()
{ /*<<<*/ 
/*
 * delete nil element and all other allocated nodes
 */
  for (int i = 0; i < no_vert; i++)
    delete[] m_edge[i];
  delete[] m_edge;
} /*>>>*/


void graph::initialize()
{ /*<<<*/
/*
 * initialize adjacency matrix
 * -> use infinity to allow 0 weight edges
 */
  for (int i = 0; i < no_vert; i++)
    for (int j = 0; j < no_vert; j++)
      m_edge[i][j] = INT_MAX;

} /*>>>*/

void graph::permutation(int* perm, int n)
{ /*<<<*/
  random_generator rg;
  int p_tmp, p_pos;

  for (int i = 0; i < n; i++)
    perm[i] = i;
  
  for (int i = 0; i < n; i++)
    {
      rg >> p_pos;
      p_pos = (p_pos % (n - i)) + i;

      p_tmp = perm[i];
      perm[i] = perm[p_pos];
      perm[p_pos] = p_tmp;
    }
} /*>>>*/

void graph::output(int** m_out, int** m_out_2)
{ /*<<<*/
  if (!m_out)
    m_out = m_edge;

  cout << "[";
  for (int i = 0; i < no_vert; i++)
    {
      cout << "[\t";
      for (int j = 0; j < no_vert; j++)
  if (m_out[i][j] == INT_MAX)
    cout << "inf\t";
  else
    cout << m_out[i][j] << "\t";

      if (m_out_2)
  {
    cout << "]\t\t[\t";
    for (int j = 0; j < no_vert; j++)
      if (m_out_2[i][j] == INT_MAX)
        cout << "inf\t";
      else
        cout << m_out_2[i][j] << "\t";
  }

      cout << "]" << endl;
    }
  cout << "]" << endl;
} /*>>>*/


// TODO: Implement problem 1
void graph::generate_random(int n_edges, int max_weight)
{

    

  cout << "no_vert: " << no_vert << endl;
  cout << "n_edges: " << n_edges << endl;
  cout << "max weight: " << max_weight << endl;
  //init permutation weight
  //int* perm_w = new int[max_weight];
  //initialize perm_w
  // for (int i=0;i<max_weight; i++){
  //   perm_w[i] = i;
  // }
  int rand_weight = -max_weight + rand() % (max_weight - (-max_weight) +1); // rand() % 2*max_weight - max_weight;
  cout << "rand_weight" << rand_weight << endl;

    //make permuations of weight 
  //std::shuffle(-max_weight,max_weight,perm_w);
  
 
  //this line crashes
  //permutation(perm_w, max_weight);
  //create random perm of weights
  
  // for ( int i=0; i<no_vert;i++){
  //   cout << "m L" << m_edge[i];
  // }

  
  //number of disticnt paths = ceiling number_edges/ max length
  int n_passes = no_vert-1;
  int n_paths = ceil(n_edges/ n_passes);
  //init perm_vert
  int* perm_vert = new int[no_vert];
  //initialize perm_vert array
  for (int i=0; i< no_vert;i++){
    perm_vert[i] = i;
  }
  
  int**temp = new int*[no_vert];
  for (int i =0; i<no_vert;i++){
    temp[i] = new int[no_vert];
  }
 

   //set diagonals to zero

   for (int i=0;i< no_vert;i++){
    for (int j=0; j<no_vert;j++){
      if (i==j){
        m_edge[i][j] = 0;
      }
    }
  }


    int count = 0;

    for (int i=0; i<=n_paths; i++) {

        //init temp to zero
        for (int i=0; i < no_vert; i++) {
            for (int j=0; j < no_vert; j++) {
                temp[i][j] = 0;
            }
        }
        std::random_shuffle(perm_vert, perm_vert +no_vert);

        for (int i=0; i < n_passes; i++) {
            if (m_edge[perm_vert[i]][perm_vert[i + 1]] == 1) {
              //cout << "m_edge: " << m_edge[perm_vert[i]][perm_vert[i+1]] <<endl;
                count;
            }
            else {
                if (count < n_edges) {
                    temp[perm_vert[i]][perm_vert[i + 1]] = -max_weight + rand() % (max_weight - (-max_weight) +1); // random weight//1;
                    //cout << "temp[i][j]" << temp[perm_vert[i]][perm_vert[i+1]] << endl;
                    count++;
                }
            }
        }

      //copy from temp to m_edge
    for (int i = 0; i<no_vert; i++){
      for (int j=0; j<no_vert;j++){
        if (temp[i][j]!=0){
          m_edge[i][j] = temp[i][j];
        }
      }
    } 
  }

    //see what's in m_edge
    // for (int i=0;i<no_vert;i++){
    //   for(int j=0;j<no_vert;j++){
    //     //cout << "temp" << temp[i][j] << endl;
    //   }
    // }
    // for (int j= 0; j<no_vert -1; j++){
      //create new random path with 
      //cout << "perm_vert i: " << perm_vert[i] << endl;
      //cout << " vert j: " << perm_vert[j] << endl;
      //stack exchage for 

      //if edge already in m_edge do nothing
      // if not then augment 
        //counter++

    //    m_edge[perm_vert[i]][perm_vert[j]] = 1 ;// ;

    //    //
    // }

  




    }
    //std::random_shuffle(perm_w,perm_w +max_weight);
    
    //permutation(perm_vert, perm_vert);
    //make random weight valued paths 
    // for (int i=0; i<no_vert; i++){
    //   for (int j=0; j< no_vert; j++){
    //     if (temp[i][j] ==0){
    //       //do nothing 
    //       tem
    //     }
    //     temp[i][j] = perm_w[i];
    //     cout << "temp_permw: " << temp[i][j] << endl;
    //   }
    // }
    

    //}




  




// TODO: Implement problem 3
bool graph::bellman_ford(int s, int*& v_d, int*& v_pi)
{
  //init u_d
  int* u_d = new int[no_vert];
  //initialize u_d
  for(int i =0; i<no_vert; i++){
    u_d[i] = i;
  }

  int max, min;
  max = INT_MAX;
  min = INT_MIN;
  //initialize single source(G,s)
  for (int i =s; i<no_vert;i++){
    //set v_d to max int/infinity
    //cout << "v_d[i]: " << v_d[i] << endl;
    v_d[i] = max; //INT_MAX;
    //set v_pi to nill
    v_pi[i] = 0; //NILL;
    //set v_d[s] to 0
    v_d[s] = 0;
    //set u_d to 0
    //u_d[i] = 0;
  }
 

  for (int i=1;i<no_vert-1;i++){
    for( int j=0; j<no_vert;j++){
      //for each edge (u, v)
      //int u_d = 0;
      int w = m_edge[s][j];
      
      //relax
      //if v.d > u.d +w(u,v)
      //if (v_d[i] > u_d[i] + w){
      //if v_d[i] !- int_max && ...
      if (v_d[j] > v_d[s] + w) {
        //update v_d
       // v_d[i] = u_d[i] + w;
        v_d[j] = v_d[s] + w; 
        v_pi[j] = s; //j
      }
    }
  }

  //for each edge (u, v) G.E
  for (int i=0; i<no_vert; i++){
    //for (int j=0; j<no_vert; j++){
      //if v.d > u.d +w(u,v)
      int w = m_edge[s][i];
      // cout << "w: " << w << endl;
      // cout << "v_d[i]: " << v_d[i] << endl;
      // cout << "v_d[s]: " << v_d[s] << endl;
      //cout << "vd[j]: " << v_d[j] << endl;
      //if(v_d[i]>u_d[i] +w)
      if (v_d[i] > v_d[s] + w){
        return false;
      }
    //}
  }

  //returns true if no negative weight cycles
  return true;
}

// TODO: Implement problem 4
void graph::floyd_warshall(int**& d, int**& pi)
{

  //must generate no_vert n x n matrcies


  // n = W.rows is just no_vert
  //D0 =wij; when k=0
  //init big D(0) = W an nxn matrix
  // int** D = new int[no_vert];
  // for (int i =0;i<no_vert; i++){
  //   D[i] = new int[no_vert];
  // }

  //copy m_edge to d
  for (int i = 0; i<no_vert; i++){
    for (int j=0; j<no_vert; j++){
      // if (i==j){
      //   d[i][j] = 0;
      // }
      d[i][j] = m_edge[i][j];
    }
  }


  //see whats in d matrix
  for (int k=1; k<no_vert;k++){
    //the following two for loops generate each of the k matricies
    //let D(k) = dij(k) be a new n x n matrix
    for (int i=1; i<no_vert; i++){
      for (int j=1; j<no_vert;j++){
        //dij(j) = min (dij(k-1), dik(k-1), dkj(k-1))
        d[i][j] =std::min(d[i][j],(d[i][k]+d[k][j]));
      }
    }
  }

  // for (int i=0; i<no_vert; i++){
  //   for(int j=0; j<no_vert; j++){
  //     cout << "d: " << d[i][j] << endl;
  //   }
  // }

}
