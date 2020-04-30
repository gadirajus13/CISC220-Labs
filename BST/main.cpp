#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

int main( )
{
    BinarySearchTree<int> t;
    int NUMS = 39;
    const int GAP = 11;
    int i;
    int floor=-1, ceiling=-1;
    

    for( i = GAP; i != 0; i = ( i + GAP ) % NUMS ) {
        cout << i << endl;
        t.insert( i );
    }
 
   t.printTree( );
	t.floorceiling(39, floor, ceiling);

    for( i = 1; i <= NUMS; i+= 2 )
        t.remove( i );

   t.printTree( );
	t.floorceiling(19,floor,ceiling);

    if( t.findMin( ) != 2 || t.findMax( ) != NUMS - 1 )
        cout << "FindMin or FindMax error!" << endl;

    for( i = 2; i <= NUMS; i+=2 )
        if( !t.contains( i ) )
            cout << "Find error1!" << endl;

    for( i = 1; i < NUMS; i+=2 )
    {
        if( t.contains( i ) )
            cout << "Find error2!" << endl;
    }

    BinarySearchTree<int> t2;
    t2 = t;
    for( i = 2; i <= NUMS; i+=2 )
        if( !t2.contains( i ) )
            cout << "Find error1!" << endl;

    for( i = 1; i <= NUMS; i+=2 )
        if( t2.contains( i ) )
            cout << "Find error2!" << endl;
    t2.printTree();
    t2.floorceiling(18, floor, ceiling);    

    cout << "Finished testing" << endl;

    return 0;
}
