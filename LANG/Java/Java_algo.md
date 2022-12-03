# Java Algorithm

## Integer

### 문자열을 정수로 변환

```java
Integer.parseInt(String s);
```



## String

### substring

```java
String answer;
answer = phone_number.substring(index1, index2);
```

String 타입의 answer의 인덱스 index1부터 index2까지 슬라이싱을 함..



## ArrayList

### ArrayList를 Array로 변환

```java
ArrayList<> answer = new ArrayList<>();
answer.stream().mapToInt(i -> i).toArray();
```

- ArrayList를 사용했을 때 장점
  - 크기를 미리 정하지 않더라도 add를 통해 요소를 추가할 수 있음 / 편함



## 삼항 연산자

```java
num = num % 2 == 0 ? num / 2 : num * 3 + 1;
// (조건식) ? (참인 경우) : (거짓인 경우)
```

