#include <iostream>
using namespace std;
// Nick Fafel and Sohan Gadiraju
struct AvlNode
{
  int      element;
  AvlNode  *left;
  AvlNode  *right;
};

void printTreeInfix( AvlNode *t ) 
{
    if (t == NULL){ 
        return; 
    }

    printTreeInfix(t->left); 
    cout << t->element << endl; 
    printTreeInfix(t->right); 
}

void printTreePrefix( AvlNode *t ) 
{
    if (t == NULL){ 
        return; 
    }
    cout << t->element << endl; 
    printTreePrefix(t->left);  
    printTreePrefix(t->right);
}

void printTreePostfix( AvlNode *t ) 
{
    if (t == NULL){ 
        return;
    } 
    printTreePostfix(t->left); 
    printTreePostfix(t->right); 

    cout << t->element << endl; 
}


AvlNode * genTree( int height, int & lastNode )
{   
   if (height < 0) {
       return nullptr;
   }
 
   AvlNode *t =(struct AvlNode*) malloc(sizeof(struct AvlNode));
 
   t->left = genTree(height-2, lastNode);
 
   lastNode += 1;
   t->element = lastNode;
 
   t->right = genTree(height-1, lastNode);
  
   return t;
}

AvlNode * minAvlTree(int h)
{
    int lastNodeAssigned  =  0;
    return genTree( h, lastNodeAssigned );
}

void freeAvlTree( AvlNode *t ) 
{
     if (t == NULL){ 
        return;
    } 
    freeAvlTree(t->left); 
    freeAvlTree(t->right); 
    free(t);
}

int main( )
{
    AvlNode *t;
    int h;
    cout << "sizeof(AvlNode)  " << sizeof(AvlNode)  << endl;
    cout << "sizeof(AvlNode*) " << sizeof(AvlNode*) << endl;
    cout << '\n';
    
    cout << "Enter the height of your desired AVL: " << endl;
    cin >> h;
    cout << '\n';
    
    t = minAvlTree(h);
    
    cout << "Infix" << endl;
    printTreeInfix(t);
    cout << "Prefix" << endl;
    printTreePrefix(t);
    cout << "Postfix" << endl;
    printTreePostfix(t);

    freeAvlTree(t);

    return 0;
}
