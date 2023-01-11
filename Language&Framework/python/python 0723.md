# 파이썬 기초

### 조건문

- ```python
  if : 
  elif :
  else :
  ```

#### - 조건 표현식(삼항 연산자)

- ```python
  (true인 경우 값) if (조건) elese (flase 인 경우 값)
  ```



### for 문

- ```python
  grades = {'join' : 80, 'eric' : 90}
  for student, grade in grades.items():
      print(student, grade)
  #dictionary.item() 은 key와 value를 모두 반환한다.
  #dictionary.get('key') 은 key값에 해당되는 value 값을 가져온다.
  ```

### Enumerate

- ```python
  #idx, value를 반환
  for dix, value in emunerate(members):
      print(idx, number)
  #start를 설정하면 해당 값부터 순차적으로 증가
  #enumerate(members, start=1)
  ```

### List Comprehension

- ```python
  [code for 변수 in iterable if 조건식]
  ```

### Dictionary Comprehension

- ```python
  {key : value for 변수 in iterable if 조건식}
  ```

### 함수

- ```python
  def name(paramter):
      pass
  	return
  #parameter는 = 를 활영하여 기본값을 설정할 수 있다
  ```

  - 여러 값을 return 하려면 tuple의 형태로 작성해야 한다.
  - return value1, value2 => (value1, value2)

##### 가변 인자

- *args : 숫자를 받음
- **kwargs : 문자를 받음 딕셔너리로 묶여서 처리된다.

### python Scope

- Built-in Scope : 파이썬이 실행중이면 유지
- Global Scope : 모듈이 호출된 시점 이후 혹은 인터프리터가 끝날 때까지 유지
- Enclosed Scope : 지역 범위 한 단계 위 범위
- Local Scope : 함수 안에서만 존재

### map

- ```python 
  map(function, iterable)
  ```

### zip

- ```python
  zip(*iterables)
  #복수의 iterable을 모아서 튜플의 형태로 반환
  ```

### 모듈

- ```python
  from 모듈 import 
  ```

  