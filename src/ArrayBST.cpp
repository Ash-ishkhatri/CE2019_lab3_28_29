#include"ArrayBST.h"
#include<iostream>

Node::Node(int key , int value)
    :key(key),value(value){}

ArrayBST::ArrayBST(){
    for(int i = 0 ; i<MAX_NUM_NODES ; i++)
        array[i] = NULL;
}

bool ArrayBST::isEmpty(){
    return array[1] == NULL;
}

void ArrayBST::add(int key , int value){
    Node* newNode = new Node(key,value);

    for(int i = 1 ; i < MAX_NUM_NODES ; ){
        if(array[i] == NULL){
            array[i] = newNode;
            std::cout << "inserted  key = " << array[i] -> key << " and value = " << array[i]->value<< std::endl;
            break;
        }else if(array[i]->key > key){
            i *= 2;
        }else if(array[i] -> key < key){
            i = i*2 + 1;
        }
    }
}

void ArrayBST::inorder(int i){
    if(array[i] == NULL) return;
    inorder(i*2);
    std::cout << "Key = " << array[i] -> key  << " and value = " << array[i] -> value << "\n";
    inorder(i*2+1);

}

void ArrayBST::postOrder(int i){
    if(array[i] == NULL) return;
    postOrder(i*2);
    postOrder(i*2+1);
    std::cout << "Key = " << array[i] -> key  << " and value = " << array[i] -> value << "\n";


}

void ArrayBST::preOrder(int i){
    if(array[i] == NULL) return;
    std::cout << "Key = " << array[i] -> key  << " and value = " << array[i] -> value << "\n";
    preOrder(i*2);
    preOrder(i*2+1);
}



void ArrayBST::inorder(){
    std::cout << "\nInorder of the BST is : ";
    if(array[1] == NULL){
        std::cout << " Empty BST" << std::endl;
    }else{
        std::cout << "\n";
        this -> inorder(1);
        std::cout << "\n";
    }
}

void ArrayBST::postOrder(){
    std::cout << "\nPostOrder of the BST is : ";
    if(array[1] == NULL){
        std::cout << " Empty BST" << std::endl;
    }else{
        std::cout << "\n";
        this -> postOrder(1);
        std::cout << "\n";
    }
}

void ArrayBST::preOrder(){
    std::cout << "\npreOrder of the BST is : ";
    if(array[1] == NULL){
        std::cout << " Empty BST" << std::endl;
    }else{
        std::cout << "\n";
        this -> preOrder(1);
        std::cout << "\n";
    }
}


void ArrayBST::max(int& output){
    if(this -> isEmpty()){
        std::cout << "Empty tree cannot find max value" << std::endl;
        return;
    }
    int i = 1;
    while( i < MAX_NUM_NODES ){
        if(array[i] == NULL){
            i = (i-1)/2;
            break;
        }
        i = 2*i + 1;
    }   
    output = array[i] -> key;
}

void ArrayBST::min(int& output){
    if(this -> isEmpty()){
        std::cout << "Empty tree cannot find max value" << std::endl;
        return;
    }
    int i = 1;
    while( i < MAX_NUM_NODES ){
        if(array[i] == NULL){
            i = (i)/2;
            break;
        }
        i = 2*i;
    }   
    output = array[i] -> key;
}


bool ArrayBST::exists(int target){
    if(this -> isEmpty()){
        std::cout << "Empty tree , target doesnot exists" << std::endl;
        return 0;
    }
    int i = 1;
    while(array[i] != NULL){
        if(array[i] -> key == target){
            return true;
        }else if(target > array[i] -> key) i = i*2 +1;
         else if(target < array[i] -> key) i = i*2;
    }
    return false;
}


