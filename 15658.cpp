#include <iostream>
#include <vector>
#include <algorithm>
#define PLUS 0
#define MINUS 1
#define MULTIPLY 2
#define DIVIDE 3
using namespace std;

int main() {
	int N;
	cin >> N;

	int num[N];
	for(int i = 0; i < N; i++)
		cin >> num[i];

	int oper[4];
	for(int i = 0; i < 4; i++)
		cin >> oper[i];

	int totalCnt;
	int result;
	int index;
	int max = -1000000000;
	int min = 1000000000;
	for(int plusCnt = 0; plusCnt <= oper[0]; plusCnt++) {
		for(int minusCnt = 0; minusCnt <= oper[1]; minusCnt++) {
			for(int multiplyCnt = 0; multiplyCnt <= oper[2]; multiplyCnt++) {
				for(int divideCnt = 0; divideCnt <= oper[3]; divideCnt++) {
					totalCnt = plusCnt + minusCnt + multiplyCnt + divideCnt;
					if(totalCnt == N-1) {
						vector<int> order;
						for(int i = 0; i < plusCnt; i++)
							order.push_back(PLUS);
						for(int i = 0; i < minusCnt; i++)
							order.push_back(MINUS);
						for(int i = 0; i < multiplyCnt; i++)
							order.push_back(MULTIPLY);
						for(int i = 0; i < divideCnt; i++)
							order.push_back(DIVIDE);

						do {
							index = 0;
							result = num[index];
							for(int i = 0; i < N-1; i++) {
								switch(order[i]) {
									case PLUS:
										result += num[++index];
										break;
									case MINUS:
										result -= num[++index];
										break;
									case MULTIPLY:
										result *= num[++index];
										break;
									case DIVIDE:
										result /= num[++index];
										break;
								}
							}
							if(result > max)
								max = result;
							if(result < min)
								min = result;
						} while(next_permutation(order.begin(), order.end()));
					}
				}
			}
		}
	}
	cout << max << '\n';
	cout << min << '\n';
	return 0;
}