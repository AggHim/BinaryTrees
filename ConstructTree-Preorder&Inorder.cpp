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
***************/

BinaryTreeNode<int>* buildTree(int *preorder, int preLenght, int *inorder, int inLength) {
    // Write your code here
    if(preLenght==0){
        return NULL;
    }
    int rootdata = preorder[0];
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootdata);
    int i=0;
    for(;i<inLength;i++){
        if(inorder[i]==rootdata){
            break;
        }
    }
    BinaryTreeNode<int>* leftChild = buildTree(preorder+1,i,inorder,i);
    int rightLen = preLenght-i-1;
    BinaryTreeNode<int>* rightChild = buildTree(preorder+1+i,rightLen,inorder+1+i,rightLen);
    root->left = leftChild;
    root->right = rightChild;
    return root;
}
