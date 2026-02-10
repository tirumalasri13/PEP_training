class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0;
        int right=0;
        int sum=0;
        int n=nums.size();
        int minLen=n+1;
        while(right<n){
            sum=sum+nums[right];

            while (sum >= target) {
            minLen = min(minLen, right - left + 1);
            sum=sum-nums[left];
            left++;}
        right++;
        }
        if(minLen>n)
        return 0;
        else
        return minLen;
        
    }    
};