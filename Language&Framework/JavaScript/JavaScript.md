# JavaScript

> 웹기술의 기반이 되는 언어
>
> 동적으로 변경할 수 있는 언어



## JavaScript 기초

### 세미콜론(semicolon)

예전에는 필수로 작성해야 했지만, 이제는 자동으로 세미콜론을 추가해주기 때문에 입력해주지 않아도 돌아감



### 들여쓰기, 코드블럭

2칸 들여쓰기

중괄호를 작성해주어야 함

일반적으로 Airbnb Style Guide를 따라 작성

- https://github.com/airbnb/javascript

- https://airbnb.io/javascript/react/



### 주석

`//` 주석



### 식별자

- 카멜 케이스
  - 변수, 객체, 함수
- 파스칼 케이스
  - 클래스, 생성자
- 대문자 스네이크 케이스(모든 문자 대문자)
  - 상수 / 재할당이 일어나지 않을 문자



### 변수 선언 키워드

재할당은 변수를 써서 다시 할당 / 재선언은 변수 선언을 통해 다시 할당

- let
  - 지역 변수 (동시에 값을 초기화)
  - 재할당 가능 / 재선언 불가
- const
  - 읽기 전용 상수 (동시에 값을 초기화)
  - 재할당/ 재선언 불가능
- var(쓰지마라!)
  - 변수를 선언 (동시에 값을 초기화)
  - 재할당 / 재선언 가능
  - ___권장되지 않는 변수 선언 !!___

선언만 하는 경우는 초기 값이 __undefined__

할당은 값을 할당해줌

초기화는 처음으로 값을 할당하는 부분



#### 호이스팅(hoisting)

변수는 선언 이전에 참조가 되는 현상

var로 선언하면 맨 위로 끌어올려져서 변수가 참조가능하게 됨

이를 방지하기 위해서 var를 사용하지 않음



기본적으로 const로 작성하고 재할당이 필요하면 let을 사용



### 데이터 타입

#### 원시 타입

#### 1. Number

정수 또는 실수형 숫자

NaN = Not a Number : 숫자가 아닌 모든 것들

#### 2. String

문자열을 표현

덧셈을 문자열 더할 수 있음

\n 이 줄바꿈

``를 사용하면 줄바꿈이 가능하고 중간에 변수 삽입( __${ }__ )도 가능

#### 3. Boolean

true / false

소문자로 표현



### 연산자

#### 동등 연산자(==)

비교시 타입을 변환해서 진행

#### 일치 연산자(===)

같은 객체이면서 타입까지 같은지 확인하는 연산자

이를 사용함

#### 논리 연산자

&& ||

#### 삼항 연산자

```javascript
const result = Math.PI > 4 ? 'Yep' : 'Nope'
```



### 조건문

#### if

```javascript
const name = 'manager'
if (name === 'admin') {
	console.log('관리자님 환영합니다.')
} else if (name === `namager`) {
	console.log(`매니저님 환영합니다.`)
} else {
	console.log(`${name}님 환영합니다.`)
}
```

#### switch(조건이 많으면 사용권장)

```javascript
const name = `홍길동`
switch(name) {
	case `홍길동` : {
        console.log(`관리자님 환영합니다.`)
        break
    }
    case `manager` : {
        console.log(`매니저님 환영합니다.`)
        break
    }
    default : {
        console.log(`${name}님 환영합니다.`)
    }
}
```

switch 문은 case로 나눠지며 break가 없으면 모든 케이스들을 훑고 지나간다. 

이를 막기 위해 break를 걸어줌

default 를 설정해 줄 수 있음 else와 같음 



### 반복문

#### while

```javascript
let i = 0
while (i<6) {
    console.log(i)
    i += 1
}
```

#### for

```javascript
for (let i = 0; i < 6; i++) {
	console.log(i)
}
```

#### for ... in 

객체의 속성을 순회할 때 사용 (python 의 dict)

```javascript
const fruits = { a:'apple', b:'banana'}
for (const key in fruits) {
    console.log(key)
    console.log(fruits[key])
}
```

#### for ... of

```javascript
const numbers = [0, 1, 2, 3]
for (const number of fruits) {
	console.log(number)
}
```



