#include <iostream>
using namespace std;

int main() {
	
	int n;
	int sum = 0;

	while(true){

		cin >> n;

		if(!cin.good()) {
			cout << "Sum: " << sum;
			break;
		}

		sum += n;
	}

	return 0;
}

