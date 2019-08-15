#include <iostream>
using namespace std;

int main() {
	int E, S, M; //Earth, Sun, Moon
	cin >> E >> S >> M;

	int MAX_E = 15;
	int MAX_S = 28;
	int MAX_M = 19;
	int MAX = 7980;
/*
	E % MAX_E + E의 배수
	S % MAX_S + S의 배수
	M % MAX_M + M의 배수
	이들의 공통 약수

	15*28*19 = 최대 7980년
*/

	int check[MAX+1];
	int i;

	//initialize
	for(i = 1; i <= MAX; i++)
		check[i] = 0;

	//check E
	for(i = E % MAX_E; i <= MAX; i += MAX_E)
		check[i] += 1;

	for(i = S % MAX_S; i <= MAX; i += MAX_S)
		check[i] += 2;

	for(i = M % MAX_M; i <= MAX; i += MAX_M)
		check[i] += 3;

	for(i = 1; i <= MAX; i++) {
		if(check[i] == 6)
			break;
	}

	cout << i << '\n';

	return 0;
}