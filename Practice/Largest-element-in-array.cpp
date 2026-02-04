class Solution {
  public:
    int largest(vector<int> &arr) {
        
        // code here
        int n=arr.size();
        int maxa=arr[0];
        for(int i=0;i<n;i++){
            if(maxa<arr[i])
                maxa=arr[i];
        }
        return maxa;
    }
};
