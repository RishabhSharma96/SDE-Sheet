class Solution {
public:

    TreeNode* solve(vector<int> & preorder, int preStart, int preEnd, vector<int> & inorder, int inStart, int inEnd, map<int,int> & elIn){

        if(inStart > inEnd || preStart > preEnd){
            return NULL;
        }

        TreeNode* newNode = new TreeNode(preorder[preStart]);
        int elementIndex = elIn[preorder[preStart]];
        int elementsOnLeft = elementIndex-inStart;

        newNode->left = solve(preorder, preStart+1, preStart+elementsOnLeft, inorder, inStart, elementIndex-1, elIn) ;
        newNode->right = solve(preorder, preStart+elementsOnLeft+1, preEnd, inorder, elementIndex+1, inEnd, elIn) ;

        return newNode;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> elIn ;
        for(int i=0 ; i<inorder.size() ; i++){
            elIn[inorder[i]] = i ;
        }

        return solve(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, elIn);
    }
};