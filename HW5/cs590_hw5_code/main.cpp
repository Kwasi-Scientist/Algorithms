#include "graph.h"
#include <iostream>
using namespace std;

int main()
{
    Graph *g = new Graph(10);

    g->set_edge(0, 1, 1);
    g->set_edge(0, 2, 1);
    g->set_edge(0, 3, 1);
    g->set_edge(1, 2, 1);
    g->set_edge(1, 5, 1);
    g->set_edge(3, 4, 1);
    g->set_edge(3, 7, 1);
    g->set_edge(4, 6, 1);
    g->set_edge(5, 7, 1);
    g->set_edge(8, 9, 1);

    //graph example from quetion 1 of HW
    Graph *g2 = new Graph(12);
    //set A(0) to D(3)
    g2 -> set_edge(0,3,1);
    //set D(3) to A(0)
    g2-> set_edge(3,0,1);
    //set D(3) to B(1)
    g2->set_edge(3,1,1);
    //setB(1) to D(3)
    g2->set_edge(1,3,1);
    //set B(1) to C(2)
    g2->set_edge(1,2,1);
    //setD(3) to E(4)
    g2->set_edge(3,4,1);
    //setE(4)toD(3)
    g2->set_edge(4,3,1);
    //set E(4) to C(2)
    g2->set_edge(4,2,1);
    //set E(4) to G(6)
    g2->set_edge(4,6,1);
    //setG(6) to H(7)
    g2->set_edge(6,7,1);
    //set H(7) to F(5)
    g2->set_edge(7,5,1);
    //set F(5) to I(8)
    g2->set_edge(5,8,1);
    //set I(8) to F(5)
    g2->set_edge(8,5,1);
    //setH(7) to I(8)
    g2->set_edge(7,8,1);
    //setH(7)to K(10)
    g2->set_edge(7,10,1);
    //set K(10) to G(6)
    g2->set_edge(10,6,1);
    //set K(10) to J(9)
    g2->set_edge(10,9,1);
    //set J(9) to L(11)
    g2->set_edge(9,11,1);
    //set L(11) to K(9)
    g2->set_edge(11,9,1);


    //graph3 example from textbook
    //unidirectional graph
    Graph *g3 = new Graph(8);
    //set V(4) to R(0)
    g3->set_edge(4,0,1);
    //setR(0) to V(4);
    g3->set_edge(0,4,1);
    //set r(0) to S(1)
    g3->set_edge(0,1,1);
    //set S(1) to R(0)
    g3->set_edge(1,0,1);
    //set S(1) to W(5)
    g3->set_edge(1,5,1);
    //set W(5) to S(1);
    g3->set_edge(5,1,1);
    //set W(5) to T(2)
    g3->set_edge(5,2,1);
    //set T(2) to W(5)
    g3->set_edge(5,2,1);
    //set W(5) to X(6)
    g3->set_edge(5,6,1);
    //setX(6) to W(5)
    g3->set_edge(6,5,1);
    //set T(2) to X(6)
    g3->set_edge(2,6,1);
    //setX(6) to T(2)
    g3->set_edge(6,2,1);
    //T(2) to U(3)
    g3->set_edge(2,3,1);
    //setU(3) to T(2)
    g3->set_edge(3,2,1);
    //set X(6) to U(3)
    g3->set_edge(6,3,1);
    //setU(3) to X(6)
    g3->set_edge(3,6,1);
    //set X(6) to Y(7)
    g3->set_edge(6,7,1);
    //set Y(7) to X(6)
    g3->set_edge(7,6,1);
    //set Y(7) to U (3)
    g3->set_edge(7,3,1);
    //set U(3) to Y(7)
    g3->set_edge(3,7,1);

    //graph 4 from DFS example
    Graph *g4 = new Graph(6);
    //set U(0) to V(1)
    g4->set_edge(0,1,1);
    //setU(0) to X(3)
    g4->set_edge(0,3,1);
    //set X(3) to V(1)
    g4->set_edge(3,1,1);
    //set V(1) to Y(4)
    g4->set_edge(1,4,1);
    //set Y(4) to X(3)
    g4->set_edge(4,3,1);
    //set W(2) to Y(4)
    g4->set_edge(2,4,1);
    //set W(2) to Z(5)
    g4->set_edge(2,5,1);
    //set Z(5) to Z(5)
    g4->set_edge(5,5,1);

    //graph 5 example for DFS
    Graph *g5 = new Graph(5);
    //set 0 to 1
    g5->set_edge(0,1,1);
    //set 1 to 0
    g5->set_edge(1,0,1);
    //set 0 to 3
    g5->set_edge(0,3,1);
    //set 3 to 0
    g5->set_edge(3,0,1);
    //set 0 to 2
    g5->set_edge(0,2,1);
    //set 2 to 0
    g5->set_edge(2,0,1);
    //set 2 to 4
    g5->set_edge(2,4,1);
    //set 4 to 2
    g5->set_edge(4,2,1);





    cout << "BFS output: " << endl;
    //check matrix
    //cout << g->matrix << endl;
    g->bfs(0);
    //test g3
    //g3->bfs(1);

    cout << endl;
    cout << "DFS output: " << endl;
    g->dfs();
    //test on g4
    //g4->dfs();
    //test g5
    //g4->dfs();
    //test g2 for Q1
    //g2->dfs();

    //delete g4;

    delete g;

    return 0;
} 
