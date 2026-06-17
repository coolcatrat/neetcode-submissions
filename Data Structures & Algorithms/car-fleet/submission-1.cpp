class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> cars(n);
        for (int i = 0; i < n; i++)
            cars[i] = {position[i], speed[i]};
        sort(cars.rbegin(), cars.rend());   // descending by position

        int count = 1;
        stack<double> st; // finish time , strictly increasing 
        for(auto v : cars){
            double time = (double)(target - v.first) / v.second;
            if(st.empty())  st.push(time);
            else if(time > st.top()) {
                st.push(time);
                count++;
            }
        }
        return count;
    }
};
