
#include "bs_tree.h"
#include <list>
#include <iostream>

using namespace std;

/*
 * constructor/destructor
 */
bs_tree::bs_tree()
{ 
  //create new node 
  //assign new node as root
 // bs_tree_node* new_Node;

  //set new_Node to root 
  //set p, L, R, and Color
  //bs_tree_node* T_root = new_Node;

  T_nil = new bs_tree_node;
 // new_Node -> color = RB_BLACK;
  // new_Node -> left = NULL;
  // new_Node -> right = NULL;
  // new_Node -> p = NULL;

  //init duplicate counter for t_info



  T_nil->p = T_nil;
  T_nil->left = T_nil;
  T_nil->right = T_nil;

  /*
 * root of bs tree
 */
  T_root = T_nil;

} 

bs_tree::~bs_tree()
{ 
  remove_all(T_root);

  delete T_nil;
} 

bs_tree_node* bs_tree::tree_search(bs_tree_node* x, int key){
  // if tree is emptu or key is trenode->key return true 
  // cout << "top of tree search" << endl;
  // cout << "x key: " << x->key << endl;
  // cout << "x left" << x->left << endl;
  // cout << "x right: " << x->right << endl; 
  // cout << " x: " << x << endl;
  // cout << " t_nil: " << T_nil << endl;
  
    if (x ==T_nil){
    return T_nil;
  }
  if (key == x->key){
    return x;
  }

  if (key < x->key){
    return tree_search(x->left, key);
  } else {
    return tree_search(x->right, key);
  }
  
}

void bs_tree::insert(int key, bs_tree_i_info& t_info)
{ 
  //create node z and call insert
  bs_tree_node* z;
  z = new bs_tree_node();
  z->key = key;
  z->left = T_nil;
  z->right = T_nil;
  z->p = T_nil;
  bs_tree_node* temp;
  //check if key already in tree
  //if tree_search returns T_nil element is not there so insert
  temp = tree_search(T_root, key);
  if (temp ==T_nil){
    //key not there insert
    //cout<< "inserting key..." << endl;
    insert(z,t_info);
  }else {
    //there is a duplicate. increment duplicate counter
    t_info.i_duplicate++;
    return;
  }


  

}

void bs_tree::insert(bs_tree_node* z, bs_tree_i_info& t_info){
  //init node x and y
  bs_tree_node* x;
  bs_tree_node* y;
  y = T_nil;
  x = T_root;
  //while x is not null
  while(x !=T_nil){
    y = x;
    //if zkey is less than xkey
    if (z->key < x->key){
      x = x->left;
    } else {
      x = x->right;
    }
  }// end while
  z->p = y;
  if ( y==T_nil){
    T_root = z; // tree T was empty
    } else if (z->key < y->key){
      y->left = z;
    } else {
      y->right =z;
    }


  //call rotate right rotate left to keep BST property
}




// TODO: modified inorder tree walk method to save the 
// sorted numbers in the first argument: int* array.
// question 2
int bs_tree::convert(int* array, int n, bs_tree_i_info& t_info)
{
  //call inorder tree walk
  int elementsAdded=0;
	for (int i = 0; i < n; i++){
		array[i] = inorder_tree_walk(T_root);
    elementsAdded++;
}
  //cout<< "eleAdded: " << elementsAdded << endl;
  //cout << "n: " << n << endl;
  //update n
  n = elementsAdded - t_info.i_duplicate;
  //cout << "n: " << n << endl;
  return n;
}

int bs_tree::inorder_tree_walk(bs_tree_node * x){
  if (x != T_nil)
    {

      //order.push_back(x->key);
      inorder_tree_walk(x->left);
     // cout << "(" << x->key << "," << level << "," 
	   //<< ((x->color == RB_RED) ? "R" : "B") << ")" << endl;
      inorder_tree_walk(x->right); 
      
      return x-> key;
}
return x->key;

}


void bs_tree::remove_all(bs_tree_node* x)
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
}
