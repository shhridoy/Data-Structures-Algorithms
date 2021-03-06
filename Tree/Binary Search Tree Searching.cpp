#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left = NULL;
    Node* right = NULL;
};
Node* Root = NULL;

void Add(int value){
    Node* nptr = new Node;
    nptr->data = value;
    nptr->left = NULL;
    nptr->right = NULL;

    if(Root == NULL){
        Root = nptr;
    }
    else{
        Node* tptr = Root;
        while(true){
            if(tptr->data > value){ /// going to left
                if(tptr->left == NULL){
                    tptr->left = nptr;
                    break;
                }
                else{
                    tptr = tptr->left;
                }
            }
            else{ /// going to right
                if(tptr->right == NULL){
                    tptr->right = nptr;
                    break;
                }
                else{
                    tptr = tptr->right;
                }
            }
        }
    }
}

void Search(int value){
    Node* tptr = Root;
    int count = 0;
    while(true){
        if(tptr == NULL || tptr->data == value){
            break;
        }
        else{
            if(value < tptr->data){
                tptr = tptr->left;
            }
            else{
                tptr = tptr->right;
            }
        }
    }
    if(tptr == NULL){
        cout<<value<<" not found"<<endl;
    }
    else{
        cout<<value<<" found"<<endl;
    }
}

void Inorder(Node* node){
    if(node != NULL){
        Inorder(node->left);
        cout<<node->data<<" ";
        Inorder(node->right);
    }
}

void Preorder(Node* node){
    if(node != NULL){
        cout<<node->data<<" ";
        Preorder(node->left);
        Preorder(node->right);
    }
}

void Postorder(Node* node){
    if(node != NULL){
        Postorder(node->left);
        Postorder(node->right);
        cout<<node->data<<" ";
    }
}

int main()
{
    Add(50);
    Add(15);
    Add(75);
    Add(87);
    Add(77);
    Add(30);
    Add(64);
    Add(99);
    Add(18);
    Add(3);
    Add(35);

    cout<<"In-Order BST: "<<endl;
    Inorder(Root);
    cout<<"\n\nPre-Order BST: "<<endl;
    Preorder(Root);
    cout<<"\n\nPost-Order BST: "<<endl;
    Postorder(Root);
    cout<<endl;

    cout<<"\nSearching......"<<endl;
    Search(99);
    Search(55);

    return 0;
}

/**
In-Order BST:
3 15 18 30 35 50 64 75 77 87 99

Pre-Order BST:
50 15 3 30 18 35 75 64 87 77 99

Post-Order BST:
3 18 35 30 15 64 77 99 87 75 50

Searching......
99 found
55 not found
**/
