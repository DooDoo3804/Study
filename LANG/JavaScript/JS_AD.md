# Advanced JavaScript



## DOM(Document Object Model)

> 복잡한 기능을 구현하는 스크립트 언어
>
> 웹 브라우저에 내장된 API 중 하나로, 컴퓨터 환경에 관한 데이터를 제공하거나 여러가지 유용하고 복잡한 일을 수행

문서를 논리 트리로 표현

동일한 문서를 표현하고, 저장하고, 조작하는 방법을 제공

웹 페이지의 객체 지향 표현이며, 스크립트 언어를 이용해야 DOM을 수정할  수 있음



### DOM의 주요 객체

#### window

DOM을 표현하는 창

탭 기능이 있는 브라우저에선 각각의 탭을 각각의 window 객체로 나타냄

```javascript
window.open()
// 새 탭 오픈
window.print()
// 
window.alert()
// 경고창
```

#### document

> document는 window의 속성

브라우저가 불러온 웹 페이지

DOM 조작 순서

- 1. 선택(Select)
  2. 조작(Manipulation)

#### 선택

```javascript
documnet.querySelector(selector)
// 제공한 선택자와 일치하는 element 한 개 선택
// 첫 번째 element 객체를 반환
```

```javascript
documnet.querySelectorAll(selector)
// 제공한 선택자와 일치하는 element 여러 개를 선택
// CSS selector를 인자로 받음
// NodeList 반환
```

위 두개는 선택하는 명령어이고 이를 확인하려면 console.log를 찍어봐서 확인 가능

```javascript
console.log(document.querySelector('#title'))
console.log(document.querySelectorAll('.text'))
// #은 id 선택
// .은 class 선택
console.log(document.querySelectorAll('body > ul > li'))
// 자식과의 관계를 통해 선택도 가능
```

##### NodeList

- index로만 각 항목에 접근 가능
- List / 배열이기 때문에 배열 관련 메서드 사용 가능
- querySelectorAll()로 나오는 nodelist는 DOM의 변경사항을 실시간으로 반영하지 않음

#### 조작

```javascript
documnet.createElement(tagName)
// 작성한 tagName의 HTML요소를 생성하여 반환
Node.innerText
// 태그 안에 작성되는 컨텐츠
Node.appendChild('추가할 자식 노드')
// 하나의 node를 특정 부모 node의 자식 nodelist 중 마지막 자식으로 삽입
// 추가하고 node를 반환
Node.removeChild('삭제할 자식 노드')
// 자식 node 제거
```

위의 과정들은 노드를 선택해야 조작이 가능함

```javascript
Element.getAttribute(attrivuteName)
// 해당 지정된 값을 반환
// 인자는 값을 얻고자 하는 속성의 이름
Element.setAttribute(name, value)
// 지정된 요소의 값을 설정
// 이미 속성이 존재하면 갱신, 아니면 지정한 값으로 생성
Element.classList.toggle('attributeName')
// style에 선언된 것으로 전환
// 만약 없다면 생성함
```

------



## Event

> DOM 요소는 Event를 '받고' 받은 것을 '처리'할 수 있음

주로 addEventListner()라는 Event 처리기를 사용해 다양한 html 요소에 '부착'하여 사용

`EventTarget.addEventListner(type, [, options])`

listener 부분이 행동이 들어갈 callback 함수가 들어감

```html
<body>
  <button id="btn">버튼</button>
  <p id="counter">0</p>
  
  <script>
    const btnClick = document.querySelector('#btn')
	// let countNum = 1
    btnClick.addEventListener('click', function(event) {
      const pCounter = document.querySelector('#counter')
      let countNum = Number(pCounter.innerText)
      countNum += 1
      pCounter.innerText = countNum
    })
  </script>
</body>
```

#### event

```html
<body>
  <input type="text" id="text-input">
  <p></p>
  <script>
    const inputTag = document.querySelector('#text-input')

    inputTag.addEventListener('input', function (event) {
      const pTag = document.querySelector('p')
      pTag.innerText = event.target.value
    })
  </script>
</body>
```

