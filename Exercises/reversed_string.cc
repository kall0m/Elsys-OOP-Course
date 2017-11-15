#include <iostream>
#include <string>

using namespace std;

#define STACK_SIZE 50

class StackException {
  string err_msg_;

public:
  StackException(string message) {
    err_msg_ = message;
  }

  string get_err_msg() {
    return err_msg_;
  }
};

template<class T>
class Stack {
  int top_;
  T data_[STACK_SIZE];

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

  void push(T val) {
    if(is_full()) {
      throw StackException("Stack is full!");
    }

    data_[top_++] = val;
  }

  T pop() {
    if(is_empty()) {
      throw StackException("Stack is empty!");
    }

    return data_[--top_];
  }
};

int main(int argc, char* argv[]) {
  string str = "";

  for(int i = 1; i < argc; i++) {
    str += argv[i];

    if(i + 1 != argc) {
      str += " ";
    }
  }

  char reversed[STACK_SIZE];

  try {
    Stack<char> st;

    char* msg = (char*)str.c_str();

    for(char* p = msg; *p != '\0'; p++) {
      st.push(*p);
    }

    char* p = reversed;

    while(!st.is_empty()) {
      *p = st.pop();
      p++; //*p++ - ?
    }

    *p = '\0';

    cout << reversed << endl;
  } catch(StackException ex) {
    cout << "StackError catched..." << endl;
		cout << ex.get_err_msg() << endl;
  }

  return 0;
}
