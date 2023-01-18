class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> graph;
        vector <int> inOrder(numCourses,0);
        queue<int> q;
        for(auto v:prerequisites)
        {
            graph[v[1]].push_back(v[0]);
            inOrder[v[0]]++;
        }
        for(int i = 0 ; i < numCourses ; i++)
        {
            if(inOrder[i]==0)
            q.push(i);
        }
        vector<int> out;
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            out.push_back(temp);
            for(int i:graph[temp])
            {
                inOrder[i]--;
                if(inOrder[i]==0)
                q.push(i);
            }
        }
        if(out.size() == numCourses)
            return out;
        else return {};
    }
};