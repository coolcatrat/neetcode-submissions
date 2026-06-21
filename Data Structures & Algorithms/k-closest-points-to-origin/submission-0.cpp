class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,int>, vector<pair<double,int>>> hp;
        for(int i = 0;i < points.size(); i++){
            int x = points[i][0];
            int y = points[i][1];
            double dist = sqrt(x*x + y*y);
            hp.push({dist,i});
            if(hp.size() > k) hp.pop();
        }
        vector<vector<int>> ans;
        while(!hp.empty()){
            int i = hp.top().second;
            hp.pop();
            ans.push_back(points[i]);
        }
        return ans;
    }

};
