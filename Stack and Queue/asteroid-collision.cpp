class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        int n = asteroids.size();
        for(int i=0; i<n; i++){
            int a = asteroids[i];
            while(!st.empty() && st.back()>0 && a0){
                if(abs(st.back())<abs(a)){
                    st.pop_back();
                    continue;
                }else if(abs(st.back())==abs(a)) st.pop_back();
                a=0;break;
            }
            if(a != 0) st.push_back(a);
        }
        return st;
        
    }
};