# Vue CLI

> Vue 개발을 위한 표준 도구

```bash
npm install -g @vue.cli
```

global 환경에 설치 (한 번만 진행)

- 프로젝트 생성

```bash
vue create vue-cli
vue create (프로젝트 이름)
```

```bash
cd vue/cli
npm run serve
```

vue/cli로 이동해서 run serve 해야함



- src/assets 
  - static 파일들 저장
- src/components
  - 하위 컴포넌트들이 저장
- src/App.vue
  - 최상위 컴포넌트



## SFC(Single File Component)

하나의 컴포넌트를 기능 단위로 나눠 작성함

### Vue component

- 탬플릿
- 스크립트
  - JS코드 작성
  - 데이터 메서드등 인스턴스를 구성하는 대부분이 작성
- 스타일
  - 컴포넌트의 스타일



### 컴포넌트 생성

- src/components 에 컴포넌트 생성

- script에 이름 등록

- template에 요소 추가
  - template에는 하나의 태그만 만들  수  있음

```vue
<template>
  <div>
    <h1>새로운 컴포넌트</h1>
  </div>
</template>

<script>
export default {
  name: 'MyComponent',
}
</script>

<style>

</style>
```

#### 컴포넌트 등록

App.vue에서 등록

- 불러오기 import

```vue
<script>
    ...
    import MyComponent from './components/MyComponent.vue'
    import MyComponent from '@/components/MyComponent'
</script>
```

- 등록하기 export

```vue
<script>
    ...
    export default {
        name: 'App',
        components: {
            HelloWorld,
            MyComponent
        }
    }
</script>
```

- 사용하기

```vue
<template>
	<div>
	    <MyComponent/>
    </div>
</template>
```

하위 컴포넌트에 또 다른 하위 컴포넌트를 추가하는 경우에도 같은 방법으로 진행하면 된다.



## Pass Props & Emit Events

**props** - 부모 => 자식의 데이터 흐름

**emit** - 자식 => 부모의 데이터 흐름

### Pass Props

요소의 속성을 사용하여 데이터 전달

부모 컴포넌트의 정보를 전달하기 위한 사용자 지정 특성

수신하는 props를 명시적으로 선언해야 함

```vue
<script>
    export default {
        name: 'HelloWorld',
        props: {
            msg: String
        }
    }
</script>
```

- static props
  - 아래와 같이 작성

```vue
<HelloWorld msg="Welcome to Your Vue.js App"/>
```

받는 쪽에도 props에 대해 명시적으로 작성해 주어야 함

부모 요소에서 static-props로 데이터를 보내주면 **(kebab-case)**

자식 요소에서 데이터를 staticProps로 받아야함 **(camelCase)**

- 변수를 props로 전달할 수 있음
  - 아래와 같이 v-bind(:)를 통해 JS표기법으로 작성할 수 있음

```vue
<HelloWorld :msg="Welcome to Your Vue.js App"/>
```

vue cli에서는 무조건 data는 `함수의 return 객체`의 형태로 작성해야 함

```vue
<script>
    export default {
        data: function() {
            return {
                dynamicProps: 'DP'
            }
        },
	...
    }
</script>
```



### Emit Events

이벤트를 발생시켜 데이터를 전달

버튼 클릭 이벤트를 청취하여 연결된 핸들러 함수 호출

호출된 함수에서 $emit을 통해 상위 컴포넌트에 이벤트 발생

- $emit('event-name') : 을 통해 부모에게 event-name이 발생했음을 알림

상위 컴포넌트는 자식 컴포넌트가 발생시킨 이벤트를 청취하여 연결된 핸들러 함수 호출

- 자식.vue

```vue
<template>
	<button @click="childToParent ">click</button>
</template>
<script>
    export default {
	...
        methods: {
            childToParent: function() {
                this.$emit('child-to-parent', (인자 작성))
            }
        }
    }
</script>
```

- 부모.vue

```vue
<template>
	<myComponent @child-to-parent="parentGetEvent" />
</template>
<script>
    import MyComponentItem from '@/components/MyComponentItem'
    export default {
        ...
        methods: {
            parentGetEvent: function((받는 인자)){
                console.log('BUG!')
            }
        }
    }
</script>
```

관계를 한 단계씩 오르 내릴 수 있음



#### array의 object삭제

```javascript
const index = this.todos.indexOf(todo)
this.todos.splice(index, 1)
// 해당 인덱스를 찾아서 이를 지우고 새로운 배열을 만든다
```

