### content 배치

```html
<!--
css 파일 또는 style에 작성
flex를 통해 수평로 배열할 수 있다
-->
display: flex;
flex-wrap: wrap; <!--defalut 값으로 nowrap이다. 이때는 자동으로 줄바꿈이 되지 않는다-->
flex-direction: row;
flex-direction: column; <!--수직 배열의 경우-->
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

