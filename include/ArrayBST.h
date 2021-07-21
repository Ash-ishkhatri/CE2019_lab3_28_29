#pragma once
#include"AbstractBST.h"
#define MAX_NUM_NODES 120

class Node{
    public:
        int key;
        int value;
        Node();
        Node(int,int);
};


class ArrayBST:public AbstractBST{
    private:
        Node* array[MAX_NUM_NODES];
    public:
        ArrayBST();
        bool isEmpty() override;
        void add(int , int) override;
        void inorder() override;
        void inorder(int);
        void postOrder(int);
        void postOrder();
        void preOrder(int);
        void preOrder();
        void max(int&) override;
        void min(int&) override;
        bool exists(int) override;
};
