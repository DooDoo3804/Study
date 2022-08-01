# HTML 과 CSS

[markup 보조자료](https://github.com/DooDoo3804/Study/blob/master/web/markdown.md)

### 웹 사이트의 구성 요소

- HTML : 구조
- CSS : 표현
- Javascript : 동작

### 웹 표준

표준적으로 사용되는 기술이나 규칙

어떤 브라우저든 웹 페이지가 동일하게 보이도록 함(크로스 브라우징)

---

### HTML

>  Hyper Text Markup Language

hyper text 는 참조를 통해 사용자가 한 문서에서 다른 문서로 즉시 접근할 수 있는 텍스트 (hyper link 와 비슷??)

markup language 는 태그 등을 이용하여 문서나 데이터의 구조를 명시하는 언어

#### HTML 스타일 가이드

- 2 space

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    
</body>
</html>
```

<head> : 문서 메타데이터 요소

- `<title> : 브라우저 상단 타이틀`
- `<meta> : 문서 레벨 메타데이터 요소`
- `<link> : 외부 리소스 연결 요소 (CSS파일, favicon등)`
- `<script> : 스크립트 요소 (JavaScript 파일/코드)`
- `<style> : CSS를 직접 작성`

#### 요소(element)

> `<h1>contents</h1>`

HTML 요소는 시작 태그와 종료 태그 그리고 그 사이의 내용으로 구성

요소는 중첩될 수 있음 (아래 예시)

```html
<h1>
    <h2>
        .......
    </h2>
</h1>
```

#### 속성(atrribute)

> `<a href="https://google.com"></a>`

속성을 통해 부가적인 정보를 설정 가능

id : 문서 전체에서 유일한 고유 식별자 지정

class : 공백으로 구분된 해당 요소의 클래스의 목록

data-* : 페이지에 개인 사용자 정의 데이터를 저장하기 위해 사용

style : inline 스타일

title : 요소에 대한 추가 정보 지정

tabindex : 요소의 탭 순서

<!-- 주석의 사용--> : 주석

#### 시맨틱 태그

> 의미적 가치를 가지는 것

__개발자 및 사용자 뿐만 아니라 검색엔진 등에 의미있는 정보의 그룹을 태그로 표현(가독성 높음)__

__검색 엔진 최적화(SEO)를 위함__

header : 문서 전체나 섹션의 헤더

nav : 내비게이션

aside : 사이드에 위치한 공간

section :  문서의 일반적인 구분 / 컨텐츠의 그룹을 표현

article :  문서, 페이지, 사이트 안에서 독립적으로 구분되는 영역

footer : 문서 전체나 섹션의 푸터(마지막 부분)

#### DOM(Document Object Model) 트리

#### HTML 문서 구조화

- 텍스트 요소

```html
<a></a> href 속성을 활용하여 다른 URL로 연결
<b></b> bold 체
<i></i> italic 체
<br> 텍스트 내에서 줄 바꿈 생성
<img> src 속성을 활용하여 이미지 표현
<span></span> 의미 없는 인라인 컨테이너
```

- 그룹 텍스트

```html
<p></p> 하나의 문단 띄어쓰기 포함
<hr> 주제의 분리를 의미 수평선 추가
<ol></ol> 순서 있는 리스트
<ul></ul> 순서 없는 리스트
<pre></pre> HTML에 작성한 내용을 그대로 유지
<blockquote></blockquote> 텍스트가 긴 인용문 / 보통 들여쓰기를 한 것으로 표현
<div></div> 의미 없는 블록 레벨 컨테이너
```

##### form

`<form>`은 정보를 서버에 제출하기 위함

- 속성
  - action : 처리할 서버의 URL (보낼곳)
  - method : form을 제출할 때 사용할 HTTP 매서드(GET : 가져오기, POST)
  - enctype : method가 post인 경우 데이터 유형

##### input

`<input>`은 다양한 타입을 가지는 입력 데이터 유형과 위젯이 제공

- 속성
  - name : form control에 적용되는 이름(이름/값 페어로 전송됨)
  - value : form control에 적용되는 값
- 유형
  - text : 일반 텍스트
  - password : 입력시 값이 보이지 않고 문자를 *로 표현
  - email : 이메일 형식이 아니면 제출 불가
  - number : min, max, step속성을 활용하여 숫자 범위 설정 가능
  - file : acccept 속성을 활용하여 파일 타입 지정 가능
  - checkbox : 다중 선택
  - radio : 단일 선택
  - color
  - date : 날짜
  - hidden : 사용자에게 보이지 않는 input
  - submit : 제출 타입
  - disabled : 내용물 수정 불가
  - required : 필수 항목
  - checked : default 값

##### input label

label을 클릭하여 input자체의 초점을 맞추거나 활성화 시킬 수 있음

`<input>`에 id 속성을 `<label>`에는 for 속성을 활용하여 상효 연관 시킴

```html
<label for="agreement">개인정보</label>
<input type="checkbox" name="agreement" id="agreement">
<input type = "" disabled> <!-- disabled 속성은 내용물 수정 불가 -->
```

___

### CSS

> Cascading Style Sheets
>
> 스타일을 지정하기 위한 언어

선택자를 통해 스타일을 지정할 HTML 요소를 선택

#### CSS 정의 방법

- 인라인 (태그 내에 작성)
- 내부 참조 (head 위에 `<style>`을 통해 작성)
- 외부 참조 (`<link>`를 통함)

#### CSS with 개발자 도구

요소 선택자 HTML 태그를 직접 선택

`*`  전체 선택자

`. `클래스 선택자

`#` id 선택자

기본 폰트 크기 : 16px

#### CSS 적용 우선순위(Cascading order)

1. 중요도
2. 우선순위
   - `*` < div < class < id < inline < !important

3. css 작성 시 나중에 있는 스타일이 우선(적용)

##### 상속

- css는 상속을 통해 부모 요소의 속성을 자식에게 상속
  - 상속 : TEXT
  - 상속 안되는 것 : Layout 이나 여백 등 배치

#### 크기 단위

- px
- %
- em
  - 상속의 영향을 받음
  - 지정된 사이즈에 상대적인 사이즈
- rem
  - 상속 영향을 받지 않음
  - 기본 글자를 기준으로 지정된 사이즈 배수

- viewpoint
  - 화면에 비율을 따름
  - vw , vh , vmin , vmax

#### 색상 단위

- 이름
- RGB



#### 결합자

- 자손 결합자 (공백)
- 자식 결합자 (>)



#### CSS Box Model

> 모든 요소는 네모!!
>
> 위에서 부터 아래로, 왼쪽에서 오른쪽으로 쌓인다

- Margin : 외부 여백
- Border : 테두리
- Padding : 테두리 안쪽의 여백
- Content : 이미지 등 요소의 실제 내용

내용물은 border 까지가 크기

한개 부터 순서대로 {(상하좌우)} {(상하)(좌우)} {(상)(좌우)(하))} {(상)(우)(하)(좌)}

##### CSS Display

- block : 줄 바꿈이 일어남 (한 줄을 다 차지함)

- inline : 줄바꿈이 없음 (contents만큼 자리 차지)

##### CSS Position

- relative : 상대 위치

- absolute : 절대 위치

- fixed : 고정 위치

- sticky 스크롤에 따라 static에서 fixed로 바뀜



