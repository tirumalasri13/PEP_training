class Solution {
  public:
    void rev(vector<int> &arr, int l, int r){
        if(l>=r) return;
        else swap(arr[l],arr[r]);
        rev(arr,l+1,r-1);
    }
    void reverseArray(vector<int> &arr) {
        int n=arr.size();
        rev(arr,0,n-1);
       
        // code here
        
    }
};