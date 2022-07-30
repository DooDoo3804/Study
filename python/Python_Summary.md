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