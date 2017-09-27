#include <iostream>
#include <string>

using namespace std;

#define STACK_SIZE 10

class Stack {
	char data_[STACK_SIZE];
	char top_;
	int elements_;

public:
	Stack() {
		elements_ = 0;
	}

	bool is_empty() {
		return elements_ == 0;
	}
	
	bool is_full() {
		return elements_ == STACK_SIZE;
	}

	void push(char val) {
		if(is_full()) {
			cout << "Stack is full! Please resize." << endl; //TODO

			return;
		}

		data_[elements_++] = val;
	}

	int pop() {
		if(is_empty()) {
			cout << "Stack is empty! There is nothing to pop." << endl;

			return -1;
		}

		return data_[--elements_];
	}
};

bool are_balanced(string);

int main(int argc, char *argv[]) {
	if(are_balanced(argv[1])) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}

bool are_balanced(string brackets) {
	Stack st;

	for(int i = 0; i < brackets.length(); i++) {
		if(brackets[i] == '(') {
			st.push(brackets[i]);
		}
		else if(brackets[i] == ')') {
			if(brackets[0] == ')' || st.is_empty()) {
				st.push(brackets[i]);
				break;
			}

			st.pop();
		}
	}

	return st.is_empty();
}
