/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>level;
            int n=q.size();
            for(int i=0;i<n;i++){
                Node *n=q.front();
                q.pop();
                level.push_back(n->val);
                for(int j=0;j<n->children.size();j++){
                    q.push(n->children[j]);
                }
            }
            ans.push_back(level);
        }
        return ans;
    }
};