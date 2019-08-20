#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main() {
	int M;
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> M; // 1 <= M <= 3,000,000

	string order;
	int num;
	int S[21];

	for(int i = 0; i < 21; i++)
		S[i] = 0;

	for(int i = 0; i < M; i++) {
		cin.tie(NULL);
		ios_base::sync_with_stdio(false);
		cin >> order;
		switch(order[1]) {
			case 'd': //add
				cin.tie(NULL);
				ios_base::sync_with_stdio(false);
				cin >> num;
				if(S[num] == 0)
					S[num] = 1;
				break;
			case 'e': //remove
				cin.tie(NULL);
				ios_base::sync_with_stdio(false);
				cin >> num;
				if(S[num] == 1)
					S[num] = 0;
				break;
			case 'h': //check
				cin.tie(NULL);
				ios_base::sync_with_stdio(false);
				cin >> num;
				int check;
				if(S[num] == 1)
					check = 1;
				else
					check = 0;
				cout << check << '\n';
				break;
			case 'o': //toggle
				cin.tie(NULL);
				ios_base::sync_with_stdio(false);
				cin >> num;
				if(S[num] == 1)
					S[num] = 0;
				else
					S[num] = 1;
				break;
			case 'l': //all
				for(int j = 1; j <= 20; j++)
					S[j] = 1;
				break;
			case 'm': //empty
				for(int j = 1; j <= 20; j++)
					S[j] = 0;
				break;
		}
	}
	return 0;
}