### 함수 선언

#### 함수 선언식

```javascript
function add(num1,num2) {
  return num1+num2
}
console.log(add(3,7))
```

#### 함수 표현식

```javascript
const sub = function (num1, num2) {
  return num1 - num2
}
console.log(sub(3,7))
```

함수의 이름을 생략한 익명 함수로 정의

이름을 작성하기도 하는데 이는 디버깅 용도로 사용

##### 기본 인자

```javascript
const greeting = function (name='Annonymous') {
  return `Hi ${name}`
}
console.log(greeting())
```

매개변수 보다 인자가 많으면 해당 객체 만큼만 반환해줌

매개변수 보다 인자가 적으면 나머지 값은 undefined 반환

...args

함수 안에서 사용하면 배열로 받음



#### 호이스팅 - 함수

함수 선언식은 함수 선언 이전에 사용해도 호이스팅 문제 때문에 사용이됨

따라서 표현식으로 작성해야 함



#### 화살표 함수

##### 1. function 키워드 생략 가능

##### 2. 함수의 매개변수가 하나라면 () 생략 가능

##### 3. 함수의 내용이 한줄이라면 {}와 return 생략 가능

```javascript
const greeting = function (name) {return `Hi ${name}`}

// 1단계
const greeting = (name) => {return `Hi ${name}`}

// 2단계 잘 사용하지 않음
const greeting = name => {return `Hi ${name}`}

// 3단계
const greeting = name => `Hi ${name}`

// 보통 1단계나 3단계를 사용함
```



#### 즉시 실행 함수

선언 즉시 실행하고 초기화함 일회성



## Array와 Object

### Array

양의 정수로 index 표현

```javascript
const numbers = [1, 2, 3, 4, 5]
console.log(numbers[0]) // 1
console.log(numbers[-1]) // undefined
console.log(numbers[numbers.length -1]) // 5
```

#### 배열 메서드 기초

##### reverse

```javascript
const numbers = [1, 2, 3, 4, 5]
numbers.reverse()
console.log(numbers) // [5, 4, 3, 2, 1]
```

##### push & pop

```javascript
const numbers = [1, 2, 3, 4, 5]
numbers.push(100)
console.log(numbers) // [1, 2, 3, 4, 5, 100]

numbers.pop()
console.log(numbers) // [1, 2, 3, 4, 5]
```

##### unshift & shift

##### includes

```javascript
const numbers = [1, 2, 3, 4, 5]
console.log(numbers.includes(1)) // true
```

##### indexOf

```javascript
const numbers = [1, 2, 3, 4, 5]
console.log(numbers.indexOf(3)) // 2
console.log(numbers.indexOf(100)) // -1 없는 값이면 -1 반환
```

##### join

```javascript
const numbers = [1, 2, 3, 4, 5]
console.log(numbers.join()) // 1,2,3,4,5
console.log(numbers.join('')) // 12345
```



#### Array 배열 심화

함수 내부에서 인자로서 특정 로직을 실행하기 위해 들어가는 것 call back

##### forEach

```javascript
array.forEach((element, index, array) => ){
	//do something
} 
```

```javascript
// 기존
const colors = ['red', 'blue', 'green']
const printClr = function (color) {
  console.log(color)
}
colors.forEach(printClr)
// 1단계
colors.forEach(function (color) {
  console.log(color)
})
// 2단계
colors.forEach((color) => {
  console.log(color)
})
// 3단계
colors.forEach((color) => console.log(color))
```

반환 값이 없이 바로 출력함

##### map

```javascript
const numbers = [1, 2, 3, 4, 5]
const doubleEle = function (number) {
  return number * 2
}
const newArray = numbers.map(doubleEle)
console.log(newArray)
// 1단계
const newArray = numbers.map(function (number) {
  return number * 2
})
// 2단계
const newArray = numbers.map((number) => number * 2)
```

새로운 배열을 반환

##### filter

