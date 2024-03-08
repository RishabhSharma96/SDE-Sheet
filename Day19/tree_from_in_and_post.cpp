class Solution {
public:

    TreeNode* solve(vector<int> & postorder, int postStart, int postEnd, vector<int> & inorder, int inStart, int inEnd, map<int,int> & elIn){

        if(inStart > inEnd || postStart > postEnd){
            return NULL;
        }

        TreeNode* newNode = new TreeNode(postorder[postEnd]);
        int elementIndex = elIn[postorder[postEnd]];
        int elementsOnLeft = elementIndex-inStart;

        newNode->left = solve(postorder, postStart, postStart+elementsOnLeft-1, inorder, inStart, elementIndex-1, elIn) ;
        newNode->right = solve(postorder, postStart+elementsOnLeft, postEnd-1, inorder, elementIndex+1, inEnd, elIn) ;

        return newNode;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> elIn ;
        for(int i=0 ; i<inorder.size() ; i++){
            elIn[inorder[i]] = i ;
        }

        return solve(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, elIn);
    }
};