class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxheight=0;
        int n = heights.size();
        for(int i=0;i<=n;i++){
            int currheight;
            if(i==n) currheight=0;
            else currheight=heights[i];
            while(!st.empty() && currheight<heights[st.top()]){
                int h = heights[st.top()];
                st.pop();
                int right = i; int left;
                if(st.empty()) left = -1;
                else left = st.top(); 
                int width = right - left - 1;
                maxheight=max(maxheight,h*width);
            }
            st.push(i);
        }
        return maxheight;
    }
};