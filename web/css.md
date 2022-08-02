### content 배치

```html
<!--
css 파일 또는 style에 작성
flex를 통해 수평로 배열할 수 있다
-->
display: flex; <!--flex 사용할 때 필수 부모에 입력하면 모든 자식 요소에 적용-->
flex-wrap: wrap; <!--defalut 값으로 nowrap이다. 이때는 자동으로 줄바꿈이 되지 않는다-->
flex-direction: row;
flex-direction: column; <!--수직 배열의 경우-->
```

##### justify-content(수평 이동)

```html
justify-content: flex-start <!--default값 컨테이너 왼쪽으로 정렬-->
justify-content: flex-end <!--컨테이너 오른쪽으로 정렬-->
justify-content: center <!--컨테이너 가운데로 정렬-->
justify-content: space-between <!--요소들 사이 동일한 간격-->
justify-content: space-around <!--요소들 주위에 동일한 간격-->
```

##### align-items(수직 이동)

```html
align-items: flex-start
align-items: flex-end
align-items: center
align-items: baseline
align-items: stretch <!--요소의 크기를 지정하지 않았을 때 baseline까지 늘린다-->
```

##### flex-direction

```html
flex-direction: row;
flex-direction: row-inverse; <!-- 오른쪽부터 첫 번째 요소 배열-->
flex-direction: column; <!--수직 배열의 경우-->
flex-direction: column-reverse; <!--아래부터 위로 수직 배열-->
```

### 색상 불투명도

```html
  {
opacity: 80%;
}
```

### 네비게이션

```html
<nav class="nav-style">
    <div>
        <a href="#women" class="text-grey">Women's</a>
        <a href="#men" class="text-grey">Men's</a>
        <a href="#lifestyle" class="text-grey">Lifestyle</a>
        <a href="#beauty" class="text-grey">Beauty</a>
        <a href="#" class="text-brown">Sale</a>
    </div>
</nav>
<!--a태그에서 차례로 women men lifestyle beauty로 목차를 이동할 수 있다.(해당 id값)-->
```

### input

##### palceholder

```html
input(placeholder="입력 값") <!--"입력 값"을 유지하고 있다가 입력을 하면 사라진다-->
```

```html
display: inline-block  <!--기본적으로 컨테이너는 box 성질 box는 공간하나를 다 차지한다-->
bertical-align: top <!--content 배치를 위로 끌어올린다-->
```



