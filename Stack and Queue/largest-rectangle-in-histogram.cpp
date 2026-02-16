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



///NSL AND NSR..


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n);
        stack<int> st;
        // NSL
        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();
        // NSR
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        long long maxArea = 0;
        for(int i = 0; i < n; i++) {
            long long width = right[i] - left[i] - 1;
            maxArea = max(maxArea, width * heights[i]);
        }
        return (int)maxArea;
    }
};
