/*
	Problem Statement:
	Convert given binary tree into threaded binary tree. Analyze time and space complexity
	of the algorithm.

============================================================================
Name : Assignment_5.cpp
Author : Gujrathi Siddhant
============================================================================*/

#include<iostream>
using namespace std ;

class Node
{
public :
    Node *left;
    Node *right;
    int data;
    bool rightThread;
    
    Node(int data)
	{
        this->data = data;
        rightThread = false;
        this->left = NULL ;
        this->right = NULL ;
    }
} ;

Node *leftMostNode(Node *root)
{
		Node *current = root;
		while(current and current->left!= NULL)
			current = current -> left;
		return current;
}


class BSTtoThreadedBST 
{
    public :
    void convert(Node *root)
	{
        inorder(root, NULL);
    }

    void inorder(Node *root, Node *previous)
	{
        if(root==NULL)
		{
            return;
        }
		else
		{
            inorder(root->right, previous);
            if(root->right==NULL &&  previous!=NULL)
			{
                root->right = previous;
                root->rightThread=true;
            }
            inorder(root->left, root);
        }
	}

	void print(Node *root)
	{
    	//first go to most left node
    	Node *current = leftMostNode(root);
    	//now travel using right pointers
    	while(current!=NULL)
		{
        	cout<<" "<<current->data ;
        	//check if node has a right thread
        	if(current->rightThread)
            	current = current->right;
        	else // else go to left most node in the right subtree
            	current = leftMostNode(current->right);
    	}
        cout<<endl;
	}
};



int main() 
{
		/*	  10	
			/   \
		   5    15
		  / \  / \
		 1  7 12  20	 */
        Node *root = new Node(10);
        root->left = new Node(5);
        root->right = new Node(15);
        root->left->left = new Node(1);
        root->left->right = new Node(7);
        root->right->left = new Node(12);
        root->right->right = new Node(20);
        
        BSTtoThreadedBST *converter = new BSTtoThreadedBST()  ;
        converter->convert(root);

        cout<<"Inorder Traversal: "<<endl;
        converter->print(root);
        
        return 0;
    }