```javascript
const producst = [
  {name:'cucumber', type:'vegetable'},
  {name:'banana', type:'fruit'},
  {name:'carrot', type:'vegetable'},
  {name:'apple', type:'fruit'},
]
const fruitFilter = function (product) {
  return product.type === 'fruit'
}
const newArray = producst.filter(fruitFilter)
console.log(newArray)
// 1단계
const newArray = products.filter(function (product) {
  return product.type === 'fruit'
})
// 2단계
const newArray = products.filter((product) => {
    return product.type === 'fruit'
})
// 3단계
const newArray = products.filter((product) => return product.type === 'fruit')
```

함수의 반환 값이 true이 것들만 반환

##### reduce

```javascript
const numbers = [90, 80, 70, 100]
const sumNumber = numbers.reduce(function (result, number) {
  return result + number
}, 0)
console.log(sumNumber)

const sumNumber = numbers.reduce((result, number) => {
  return result + number
}, 0)

const sumNumber = numbers.reduce((result, number) => {result + number}, 0)
```

하나의 결과를 반환

default 탐색 값은 배열의 맨 처음 값 / 만약 빈 배열이라면 이는 오류가 발생

따라서 을 default로 보통 설정해줌

##### find

```javascript
const avengers = [
  {name : 'tony start', age:45},
  {name : 'steve rangers', age:35},
  {name : 'thor', age:40},
]
const avenger = avengers.find((avenger) => {
  return avenger.name === 'thor'
})
console.log(avenger)
```

반환 값이 참이면 조건을 만족하는 맨 처음 요소를 반환

참이 아니라면 undefined를 반환

##### some

```javascript
const arr = [1, 2, 3, 4, 5]
const result = arr.some((ele) => ele % 2 === 0)
```

배열을 탐색하면서 하나라도 조건을 만족하면 true

만약 모두 조건을 만족하지 않는다면 false

빈배열은 항상 false

##### every

```javascript
const arr = [1, 2, 3, 4, 5]
const result = arr.every((ele) => ele % 2 === 0)
```

모든 요소가 조건을 만족하면 true

하나라도 조건을 만족하지 않으면 false

빈배열은 항상 true



#### forEach

```javascript
const chars = ['A', 'B', 'C', 'D',]
chars.forEach((char, idx) => {
    console.log(char, idx)
})
// ,idx 로 인덱스도 반환 가능
```

모든 요소 하나를 탐색

break, continue 사용 불가



### Object

key와 value를 가짐

key는 문자만 가능

value는 함수 포함하여 모든 타입 가능

```javascript
const myInfo = {
  name : 'jack',
  phonemunber : '12345',
  'samsung product' : {
    buds : 'buds pro',
    galaxy : 's99',
  },
}

console.log(myInfo.name)
console.log(myInfo['name'])
console.log(myInfo['samsung product'])
// 띄어쓰기가 있으면 대괄호로 묶어 주어야 함
console.log(myInfo['samsung product'].galaxy)
```



#### 속성명 축약

key이름과 value가 같으면 축약 가능

```javascript
const books = [...]
const myInfo = {
	books,
}
```



#### 메서드 명 축약

메서드 선언 시 function 키워드 생략 가능

```javascript
const obj = {
  name : 'jack',
  greeting() {
    console.log('HI!')
  }
}
obj.greeting()
```



#### 계산된 속성

```javascript
const myObj = {
	[key] : value,
}
// key 값이 정의된 값에 따라서 호출 할때 달라짐
```



#### 구조 분해 할당

```javascript
const myInfo = {
  name : 'jack',
  phonemunber : '12345',
  'samsung product' : {
    buds : 'buds pro',
    galaxy : 's99',
  },
}

const { name } = myInfo
const { name, phonmunber } = myInfo
// 여러 개를 한번에 할당도 가능
```



##### Spread syntax

... 를 사용함



### JSON

기본 문자열이라서 object로 반환 해주어야사용 가능

```javascript
const jsonData = {
  coffee: 'Americano',
  iceCream: 'Mint Choco',
}

// object -> JSON
const objToJson = JSON.stringify(jsonData)
console.log(objToJson) // {"coffee":"Americano","iceCream":"Mint Choco"}
console.log(typeof objToJson) // string

// JSON -> object
const jsonToObj = JSON.parse(objToJson)
console.log(jsonToObj) // {"coffee":"Americano","iceCream":"Mint Choco"}
console.log(typeof jsonToObj) // object
```
