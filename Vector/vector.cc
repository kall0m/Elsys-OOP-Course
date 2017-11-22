#include <iostream>

using namespace std;

class VectorError {};

class Vector {
	int capacity_;
	int size_;
	int* buffer_;
public:
	Vector(int capacity = 10) : capacity_(capacity), size_(0), buffer_(new int[capacity]) {}

	Vector(const Vector& other) : capacity_(other.capacity_), size_(other.size_), buffer_(new int[other.capacity_]) {
		for(int i = 0; i < size_; i++) {
			buffer_[i] = other.buffer_[i];
		}
	}

	~Vector() {
		delete [] buffer_;
	}

	Vector& operator=(const Vector& other) {
		if(this != &other) {
			size_ = other.size_;
			capacity_ = other.capacity_;

			buffer_ = new int[capacity_];
	
			for(int i = 0; i < size_; i++) {
				buffer_[i] = other.buffer_[i];
			}
		}

		return *this;
	}

	int size() const {
		return size_;
	}

	bool empty() const {
		return size_ == 0;
	}

	int& operator[](int n) {
		if(n < 0 || n >= size_) {
			throw VectorError();
		}
		return buffer_[n];
	}

	const int& operator[](int n) const {
		if(n < 0 || n >= size_) {
			throw VectorError();
		}
		return buffer_[n];
	}

	void clear() {
		size_ = 0;
	}

	int capacity() const {
		return capacity_;
	}

	int& front() {
		if(empty()) {
			throw VectorError();
		}
		return buffer_[0];
	}

	const int& front() const {
		if(empty()) {
			throw VectorError();
		}
		return buffer_[0];
	}

	int& back() {
		if(empty()) {
			throw VectorError();
		}
		return buffer_[size_ - 1];
	}

	const int& back() const {
		if(empty()) {
			throw VectorError();
		}
		return buffer_[size_ - 1];
	}

	void resize() {
		cout << "res" << endl;
		capacity_ *= 2;
		int* tmp = buffer_;

		buffer_ = new int[capacity_];

		for(int i = 0; i < size_; i++) {
			buffer_[i] = tmp[i];
		}

		delete [] tmp;
	}

	void push_back(const int& value) {
		if(size_ == capacity_) {
			resize();
		}
		buffer_[size_++] = value;
	}

	void pop_back() {
		if(empty()) {
			throw VectorError();
		}
		size_--;
	}

	class iterator {
		friend class Vector;

		int* current_;

		iterator(int* current) : current_(current) {}
	public:
		iterator& operator++() {
			current_ = current_ + 1;

			return *this;
		}

		iterator operator++(int) {
			iterator previous(current_);
			current_ = current_ + 1;

			return previous;
		}

		bool operator==(const iterator& other) const {
			return current_ == other.current_;
		}

		bool operator!=(const iterator& other) const {
			return !operator==(other);
		}

		int& operator*() {
			return *current_;
		}
	};

	iterator begin() {
		return iterator(&front());
	}

	iterator end() {
		return iterator(&buffer_[size_]);
	}

	class const_iterator {
		friend class Vector;

		const int* current_;

		const_iterator(const int* current) : current_(current) {}
	public:
		const_iterator& operator++() {
			current_ = current_ + 1;

			return *this;
		}

		const_iterator operator++(int) {
			const_iterator previous(current_);
			current_ = current_ + 1;

			return previous;
		}

		bool operator==(const const_iterator& other) const {
			return current_ == other.current_;
		}

		bool operator!=(const const_iterator& other) const {
			return !operator==(other);
		}

		const int& operator*() {
			return *current_;
		}
	};

	const_iterator begin() const{
		return const_iterator(&front());
	}

	const_iterator end() const{
		return const_iterator(&buffer_[size_]);
	}

	class reverse_iterator {
		friend class Vector;

		int* current_;

		reverse_iterator(int* current) : current_(current) {}
	public:
		reverse_iterator& operator++() {
			current_ = current_ + 1;

			return *this;
		}

		reverse_iterator operator++(int) {
			reverse_iterator previous(current_);
			current_ = current_ + 1;

			return previous;
		}

		bool operator==(const reverse_iterator& other) const {
			return current_ == other.current_;
		}

		bool operator!=(const reverse_iterator& other) const {
			return !operator==(other);
		}

		int& operator*() {
			return *current_;
		}
	};

	reverse_iterator rbegin() {
		return reverse_iterator(&buffer_[size_]);
	}

	reverse_iterator rend() {
		return reverse_iterator(&front());
	}

	class const_reverse_iterator {
		friend class Vector;

		const int* current_;

		const_reverse_iterator(const int* current) : current_(current) {}
	public:
		const_reverse_iterator& operator++() {
			current_ = current_ + 1;

			return *this;
		}

		const_reverse_iterator operator++(int) {
			const_reverse_iterator previous(current_);
			current_ = current_ + 1;

			return previous;
		}

		bool operator==(const const_reverse_iterator& other) const {
			return current_ == other.current_;
		}

		bool operator!=(const const_reverse_iterator& other) const {
			return !operator==(other);
		}

		const int& operator*() {
			return *current_;
		}
	};

	const_reverse_iterator rbegin() const {
		return const_reverse_iterator(&buffer_[size_]);
	}

	const_reverse_iterator rend() const {
		return const_reverse_iterator(&front());
	}

	iterator insert(iterator pos, const int& x) {
		if(pos == end()) {
			push_back(x);
		} else {
			int value = *pos.current_;
			*pos = x;

			for(iterator it = ++pos; it != end(); ++it) {
				int tmp = *it;
				*it = value;
				value = tmp;
			}

			push_back(value);
		}

		return pos;
	}
};

int main() {
	Vector v1;

	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(12);
	v1.push_back(24);
	v1.push_back(421);
	v1.push_back(32);
	v1.push_back(6);

	cout << "iterator in da game" << endl;

	for(Vector::iterator it=v1.begin(); it!=v1.end(); ++it) {
		cout << *it << endl;
	}

	Vector::iterator it(v1.begin());

	v1.insert(it, 7);

	cout << "inserted: " << v1.front() << endl;

	Vector::iterator it2(v1.end());

	v1.insert(it2, 5);

	cout << "inserted: " << v1.back() << endl;

	return 0;
}
