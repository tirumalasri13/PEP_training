class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        // code here
        int low=0;
        int n=arr.size();
        int high=n-1;
        int floori=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]<=x){
                floori=mid;
                low=mid+1;
            }
            else
            high=mid-1;
        }
        return floori;
        
        
    }
};