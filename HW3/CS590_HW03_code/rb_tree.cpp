
#include "rb_tree.h"
#include <list>
#include <iostream>
#include <vector>
#include <stack>
#include <array>

using namespace std;

/*
 * constructor/destructor
 */
rb_tree::rb_tree()
{ /*<<<*/
/*
 * create T_nil element
 */
  T_nil = new rb_tree_node();
  T_nil->color = RB_BLACK;
  T_nil->p = T_nil;
  T_nil->left = T_nil;
  T_nil->right = T_nil;

/*
 * root of rb tree
 */
  T_root = T_nil;
} /*>>>*/

rb_tree::~rb_tree()
{ /*<<<*/ 
/*
 * delete nil element and all other allocated nodes
 */
  remove_all(T_root);

  delete T_nil;
} /*>>>*/

rb_tree_node* rb_tree::tree_search(rb_tree_node* x, int key){
  // if tree is emptu or key is trenode->key return true 
  if (x ==T_nil || key == x->key){
    return x;
  }
  if (key < x->key){
    return tree_search(x->left, key);
  } else {
    return tree_search(x->right, key);
  }
  
}
void rb_tree::insert(int key, rb_tree_i_info& t_info)
{ /*<<<*/
/*
 * wrapper around insert
 * -> creates black node with key
 * -> inserts node
 */
  rb_tree_node* z;

  z = new rb_tree_node;
  z->color = RB_BLACK;
  z->key = key;
  z->right = T_nil;
  z->left = T_nil;
  z->p = T_nil;

  //insert(z, t_info);

  rb_tree_node* temp;
  //check if key already in tree
  //if tree_search returns T_nil element is not there so insert
  temp = tree_search(T_root, key);
  if (temp ==T_nil){
    //key not there insert
    //cout<< "inserting key..." << endl;
    insert(z,t_info);
  }else {
    //there is a duplicate
    //cout << "key is in tree" << endl;
    t_info.i_duplicate++;
    return;
  }

  //inorder_output(T_root, 0);


} /*>>>*/

void rb_tree::insert(rb_tree_node* z, rb_tree_i_info& t_info)
{ /*<<<*/
/*
 * binary tree type insert 
 * -> search position, insert new node
 * -> fix properties after insert
 */
  rb_tree_node* x;
  rb_tree_node* y;

  y = T_nil;
  x = T_root;
  while (x != T_nil)
    {
      y = x;

      if (z->key < x->key)
	x = x->left;
      else
	x = x->right;
    }

  z->p = y;
  if (y == T_nil)
    T_root = z;
  else
    {
      if (z->key < y->key)
	y->left = z;
      else
	y->right = z;
    }

  z->left = T_nil;
  z->right = T_nil;
  z->color = RB_RED;

/*
 * after binary tree type insert we need to fix RB tree properties
 * -> update the info file
 */
  insert_fixup(z, t_info);
} /*>>>*/

void rb_tree::insert_fixup(rb_tree_node*& z, rb_tree_i_info& t_info)
{ /*<<<*/
/*
 * fix RB tree properties, after inserting a node
 * -> see book/slides for details on the cases
 */
  rb_tree_node* y;

  while (z->p->color == RB_RED)
    {
      if (z->p == z->p->p->left)
	{
	  y = z->p->p->right;

	  if (y->color == RB_RED)
	    {
	      z->p->color = RB_BLACK;		// Case 1
	      y->color = RB_BLACK;
	      z->p->p->color = RB_RED;
	      z = z->p->p;
	    }
	  else
	    {
	      if (z == z->p->right)
		{
		  z = z->p;			// Case 2
		  left_rotate(z);
      //increment leftrotate counter
      t_info.i_left_rotate++;
		} 

	      z->p->color = RB_BLACK;		// Case 3
	      z->p->p->color = RB_RED;
	      right_rotate(z->p->p);
        //increment right rotate
        t_info.i_right_rotate++;
	    }
	}
      else
	{

	  y = z->p->p->left;

	  if (y->color == RB_RED)
	    {
	      z->p->color = RB_BLACK;		// Case 1
	      y->color = RB_BLACK;
	      z->p->p->color = RB_RED;
	      z = z->p->p;
        //increment case 1
        t_info.i_case_1++;
	    }
	  else
	    {
	      if (z == z->p->left)
		{
		  z = z->p;			// Case 2
		  right_rotate(z);
      //increment right rotate
      t_info.i_right_rotate++;
      //increment case 1
      t_info.i_case_2++;

		}

	      z->p->color = RB_BLACK;		// Case 3
	      z->p->p->color = RB_RED;
	      left_rotate(z->p->p);
        //increment left rotate
        t_info.i_left_rotate++;
        //increment case 3
        t_info.i_case_3++;
	    }
	}
    }

  T_root->color = RB_BLACK;
} /*>>>*/


void rb_tree::left_rotate(rb_tree_node* x)
{ /*<<<*/
/*
 * rotate left -> see book/slides
 */
  rb_tree_node* y;

  y = x->right;			// set y
  x->right = y->left;		// turn y's left subtree into x's right subtree
  if (y->left != T_nil)
    y->left->p = x;

  y->p = x->p;			// link x's parent to y
  if (x->p == T_nil)
    T_root = y;
  else
    {
      if (x == x->p->left)
	x->p->left = y;
      else
	x->p->right = y;
    }

  y->left = x;			// put x on y's left
  x->p = y;
} /*>>>*/

