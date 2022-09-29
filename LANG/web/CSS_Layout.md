### CSS Layout

----

#### Float

텍스트를 포함한 인라인 요소들이 주변을 wrapping 하도록 함

```html
float: left
float: right
.clearfix::after{ } <!--clearfix class들의 float를 초기화-->
```

#### Flex box

블록 요소들이 인라인 처럼 성질이 바뀜

- 배치 설정
  - flex-direction
  - flex-wrap : 영역을 벗어나는 경우 자동 줄바꿈
- 공간 나누기
  - justify-content
  - align-content
- 정렬
  - align-items
  - align-self

##### justify-content(메인축 이동)

```html
justify-content: flex-start <!--default값 컨테이너 왼쪽으로 정렬-->
justify-content: flex-end <!--컨테이너 오른쪽으로 정렬-->
justify-content: center <!--컨테이너 가운데로 정렬-->
justify-content: space-between <!--요소들 사이 동일한 간격-->
justify-content: space-around <!--요소들 주위에 동일한 간격 (간격이 요소의 2배)-->
justify-content: space-evenly <!--요소들 주위에 동일한 간격 (간격이 요소들 만큼이다)-->
```

##### align-items(cross 축 이동) / align-self(개별적인 이동)

```html
align-items: flex-start
align-items: flex-end
align-items: center
align-items: baseline <!--글자의 baseline에 맞춘다-->
align-items: stretch <!--요소의 크기를 지정하지 않았을 때 바닥까지 늘린다-->
```

##### flex-direction(메인 축 설정)

```html
flex-direction: row;
flex-direction: row-inverse; <!-- 오른쪽부터 첫 번째 요소 배열-->
flex-direction: column; <!--수직 배열의 경우-->
flex-direction: column-reverse; <!--아래부터 위로 수직 배열-->
```

##### flex-flow

```html
flex-flow: (정렬방법) (줄바꿈)
flex-flow: row wrap <!--가로 정렬해서 줄 바꿈 가능-->
flex-flow: row wrap-reverse <!--줄 바꿈을 반대로 가능-->
```

##### flex-grow

남은 영역을 설정해 준 요소가 나눠서 가진다.

```html
flex-grow: 1
flex-grow: 2
<!--남는 여백을 1대2의 비율로 나눠서 크기를 늘린다-->
```

##### align-content

```html
align-content: flex-start <!--전부 위로 정렬-->
```

