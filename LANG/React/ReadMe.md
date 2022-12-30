# React

**사용량 1위**

- Single Page Application 가능

- Component로 재사용 가능

- 데이터가 html에 자동 반영

Angular PWA react-native 등을 이용하면 앱으로 발행 가능

## Getting Start 

### 프로젝트 생성

폴더를 생성하고 `shift+우클릭` -> powershell 창 열기

```powershell
npx create-react-app (pjt이름)
```

pjt이름은 대문자 불가능

![image-20221229165739539](./assets/image-20221229165739539.png)

src > App.js 가 메인 페이지

### 프로젝트 실행

```
npm start
```

저장 시 자동으로 변경사항 적용됨

일반적으로 아래의 라이브러리를 이용하여 앱을 생성함

(https://create-react-app.dev/)

- modules
  - 프로젝트 구동에 필요한 모든 라이브러리
- public
  - static 파일 보관함
- src
  - source code 보관함
  - App.js
    - 여기에 쓰여있는 html 태그들을 public>index.html 에 적용된다.

다 지우고 아래와 같이 시작하면 된다.

```javascript
import logo from './logo.svg';
import './App.css';

function App() {
  return (
    <div className="App">

    </div>
  );
}
export default App;
```

- div의 클래스는 className으로 써야 Html class 로 인식
- 변수는 `{ 변수이름 }`를 활용하여 입력한다. id / className / src 모든 곳에 변수를 넣을 수 있음

**function App 안에는 하나의 div가 존재해야 한다.** (Vue와 동일)

#### state

변수를 임시적으로 저장하기 위함

```javascript
import { useState } from 'react';

let [a, b] = useState('남자 코트 추천')
// a와 b는 다른 이름으로 설정 가능

<h4>{ a }</h4>
// 남자 코트 추천
<h4>{ b }</h4>
// b는 해당 자료의 추가적인 가공을 할 때 사용 ex) b.length => 1
```

state를 쓰면 변수의 값이 변경되는 경우 HTML에 자동으로 바뀌어서 재렌더링됨

자주 변경되는 경우를 state로 선언하면 좋음

```react
import './App.css';
import { useState } from 'react';

function App() {

  let [글제목] = useState(['남자 코트 추천', '강남 우동맛집', '역삼 닭갈비 맛집'])
  let [좋아요, 좋아요변경] = useState(0);

  function like() {
    좋아요변경(좋아요+1);
  }
	// 좋아요의 샅태를 변화시킬때 부르는 이름 => 좋아요변경
  return (
    <div className="App">
      <div className="black-nav">
        <h4>블로그</h4> 
      </div>
      <div className='list'>
        <h4>{ 글제목[0] } <span onClick={ like }>💕</span> { 좋아요 } </h4>
        <p>2월 17일 발행</p>
      </div>
      <div className='list'>
        <h4>{ 글제목[1] }</h4>
        <p>2월 10일 발행</p>
      </div>
      <div className='list'>
        <h4>{ 글제목[2] }</h4>
        <p>2월 25일 발행</p>
      </div>
    </div>
  );
}

export default App;
```

만약 state의 변수가 array나 object면 카피를 한 다음에 바꿔줘야 state 값을 수정할 수 있음

### Component

반복적으로 하나의 틀을 써야할 때 / 큰 페이지 하나씩 / 자주 바뀌는 것들

component는 state를 변수로 적용하는 경우에는 사용하기 힘듦 / 불가능 하지는 않다.

1. function을 만들고
2. return() 안에 html 담기
3. `<함수명></함수명>` 으로 사용

```react
.....

      <Modal></Modal>
      <Modal/>
// 위의 두 가지 모두 가능한 문법
// 아래에서 정의된 Modal component를 사용

    </div>
  );
  function Modal() {
    return (
      <div className='modal'>
        <h4>제목</h4>
        <p>날짜</p>
        <p>상세내용</p>
      </div>
    );
  }
```

App() {} 밖에 함수 component를 작성해야 함

만약 component안에 여러 개의 div를 쓰고 싶다면 <> </> 묶어줄 수 있음 (react 문법)



