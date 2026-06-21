class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minheap;
    int s;
    KthLargest(int k, vector<int>& nums) {
        s = k;
        for(int x: nums) add(x);
    }
    
    int add(int val) {
        minheap.push(val);
        if(minheap.size() > s ) minheap.pop();
        return minheap.top();
    }
};
