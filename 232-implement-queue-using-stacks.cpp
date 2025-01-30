#include <stack>

using namespace std;

class MyQueue {
public:
    MyQueue() {

    }

    void push(int x) {
        this->input_stack.push(x);
    }

    int pop() {
        if (this->output_stack.empty()) this->move_all_to_output_stack();
        int val = this->output_stack.top();
        this->output_stack.pop();
        return val;
    }

    int peek() {
        if (this->output_stack.empty()) this->move_all_to_output_stack();
        int val = this->output_stack.top();
        return val;
    }

    bool empty() {
        return (this->input_stack.empty() && this->output_stack.empty());
    }

private:
    stack<int> input_stack;
    stack<int> output_stack;

    void move_all_to_output_stack() {
        while (!this->input_stack.empty()) {
            int val = this->input_stack.top();
            this->input_stack.pop();
            this->output_stack.push(val);
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */