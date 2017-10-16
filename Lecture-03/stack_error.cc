#include <iostream>
using namespace std;

#define STACK_SIZE 10

class StackError {
  string err_msg_;

public:
  StackError(string message) {
    err_msg_ = message;
  }

  string get_err_msg() {
    return err_msg_;
  }
};

class Stack {
  int data_[STACK_SIZE];
  int top_;

public:
  Stack() {
    top_ = 0;
  }

  bool is_empty() {
    return top_ == 0;
  }

  bool is_full() {
    return top_ == STACK_SIZE;
  }

  void push(int val) {
    if(is_full()) {
      throw StackError("Stack is full...");
    }

    data_[top_++] = val;
  }

  int pop() {
    if(is_empty()) {
      throw StackError("Stack is empty...");
    }

    return data_[--top_];
  }
};

int main() {
  Stack st;

	cout << st.is_empty() << endl;
	cout << st.is_full() << endl;
	
	try {
		st.push(0);

		cout << st.is_empty() << endl;
		cout << st.is_full() << endl;

		for(int i = 1; i <= STACK_SIZE; i++) {
			st.push(i);
		}
		
		//st.pop();
	} catch(StackError ex) {
		cout << "StackError catched..." << endl;
		cout << ex.get_err_msg() << endl;
	}
	
	cout << st.is_empty() << endl;
	cout << st.is_full() << endl;
	
	while(!st.is_empty()) {
		cout << "pop: " << st.pop() << endl;
	}

  return 0;
}
