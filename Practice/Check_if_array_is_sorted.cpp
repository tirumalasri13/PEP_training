class Solution {
  public:
    bool isSorting(vector<int>& arr, int n){
        if(n==1 || n==0)
        return true;
        if(arr[n-1]<arr[n-2])
        return false;
        
        return isSorting(arr,n-1);
    }
    bool isSorted(vector<int>& arr) {
        // code here
       int n=arr.size();
       return isSorting(arr,n);
        
        
    }
};