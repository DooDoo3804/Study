​	

# Vuex

프로젝트 시작 이후

```bash
vue add vuex
```

>  중앙 저장소(store)에 데이터를 모아서 상태 관리

규칙을 설정하며, vue의 반응성을 효율적으로 사용하는 상태 관리 기능을 제공

```javascript
export default new Vuex.Store({
  state: {
  },
  getters: {
  },
  mutations: {
  },
  actions: {
  },
  modules: {
  }
})
```

### 1. State

중앙에서 관리하는 모든 상태 정보

$store.state로 state에 접근

### 2. Mutations

실제로 state를 변경하는 **유일한** 방법

반드시 동기적

첫 번째 인자로 state를 받으며, component 혹은 Actions 에서 commit() 메서드로 호출됨

mutations라는 것을 강조하기 위해 전체 대문자로 작성이 권장됨

```vue
context.commit('mutation 메서드 이름', 추가 데이터)
```

### 3. Actions

Mutations와 비슷하지만 비동기 작업을 포함

component에서 dispatch() 메서드에 의해 호출됨

```vue
this.$store.dispatch('액션 메서드 이름', 추가 데이터)
```

별다른 Actions을 하지 않는 경우 바로 Mutations를 호출해도 괜찮다.

### 4. Getters

vue에서 computed에 해당	

state를 활용하여 계산된 값을 얻고자 할 때 사용 (state에 영향을 끼치지 않음)

첫 번째 인자로 state, 두 번째 인자(다른 getters가 계산한 값)로 getter를 받음

![](https://russianblogs.com/images/185/b7a0281faa1f08ca14804373524f0649.png)

## Start Vuex

```vue
<template>
<div id="app">
    <h1>{{ message }}</h1>
    </div>
</template>
<script>
    export default {
        name: 'App',
        components: {
        },
        computed: {
            message() {
                return this.$store.state.message
            }
        }
    }
</script>
```

computed로 작성하여 state의 data에 접근하는 것이 권장됨.



context는 Vuex의 모든 요소를 포함. 따라서 Actions가 모든 데이터에 접근 가능

- app.vue

```vue
<template>
  <div id="app">
    <h1>{{ message }}</h1>
    <h2>{{ messageLength }}</h2>
    <input
      type="text"
      @keyup.enter="changeMessage"
      id=""
      v-model="inputData"
    >
  </div>
</template>

<script>

export default {
  name: 'App',
  data () {
    return{
      inputData: null,
    }
  },
  components: {
  },
  computed: {
    message() {
      return this.$store.state.message
    },
    messageLength() {
      return this.$store.getters.messageLength
    }
  },
  methods: {
    changeMessage() {
      const newMessage = this.inputData
      this.$store.dispatch('changeMessage', newMessage)
    }
  }
} 
</script>
```

- store/index.js

```javascript
import Vue from 'vue'
import Vuex from 'vuex'

Vue.use(Vuex)

export default new Vuex.Store({
  state: {
    message: 'message in store'
  },  
  getters: {
    messageLength(state) {
      return state.message.length
    }
  },
  mutations: {
    CHANGE_MESSAGE(state, newMessage){
      state.message = newMessage
    }
  },
  actions: {
    changeMessage(context, newMessage) {
      context.commit('CHANGE_MESSAGE', newMessage)
    }
  },
  modules: {
  }
})
```



## Lifecycle Hooks

각 Vue 인스턴스는 생성과 소멸의 과정 중 단계별 초기화 과정을 거침

이를 Lifecycle Hooks 라고 함

### created

Vue instance가 생성된 후 호출됨

첫 실행 이후 바로 동작

### mounted

Vue instance가 요소에 mount된 후 호출됨

created의 경우 mount 되기 전이므로 DOM에 접근할 수 없음 / 동작하지 않음

### updated

데이터가 변경되어 DOM에 변화를 줄 때 호출됨

### 특징

instance는 서로 독립적이고 서로 다른 lifecycle을 가진다.

부모-자식 간의 순서가 존재하지 않는다.



## Local Storage

vuex-persistedstate

local storage에 자동으로 저장하고 불러오는 라이브러리



```
```

