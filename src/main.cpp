#include<iostream>
#include"ArrayBST.h"

int main(){

    ArrayBST* A = new ArrayBST();
    A -> inorder();
    std::cout << "\n";
    A -> add(10 , 10000);
    A->add(5 , 5000);
    A->add(2,2000);
    A->add(6,6000);
    A -> add(15 , 15000);
    A -> add(12 , 12000);
    A -> add(11 , 11000);
    A -> add(14 , 14000);
    A -> add(13 , 13000);

    A->inorder();
    A->postOrder();
    A->preOrder();  

    int maxKey;
    A->max(maxKey);
    std::cout << "MaxKey value = " << maxKey<<std::endl; 

    int minKey;
    A->min(minKey);
    std::cout << "MinKey value = " << minKey<<std::endl; 

    std::cout << A->exists(5) << std::endl;
    std::cout << A->exists(30) << std::endl;

    return 0;
}