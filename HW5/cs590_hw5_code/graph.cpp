#include <iostream>
#include <set>
#include <queue>

#include "graph.h"

using namespace std;

Graph::Graph(int nodes)
{
    this->nodes = nodes;
    this->matrix = new int*[nodes];
    //added edges to class
    //set edges
    //this->edges = NO_EDGE;
    int NO_EDGE = 0;
    for (int i = 0; i < nodes; ++i) {
        (this->matrix)[i] = new int[nodes];

        for (int j = 0; j < nodes; ++j) {
            (this->matrix)[i][j] = NO_EDGE;
        }
    }
}

Graph::Graph(int **matrix, int nodes) {
    this->nodes = nodes;
    this->matrix = new int*[nodes];

    for (int i = 0; i < nodes; ++i) {
        (this->matrix)[i] = new int[nodes];

        for (int j = 0; j < nodes; ++j) {
            (this->matrix)[i][j] = matrix[i][j];
        }
    }
}

Graph::~Graph()
{
    for (int i = 0; i < this->nodes; ++i) {
        delete[] (this->matrix)[i];
    }
    delete[] this->matrix;
}

bool Graph::set_edge(int i, int j, int edge)
{
    if (i < this->nodes && j < this->nodes && i >= 0 && j >= 0) {
        (this->matrix)[i][j] = edge;
        return true;
    }

    return false;
}

void Graph::dfs()
{
    //define set
    set<int> visited;
    //if color is white it is  NOT in set
    //consider starting from 0
    //int start = rand() % nodes; //random number from number of nodes
    int start = 0;
    //cout << "start" << start << endl;
    //for each vertex u e G.v
    
    //loop through all nodes and call dfs if node hasnt been discovered
    //for (int i =start; i<nodes;i++){
    for (int i =start; i<nodes;i++){
       for(int j=0; j< nodes;j++){
           //if there is an edge between i and j
           if( matrix[i][j]==1){
               //if u.color == white. if u not in visited
               if (visited.count(i)==0){
                   //call dfs-visit(G,u)
                   //visited.insert(i);
                   //cout << "i: " << i << "j: " << j<< endl;
                   dfs(i,visited);
               }
           }

        }
    }
    //source has been discovered
    //add source to visited and color gray
    //visited.insert(start);
    //dfs(start, visited);
}

void Graph::dfs(int start, set<int> &visited)
{
    //init queue gray
    //queue<int> Q;
    //change time
    //white vertex u has been discovered
    visited.insert(start);
    //cout << "nodes: " << nodes << endl;
    cout << "discovered: " << start << endl;
    for(int i =start;i<start+1; i++){
        for( int j=0;j<nodes; j++){
            if (Graph::matrix[i][j]==1){
                if (visited.count(j)==0){
                    //cout << "i: " << i << endl;
                    //cout << "front: " << visited.front() << endl;
                    //cout << "discovered: " << j << endl;
                    dfs(j,visited);
                }
            }
        }
    }
}
    

void Graph::bfs(int start)
{
    //define set 
    set<int> visited;
    //define que
    queue<int> Q;
    //define white and black que
    queue<int> gray;
    queue<int> black;
    //define u
    int u;
    //add source node to set
    // for (int i =0; i<visited.size; i++){
    //     visited[i] = start;
    // }
    visited.insert(start);
    //enqueue start
    Q.push(start);
    //print matrix to see
    // for (int i =0;i<nodes;i++){
    //     for (int j=0; j<nodes;j++){
    //         cout << "i: " << i<< "j: " << j<< "matrix:"<< Graph::matrix[i][j] << endl;
    //     }
    //     //cout << Graph::matrix[i]
    // }
   // cout << "matrix: " << Graph::matrix << endl;
   // cout << "nodes" << Graph::nodes << endl;
    while (!Q.empty()){
        //set u to dequeQ
        u = Q.front();
        //pop
        Q.pop();
        cout << "Discovered: " << u <<endl;
        //for each v in adjacency matrix 
        //for (int i =u;i<nodes;i ++){
        for (int i =u;i<u+1;i ++){
            for (int j=0; j< nodes;j++){
                //if matrix[i][j] ==1 then j is adjacent to i
                if (Graph::matrix[i][j]==1){
                    //if j not in set. if v.color is white. v.color = gray or add to gray que
                    if (visited.count(j) ==0){
                        //set color to gray
                        gray.push(j);
                        //enqueue v to q
                        Q.push(j); //change j to i
                        //cout << "pushed:" << j << endl;
                        //add to visited
                        visited.insert(j);
                        //cout << "discovered:" << j << endl;
                        //cout<< "next element in Q : " << Q.front() << endl;
                        //cout<< "last element in Q: " << Q.back() << endl;
                    } //end if

                } //end if
        
        
            }// end for
  
        }//end for
        //color node black
          //black.push(u);
       //     visited.insert(i);
       // cout <<"discovered: " << i << endl; 

    }


    
}
void Graph::bfs(int start, set<int> *visited)
{

}

