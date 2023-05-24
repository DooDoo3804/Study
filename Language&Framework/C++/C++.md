# 1.  C++ 기초

## (1) C++ 시작

### 선행처리문

`#include` - 외부에 선언된 함수나 상수 등을 사용하기 위해서 헤더파일의 내용을 현재 파일에 포함할 때 사용

`# include <iostream>` - 표준 입출력 함수를 사용하기 위함



## (2) 변수와 상수

### 변수

변수는 선언을 하고 초기화를 해주어야 함

> 만약 전역 변수로 선언하는 경우 0으로 입력을 받기 때문에 초기화를 안해도 된다.

```c++
int num1, num2;
double num3 = 1.23, num4 = 4.56;
```

### 상수

### 리터럴 상수

변수와 달리 데이터가 저장된 메모리 공간을 가지고 있지 않음

```c++
int a = 4;
```

### 심볼릭 상수

변수와 마찬가지로 이름을 갖는 상수

선언과 동시에 반드시 초기화 해주어야함

```c++
const int ages = 30;
```

1. 상수의 타입을 명시적으로 지정
2. 구조체와 같은 복잡한 사용자 정의 타입에도 사용 가능
3. 특정 함수나 파일에서만 사용할 수 있도록 제한 가능



# 2. 컨테이너

같은 타입의 여러 객체를 저장하는 일종의 집합

## (1) 시퀸스 컨테이너

- 데이터를 선형으로 저장

- 삽입된 요소의 순서가 그대로 유지

> Vector / deque / list / foward_list

### 1) Vector

> Array의 경우 크기가 고정되어 있어 원소를 추가하거나 삭제가 불가능하다. Vector는 요소가 추가되거나 삭제될 때마다 자동으로 메모리를 재할당하여 크기를 동적으로 변경

````C++
vector <템플릿인수> 객체이름(생성자인수);
````

템플릿인수 : 저장될 요소의 타입

생성자인수 : 생략하면 요소를 가지지 않는 빈 벡터를 생성

```c++
vector <int> vc = {10, 20, 30};
vector <int> vc(10);
// 크기가 10인 vector
vector <int> vc(10, -1);
// 크기가 10이고 -1로 초기화한 벡터
vector.resize(N)
// 벡터 크기를 N으로 재설정
    
/*
	.size() 컨테이너에 저장된 요소의 개수를 반환
	.push_back() 컨테이너 마지막 요소로 해당 데이터 추가
	.begin() 컨테이너 첫 요소를 가리키는 반복자를 반환
	.end() 컨테이너 마지막 요소 바로 다음을 가리킴
*/
```





### set container

노드 기반 컨테이너로 균형 이진트리로 구현

Key라 불리는 원소들의 집합 / Key는 중복 안됨

insert로 삽입이 되면 원소는 자동으로 정렬됨

```c++
// 선언
set <int> s;

s.begin();
s.end();
s.clear();
s.count(k);
s.empty();
s.insert(k);
// k 찾기 없으면 s.end() 반환
s.find(k);
// k key에 해당하는 value
s[k];
```

### Stack



### queue

```c++
#include <queue>

priority_queue<자료형, Container, 비교함수> 변수명;
// 선언한 자료형 변수들을 비교함수에 따라 정렬하는 Priority_Queue를 선언
priority_queue<자료형> 변수명;
// 선언한 자료형 변수들을 내림차순에 따라 정렬하는 Priority_Queue를 선언
.push();
// 원소 삽입 이후 자동으로 정렬됨
.pop();
// 맨 앞에 있는 원소를 삭제
```







# 함수

## 함수의 정의

```c++
#include <iostream>
using namespace std;  
int SmallNum(int num1, int num2)
{
    if (num1 <= num2)
    {
        return num1;
    }
    else
    {
        return num2;
    }
}

// 함수의 원형 선언
int SmallNum(int, int);
// 반환타입 SmallNum(매개변수목록);

int main(void)
{
    int result;  
    result = SmallNum(4, 6);
    cout << " 두 수 중 더 작은 수는 " << result << "입니다." << endl;
    result = SmallNum(8, 6);
    cout << " 두 수 중 더 작은 수는 " << result << "입니다." << endl;
    result = SmallNum(2, 8);
    cout << " 두 수 중 더 작은 수는 " << result << "입니다." << endl;
    return 0;
}
```

함수의 원형을 main앞에 정의 해야함

### 스택 오버플로우 (Stack overflow)

