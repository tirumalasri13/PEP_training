class Solution {
  public:
    int countWords(string list[], int n) {
        // code here.
        map<string, int> f;
        for(int i=0;i<n;i++){
            f[list[i]]++;
        }
        int count = 0;
        for(auto it = f.begin(); it != f.end(); it++) {
            if(it->second == 2) 
            count++;
        }
        return count;
            
    }
};