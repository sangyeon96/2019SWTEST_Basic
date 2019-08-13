# 2019SWTEST_Basic

[TOC]

## 나머지 연산 [10430]

ex) 1,000,000,007으로 9를 나눈 나머지를 출력하라.

int(4 bytes)의 최대값: 2^31-1

long long(8 bytes)의 최대값: 2^63-1

이 자료형을 넘어가는 숫자의 경우?



(A+B) % C = (A % C + B % C) % C

(A-B) % C = ( (A % C) - (B % C) + C) % C

(AxB) % C = ((A % C) x (B % C) ) % C



페르마의 소정리(드물다)

(A/B) % C = (A x B^C-2) % C(C는 소수, A, B는 서로소)



## 최대공약수 [2609, 9613]

최대공약수(GCD: Greatest Common Divisor)

=> 유클리드호제법을 활용하면 빠르다.

### 유클리드 호제법

a를 b로 나눈 나머지를 r이라고 했을 때, GCD(a, b) = GCD(b, r)과 같다.

r이 0이면 그 때 b가 최대공약수 이다.

ex) GCD(24, 16) = GCD(16, 8) = GCD(8, 0) = 8

#### 재귀함수 활용

```c++
int gcd(int a, int b) {
  if(b == 0) {
    return a;
  } else {
    return gcd(b, a%b);
  }
}
```

시간복잡도는 O(log N)이다.

#### 반복문 활용

```c++
int gcd(int a, int b) {
  while(b != 0) {
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}
```

시간복잡도는 재귀함수 활용했을 시와 같이 O(log N)이다.

### 세 수 이상의 최대공약수

GCD(a, b, c) = GCD(GCD(a, b), c)

## 최소공배수 [1934]

주어진 수의 곱 / GCD = 최소공배수

## 소수(Prime Number)

약수가 1과 자기자신 밖에 없는 수.

### 소수와 관련된 알고리즘

1. 어떤 수 N이 소수인지 아닌지 판별하는 방법
2. N보다 작거나 같은 모든 자연수 중에서 소수를 찾아내는 방법

### 1. 어떤 수 N이 소수인지 아닌지 판별하는 방법 [1978]

#### 방법1: O(N)

N이 소수가 되려면, 2보다 크거나 같고, **N/2보다 작거나 같은 자연수로 나누어 떨어지면 안된다.**

N = a x b

a = 2라고 하면, b = N/2여야 한다. N은 2 또는 N/2로 나누어 떨어지므로 안된다.

a = 3이라고 하면, b = N/3여야 한다. N은 3 또는 N/3으로 나누어 떨어지면 안된다.

N/3 < N/2이므로 2부터 N/2까지만 확인해도 소수인지 아닌지 판별할 수 있다.

```c++
bool prime(int n) {
  if(n < 2) {
    return false;
  }
  else {
    for (int i = 2; i <= n/2; i++) {
			if(n % i == 0) {
        return false;
      }
    }
    return true;
  }
}
```

#### 방법2: O(root N)

N이 소수가 되려면, 2보다 크거나 같고, **루트N보다 작거나 같은 자연수로 나누어 떨어지면 안된다.**

N = a x b

a <= root N이라고 하면,  b > root N이어야 한다.

고로 a, b 모두 root N보다 클 수는 없다.

그러므로 2부터 root N까지만 확인해도 소수인지 아닌지 판별할 수 있다.

ex 1) 24: 1, 2, 3, 4 / 6, 8, 12, 24

root 24 = 4.xx

4까지만 확인해도 소수인지 아닌지 알 수 있다.

ex 2) 36: 1, 2, 3, 4 / 6 / 9, 12, 18, 36

root 36 = 6

6까지만 확인해도 소수인지 아닌지 알 수 있다. 

```c++
bool prime(int n) {
  if(n < 2) {
    return false;
  }
  else {
    for(int i = 2; i*i <= n; i++) {
      if(n % i == 0) {
        return false;
      }
    }
    return true;
  }
}
```

### 2. N보다 작거나 같은 모든 자연수 중에서 소수를 찾아내는 방법

#### 에라토스테네스의 체: O(N log log N) by Prime Harmonic Series [1929]

1. 2부터 N까지 모든 수를 써놓는다.
2. 아직 지워지지 않은 수 중에서 가장 작은 수를 찾는다.
3. 그 수는 소수이다.
4. 이제 그 수의 배수를 모두 지운다.

```c++
int prime[100]; // 소수 저장
int pn=0; // 소수의 개수
bool check[101]; // 지워졌으면 true
int n = 100; // 100까지 소수
for(int i = 2; i <= n; i++) {
  if(check[i] == false) {
    prime[pn++] = i;
    for(int j = i*i; j <= n; j+=i) {
      check[j] = true;
    }
  }
}
```

#### 골드바흐의 추측 [6588]

2보다 큰 모든 짝수는 두 소수의 합으로 표현 가능하다.

=> 5보다 큰 모든 홀수는 세 소수의 합으로 표현 가능하다.