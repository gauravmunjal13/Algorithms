#include <stdlib.h>
#include <stdio.h>
#include <iostream>


using namespace std;

/* node structure */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

/* To create new node */
struct node* newNode(int data)
{
    struct node* node = new struct node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

struct node *LCA( struct node* root, struct node* first, struct node* second)
{
    /* Base cases */
    if (root == NULL)
        return NULL;
    if ( root == first || root == second )
        return root;

    struct node* left,* right; // NOTICE
    left = LCA(root->left, first, second);
    right = LCA(root->right, first, second);

    if(left && right) // root is the LCA
        return root;
    else
        return (left?left:right);
}

/* **** Private Functions **** */
int main( void )
{
    /* Constructed binary tree is
           1
          / \
         2   3
        / \   \
       4   5   6
      / \
     7   8
    */
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  root->right->right= newNode(6);
  root->left->left->left  = newNode(7);
  root->left->left->right  = newNode(8);

  struct node *lca;
  lca = LCA(root, root->left->left, root->left->right);
  printf("[LCA] %d",lca->data);

  return 0;
}
