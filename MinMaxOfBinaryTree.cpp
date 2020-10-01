#include <climits>
/**************
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
 
 // PairAns class -
 class PairAns {
    public :
        int min;
        int max;
 };
 
***************/

/*
int maxi(BinaryTreeNode<int>* root){
    if(root==NULL){
        return INT_MIN;
    }
    return max(root->data,max(maxi(root->left),maxi(root->right)));
}

int mini(BinaryTreeNode<int>* root){
    if(root==NULL){
        return INT_MAX;
    }
    return min(root->data,min(mini(root->left),mini(root->right)));
}
*/

PairAns minMax(BinaryTreeNode<int> *root) {
    if(root==NULL){
        PairAns p;
        p.max = INT_MIN;
        p.min = INT_MAX;
        return p;
    }
    PairAns p1 = minMax(root->left);
    PairAns p2 = minMax(root->right);
    PairAns p;
    p.max = max(root->data,max(p1.max,p2.max));
    p.min = min(root->data,min(p1.min,p2.min));
    return p;
}
