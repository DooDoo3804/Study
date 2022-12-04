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
