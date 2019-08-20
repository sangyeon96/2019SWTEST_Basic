#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int L, C; // 서로 다른 L개의 알파벳 소문자, C가지 문자
	cin >> L >> C; // 3 <= L <= C <= 15

	char ch[C];
	for(int i = 0; i < C; i++)
		cin >> ch[i]; // 사용했을 법한 문자 종류

	sort(ch, ch+C);
	/* check ch sorting
	for(int i = 0; i < C; i++)
		cout << ch[i];
	cout << '\n';
	*/

	vector<int> choose;
	for(int i = 0; i < C; i++) {
		if(i < L)
			choose.push_back(1);
		else
			choose.push_back(0);
	}

	do {
		char pw[L];
		int index = 0;
		for(int i = 0; i < C; i++) {
			if(choose[i]) {
				pw[index++] = ch[i];
			}
		}
		//모음 최소 1개, 자음 최소 2개 체크
		bool aeiou = false;
		int leftover = 0;
		for(int i = 0; i < L; i++) {
			if(pw[i] == 'a' || pw[i] == 'e' || pw[i] == 'i' || pw[i] == 'o' || pw[i] == 'u')
				aeiou = true;
			else
				leftover++;
		}

		if(aeiou && leftover >= 2) {
			for(int i = 0; i < L; i++) {
				cout << pw[i];
			}
			cout << '\n';
		}
	} while(prev_permutation(choose.begin(), choose.end()));


	return 0;
}