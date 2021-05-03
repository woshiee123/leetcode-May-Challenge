class Solution {
public:
    int maxcourse = 0;
    int scheduleCourse(vector<vector<int>>& courses) {
        unordered_set<int>visited;
        dfs(0, visited, courses, 0);
        return maxcourse;
        
    }
    
    void dfs(int curDay, unordered_set<int>&visited, vector<vector<int>>& courses, int count) {
        maxcourse = max(maxcourse,count);
        int n = courses.size();
        
        for(int i = 0; i < n; i++) {
            if(visited.count(i))
                continue;
            if(curDay+courses[i][0] <= courses[i][1]) {
                visited.insert(i);
                dfs(curDay+courses[i][0],visited, courses, count+1 );
                visited.erase(i);
            }
            
        }
    }
};
