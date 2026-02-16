// Brute Force.....
class StockSpanner {
public:
    vector<int> prices;
    StockSpanner() {
        
    }
    
    int next(int price) {
        prices.push_back(price);
        int span=0;
        for(int i=prices.size()-1; i>=0; i--){
            if(prices[i]<=price) span++;
            else break; 
        }
        return span;
    }
};

//Monotonic Stack.....

class StockSpanner {
public:
    vector<int> prices;
    stack<int> st;
    StockSpanner() {     
    } 
    int next(int price) {
        prices.push_back(price);
        int i = prices.size() - 1;
        while(!st.empty() && prices[st.top()] <= price) {
            st.pop();
        }
        int span;
        if(st.empty()) span = i + 1;
        else span = i - st.top();
        st.push(i);
        return span;
    }
};