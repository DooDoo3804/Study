# Java

## Start Java

- print - 단순히 문자열 출력

- println - 문자열 출력 이후 자동으로 줄바꿈

- `\n` - enter와 같음

- `\t` - tab과 같음

- `//` - comment 입력

- ```java
  /*
   * 여러 줄 주석
   *
   *
   */
  ```

  

## Variables

------

### Data Types

- **boolean**
  - 1 bit
  - frue / false
- **int**
  - 4 byte
  - -2 billion to 2 billion
- **double**
  - 8 byte
  - 15자리 까지 표기
- **char**
  - 2 bytes
  - `'f'` 단 하나의 문자
- **String**
  - varies
  - `"long sentences"`



```java
int x; // declation
x = 123; // assignment
int x = 123; // initialization
```

```java
System.out.println("My bumver is: " + x); // 변수와 String 같이 출력 가능
```



```java
// main치고 enter 하면 아래 자동 완성
	public static void main(String[] args) {
		 
	}
```



java는 python 과는 다르게 두 값을 바꾸려면 매게변수가 필요함

```java
public class Variables {
	public static void main(String[] args) {
		String x = "water";
		String y = "Kool-Aid";
		String temp;
        
        temp = x;
        x = y;
        y = temp;
        
		System.out.println(x);
        System.out.println(y);
	}
}

```



### Scanner

유저의 인풋을 받을 때 사용함

```java
import java.util.Scanner;

public class ScannerMain {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("What is yout name?" );
		String name = scanner.nextLine();
		System.out.println("How old are you?" );
		int age = scanner.nextInt();
        /* 아래의 nextLine이 없으면 여기서 끝난다.
         * 우리가 입력을 할 때 나이(숫자)를 입력하고 엔터를 치기 때문
         * 하지만 nextInt()는 다음의 숫자까지만 읽기에 엔터(\n)를 읽지 못한다
         * 이를 해결하려면 nextLine()을 입력해서 (\n)를 제거하고 그 다음을 읽어야함
         */
        scanner.nextLine();
        
		System.out.println("What is your favorite food?" );
		String food = scanner.nextLine();
		
		System.out.println("Hello "+name);
		System.out.println("You are "+age+" yaers old");
		System.out.println("You like" +food);
	}
}
```



5.expressions
