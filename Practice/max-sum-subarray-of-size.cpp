class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        //can also be done using kadanes algorithm
        int sum=0;
        int n=arr.size();
        for(int i=0;i<k;i++){
            sum+=arr[i];
        }
        int maxsum=sum;
        for(int i=k;i<n;i++){
            sum+=arr[i];
            sum-=arr[i-k];
            maxsum = max(maxsum, sum);
        }
        return maxsum;
    }
};