#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int dwarf[9];
	int ans_dwarf[7];
	int ans_dwarf_index = 0;
	int i, j, k;

	for(i = 0; i < 9; i++)
		cin >> dwarf[i]; // 1 <= dwarf[i] <= 100

	//일곱개의 index를 고른다.
	int missIndex1, missIndex2;
	bool answerFlag = false;
	for(i = 0; i < 9; i++) {
		missIndex1 = i;
		for(j = i+1; j < 9; j++) {
			missIndex2 = j;

			int sum = 0;
			for(k = 0; k < 9; k++) {
				if(k != missIndex1 && k != missIndex2)
					sum += dwarf[k];
			}
			if(sum == 100) {
				answerFlag = true;
				for(k = 0; k < 9; k++) {
					if(k != missIndex1 && k != missIndex2)
						ans_dwarf[ans_dwarf_index++] = dwarf[k];
				}
				break;
			}
		}
		if(answerFlag)
			break;
	}

	sort(ans_dwarf, ans_dwarf+7); //default가 오름차순
	for(i = 0; i < 7; i++) {
		cout << ans_dwarf[i] << '\n';
	}

	return 0;
}