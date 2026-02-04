class Solution {
  public:
    int thirdLargest(vector<int> &arr) {
        // code here
        int n=arr.size();
        if(n<3) return -1;
        int l=INT_MIN;
        int sl=INT_MIN;
        int tl=INT_MIN;
        for(int i=0;i<n;i++){
            if(arr[i]>l){
                tl=sl;
                sl=l;
                l=arr[i];
            }
            else if(sl<arr[i]){
                tl=sl;
                sl=arr[i];
            }
            else if (arr[i] > tl) 
            tl = arr[i];
            
            
        }
        return tl;
    }
}