class Solution {
  public:
       
    int minCost(vector<int>& arr) {
        if(arr.size() <= 1)
            return 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < arr.size(); i++) {
            pq.push(arr[i]);
        }
        int totalCost = 0;
        while(pq.size() > 1) {
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            int sum = first + second;
            totalCost += sum;
            pq.push(sum);
        }
        return totalCost;
    }
};