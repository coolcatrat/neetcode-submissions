class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = INT_MIN;
        int n = heights.size();
        vector<int> rightside(n);   // how many idicies to the right can it fit
        vector<int> leftside(n);
        for(int i = 0; i < n; i++){
            int currh = heights[i];
            while(!st.empty() && heights[st.top()] > currh){
                int popped = heights[st.top()]; st.pop();
                int width = st.empty() ? i : i - 1 - st.top();
                maxArea = max(maxArea, popped*width);
            }
            st.push(i);
        }

        // empty remaining stack and calculate.
        while(!st.empty()){
            int height = heights[st.top()]; st.pop();
            int width = st.empty() ? n : n-1-st.top();
            maxArea = max(maxArea, height * width);
        }
        return maxArea;
    }
};
