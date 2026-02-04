class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int n = arr.size();
        if(n<2)
        return -1;
        int l=-1;
        int sl=-1;
        for(int i=0;i<n;i++){
            if(arr[i]>l){
                sl=l;
                l=arr[i];
            }
            else if(arr[i]<l&&arr[i]>sl){
                sl=arr[i];
            }
        }
        return sl;
    }
};