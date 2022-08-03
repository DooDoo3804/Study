# Bootstrap

### Bootstrap 사용

- head에 CDN link 입력

- body에 CDN script 입력

```html
<link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.0/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-gH2yIJqKdNHPEq0n4Mqa/HGKIhSkIHeL5AyhkYV8i59U5AR6csBvApHHNl/vI1Bx" crossorigin="anonymous">
<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.0/dist/js/bootstrap.bundle.min.js" integrity="sha384-A3rJD856KowSb7dwlZdYEkO39Gagi7vIsF0jrRAoQmDKKtQBHUuLZ9AsSv4jD4Xa" crossorigin="anonymous"></script>
```

### spacing(margin & padding)

{property}{sides}-{size}

클래스에다 입력한다. ex) `class = "ms-5"`

- property
  - m margin
  - p padding
- sides
  - t top
  - b bottom
  - s start
  - e end
  - x 양옆(좌우)
  - y 상하
  - blank 모든방향
- size (1rem = 16px)
  - 0 0
  - 1 - 0.25rem
  - 2 - 0.5rem
  - 3 - 1rem
  - 4 - 1.5rem
  - 5 - 3rem
  - auto ex)mx-auro : 수평가운데정렬

### color

- 공식 문서를 활용하자
- primary
- secondary
- success
- info
- warning

### Modal

경고 알림 같은 창

무조건 독립적으로 작성 : 하위항목으로 작성하면 동작 할 수도 있음

### Grid

12개의 column과 6개의 grid breakpoints가 존재

Guter : column 사이의 공간

##### row

```html
<div class="row row-cols-1 row-cols-md-2 row-cols-lg-4 g-4">
    md lg g 등 사이별로 row와 colmn이 변화한다
```



##### 필요한 기능은 공식 문서를 활용하자!