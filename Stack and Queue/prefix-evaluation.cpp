class Solution {
  public:
       int floorDiv(int a, int b) {
        int q = a / b;
        int r = a % b;
        if (r != 0 && ((a < 0) ^ (b < 0))) {
            q--;
        }
        return q;
    }
    
     int power(int a, int b) {
        long long res = 1;
        long long base = a;

        while (b > 0) {
            if (b & 1) res = res * base;
            base = base * base;
            b >>= 1;
        }
        return (int)res;
    }
    int evaluatePrefix(vector<string>& arr) {
        // code here
        int n=arr.size();
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            string choice = arr[i];
            if(choice=="+" || choice=="-" || choice=="*" || choice=="/" || choice=="^"){
                int a= st.top(); st.pop();
                int b= st.top(); st.pop();
                if(choice=="+") st.push(a+b);
                else if(choice=="-") st.push(a-b);
                else if(choice=="*") st.push(a*b);
                else if(choice=="/") st.push(floorDiv(a,b));
                else if(choice=="^") st.push(power(a,b));
            }
            else{
                st.push(stoi(choice));
            }
        }
        return st.top();
    }
};