#include <iostream>

using namespace std;

class ListError {
	string err_msg_;

public:
	ListError(string message) : err_msg_(message) {}

	string get_err_msg() const {
		return err_msg_;
	}
};

class List {
	struct Node {
		int data_;
		Node* prev_;
		Node* next_;

		Node(int val) : data_(val), prev_(0), next_(0) {}
	};

	Node* head_;

public:
	List() : head_(new Node(0)) {
		head_->prev_ = head_;
		head_->next_ = head_;
	}

	List(const List& other) { //Q: How to make copy constructor for List ?
		Node* otherFront = other.head_->next_;

    head_ = other.head_;//new Node(other.head_->data_);

    //Node* prev = head_;

    while(otherFront) {
		  head_->next_ = new Node(otherFront->data_);
		  otherFront = otherFront->next_;
		  head_ = head_->next_;
    }
	}

	~List() {
		while(!empty()) { //Q: Without while ?
			pop_back();
		}

		delete head_;
	}

	List& operator=(const List& other) { //Q: How to make assigning operator for List ?
		if(this != &other) {
				head_ = other.head_;
		}

		return *this;
  }

	bool empty() const {
		return head_->next_ == head_;
	}

	void push_back(int val) {
		Node* element = new Node(val);
		Node* back = head_->prev_;

		back->next_ = element;
		element->prev_ = back;

		element->next_ = head_;
		head_->prev_ = element;
	}

	int front() const {
		if(empty()) {
			throw ListError("List is empty!");
		}

		return head_->next_->data_; //check for this "head_" element
	}

	int back() const {
		if(empty()) {
			throw ListError("List is empty!");
		}

		return head_->prev_->data_;
	}

	void pop_back() {
		if(empty()) {
			throw ListError("List is empty! Cannot pop!");
		}

		Node* back = head_->prev_;
		Node* new_back = back->prev_;

		new_back->next_ = head_;
		head_->prev_ = new_back;

		delete back;
	}

	//push_front() ^, pop_front() ^, copy-constr ?, operator= ?

	void push_front(int val) {
		Node* element = new Node(val);
		Node* front = head_->next_;

		head_->next_ = element;
		element->prev_ = head_;

		front->prev_ = element; //Q: Order of connections ?
		element->next_ = front;
	}

	void pop_front() {
		if(empty()) {
			throw ListError("List is empty!");
		}

		Node* front = head_->next_;
		Node* new_front = front->next_;

		head_->next_ = new_front;
		new_front->prev_ = head_;

		delete front;
	}

	class iterator {
		friend class List;

		List* list_;
		Node* current_;

		iterator(List* list, Node* current) : list_(list), current_(current) {}
	public:
		bool operator==(const iterator& other) const {
			return list_ == other.list_ && current_ == other.current_;
		}

		bool operator!=(const iterator& other) const {
			return !operator==(other);
		}

		iterator& operator++() {
			current_ = current_->next_;

			return *this;
		}

		int& operator*() const {
			return current_->data_;
		}
	};

	iterator begin() {
		return iterator(this, head_->next_);
	}

	iterator end() {
		return iterator(this, head_);
	}

	iterator insert(iterator position, int val) {
		Node* element = new Node(val);
		Node* prev = position.current_->prev_;

		element->next_ = position.current_;
		position.current_->prev_ = element;

		prev->next_ = element;
		element->prev_ = prev;

		return iterator(this, element);
	}

	iterator erase(iterator position) {
		if(empty()) {
				throw ListError("List is empty!");
		}
		if(position.current_ == position.list_->head_) {
				throw ListError("Iterator cannot be positioned to head!");
		}

    Node* prev = position.current_->prev_;
    Node* next = position.current_->next_;
     
    prev->next_ = next;
    next->prev_ = prev;

		//position.current_->prev_->next_ = position.current_->next_;
		//position.current_->next_->prev_ = position.current_->prev_;

		delete position.current_;

		return iterator(position.list_, next);
	}
};

int main() {
	List l1;

	cout << l1.empty() << endl;

	l1.push_back(6);
	cout << l1.empty() << endl;

	l1.push_back(5);
	l1.push_back(7);
	cout << l1.front() << " " << l1.back() << endl;

	l1.pop_back();
	cout << l1.front() << " " << l1.back() << endl;

	l1.pop_back();
	l1.pop_back();

	try {
		l1.back();
	} catch(ListError ex) {
		cout << ex.get_err_msg() << endl;
	}

	l1.push_front(1);
	l1.push_back(2);
	cout << l1.front() << " " << l1.back() << endl;

	l1.pop_front();
	cout << l1.front() << " " << l1.back() << endl;

	List l2;
	cout << l2.front() << " " << l2.back() << endl;

	return 0;
}