```html
<body>
  <h1></h1>
  <button id="btn">클릭</button>
  <input type="text">

  <script>
    const btn = document.querySelector('#btn')
    btn.addEventListener('click', function (event) {
      const h1Tag = document.querySelector('h1')
      h1Tag.classList.toggle('blue')
    })

    const inputTag = document.querySelector('input')
    inputTag.addEventListener('input', function (event) {
      const h1Tag = document.querySelector('h1')
      h1Tag.innerText = event.target.value
    })  
  </script>
</body>
```



##  Event 취소

`event.preventDefault()`

태그 기본적인 동작을 제어

a태그 / form태그 / 복사 막기

```html
<body>
  <div>
    <h1>정말 중요한 내용</h1>
  </div>
  
  <script>
    const h1Tag = document.querySelector('h1')
    h1Tag.addEventListener('copy', function(event){
      event.preventDefault()
      alert('복사 금지')
    })
  </script>
</body>
```

```html
<body>
  <h1>로또 추천 번호</h1>
  <button id="lotto-btn">행운 번호 받기</button>
  <div id="result"></div>

  <script src="https://cdn.jsdelivr.net/npm/lodash@4.17.21/lodash.min.js"></script>
  <script>
    const btn = document.querySelector('#lotto-btn')
    btn.addEventListener('click', function (event){
      const ballContainer = document.createElement('div')
      ballContainer.classList.add('ball_container')
      const numbers = _.sampleSize(_.range(1, 46), 6)
      numbers.forEach((number) => {
        const ball = document.createElement('div')
        ball.innerText = number
        ball.classList.add('ball')
        ball.style.backgroundColor = 'red'
        ballContainer.appendChild(ball)
        const resulttoDiv = document.querySelector('#result')
        resulttoDiv.appendChild(ballContainer)
      })
    })
  </script>
</body>

    // const getLotto = document.querySelector('#lotto-btn')
    // getLotto.addEventListener('click', function(event){
    //   const numbers = _.sampleSize(_.range(1, 46), 6)
    //   for (let i = 0; i < 6; i++)  {
    //     const ballContainer = document.createElement('div')
    //     ballContainer.classList.add('ball-container')
    //     const ball = document.createElement('div')
    //     ball.innerText = ''
    //     ball.classList.add('ball')
    //     ball.innerText = numbers[i]
    //     ball.style.backgroundColor = 'red'
    //     ballContainer.appendChild(ball)
    //     const setBall = document.querySelector('#result')
    //     setBall.appendChild(ball)
    //   }
    // })
```

```html
<body>
  <form action="#">
    <input type="text" class="inputData">
    <input type="submit" value="Add">
  </form>
  <ul></ul>

  <script>
    const formTag = document.querySelector('form')
    formTag.addEventListener('submit', function (event) {
      event.preventDefault()
      const inputTag = document.querySelector('.inputData')
      const data = inputTag.value

      if (data.trim()) {
          // 빈 공백입력시 alert 발생시키는 로직
        const liTag = document.createElement('li')
        liTag.innerText = data
      
        const ulTag = document.querySelector('ul')
        ulTag.appendChild(liTag)

        event.target.reset()
      }else {
        alert('!')
      }})
  </script>
</body>
```



### This

암묵적으로 전달받는 this

동적으로 할당 됨

#### 전역

전역에서는 window를 가리킴

#### 함수

- 단순호출
  - window를 가리킴
- Method
  - 메서드로 선언하면, 해당의 객체가 바인딩
- Nested
  - function 키워드로 작성하면 window를 가리킴
- 화살표 함수
  - 해당의 객체가 바인딩 / 자신을 감싼 정적 범위
  - 호출의 위치와 상관 없이 상위 스코를 가리킴 / **선언**이 중요함
  - ___addEventListener의 콜백 함수는 function 키워드를 사용해라___

