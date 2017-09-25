#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char* argv[]) { //moje da polzva arg ot command red
	
	int sum = 0;

	for(int i = 1; i < argc; ++i) {

		char *snum = argv[i];
		int sign = 1;
		int len = strlen(snum);
		int j = 0;

		if(snum[0] == '-') {
			sign = -1;
			j = 1;
			//snum++;
		}

		int num = 0;
		
		while(j < len) {
			if(snum[j] >= '0' && snum[j] <= '9') {
				num *= 10;
				num += (int) (snum[j] - '0');
				//snum++;
			}
			j++;
		}

		num *= sign;

		sum += num;
		//cout << "argv[" << i << "]=" << argv[i] << endl;
	}

	cout << "Sum = " << sum << endl;
	
	return 0;
}

//sum na comm red

//chete ot stand vhod celi chisla i otpechatva sum

