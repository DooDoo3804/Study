# JavaScript

HTML을 핸들링 하기 위한 프로그램

보통 body안 제일 밑에 script를 작성한다
-> 스크립트의 양이 많다면 화면 로딩이 느려지기 때문

만약 BootStrap을 넣을 생각이라면 css는 head에 script는 우리가 작성할 스크립트 위에 넣어준다.

> 사용자의 Input을 받아오는 용도 / 특정 element를 보였다가 감추는 용도



## 클릭시 액션

```javascript
    <button type=""button onclick="regist();">등록</button>
...
    function regist(){
      alert('버튼을 클릭했습니다!') ## 경고창 띄우기
    }
```



## html Input 데이터 가져오기

```javascript
document.getElementById("name").value // name의 id 값에 맞는 값을 가져온다.
```



## JS를 활용한 데이터 가져오기

```javascript
alert($("#name").val())
```



## 선택에 따른 하위 선택 값 변경

```javascript
      <select id="city" onchange="changeCity();">
        <option value="02">서울</option>
        <option value="064">제주</option>
      </select>
...
	function changeCity(){
      // let city = document.getElementById("city").value;
      // document.getElementById("region_02").style.display="none";
      // document.getElementById("region_064").style.display="none";
      
      // document.getElementById("region_"+city).style.display="";

      let city = $('#city').val();
      $('#region_02').hide();
      $('#region_064').hide();
      $('#region_'+city).show();
    }
```



## 변수 선언

### var

이후 같은 이름으로 변수를 다시 선언할 때 덮어서 쓰일 수 있음
위에서 선언한 이름의 변수가 더 이상 필요 없고 재정의해도 상관 없는 경우

### let

같은 변수 이름에 대해서 다시 재정의 할 수 없음
유일한 변수명에 대해서 선언해 주면 된다

### const

한 번 할당한 경우 재할당 조차 할 수 없음 / 상수 값이다



## 데이터 타입

### object

let obj = {}로 선언

### 배열

배열은 []로 선언



### JS에서 for문

```javascript
      for (let index = 0; index < city.length; index++) {
        ...
        
      }
```



### JS에서 if문

```javascript
        if (i == 0) {
            ...
        } else {
            
        }
```

