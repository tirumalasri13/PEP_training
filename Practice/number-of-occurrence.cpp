class Solution {
  public:
    int occ(vector<int>& arr,int n,int i, int target){
        if(i==n)
        return 0;
        return(arr[i]==target)+occ(arr,n,i+1,target);
        
    }
    
    int countFreq(vector<int>& arr, int target) {
        // code here
        int n= arr.size();
        return occ(arr,n,0,target);
        
    }
};
