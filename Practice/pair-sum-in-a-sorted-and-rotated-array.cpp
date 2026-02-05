class Solution {
  public:
    bool pairInSortedRotated(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int point=-1;
        for(int i=0;i<n-1;i++){
            if(arr[i]>arr[i+1]){
                point = i;
            }
        }
        if(point == -1)
            point=n-1;
        int l=(point+1)%n;
        int r=point;
        while(l!=r){
            int sum=arr[l]+arr[r];
            if(sum==target)
            return true;
            else if(sum<target)
            l=(l+1)%n;
            else
            r=(r-1+n)%n;
        }
        return false;
        
    }       
    
};