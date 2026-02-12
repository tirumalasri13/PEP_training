class myStack {
  public:
    int *arr;
    int size;
    int top;
    myStack(int n) {
        size=n;
        arr=new int[size];
        top=-1;
        // Define Data Structures  
    }

    bool isEmpty() {
        return top == -1;
        
        // check if the stack is empty
    }

    bool isFull() {
        return top == size-1;
        // check if the stack is full
    }

    void push(int x) {
        if (isFull()) return;
        else{
                top++;
                arr[top] = x;
            
        }
        // inserts x at the top of the stack
    }

    void pop() {
        if (isEmpty()) return;
        else{ 
                top--;
            
        }
        // removes an element from the top of the stack
    }

    int peek() {
        if (isEmpty()) return -1;
        else
        {
            return arr[top];
            
        }
        // Returns the top element of the stack
    }
};