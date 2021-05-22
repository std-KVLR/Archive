#include <iostream>




using namespace std;

int main()
{
	unsigned long long R_count = 1;


	for(size_t i = 1; i <= 64; ++i){
		R_count *= R_count;
		if(R_count >= 1000) cout << "1000  zeren  na kletke: " << i << '\n';
		if(R_count >= 1000000) cout << "1000000  zeren  na kletke: " << i << '\n';
		if(R_count >= 1000000000) cout << "1000000000  zeren  na kletke: " << i << '\n';
	}
	return 0;

}





