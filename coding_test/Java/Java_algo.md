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



### startsWith

```java
String1.startsWith(String2);
```

String1이 String2로 시작하는지 확인하는 함수

boolean을 return함



### equals

```java
String hand = "right";
if (hand.equals("right")) {
    System.out.println("same string");
}
```

위의 예시처럼 문자열은 String 즉 객체로 선언된다. 즉 그냥 단순히 `==`로 비교하면 오류가 발생한다. 따라서 String의 메서드 equals를 사용하여 비교하면 된다.



### valueOf

```java
String.valueOf(subNum.charAt(k));
```

char 를 String 으로 변환



### charAt

```java
String lineNum1;
lineNum1.charAt(i)
```

String의 인덱스 i의 문자 char 형태로 반환



### replaceAll

```java
String s;
String[] engList = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

s = s.replaceAll(engList[i], Integer.toString(i));
```

replaceAll(pref, stuf)을 하면 String 안에 포함된 모든 단어 배열에 대해 pref를 stuf로 바꿔준다. (패턴 일치)



## Character

### idDigit 

```java
Character.isDigit(s.charAt(i));
```

10진수 숫자인지 확인하는 메서드 true false를 반환



## Method

### void

리턴되는 타입이 없는 메서드

아무것도 리턴하지 않음

즉, 아무것도 리턴하지 않아야 오류가 발생하지 않는다.

```java
public void name() {
    // return 하는 것이 없어야 오류 발생하지 않음
}
```



## Arrays

### Arrays.sort

```java
import java.util.Arrays;
int[] d;
Arrays.sort(d);
// 오름차순으로 정렬
import java.util.Collections;
Arrays.sort(d, Collections.reverseOrder());
// 내림차순으로 정렬
```



## ArrayList

### ArrayList -> Array

```java
ArrayList<> answer = new ArrayList<>();
answer.stream().mapToInt(i -> i).toArray();
```

- ArrayList를 사용했을 때 장점
  - 크기를 미리 정하지 않더라도 add를 통해 요소를 추가할 수 있음 / 편함

### set

```java
ArrayList<> list = new ArrayList();
list.set(i, v);
// 인덱스 i 위치를 값 v로 변경
```

ArrayList의 특정 위치의 값을 변경.



## Map

Collection과는 다른 저장 방식을 가짐

HashMap으로 선언하여 사용

```java
Map<String, String> member = new HashMap<>();
```

### put

key와 value를 입력

### get

value 값을 추출

### remove

key에 해당하는 key와 value를 삭제하고 그 value를 리턴



### Map -> List 형태로 변환

```java
// List<Map.Entry<Integer, Integer>> everyList = new LinkedList<>(sizeCount.entrySet());
List<Map.Entry<Integer, Integer>> everyList = new ArrayList<>(sizeCount.entrySet());
everyList.sort(Map.Entry.comparingByValue());
// Array를 value를 기준으로 정렬함
```

`Arrays.sort()`을 사용하기 위해서는 List의 형태로 바꿔줄 필요가 있음.

배열은 탐색 정렬에 유리

데이터 추가/삭제가 많으면 연결 리스트가 유리



## PriorityQueue

우선순위 큐 - 숫자가 낮을 수록 우선 순위를 가짐

```java
import java.util.PriorityQueue;
PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
```

### offer

우선순위 큐에 삽입

### peek

처음 항목을 엿보기 / 추출하지 않음

### poll

처음 항목을 제거하고 반환함



## Stack

### .peek()

맨 뒤의 값을 확인할 수 있음



## 삼항 연산자

```java
num = num % 2 == 0 ? num / 2 : num * 3 + 1;
// (조건식) ? (참인 경우) : (거짓인 경우)
```



## 입출력

```java
import java.io.BufferedReader;
import java.io.InputStreamReader;
BufferedReader br = new BufferedReader(new InputStreamReader(system.in));
int input = Integer.parseInt(br.readLine());
```

scanner를 통한 입력을 받는 것은 느리다.

BufferReader가 빠름



## Comparable

```java
    private static class Stage implements Comparable<Stage> {
        int stageIdx;
        double failPercent;

        public Stage(int stageIdx, double failPercent) {
            this.stageIdx = stageIdx;
            this.failPercent = failPercent;
        }

        @Override
        public int compareTo(Stage o) {
            if (this.failPercent == o.failPercent)
                return this.stageIdx - o.stageIdx;
            else
                return Double.compare(o.failPercent, this.failPercent);
            }
        // sort할 때 필요한 부분
    }
```

Comparable은 상속을 받아서 사용할 수 있는 메서드이다.

객체를 선언해주고 Override를 통해 compareTo를 재정의 해주어야 한다.

`Comparable<type>` 이 안에는 Stage 가 들어가서 비교할 객체를 선언해 준다.

compareTo를 직접 사용하지 않지만, 해당 문제에서는 sort 메서드를 사용하기 위해 비교하여 정렬이 되는 기준을 쓸 필요가 있어 Comparable을 상속받아 사용한다.



## 알고리즘

### 약수 구하기

```java
for (int i = 1; i*i <= number; i++) {
    if (i*i == number)
        subSum ++;
    else if (number%i == 0) {
        subSum += 2;
    }
}
```

위의 알고리즘이 훨씬 시간이 단축됨!!



### LRU(Least Recently Used)

head 쪽이 최근에 참조된 것, tail쪽이 오랫동안 참조되지 않은 것

Double Linked Lists 로 구현하기 때문에 두 개의 Class를 선언