> 메모리 구조 중 스택 영역에서 해당 프로그램이 사용할 수 있는 메모리 공간 이상을 사용하려고 할 때 발생

# 구조체

> Structure type 사용자가 C++의 기본 타입을 가지고 새롭게 정의할 수 있는 사용자 정의 타입
>
> 다양한 타입의 변수를 집합으로 묶어서 나타냄 / 클래스(class)의 기초

- 구조체의 선언

```c++
struct book
{
    char title[30];
    char author[30];
    int price;
}
```

구조체 멤버 변수를 선언할 때 struct 키워드를 생략할 수 있음

- 구조체 멤버 변수 선언

```c++
book web_book;
```

- 멤버 변수 선언과 초기화

변수 초기화는 중괄호를 사용한 초기화 리스트를 사용

```c++
book web_book = {"title", "Jhon do", 200000}
```

구조체를 인수로 전달 할 수도 있고, 함수의 반환 값으로도 사용 가능

함수의 인수로 전달할 때는 수정이 불가능 하도록 `const`로 선언해 주어야 함

구조체를 정의할 때 멤버 변수로 또 다른 구조체를 포함할 수 있음

```c++
struct Name
{
    string first;
    string last;
};

struct Friends
{
    Name first_name;
    string address;
    string job;
};
```

## 패딩

구조체는 다양한 크기의 타입을 멤버 변수로 가질 수 있음

바이트 패딩 - 컴파일러는 메모리의 접근을 쉽게 하려고 크기가 가장 큰 멤벼 변수를 기준으로 모든 멤버 변수의 메모리 크기를 맞춤, 이때 추가되는 바이트를 패딩 바이트

## 공용체 (union)

`union` 키워드를 사용하여 선언하며, 모든 면에서 구조체와 같지만, 모든 멤버 변수가 하나의 메모리 공간을 공유함. 따라서 공용체는 한 번에 하나의 멤버 변수밖에 사용할 수 없음

## 열거체 (enumerated types)

`enum` 키워드를 사용하여 선언. 새로운 타입을 선언하면서 동시에 그 타입이 가질 수 있는 정수형 상숫값도 같이 명시



# 포인터

메모리의 `주소값`을 저장하는 변수이며, 포인터 변수라고도 부름

## 포인터 연산자

### 주소 연산자 (&)

변수의 이름 앞에 사용되며, 해당 변수의 주소값을 반환

### 참조 연산자 (*)

포인터의 이름이나 주소 앞에 사용하여, 포인터에 저장된 주소에 저장되어 있는 값을 반환

```
타입* 포인터이름;
```

초기화 하지 않으면 어딘지 모르는 메모리 장소에 값을 저장하므로 매우 위험한 행동, 포인터는 반드시 선언과 동시에 초기화 되어야함. 보통 NULL 로 초기화...?

```c++
타입* 포인터이름 = &변수이름;
타입* 포인터이름 = &주소값;
```

선언된 포인터는 참조 연산자(*)를 사용해서 참조할 수 있음

```c++
int x = 7;            // 변수의 선언
int *ptr = &x;      // 포인터의 선언
int **pptr = &ptr; // 포인터의 참조
```

## 포인터 연산

다음의 규칙을 따름

1. 포인터 끼리의 덧셈, 곱셈, 나눗셈은 의미가 없음
2. 포인터 끼리의 뺄셈은 두 포인터 사이의 상대적 거리를 나타냄
3. 포인터에 정수를 더하거나 뺼 수는 있지만, 실수와의 연산은 허용하지 않음
4. 포인터끼리 대입하거나 비교할 수 있음

### 포인터와 배열

어떤 부분에서는 서로를 대체할 수 있음

배열의 크기를 계산할 때에는 배열의 이름과 포인터 사이에 큰 차이가 발생

배열의 이름을 이용한 크기 계산에서는 배열의 크기가 int형 배열 요소 3개의 크기인 12바이트로 제대로 출력

포인터를 이용한 크기 계산에서는 배열의 크기가 아닌 포인터 변수 자체의 크기가 출력된는 차이가 있음





# 클래스

> 객체 지향 프로그래밍의 특징 중 하나인 추상화를 사용자 정의 타입으로 구현한 것

클래스의 선언 밖에서 멤버 함수를 정의할 때에는 범위 지정 연산자(::)를 사용하여 해당 함수가 어느 클래스에 속하는지를 명시해야 함.

