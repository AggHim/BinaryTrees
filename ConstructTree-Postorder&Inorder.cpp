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

BinaryTreeNode<int>* getTreeFromPostorderAndInorder(int *postorder, int postLength, int *inorder, int inLength) {
    // Write your code here
    if(postLength==0) return NULL;
    int rootdata = postorder[postLength-1];
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootdata);
    int i=0;
    for(;i<inLength;i++){
        if(inorder[i]==rootdata){
            break;
        }
    }
    root->left = getTreeFromPostorderAndInorder(postorder,i,inorder,i);
    int rl = postLength-i-1;
    root->right = getTreeFromPostorderAndInorder(postorder+i,rl,inorder+i+1,rl);
    return root;
}
