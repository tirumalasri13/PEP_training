class Solution {
  public:
    int findFrequency(vector<int> arr, int x) {
        // Your code here
        map<int,int> f;
        int n = arr.size();
        for(int i=0;i<n;i++){
            f[arr[i]]++;
            
        }
        return f[x];
        
    }
}