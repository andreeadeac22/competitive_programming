//
//  Convert Ternary Expression to Binary Tree.cpp
//  
//
//  Created by Andreea-Ioana Deac on 28/11/2017.
//
// http://practice.geeksforgeeks.org/problems/convert-ternary-expression-to-binary-tree/1 

#include <stdio.h>
/*
 Please note that it's Function problem i.e.
 you need to write your solution in the form of Function(s) only.
 Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*Complete the function below
 Node is as follows
 struct Node{
 char data;
 Node *left,*right;
 };
 */
Node *convertExpression(string str,int i)
{
    if (i >=str.size()) {  // empty string
        return new Node();
    }
    Node *root = new Node();
    root->data = str[i];
    if( i<str.size()-1 ) {
        if(str[i+1] == '?')
            root->left = convertExpression(str, i+2);
        if(str[i+1] == ':')
            root->right = convertExpression(str, i+2);
    }
    return root;
}
