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



# 클래스



# #include 

## algorithm

`#include <algorithm>`로 선언해줌

`sort` 등 을 사용할 수 있음



## vector

vector 사용 가능



## map



## string



# Algorithm

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
