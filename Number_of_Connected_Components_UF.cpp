class Solution {
public:
    
    unordered_map<int, int>root;
    
    int countComponents(int n, vector<vector<int>>& edges) {
        for(int i = 0; i < n; i++) {
           root[i] = i;
        }
        
        for(auto edge :edges) {
            int node1 = edge[0];
            int node2 = edge[1];
            int root1 = findroot(node1);
            int root2 = findroot(node2);
            root[root1] = root2;
        }
        unordered_set<int>roots;
        for(int i = 0; i < n; i++) {
            roots.insert(findroot(i));
        }
        return roots.size();
    }
    
    int findroot(int node) {
        while(root[node] != node)
            node = root[node];
        return node;
    }
};
