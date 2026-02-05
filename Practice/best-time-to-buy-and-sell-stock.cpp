class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int p=0;
        int maxp=0;
        int buy=0;
        int n=prices.size();
        for(int i =0;i<n;i++){
            if(prices[i]<prices[buy]){
                buy=i;
            }if(prices[i]>prices[buy]){
                p=prices[i]-prices[buy];
                maxp=max(maxp,p);
            }

        }
        return maxp;
        
    }

};