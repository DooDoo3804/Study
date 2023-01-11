# VUE.JS

### Front-end Framework

#### Web App 

##### 웹페이지 그대로가 아니라 디바이스에 설치된 앱처럼 보이게 함



#### SPA(Single Page Application)

서버에서 최초의 1장의 HTML만 전달받아 모든 요청에 대응

기존의 방식은 **SSR(Server Side Rendering)**

사용자의 요청에 적합한 HTML을 렌더링하여 제공하는 방식 / 이를 수행하기 위해 **새로고침**을 진행



**CSR (Client Side Rendering)**

최초로 받아오는 HTML은 빈 문서

각 요청에 대한 대응을 JS를 통해 필요한 부분만 불러옴

**AJAX**를 통해 요청

서버는 화면을 그리기 위해 필요한 데이터를 JSON으로 전달

이를 JS로 처리하고 DOM트리에 반영

- 장점
  - 트래픽이 감소 :arrow_right:응답속도가 빨라짐
  - 새로고침이 진행되지 않아 자연스러운 요청이 된다
  - BE와 FE의 작업 영역을 명확하게 분리할 수 있음
- 단점
  - 빈화면을 받고 나중에 화면을 채우기 때문에 검색엔진같은 페이지 최적화에는 좋지 않음



## Vue.js

```html
<template>
	...
</template>
<script>
	...
</script>

<style>
	...
</style>
// 위와 같은 구조를 가짐
```

#### 초기 설정

Chrome Extensions에서 vue js extensions를 설치

확장프로그램관리에서 url 체크

개발자모드에서  Vue 확장을 통해 확인 가능

#### CDN

```html
<script src="https://cdn.jsdelivr.net/npm/vue@2.7.13/dist/vue.js"></script>
```

```html
<p id="name">name : {{ message }}</p>
<input id="inputName" type="text" v-model="message">
<script>
    const app = new Vue({
        el: '#app',
        // 적용할 app 이름
        // 연결할 DOM의 이름 / id 또는 class에 연결
        data: {
            message: '',
            },
        methods: {
	        print: function () {
    	      console.log(this.message)
        	}, // 여기서 this는 Vue를 지칭
        bye: function () {
        	this.message = 'Bye, Vue!'
        }, // method를 통해 데이터에 접근이 가능
           // 그렇기 때문에 변경하는 것 역시 가능!!
           // 화면에 보이는 것이 변경된다
        })
</script>
```

**method를 선언할 때 Arrow Function을 사용하면 안된다!!!**

Arrow로 선언하면 this가 window를 지칭하기 때문

이렇게 되면 data를 변경하지 못함



Vue는 눈에 보이는 데이터를 조작하는 것이 아니라 Vue의 데이터를 조작한다

v-model을 통해 조작할 데이터를 설정?

#### MVVM Pattern

그래픽 사용자 인터페이스의 개발을 BE와 분리

View / Model / View Model



## Basic of Syntax

- 일반적인 변수 데이터는 중괄호 2개로 연결

```html
<div id="app">
      <p>메시지: {{ msg }}</p>   
      <p>HTML 메시지 : {{ rawHTML }}</p>
      <p>HTML 메시지 : <span v-html="rawHTML"></span></p>
      <p>{{ msg.split('').reverse().join('') }}</p>
</div>
<script>
    const app = new Vue({
        el: '#app',
        data: {
            msg: 'Text interpolation',
            rawHTML: '<span style="color:red"> 빨간 글씨</span>'
        }
    })
</script>
```

- v-html은 날것 그대로의 html을 입력해준다

```html
<div id="app2">
    <p v-text="message"></p>
    <p>{{ message }}</p>
    <p v-html="html"></p>
</div>
<script>
    const app2 = new Vue({
        el: '#app2',
        data: {
            message: 'Hello!',
            html: '<a href="https://www.google.com">GOOGLE</a>'
        }
    })
</script>
```

- v-show - Boolean 값에 따라 show가 결정
  - 하지만 false인 경우에도 display:none 이기 때문에 렌더링은 됨 (자리를 차지함) 개발자 도구에 있음
  - 초기 로딩은 비싸지만(첨부터 생성을 하므로), 나중에 toggle은 쌈
- v-if - 사용 방법은 v-show와 동일
  - false인 경우 렌더링 자체가 되지 않는다. (즉, 불러오지 않음 / 존재 자체가 없어짐) 개발자 도구에 없음
  - 초기 로딩은 싸지만, 나중에 toggle은 비쌈(생성이 되어야 하므로)

```html
<div id="app3">
    <p v-show="isActive">보이니? 안보이니?</p>
    <p v-if="isActive">안보이니? 보이니?</p>
</div>
<script>
    const app3 = new Vue({
        el: '#app3',
        data: {
            isActive: false
        }
    })
</script>
```

- v-for

```html
<div v-for="char in myStr">
    {{ char }}
</div>
<div v-for="(char, index) in myStr" :key="index">
    <p>{{ index }}번째 문자열 {{ char }}</p>
</div>
<script>
    const app = new Vue({
        el: '#app',
        data: {
            myStr: 'Hello, World!'}
</script>
```