```c++
void Book::Move(int page) { current_page_ = page; }
```

하나의 클래스에서 생성된 인스턴스는 각각 독립된 메모리 공간에 저장된 자신만의 멤베 변수를 가지지만, 멤버 함수는 모든 인스턴스가 공유



## pair 클래스

> 서로 연관된 2개의 데이터 쌍을 묶어서 다룰 때 편리

```c++
pair<int, int> p;
p.fisrt;
// p의 첫번째 인자를 반환
p.second;
// p의 두번째 인자를 반환
mape_pair(value1, value2);
// 값1, 값2를 한쌍으로 하는 pair를 만들어서 반환
```

보통 vector와 함께 많이 사용한다

pair는 대소를 할 경우 첫 번째를 먼저 비교하고 첫번 째 값이 같을 경우 두 번째로 판단

```c++
vector<pair<int, int>> p;
```





# #include 

## algorithm

`#include <algorithm>`로 선언해줌

`sort` 등 을 사용할 수 있음

- next_permutation

> 부분집합을 구할 때 사용

```c++
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		sort(input.begin(), input.end());
        // next_permutation 을 사용하여 부분집합을 구할 수 있음
		while (next_permutation(input.begin(), input.end())) {
			for (int j = 0; j < input.size(); j++) {
				cout << input[j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
```

오름차순으로 정렬된 값을 가진 컨테이너로만 사용 가능함 / 즉, 사용 이전에 sort로 정렬을 해줘야 함

기본값으로 오름차순으로 순열을 생성해 줌

**중복이 있는 원소는 중복을 제외하고 순열을 만들어줌!!**











## string



# Algorithm

## auto, auto&, auto*

### auto

초기화 값에 따라서 타입을 추런해서 결정해줌

참조의 경우는 복사나 대입과 다르기 때문에 컴파일러가 알 수 없어서 참조로 받아지지 않음!!

```c++
int c = 0;
for (auto tm : time_list) {
    tm.second = c++;
}
```

### auto& // auto*

레퍼런스로 받을 수 있다

복사보다 참조하여 사용하는 경우가 더 많음

```c++
int c = 0;
for (auto& tm : time_list) {
    tm.second = c++;
}
```



## cout 소수점 출력

```c++
double ans = 123.4567;

// 숫자 2개로 고정해서 출력
// 이것만 쓰면 소수점과 관련이 없다
cout.precision(2);

// fixed를 쓰면 소수점을 고정하겠다는 의미
// precision(2)가 위에 있으므로 소수점 2자리까지 반올림하여 출력해줌
cout << fixed << ans
```



## using namespace

```c++
using namespace std;
std::cin << a;
std::cin << b;
// 등을 사용하게 해줌

또는 라이브러리를 불러와서 사용하게 해줌
```

권장되는 사용은 아니다.

만약 서로 다른 라이브러리에서 같은 이름의 함수가 있다고 하면 함수 사용에 있어서 충돌이 일어나기 때문!!

## ios::sync_with_stdio(0);

```c++
ios::sync_with_stdio(0);
```

싱글 스레드 환경에서만 사용. C 표준 stream과 C++ 표준 stream의 동기화를 끊음

따라서 C의 버퍼가 사라져 버퍼의 수가 줄어들었기 때문에 속도가 빨라짐

## cin.tie(0); cout.tie(0);

```c++
cin.tie(0);
cout.tie(0);
```

cin을 cout으로부터 untie 한다.

> cin cout이 scanf와 printf에 비해서 속도가 많이 느림
>
> 이를 가속화하기 위해 사용

## string to int

```c++
string sub_num = "1"
cout << stoi(sub_num);
// 1 int로 출력
```



## 숫자 char 를 int로 변환

```c++
int('3') - '0';
// int 3을 의미
```

char * 타입이라면 아래와 같이 가능

```c++
int num[1] = aoti('3');
// char[N], char* 로 표현이 되는 문자열에서만 동작
```

## fill

```c++
fill(dp[0], dp[5000], -1);
```

fill 을 이용하면 배열, 다차원 배열도 같은 값으로 채울 수 있다.

## memset

메모리의 내용을 원하는 크기만큼 특정 값으로 세팅할 수 있는 함수

```c++
memset(void* ptr, int value, size_t num);
// 메모리의 시작 주소 , 메모리에 세팅하고자 하는 값 , 길이
```

실패하면 NULL을 반환 성공하면 ptr을 반환



