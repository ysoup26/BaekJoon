#include <iostream>
 
using namespace std;
 
int findHansu(int i) {
	int cnt = 0;
 
	if (i < 100) { //1~99는 모두 한수
		return i;
	} else { 
		cnt = 99;  
 
		for (int n = 100; n <= i; n++) {
			int hun = n / 100;		 // 백의 자릿수
			int ten = (n / 10) % 10; // 십의 자릿수
			int one = n % 10;
 
			if ((hun - ten) == (ten - one)) { 
				cnt++;
			}
		}
	}
	return cnt;
}
 
int main() {
 
	int i;
	cin >> i;
	cout << findHansu(i);
	return 0;
}