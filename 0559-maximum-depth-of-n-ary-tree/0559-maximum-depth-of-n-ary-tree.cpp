class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) return 0;
        
        queue<Node*> q;
        q.push(root);
        int depth = 0;
        
        while (!q.empty()) {
            int levelSize = q.size();
            depth++;
            
            for (int i = 0; i < levelSize; ++i) {
                Node* curr = q.front();
                q.pop();
                
                for (Node* child : curr->children) {
                    if (child) {
                        q.push(child);
                    }
                }
            }
        }
        
        return depth;
    }
};