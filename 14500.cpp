#include <iostream>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M; // 4 <= N, M <= 500

	int arr[N][M];
	int i, j;

	for(i = 0; i < N; i++) {
		for(j = 0; j < M; j++) {
			cin >> arr[i][j]; // 1 <= arr <= 1000
		}
	}

	int max = 0;
	int tmp;

	//Shape 1: __ |
	for(i = 0; i < N; i++) { // __
		for(j = 0; j <= M-4; j++) {
			tmp = arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i][j+3];
			if(tmp > max)
				max = tmp;
		}
	}

	for(i = 0; i <= N-4; i++) { // |
		for(j = 0; j < M; j++) {
			tmp = arr[i][j]+arr[i+1][j]+arr[i+2][j]+arr[i+3][j];
			if(tmp > max)
				max = tmp;
		}
	}

	//Shape 2: ㅁ
	for(i = 0; i <= N-2; i++) {
		for(j = 0; j <= M-2; j++) {
			tmp = arr[i][j]+arr[i][j+1]+arr[i+1][j]+arr[i+1][j+1];
			if(tmp > max)
				max = tmp;
		}
	}

	// Shape 3: |_ |-- -| _|
	for(i = 0; i <= N-3; i++) {
		for(j = 0; j <= M-2; j++) {
			tmp = arr[i][j]+arr[i+1][j]+arr[i+2][j]+arr[i+2][j+1];
			if(tmp > max)
				max = tmp;
		}
	}

	for(i = 0; i <= N-2; i++) {
		for(j = 0; j <= M-3; j++) {
			tmp = arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j];
			if(tmp > max)
				max = tmp;
		}
	}

	for(i = 0; i <= N-3; i++) {
		for(j = 0; j <= M-2; j++) {
			tmp = arr[i][j]+arr[i][j+1]+arr[i+1][j+1]+arr[i+2][j+1];
			if(tmp > max)
				max = tmp;
		}
	}

	for(i = 0; i <= N-2; i++) {
		for(j = 0; j <= M-3; j++) {
			tmp = arr[i][j+2]+arr[i+1][j]+arr[i+1][j+1]+arr[i+1][j+2];
			if(tmp > max)
				max = tmp;
		}
	}

	for(i = 0; i <= N-3; i++) {
		for(j = 0; j <= M-2; j++) {
			tmp = arr[i][j+1]+arr[i+1][j+1]+arr[i+2][j]+arr[i+2][j+1];
			if(tmp > max)
				max = tmp;
		}
	}

	for(i = 0; i <= N-2; i++) {
		for(j = 0; j <= M-3; j++) {
			tmp = arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+2];
			if(tmp > max)
				max = tmp;
		}
	}

	for(i = 0; i <= N-3; i++) {
		for(j = 0; j <= M-2; j++) {
			tmp = arr[i][j]+arr[i][j+1]+arr[i+1][j]+arr[i+2][j];
			if(tmp > max)
				max = tmp;
		}
	}

	for(i = 0; i <= N-2; i++) {
		for(j = 0; j <= M-3; j++) {
			tmp = arr[i][j]+arr[i+1][j]+arr[i+1][j+1]+arr[i+1][j+2];
			if(tmp > max)
				max = tmp;
		}
	}

	// Shape 4: |-|
	for(i = 0; i <= N-3; i++) {
		for(j = 0; j <= M-2; j++) {
			tmp = arr[i][j]+arr[i+1][j]+arr[i+1][j+1]+arr[i+2][j+1];
			if(tmp > max)
				max = tmp;
		}
	}

	for(i = 0; i <= N-2; i++) {
		for(j = 0; j <= M-3; j++) {
			tmp = arr[i][j+1]+arr[i][j+2]+arr[i+1][j]+arr[i+1][j+1];
			if(tmp > max)
				max = tmp;
		}
	}

	for(i = 0; i <= N-3; i++) {
		for(j = 0; j <= M-2; j++) {
			tmp = arr[i][j+1]+arr[i+1][j]+arr[i+1][j+1]+arr[i+2][j];
			if(tmp > max)
				max = tmp;
		}
	}

	for(i = 0; i <= N-2; i++) {
		for(j = 0; j <= M-3; j++) {
			tmp = arr[i][j]+arr[i][j+1]+arr[i+1][j+1]+arr[i+1][j+2];
			if(tmp > max)
				max = tmp;
		}
	}

	//Shape 5: ㅜ ㅓ ㅗ ㅏ
	for(i = 0; i <= N-2; i++) { // ㅜ
		for(j = 0; j <= M-3; j++) {
			tmp = arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+1];
			if(tmp > max)
				max = tmp;
		}
	}

	for(i = 0; i <= N-3; i++) { // ㅓ
		for(j = 0; j <= M-2; j++) {
			tmp = arr[i][j+1]+arr[i+1][j]+arr[i+1][j+1]+arr[i+2][j+1];
			if(tmp > max)
				max = tmp;
		}
	}

	for(i = 0; i <= N-2; i++) { // ㅗ
		for(j = 0; j <= M-3; j++) {
			tmp = arr[i][j+1]+arr[i+1][j]+arr[i+1][j+1]+arr[i+1][j+2];
			if(tmp > max)
				max = tmp;
		}
	}

	for(i = 0; i <= N-3; i++) { // ㅏ
		for(j = 0; j <= M-2; j++) {
			tmp = arr[i][j]+arr[i+1][j]+arr[i+2][j]+arr[i+1][j+1];
			if(tmp > max)
				max = tmp;
		}
	}
	
	cout << max << '\n';
	return 0;
}