void rb_tree::right_rotate(rb_tree_node* x)
{ /*<<<*/
/*
 * rotate right -> see book/slides
 */
  rb_tree_node* y;

  y = x->left;			// set y
  x->left = y->right;		// turn y's right subtree into x's left subtree
  if (y->right != T_nil)
    y->right->p = x;

  y->p = x->p;			// link x's parent to y
  if (x->p == T_nil)
    T_root = y;
  else
    {
      if (x == x->p->right)
	x->p->right = y;
      else
	x->p->left = y;
    }

  y->right = x;			// put x on y's right
  x->p = y;
} /*>>>*/

void rb_tree::inorder_output(rb_tree_node* x, int level)
{ /*<<<*/
/*
 * in order walk through binary tree
 * -> see book or slides
 */
  //create temp stack to hold keys in reverse order
  // stack<int> temp;
  // vector<int> color;
  // vector<int> order;
  //int order [100];
  if (x != T_nil)
    {
      // if(x->color == RB_BLACK){
      //   color.push_back(1);
      // } else {
      //   color.push_back(0);
      // }
      //order.push_back(x->key);
      inorder_output(x->left, level+1);
      cout << "(" << x->key << "," << level << "," 
	   << ((x->color == RB_RED) ? "R" : "B") << ")" << endl;
      inorder_output(x->right, level+1); 
    }
  // while (!temp.empty()){
  //   cout << 'Ordered Keys: ' << temp.pop();
    
  // }

  // for (int i = 0; i< temp.size(); i ++){
  //   order[i] = temp.pop();
  // }

  // for (int i =0; i< order.size(); i++){
  //   cout << "Ordered Keys" << order.at(i) <<endl;
  // }
  // for (vector<int>::const_iterator i = order.begin(); i != order.end(); i++){
  //     cout << "Ordered Vector" << *i << endl;
  // }
  //return color;

} /*>>>*/

void rb_tree::output(rb_tree_node* x, int r_level)
{ /*<<<*/
/*
 * some structured output
 */
  list< pair<rb_tree_node*,int> > l_nodes;
  pair<rb_tree_node*,int> c_node;
  int c_level;

  c_level = r_level;
  l_nodes.insert(l_nodes.end(), pair<rb_tree_node*,int>(x, r_level));

  while (!l_nodes.empty())
    {
      c_node = *(l_nodes.begin());

      if (c_level < c_node.second)
	{
	  cout << endl;
	  c_level = c_node.second;
	}

      cout << "(" << c_node.first->key << "," 
	   << ((c_node.first->color == RB_RED) ? "R" : "B");

      if (c_node.first->p == T_nil)
	cout << ",ROOT) ";
      else
        cout << ",P:" << c_node.first->p->key << ") ";

      if (c_node.first->left != T_nil)
	l_nodes.insert(l_nodes.end(), pair<rb_tree_node*,int>(c_node.first->left, 
							      c_node.second+1));
      if (c_node.first->right != T_nil)
	l_nodes.insert(l_nodes.end(), pair<rb_tree_node*,int>(c_node.first->right, 
							      c_node.second+1));
      l_nodes.erase(l_nodes.begin());
    }

  cout << endl;
} /*>>>*/

void rb_tree::remove_all(rb_tree_node* x)
{ /*<<<*/
/*
 * recursively remove all tree elements
 */
  if (x != T_nil)
    {
      remove_all(x->left);
      remove_all(x->right);

      delete x;
    }
} /*>>>*/

// question 2
int rb_tree::convert(int* array, int n)
{
  //n is number of tree elements
  //call inorder_output on T_root 
  // for (int i = 0; i<n; i++){
  //   array[i] = inorder_output(T_root, i);
  // }
  //array = inorder_output(T_root, 0);
  //cout << "convert output: " << endl;
  //output( T_root,0);
  //cout << "inorder output " << endl;
  //inorder_output(T_root, 0);

  

  return n;
}






//question 4
int rb_tree::check_black_height(rb_tree_node* x)
{
  //init black height counter
  int counter;

  //call inorder tree walk
  

  cout<< "Check black height 398" << endl;
  //std::vector<int> color;
  counter = black_height_helper(x,0, counter);

  // for (int i= 0;i<color.size(); i++){
  //   if (color.at(i) == 1){
  //     counter++;
  //   }
  // }


  //if current node is black increment counter
  // if (x->color ==RB_BLACK){
  //   counter++;
  // }

  // while (x!=T_nil){
    
  // }


  //traverse left
  // if(x->left !=T_nil){
  //     check_black_height(x->left);
  // } else if (x->right != T_nil){
  //   //traverse right child
  //   check_black_height(x->right);

  // }
  
  


  //in order traverse 


  return counter;
}

// int rb_tree::inorder_tree_walk_color(bs_tree_node * x){
//   if (x != T_nil)
//     {

//       //order.push_back(x->key);
//       inorder_tree_walk_color(x->left);
//      // cout << "(" << x->key << "," << level << "," 
// 	   //<< ((x->color == RB_RED) ? "R" : "B") << ")" << endl;
//       inorder_tree_walk_color(x->right); 
      
//       return x->color;
// }
// return x->color;


int rb_tree::black_height_helper(rb_tree_node* x, int level, int blackNodes){
  //make vector global 
  //vector<int> color;

    cout << "top of helper" << endl;
    if (x != T_nil)
    {
      if (x->color ==RB_BLACK){
        cout << "helper black++" << endl;
        blackNodes++;
        }
      
      black_height_helper(x->left, level+1, blackNodes);
     // cout << "(" << x->key << "," << level << "," 
	   //<< ((x->color == RB_RED) ? "R" : "B") << ")" << endl;
      black_height_helper(x->right, level+1, blackNodes); 
    }

  




  //find tree height

  //traverse left child
  //black_height_helper(x->left, blackNodes+1);
  //traverse right child
  //black_height_helper(x->right, blackNodes+1);


  return blackNodes;
}
