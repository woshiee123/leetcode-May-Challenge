class Solution {
public:
    
   
    unordered_set<int>visited;
    
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>>mp;
        int count = 0;
        
        for(auto edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];
            mp[node1].insert(node2);
            mp[node2].insert(node1);
        }
        
        for(int i = 0; i < n; i++) {
            if(visited.count(i))
                continue;
            else {
                count++;
                dfs(i, mp);
            }
        }
        
        return count;
    }
    
    void dfs(int i, unordered_map<int, unordered_set<int>>&mp) {
        visited.insert(i);
        for(auto m :mp[i]) {
            if(!visited.count(m)) {
                dfs(m,mp);
            }
        }
   
    }
    
};