## Dijkstra

> 출발 노드와 도착 노드를 설정
>
> 최단 거리 테이블을 초기화
>
> 현재 위치한 노드의 인접 노드 중 방문하지 않은 노드를 구분하고, 방문하지 않은 노드 중 거리가 가장 짧은 노드를 선택한다. 그 노드를 방문 처리
>
> 해당 노드를 거쳐 다른 노드로 넘어가는 간선 비용을 계산해 '최단 거리 테이블'을 업데이트

우선순위 큐를 통한 구현 (힙)

```c++
# define INF 999999999

vector<int> dijkstra(int start, int N, vector<pair<int, int>> graph[])
{
    // 거리를 저장할 리스트 초기화
    vector<int> dist(N, INF);
    // 우선순의 큐 선언
    priority_queue<pair<int, int>> pq;
    
    // 시작 노드 거리 0으로 초기화
    dist[start] = 0;
    // 우선순위 큐에 넣기
    pq.push({0, start});
    
    while (!pq.empty()){
        // 큐에서 꺼내 방문하고 있는 정점의 거리
        int cur_dist = -pq.top().first;
        // 정점의 인덱스
        int cur_node = pq.top().second;
        pq.pop();
        
        for(int i = 0; i < graph[cur_node].size(); i++) {
            // 인접 정점 번호
            int nxt_node = graph[cur_node][i].first;
            // 인접 정점까지 거리
            int nxt_dist = cur_dist + graph[cur_node][i].second;
            
            // 지금 계산한 것이 기존 값보다 작다면
            // 거리 업데이트 하고 우선순위 큐에 넣기
            if (nxt_dist < dist[nxt_node]) {
                dist[nxt_node] = nxt_dist;
                pq.push({ -nxt_dist, nxt_node });
            }
        }
    }
    return dist;
}

int main() {
    // 노드의 개수
    const int N = 10;
    // 간선의 개수
    int E = 20;
    vector<pair<int, int>> graph[N];
    for (int i = 0; i < E; i++) {
        // 시작점 끝점 가중치
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back({ to, cost });
        graph[to].push_back({ from, cost });
    }
    vector<int> dist = dijkstra(0, N, graph);
    cout << dist[N-1];
    return 0;
}
```

## Segment Tree

주어진 쿼리에 대해 빠르게 응답하기 위해 만들어진 자료구조

### 1) 세그먼트 트리의 전체 크기

```
<<크기가 N인 배열이 있다면>>
트리의 높이 - ceil(log2(N))
세그먼트 트리의 크기 - 1 << (트리의 높이 + 1)
```

### 2) 트리 만들기

> 세그먼트 트리는 full binary tree에 가깝기에 배열에 모든 값들이 꽉차서 올가능성이 매우 높기 때문에 포인터보다는 배열을 사용하여 생성

루트 노드 = 1로 생각

이때 루트 노드의 왼쪽은 2번, 오른쪽은 3번이 된다.

2번 노드의 왼쪽은 4번, 오른쪽은 5번이 된다.

3번  노드의 왼쪽은 6번, 오른쪽은 7번인 된다. ,,,

```
<<현재 노드의 번호가 node일 때>>
노드의 왼쪽 자식 배열 번호 : node * 2
노드의 오른쪽 자식 배열 번호 : node * + 1
```

tree 배열은 세그먼트 트리가 만들어지는 배열

arr 배열은 처음에 입력받아 생성된 배열

#### 1. 초기화 과정(init)

```c++
long long init(vector<long long> &arr, vector<long long> &tree, int node, int start, int end) {
    if (start == end) return tree[node] = arr[start];
    int mid = (end + start) / 2;
    return tree[node] = init(arr, tree, node * 2, start, mid) + init(arr, tree, node * 2 + 1, mid + 1, end);
}
```



#### 2. 갱신 과정 (update)

```c++
void update(vector<long long> &tree, int node, int start, int end, int index, long long diff) {
    if (!(start <= index && index <= end)) return;
    tree[node] += diff;
    if (start != end) {
        int mid = (start + end) / 2;
        update(tree, node * 2, start, mid, index, diff);
        update(tree, node * 2 + 1, mid + 1, end, index, diff);
    }
}
```

#### 3. 합 과정(sum)

```c++
long long sum(vector<long long> &tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return sum(tree, node * 2, start, mid, left, right) + sum(tree, node * 2 + 1, mid + 1, left, right);
}
```
