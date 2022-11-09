# Vue with Django

## UX & UI

### UX(User Experience)

유저가 느끼는 느낌, 태도 그리고 행동을 디자인

### UI(User Interface)

유저에게 보여지는 화면을 디자인



## Vue Router

### Routing

네트워크에서 경로를 선택하는 프로세스

유저가 방문한 URL에 대해 적절한 결과를 응답하는 것

### Routing in SPA / CSR

하나의 URL만 가질 수 있음

라우팅이 존재하지 않는다면 유저가 페이지의 변화를 감지할 수 없음

### Vue Router

routes에 컴포넌트를 매핑한 후, 어떤 URL에서 렌더링 할지 알려줌

유저에게 페이지가 많은 것 처럼 보이게 함

```bash
vue create vue-router-app	// vue 프로젝트 생성
cd vue0router-app	// 디렉토리 이동
vue add router	// Vue CLI를 통해 router plugin 적용
```

### History mode

브라우저의 History API를 활용한 방식

- 새로고침 없이 URL 이동 기록을 남길 수 있음
- `/`를 통해 UI를 구분

### router-link

a태그와 비슷한 기능 > url을 이동시킴

클릭 이벤트가 차단되어 있음

목표 경로는 **`to`속성**으로 지정 되어 있음

### router-view

주어진 url에 대해 일치하는 컴포넌트를 렌더링 하는 컴포넌트

렌더링 되는 위치

- App.vue는 base.html의 역할을 함

- router-view는 block으로 감싼 부분

### src/rpiter/index.js

라우터에 관련된 정보 및 설정이 작성 되는 곳

### src/Views

router-view에 들어갈 component 작성

원래 component가 들어가는 경로의 파일들과 크게 기능적인 차이가 없음

router와 관련된 component만 들어가는게 권장됨



## Vue Router 실습

### 선언적 방식

router-link의 `to`속성으로 주소 전달

```javascript
const routes = [
  {
    path: '/',
    name: 'home',
    component: HomeView
  },
]
```

```vue
<router-link to="/about">About</router-link>

<router-link :to="{ name : 'about'}">About</router-link>
// 객체 형태로 이름을 사용할 수 있음
```

### 프로그래밍 방식 네비게이션

`this.$router.push`를 사용하여 이동할 주소를 입력함

```vue
<template>
  <div class="about">
    <h1>This is an about page</h1>
    <button @click="toHome">Homeee</button>
  </div>
</template>
<script>
export default {
  name: 'AboutView',
  methods: {
    toHome() {
      this.$router.push({name:'home'})
    }
  }
}
</script>
```

### Dynamic Route Matching

변수로서 동적으로 할당

`$route.params` 로 변수에 접근 가능

```javascript
{
    path : '/hello/:userName',	// :userName 는 변수 이름
    name: 'hello',
    component: HelloView 
}
```

```vue
<router-link :to="{ name:'hello', params: {userName: 'SSAFY'}}">Hello</router-link>



<input
       id="nameInput"
       type="text"
       @keyup.enter="goHello"
       v-model="message"
       >
data() {
	return{
		message: null
}}
goHello() {
this.$router.push({ name:'hello', params: {userName: `${this.message}`}})
<!--
v-model로 양방향 바인딩을 함
router이름을 적고 params로 변수를 넘겨준다.
변수가 여러 개라면 object 형태로 넘겨줌
-->
}
```

### lazy-loading

모든 파일을 한 번에 로드하려 하면 로딩 시간이 오래걸림

당장 필요하지 않은 컴포넌트는 미리 로드하지 않고 방문 때 로딩을 함으로써 최초의 로드 시간이 빨라짐

```javascript
const routes = [{
  ...
  component: () => import('../views/AboutView.vue')
}]
```



## Navigation Guard

다른 url로 redirect를 하거나 해당 url로의 접근을 막는 방법

- 전역 가드
- 라우터 가드
- 컴포넌트 가드

### 전역 가드(Global Before Guard)

다른 url 주소로 이동할 때 항상 실행

router/index.js에 **router.beforeEach()**를 사용하여 설정

콜백 함수의 값으로 아래 3개의 인자를 받음

- to
  - 이동할 URL 정보가 담긴 Route 객체
- from
  - 현재 URL 정보가 담긴 Route 객체
- next()
  - 지정한 URL로 이동하기 위해 호출하는 함수
  - 콜백 함수 내부에서 단 한 번만 호출되어야 함
  - 기본적으로 to에 해당하는 URL로 이동
  - 일반적으로는 이전까지 대기 상태라서 이동하지 않고 next()를 호출해야 화면이 전환됨

``` javascript
router.beforeEach((to, from, next) => {
  const isLoggedIn = true	// 인증된 사용자인지 확인한 변수 임시로 true
  const authPages = ['hello']	// 권한이 필요한 페이지 array
  const isAuthRequired = authPages.includes(to.name)	// 인증된 사용자인지 확인
  if (isAuthRequired && !isLoggedIn) {
    next({name: 'login' })
      // 인증된 사용자가 hello로 가려는 경우 login 페이지로 이동
  } else {
    next()	// 아니면 상관 없음
  }
})
```



### 라우터 가드(Router Guard)

특정 route에 대해서만 가드를 설정하고 싶을 때 사용

**beforeEnter()**로 설정

다른 경로에서 이 route로 접속 요처할 때만 동작

해당 라우터를 등록한 위치에 추가

```javascript
const routes = [
    {
        path: '/login/',
        name: 'login',
        component: LoginView,
        beforeEnter(to, from, next) {
            if (isLoggedIn) {
                alert('로그인이 되어있어 HOME으로 이동합니다.')
                next({ name: 'home'})
            } else {
                next()
            }
        }
    }
]
```



### 컴포넌트 가드(Component Guard)

특정 컴포넌트에 대해서만 가드를 설정

`beforeRouteUpdate()`

```vue
<script>
    export default {
        beforeRouteUpdate(to, from, next) {
            this.userName = to.params.userName
            next()
        }
    }
</script>
```

parameter의 변화를 감지하여 해당 컴포넌트를 다시 호출함



- npm axios 설치

```bash
npm i axios
```

```vue
import axios from 'axios'
 vue에 작성
```



