class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int,vector<int>> q;
        for(int x : stones) q.push(x);
        while(q.size() >= 2){
            int y = q.top(); q.pop();
            int x = q.top(); q.pop();
            // x < y
            if(y-x)
                q.push(y-x);
        }
        return q.empty() ? 0 : q.top();
    }
};
