class Solution {
public:

    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(),cmp);
        priority_queue<int>pq;
        
        int sumDays = 0;
        
        for(auto course : courses) {
            pq.push(course[0]);
            sumDays += course[0];
            if(sumDays > course[1]) {
                sumDays -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
    
    static bool cmp(vector<int>&v1, vector<int>&v2) {
        if(v1[1]<v2[1])
            return true;
        else if(v1[1]>v2[1])
            return false;
        else
            return v1[0]<v2[0];

    }
};
