# 1.  C++ 기초

## (1) C++ 시작

### 선행처리문

`#include` - 외부에 선언된 함수나 상수 등을 사용하기 위해서 헤더파일의 내용을 현재 파일에 포함할 때 사용

`# include <iostream>` - 표준 입출력 함수를 사용하기 위함

`#include <string>` - string을 사용하기 위함



## (2) 변수와 상수

### 변수

변수는 선언을 하고 초기화를 해주어야 함

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

# #include 

## <algorithm>

`#include <algorithm>`로 선언해줌

`sort` 등 을 사용할 수 있음



# Algorithm

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

