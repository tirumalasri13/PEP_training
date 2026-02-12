#include <bits/stdc++.h> 
void deleteMiddle(stack<int>&inputStack, int N){
    int total = N + 1;
    
    if(total == 0) return;
    int mid = (total - 1) / 2;              // from bottom (0-based)
    int pops = total - mid - 1; 
    stack<int> temp;
    for(int i = 0; i < mid; i++) {
        temp.push(inputStack.top());
        inputStack.pop();
    }
    inputStack.pop();
    while(!temp.empty()) {
        inputStack.push(temp.top());
        temp.pop();
    }
   
}