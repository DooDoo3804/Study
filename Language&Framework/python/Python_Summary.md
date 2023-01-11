# Python Summary

### 기초 문법

##### 들여쓰기

코드 블록을 구분할 때 들여쓰기를 사용

4칸(space bar 4번) 또는 1탭(Tab키 1번)을 입력

#### 변수

객체를 참조하기 위해 사용되는 이름

객체 : 숫자, 문자, 클래스 등 값을 가지고 있는 모든 것

- 할당 연산자 (=)
- 데이터의 타입을 확인 type()
- 해당 값의 메모리 주소를 확인 id()

#### 식별자

식별하는데 사용되는 이름

- 첫글자에 숫자가 올 수 없다
- 길이제한이 없음
- 내장함수(built in)의 이름은 사용할 수 없음

#### 사용자 입력

input()으로 입력받는다

#### 주석

주석은 #으로 표시한다

'''를 쓰면 여러 줄을 주석처리 할 수 있다

#### 문자열 (string type)

모든 문자는 str로 표현된다

' 나 "로 표현한다

- 이스케이프 시퀀스
  - \n 줄바꿈
  - \t 탭
  - \r\ 캐리지리턴
  - \o 널(null)
  - \ \ 역슬래시
  - \\' 단일 인용 부호
  - \\" 이중 인용 부호

##### string interpolation

```python
print('%s' % name) # %-formatting
print('{}'.format(name)) # str.format()
print(f'{name}') # f string
```

#### 컨테이너

##### 리스트

[] 또는 list()를 통해 만들 수 있다

##### 튜플

(value1, value2)

수정 불가능

```python
a = 1, # 하나의 항목으로 구성된 튜플
print(a) # (1,)
```

##### 딕셔너리 (dictionary)

```python
{}
dict()
```

### 형변환

|            | string | list     | tuple    | range | set      | dictionary |
| ---------- | ------ | -------- | -------- | ----- | -------- | ---------- |
| string     |        | O        | O        | X     | O        | X          |
| list       | O      |          | O        | X     | O        | X          |
| tuple      | O      | O        |          | X     | O        | X          |
| range      | O      | O        | O        |       | O        | X          |
| set        | O      | O        | O        | X     |          | X          |
| dictionary | O      | O(KEY만) | O(KEY만) | X     | O(KEY만) |            |

### 연산자

divmod : qutient 와 ramainder 두개를 반환

##### 논리 연산자

- and : 둘 모두 True 일때 True

- or : 둘 중 하나라도 True 일때 True

- not : inverter

- ##### 단축평가

  - ```python
    print(3 and 5) # 5
    print(3 and 0) # 0 첫 값이 True라도 두번 째 값을 확인함 False
    print(0 and 3) # 0 첫 값이 False이면 바로 False
    print(0 and 0) # 0
    ```

  - ```python
    print(5 or 3) # 5
    print(3 or 0) # 3 첫 번째 값이 True 면 바로 True 반환
    print(0 or 3) # 3 첫 값이 False라도 두 번째 값 까지 확인함
    print(0 or 0) # 0
    ```

#### 연산자 우선순위

1. `()`을 통한 grouping
2. Slicing
3. Indexing
4. 제곱연산자 `**`
5. 단항연산자  `+`, `-` (음수/양수 부호)
6. 산술연산자 `*`, `/`, `%`
7. 산술연산자 `+`, `-`
8. 비교연산자, `in`, `is`
9. `not`
10. `and` 
11. `or`

#### 비 시퀀스형 컨테이너

##### 세트

빈 세트는 set()로 생성

세트에는 중복된 값이 존재할 수 없다

set = {1, 2, 3}

차집합(-) / 합집합(|) / 교집합(&)

___

### 제어문

#### 조건문

```python
if <expression>:
    <코드 블럭>
elif <expression>:
    <코드 블럭>
else:
    <코드 블럭>
```

##### 조건 표현식

```python
(True일 때의 값) if <조건식> else (False일 때의 값)
```

#### 반복문

##### while 반복문

```python
while <조건식>:
    <코드 블럭>
```

##### for 문

```python
for <임시변수> in <순회가능한데이터(iterable)>:
    <코드 블럭>
```

enumerate

```python
for idx, member in enumerate(members):
    print(idx, member) # 인덱스와 값이 같이 나온다
```

##### list comprehension

```python
[expression for 변수 in iterable]
list(expression for 변수 in iterable) # 한 줄로 작성하는 방법
```

##### dictionart comprehension

```python
{키: 값 for 요소 in iterable}
dict({키: 값 for 요소 in iterable}) # dictionary도 가능하다
```

- break - 반복문을 종료한다
- continue - countinue이후의 코드를 실행하지 않고 진행한다
- pass - _아무것_도 진행하지 않는다
- for ~ else - for문을 끝까지 진행한 이후에 실행된다

---

### 함수

def 로 정의한다

`return`을 작성해 주어야 한다 (작성하지 않고 print로 반환하는 경우 함수 호출 시에는 None이 반환된다)

__기본 인자값(Default Argument Value)을 가지는 인자 다음에 기본 값이 없는 인자를 사용할 수는 없다__

```python
def greeting(age, name='peter'):
    return f'{name}은 {age}살입니다.' # 기본 인자들은 마지막에 제시해 주어야 한다
```

##### 키워드 인자

아래와 같이 `키워드 인자`를 활용한 다음에 `위치 인자`를 활용할 수는 없습니다.

```python
greeting(age=24, '철수') # 이처럼 사용할 수는 없다
greeting(24, name='철수') # 올바른 예시
```

##### 가변 인자

```python
def func(a, b, *args): # *args 임의의 개수의 위치 인자를 받는다
def func(**kwargs): # **kwargs 는 dict의 형태로 처리된다
```

----

### 함수의 스코프

- `L`ocal scope: 함수

- `E`nclosed scope: 특정 함수의 상위 함수 

- `G`lobal scope: 함수 밖의 변수 혹은 import된 모듈

- `B`uilt-in scope: 파이썬안에 내장되어 있는 함수 또는 속성

- LEGB 로 갈수록 넓은 범위이다

---

#### filter

- iterable에서 function의 반환된 결과가 `True` 인 것들만 구성하여 반환합니다.

- `filter object` 를 반환합니다.

```python
filter(functionm iterable)
```

#### zip

- 복수의 iterable 객체를 모아(`zip()`)줍니다.

- 결과는 튜플의 모음으로 구성된 `zip object` 를 반환합니다.

```python
zip(iterables)
```

#### lambda 함수

- 표현식을 계산한 결과 값을 반환하는 함수로, 이름이 없는 함수여서 익명함수라고도 불립니다.
- return 문을 가질 수 없고, 간단한 조건문 외의 구성이 어렵습니다.
- 함수를 정의해서 사용하는 것보다 간결하게 사용 가능합니다.

```python
def triangle_area(b, h):
    return 0.5 * b * h
lambda b, h: 0.5 * b * h
```

---

### 모듈

import 로 모듈을 가져온다

`from 패키지 import 모듈`

모듈 : 특정 기능을 .py 파일 단위로 작성한 것

패키지 : 여러 모듈들의 집합

---

### 데이터 구조

#### 문자열 (string)

##### .find(x)

- x의 첫 번째 위치 반환 없으면 -1 반환

##### .index(x)

- x의 첫 번째 위치를 반환 없으면 ___오류___

##### .startwith(x) / .endwith(x)

- 문자열이 x로 시작하면/끝나면 True를 반환

##### .isdecimal()

- 문자열이 0~9까지의 숫자

##### .isdigit()

- 문자열이 숫자로 이루어져 있는가

##### .isdecimal()

- 문자열이 수의 형태로 읽을 수 있는가

##### .reaplace(old, new[,count])

- old 문자를 new로 count 개수 만큼 바꿈

##### .strip([chars])

- 특정한 문자들을 지정하면 문자열의 모든 조합을 제거함 ___(인자가 없을 경우 공백을 제거)___

##### .split([chars])

- 문자열을 특정한 단위로 나눠 리스트로 반환

##### '문자열'.join(iterable)

#### 리스트(list)

##### .append(x)

##### .extend([iterable])

##### .insert(i, x)

##### .remove(x)

- x가 존재하지 않으면 ___오류___

##### .pop([i])

- 정해진 위치 i의 값을 반환하고 삭제한다 (i가 없으면 ___마지막 항목___을 반환하고 삭제)

---

### 얕은 복사와 깊은 복사

##### 변경 불가능한 데이터

- 리터럴
  - 숫자 글자 Boolean (id가 존재하기 때문)
- range()
- tuple()
- frozenset()

##### 변경 가능한 데이터

- list
- dict
- set

#### 할당

할당의 경우 변수만 복사하기 때문에 그 id 는 동일하다

따라서 어느 한쪽의 데이터를 바꾸면 나머지 한쪽도 같이 변화한다

#### 얕은 복사 Shallow copy

##### list()

##### slice 연산자 [:]



#### 깊은 복사 Deep copy

##### deep copy

```python
import copy
a = [1, 2, [1, 2]]
b = copy.deepcopy(a) # copy 모듈을 활용
```