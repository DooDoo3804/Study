# Java FullCourse

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



### Expressions

```java
public class Expressions {
	public static void main(String[] args) {
		double friends = 10;
		
		friends = (double) friends / 3;
		
		System.out.println(friends);
	}
}
```

사칙연산 모두 python 과 동일

나눗셈의 경우 int로 저장한 값은 int로만 출력됨 -> 따라서 원래의 데이터 타입을 바꿔주어야함 (double)



### GUI intro

```java
import javax.swing.JOptionPane;

public class GUI {
	public static void main(String[] args) {
		String name = JOptionPane.showInputDialog("Enter your name");
		JOptionPane.showMessageDialog(null, "Hello "+name);
		
		int age = Integer.parseInt(JOptionPane.showInputDialog("Enter your age"));
		JOptionPane.showMessageDialog(null, "You are "+age+" years old");
		
		double height = Double.parseDouble(JOptionPane.showInputDialog("Enter your age"));
		JOptionPane.showMessageDialog(null, "You are "+height+" cm tall");
	}
}
```



### Math class

```java
import java.util.Scanner;

public class MathClass {
	public static void main(String[] args) {
		double x;
		double y;
		double z;
		// result z
		
		Scanner scanner = new Scanner(System.in);
		
		System.out.println("Enter side x: ");
		x = scanner.nextDouble();
		System.out.println("Enter side y: ");
		y = scanner.nextDouble();
		
		z = Math.sqrt((x*x)+(y*y));
		
		System.out.println("The hypotenuse is : "+z);
		scanner.close();
	}
}
```



### Random 

```java
import java.util.Random;

public class RandomNum {
	public static void main(String[] args) {
		Random random = new Random();
		
		int x = random.nextInt(1,7);
		double y = random.nextDouble();
		boolean z = random.nextBoolean();
		System.out.println(z);
	}
}
```



## if 문

```java
public class If_statements {
	public static void main(String[] args) {
		int age = 18;
		
		if(age > 18) {
			System.out.println("You are an adult!");
		}
		else if(age == 18) {
			System.out.println("You are 18 years old!");
		}
		else {
			System.out.println("You are not an adult!!");
		}
	}
}
```



## Switch 문

```java
public class Switches {
	public static void main(String[] args) {
		String day = "Friday";
		
		switch (day) {
		case "Sunday": {
			System.out.println("It is sunday!");
			break;
		}
		case "Monday": {
			System.out.println("It is Monday!");
			break;
		}
		default: {
			System.out.println("It is Fridayday!");
		}}
	}
}
```

만약 break가 없다면 모든 switch 문들을 돌면서 값을 출력한다.

default는 아무 것도 만족하지 않을 때 동작할 기본 값



### logical operators

```java
import java.util.Scanner;

public class LogicalOperator {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.println("You are plating game! Press q or Q to quit!");
		String response = scanner.next();
		
		if(response.equals("q") || response.equals("Q")) {
			System.out.println("You quit the game");
		}
		else {
			System.out.println("You still playing the game!");
		}
	}
}
```

scanner.equal 로 사용자의 input을 바로 확인이 가능함



## While Loop

```java
import java.util.Scanner;

public class WhileLoop {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String name = "";
		while(name.isBlank()) {
			
			System.out.print("Enter your name: ");
			name = scanner.nextLine();
		}
		System.out.println("Hello "+name);
	}
}
```

### do loop

```java
		do {
			System.out.print("Enter your name: ");
			name = scanner.nextLine();
		} while(name.isBlank());
```

do 와 while은 비슷하게 동작하지만 do의 경우 조건과 상관 없이 안의 동작을 최소 한번 실행하고 조건을 확인한다. 반면 while은 조건을 만족하지 않으면 동작하지 않는다.



## for loop

```java
public class ForLoop {
	public static void main(String[] args) {
		for(int i=10; i>=0; i--) {
			System.out.println(i);
		}
		System.out.println("Happy new year!");
	}
}
```



## Nested Loop

```java
import java.util.Scanner;

public class NestedLoop {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int rows;
		int columns;
		String symbol = "";
		
		System.out.println("Enter # of rows: ");
		rows = scanner.nextInt();
		System.out.println("Enter # of columns: ");
		columns = scanner.nextInt();
		System.out.println("Enter symbol to use");
		symbol = scanner.next();
		
		for(int i=1; i<=rows; i++) {
			System.out.println();
			for(int j=1; j<=columns; j++) {
				System.out.print(symbol);	
			}
		}
	}
}
```



## Arrays

```java
public class Arrays {
	public static void main(String[] args) {
		String[] cars = {"Camaro", "Corvette", "Tesla"};
		cars[0] = "Mustang";
		
		String[] car = new String[3];
        // 아래와 같이 선언도 가능
	}
}
```

### 2D arrays

```java
public class Arrays {
	public static void main(String[] args) {
		String[][] car = new String[3];
     	// 위와 같이 선언하고 python과 접근 방식은 동일   
	}
}
```

### Array List

```java
import java.util.ArrayList;

public class Arraylist {
	public static void main(String[] args) {
	
		ArrayList<String> food = new ArrayList<String>();
		
		food.add("pizza");
		food.add("hamburger");
		food.add("hotdog");
		
		food.set(0, "sushi");
		food.remove(2);
		food.clear();
		for(int i = 0 ; i<food.size(); i++) {
			System.out.println(food.get(i));
		}
	}
}
```

### Array List 2D

```java
import java.util.*;
public class Arraylist2D {
	public static void main(String[] args) {
		
		ArrayList<ArrayList<String>> groceryList = new ArrayList();
		
		ArrayList<String> bakeryList = new ArrayList();
		bakeryList.add("pasta");
		bakeryList.add("donuts");
		bakeryList.add("garlic bread");
		
		ArrayList<String> drinksList = new ArrayList();
		drinksList.add("coke");
		drinksList.add("coffee");
		
		ArrayList<String> produceList = new ArrayList();
		produceList.add("peppers");
		produceList.add("tomatos");
		produceList.add("zucchini");
		
		groceryList.add(bakeryList);
		groceryList.add(drinksList);
		groceryList.add(produceList);
		
		System.out.println(groceryList);
	}
}
```

인덱스에 접근하려면 `.get(index)`을 사용해야함



## String method

```java
public class StringMethod {
	public static void main(String[] args) {
		
		String name = " Bro ";
//		boolean result = name.equals("bro");
//		boolean result = name.equalsIgnoreCase("bro");
//		위와 같이 작성하면 대소문자 구문을 없앰
		
//		char result = name.charAt(0);
//		해당 인덱스의 문자를 반환
		
//		int result = name.indexOf("B");
//		해당 문자의 처음 인덱스를 반환
		
//		boolean result = name.isEmpty();
//		빈칸인지 아닌지 true false로 반환
		
//		String result = name.toUpperCase();
//		모두 대문자로 변환
		
//		String result = name.toLowerCase();
//		모두 대문자로 변환
		
		String result = name.trim();
//		앞뒤의 빈칸을 삭제
		System.out.println(result);
		
	}
}
```



## Wrapper classes

java에서는 8개의 기본형을 객체로 다루지 않는다.

객체이기 때문에 객체로 생성된 것들은 서로 다르다.

```java
Integer i = new Integer(100):
Integer i2 = new Integer(100):
// i != i2
```



21. for-each loop