```html
<div v-for="(item, index) in myArr2" :key="`arry-${index}`">
    <p>{{ index }}번째 아이템</p>
    <p>{{ item.name }}</p>
</div>
<script>
    myArr2: [
        { id: 1, name: 'python', completed: true},
        { id: 2, name: 'django', completed: true},
        { id: 3, name: 'vue.js', completed: false},
    ],
</script>
```

```html
    <h2>Object</h2>
    <div v-for="value in myObj">
      <p>{{ value }}</p>
    </div>
    <div v-for="(value, key) in myObj"  :key="key">
      <p>{{ key }} : {{ value }}</p>
    </div>
<scrip>
    myObj: {
    name: 'harry',
    age: 27
    },
</scrip>
```

index 출력하려면 (char, index) 형식으로 작성해야함

key는 고유의 값으로 다른 순회에서도 곂치지 않게 하는 것이 좋다

​	보통 `문자열-index`가 일반적

index를 사용하지 않더라도 써주는 것이 좋음

- v-on

```html
<button v-on:click="number++">increase Number</button>
<p>{{ number }}</p>

<button v-on:click="toggleActive">toggle isActive</button>
<p>{{ isActive }}</p>
<script>
    const app = new Vue({
        el: '#app',
        data: {
            number: 0,
            isActive: false,
        },
        methods: {
            toggleActive: function () {
                this.isActive = !this.isActive
            },

            checkActive: function (check) {
                console.log(check)
            }
        }
    })
</script>
```

```html
<button @click="checkActive(isActive)">check isActive</button>
```

v-on을 @로 대신쓴다.

- v-bind:(속성)

```html
<a v-bind:href="url">Go To GOOGLE</a>
<!-- url은 문자열이 아니라 변수 이름 -->
<script>
    const app2 = new Vue({
        el: '#app2',
        data: {
            url: 'https://www.google.com/',
            redTextClass: 'red-text',
            borderBlack: 'border-black',
            isActive: true,
            theme: 'dark-mode'
        },
        methods: {
            darkModeToggle() {
                this.isActive = !this.isActive
                if (this.isActive) {
                    this.theme = 'dark-mode'
                } else {
                    this.theme = 'white-mode'
                }
            }
        }
    })
</script>
```

```html
<p v-bind:class="redTextClass">빨간 글씨</p>
<p v-bind:class="{ 'red-text': true }">빨간 글씨</p>
<p v-bind:class="[redTextClass, borderBlack]">빨간 글씨, 검은 테두리</p>
```

{}를 활용하면 true/false로 조절 가능

[]를 활용하면 여러개의 속성을 설정 가능

```html
<p :class="theme">상황에 따른 활성화</p>
<button @click="darkModeToggle">dark Mode {{ isActive }}</button>
```

v-bind는 :로 대신할 수 있음

- v-model

```html
<div id="app">
    <h2>1. Input -> Data</h2>
    <h3>{{ myMessage }}</h3>
    <input @input="onInputChange" type="text">
    
    <h2>2. Input <-> Data</h2>
        <h3>{{ myMessage2 }}</h3>
        <input v-model="myMessage2" type="text">
</div>
    ...
```

한국어의 경우 v-model의 실시간 저장이 이뤄지지 않는다

실시간 저장을 원하는 경우 위의 방식으로 작성



## Vue Advanced

### Computed

computed는 실핸한 값을 저장해 둔다. 이후 **재사용**(실행시간이 단축)

종속 대상이 변화되지 않으면 계산을 다시 수행하지 않는다

그냥 method를 쓰면 연산을 계속 수행함

computed는 변수 값으로서 호출함

```html
<h1>add_method : {{ add_method() }}</h1>
<h1>add_method : {{ add_method() }}</h1>
<h1>add_method : {{ add_method() }}</h1>
<h1>add_computed : {{ add_computed }}</h1>
<h1>add_computed : {{ add_computed }}</h1>
<h1>add_computed : {{ add_computed }}</h1>

<script>
    const app = new Vue({
        el: '#app',
        data: {
            number1: 100,
            number2: 100
        },
        computed: {
            add_computed: function () {
                console.log('computed 실행됨!')
                return this.number1 + this.number2
            }
        },
        methods: {
            add_method: function () {
                console.log('method 실행됨!')
                return this.number1 + this.number2
            },
            dataChange: function () {
                this.number1 = 200
                this.number2 = 300
            }
        }
    })
</script>
```

### Watch

감시하는 데이터가 변화되는 경우 실행됨

보통 디버깅 용도로 사용함

```html
<script>
    watch: {
        number: function (val, oldVal) {
            console.log(val, oldVal)
        },
            // val:변화 이후 값, oldval: 이전의 값
        name: {
            handler: 'nameChange'
        },
            // 메서드 호출은 handler를 이용함
        myObj: {
            handler: function (val) {
                console.log(val)
            },
                deep: true
        },
    }
</script>
```

### filter

` 변수 | (filter 함수)` 를 통해 filter를 적용시킨다

filter는 chaining이 되고, 앞의 filter부터 적용이 됨

```html
<div id="app">
    <p>{{ numbers | getOddNums}}</p>
</div>
<script>
    const app = new Vue({
        el: '#app',
        data: {
            numbers: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15],
        },
        filters: {
            getOddNums: function (nums) {
                const oddNums = nums.filter((num) => {
                    return num % 2
                })
                return oddNums
            },
        }
    })
</script>
```