#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	
	int sum = 0;

	for(int i = 1; i < argc; ++i) {

		char *snum = argv[i];
		int sign = 1;

		if(*snum == '-') {
			sign = -1;
			snum++;
		}

		int num = 0;
		
		while(*snum >= '0' && *snum <= '9') {
				num *= 10;
				num += *snum - '0';
				snum++;
		}

		num *= sign;

		sum += num;
	}

	cout << "Sum = " << sum << endl;
	
	return 0;
}

