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



## 조건문

### if 문

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



### Switch 문

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
		System.out.println("You are playing game! Press q or Q to quit!");
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



## 반복문

### While Loop

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



### for loop

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



### Nested Loop

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



### Array of Objects

```java
public class arrayObjects {
	public static void main(String[] args) {
		Food food1 = new Food("pizza");
		Food food2 = new Food("donut");
		Food food3 = new Food("hamburger");
		
		Food[] refrigerator = {food1, food2, food3};
		
		System.out.println(refrigerator[0].name);
		System.out.println(refrigerator[1].name);
		System.out.println(refrigerator[2].name);
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



## for each

```java
import java.util.ArrayList;

public class ForEach {
	public static void main(String[] args) {
		String[] animals = {"cat", "dog", "rat", "bird"};
//		ArrayList<String> animal = new ArrayList<String>();
//		animal.add("cat");
//		animal.add("dog");
//		animal.add("bird");
//		animal.add("rat");
		
		for(String i : animals) {
			System.out.println(i);
		}
	}
}
```

JavaScript의 forEach와 같은 방식

ArrayList 에서도 똑같이 적용 가능



## methods

```java
public class Methods {
	public static void main(String[] args) {
		int x = 3;
		int y = 4;
		int z = add(x, y);
		System.out.println(z);
//		선언 때 ㅁ다ㅏ 데이터 타입을 선언해주는 것이 바람직함
	}
	static int add(int x, int y) {
//		함수 안에 받을 변수와 데이터 타입을 선언해준다.
//		static을 선언해야 함수든 뭐든 사용할 수 있음.
		int z = x + y;
		return z;
	}
}
```



### String method

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



### Overload methods

같은 이름을 갖지만 다른 parameter를 갖는 함수를 말함

조건

- 메서드 이름이 같아야 함
- 매개변수의 개수 또는 타입이 달라야 함
  - 이때 같으면 오류가 발생

```java
public class OverloadMethods {
	public static void main(String[] args) {
		int x = 2;
		int y = 3;
		double z = add(x, y, 4, 5);
		System.out.println(z);
	}
	static int add(int a, int b) {
		System.out.println("This is overloaded method #1");
		return a + b;
	}
	static int add(int a, int b, int c) {
		System.out.println("This is overloaded method #2");
		return a + b + c;
	}
	static int add(int a, int b, int c, int d) {
		System.out.println("This is overloaded method #3");
		return a + b + c + d;
	}
	static double add(double a, double b) {
		System.out.println("This is overloaded method #4");
		return a + b;
	}
	static double add(double a, double b, double c) {
		System.out.println("This is overloaded method #5");
		return a + b + c;
	}
	static double add(double a, double b, double c, double d) {
		System.out.println("This is overloaded method #6");
		return a + b + c + d;
	}
}
```

**parameter가 정확하게 일치하는 함수가 실행된다!!!**

데이터 타입도 int와 double을 가려서 다른 함수를 실행함

데이터 타입 역시 중요한 요소



## printf

```java
public class Pinrtf {
	public static void main(String[] args) {
		boolean MyBoolean = true;
		char MyChar = '@';
		String myString = "DooDoo";
		int MyInt = 123;
		double MyDouble = 1000;
		
//		boolean
		System.out.printf("%b", MyBoolean);
//		char
		System.out.printf("%c", MyChar);
//		string
		System.out.printf("%s", myString);
//		int
		System.out.printf("%d", MyInt);
//		double
		System.out.printf("%f", MyDouble);
	}
}
```

- %(숫자)s 중간에 space를 숫자 만큼 채움
  - -와 함께 숫자를 입력하면 뒤로 space를 추가함

- %.2f 와 같이 쓰면 소수점 2자리 까지만 출력
- ,를 쓰면 숫자의 경우 3자리 씩 끊어서 출력함

## KeyWords



### final Keyword

```java
public class FirnalKeyword {
	public static void main(String[] args) {
		final double pi = 3.141592;
        pi = 4;
        // final을 입력한 경우 더 이상 해당 변수에 대해 할당을 할 수 없게 됨
        // 따라서 위의 경우는 오류가 발생함
        // 만약 final을 입력하지 않고 이후 4를 할당하면 아래에서 4가 출력됨
		System.out.println(pi);
		
	}
}
```



### Static Keyword

생성하고 공유할 수 있음

class가 static member를 소유함

즉 class의 객체 메소드에 있는 것이 아니라 class 자체에 존재함

```java
public class Friend {
	String name;
	static int numberOfFriends;
	
	Friend(String name) {
		this.name = name;
		numberOfFriends += 1;
	}
	
	static void displayFriends() {
		System.out.println("You have "+numberOfFriends+" firends");
	}
}
```

```java
public class staticKeyword {
	public static void main(String[] args) {
		
		Friend friend1 = new Friend("DooDoo");
		Friend friend2 = new Friend("Auther");
//		System.out.println(Friend.numberOfFriends);
		Friend.displayFriends();
	}
}
```

static void를 사용하면 생성자로 만들고 접근하지 않아도 된다.(?)



### Super Keyword

```java
public class superKeyword {
	public static void main(String[] args) {
		Hero hero1 = new Hero("Batman", 42, "$$$");
		
		System.out.println(hero1.name);
		System.out.println(hero1.age);
		System.out.println(hero1.power);
	}
}
```

```java
public class Person {

	String name;
	int age;
	
	Person(String name, int age){
		this.name = name;
		this.age = age;
	}
}

public class Hero extends Person{

	String power;
	
	Hero(String name, int age, String power) {
		super(name, age);
		this.power = power;
	}
}
```

super를 통해 super class의 모든것을 상속 받을 수 있음

```java
public class Person {

	String name;
	int age;
	
	Person(String name, int age){
		this.name = name;
		this.age = age;
	}
	public String toString() {
		return this.name+"\n"+this.age+"\n";
	}
}
//
public class Hero extends Person{

	String power;
	
	Hero(String name, int age, String power) {
		super(name, age);
		this.power = power;
	}
	public String toString() {
		return super.toString()+this.power;
	}
}
//
System.out.println(hero1.toString());
```

위와 같이 작성하면 super의 tostring으로 부터 모든 것을 상속받아 이후 추가적인 작업을 할 수 있음



## OOP(객체지향)

- OOPCar 클래스

```java
public class OOPCar {
	
	String make = "Chevrolet";
	String model = "Corvette";
	int year = 2020;
	String color = "blue";
	double price = 50000.00;
	
	void drive() {
		System.out.println("You drive the car");
	}
	void brake() {
		System.out.println("You step on the brakes");
	}
}
```

- main 클래스

```java
public class OOP {	
	public static void main(String[] args) {
		 
		OOPCar myCar = new OOPCar();
		System.out.println(myCar.make);
		myCar.brake();
	}
}
```

다른 클래스에서 만든 것을 main에서 불러와 사용할 수 있음

### Constructors

조건

- 생성자의 이름은 클래스의 이름과 같아야함
- 생성자는 리턴 값이 없음
- 메서드와 동일함 

```java
public class Human {
	String name;
	int age;
	double weight;
	
	Human(String name, int age, double weight) {
		this.name = name;
        // 좌항은 인스턴스 변수, 우항은 매개변수이다.
		this.age = age;
		this.weight = weight;
	}
    void eat() {
		System.out.println(this.name+" is eating");
	}
} // human을 위와 같이 선언함
```

```java
public class Constructors {
	public static void main(String[] args) {
		Human human = new Human("DooDoo", 19, 178.3);
		System.out.println(human.name);
	}
}
```

this를 통해 해당 객체의 속성을 자체적으로 정의 ?

같은 객체 내의 함수에서 this를 통해 상위 속성에 접근이 가능함

this는 참조 변수로 인스턴스 자신을 가리킨다. 인스턴스의 주소가 저장되어 있음



### Overload

```java
public class Pizza {
	String bread;
	String souce;
	String cheese;
	String topping;

	Pizza(String bread, String souce, String cheese) {
		this.bread = bread;
		this.souce = souce;
		this.cheese = cheese;
	}

	Pizza(String bread, String souce, String cheese, String topping) {
		this.bread = bread;
		this.souce = souce;
		this.cheese = cheese;
		this.topping = topping;
	}
}
```

class 에서도 역시 overload 할 수 있음



## Variable Scope

- local scope
  - method 안에 정의된 범위
  - 오직 그 method 안에서만 보임
- global scope
  - method 밖이지만 class 안에 정의
  - 모든 class에서 보임

```java
import java.util.Random;
public class DiceRoller {
	Random random;
	int number = 0;
//	global scope 범위
	
	DiceRoller(){
//      local scope 범위
		random = new Random();
		roll();
	}
	void roll() {
		number = random.nextInt(1,7);
		System.out.println(number);
	}
}

```



## toString

```java
public class toString {
	public static void main(String[] args) {
		toStringCar car = new toStringCar();
		
		System.out.println(car.toString());
	}
}
```

일반적으로 toString을 하면 클래스의 adress를 주지만 `클래스이름+@+16진수 해시코드`

```java
public class toStringCar {
	String make = "Chevrolet";
	String model = "Corvette";
	int year = 2020;
	String color = "blue";
	double price = 50000.00;
	
	public String toString() {
		String myString = make + "\n" + model + "\n" + color + "\n" + year;
		return myString;
	}
}
```

해당 클래스에서 toString을 overload를 하면 다른 것을 반환해 줄 수 있음

String 클래스에는 그대로 문자열로 반환하는게 기본값이다.

**제어자가 `public` 임을 유의**



## Objects passing

```java
public class objectsPassing {
	public static void main(String[] args) {
		Garage garage = new Garage();
		Car car = new Car("Tesla");
		garage.park(car);
	}
}
```

```java
public class Car {
	String name;
    
	Car(String name){
		this.name = name;
	}
}
```

```java
public class Garage {
	
	void park(Car car) {
		System.out.println("The "+car.name+"is parked in the garage");
	}
}
```

클래스의 void에 class로 인자 전달하는 방법



## Inheritance(상속)

부모로 부터 받는 속성

```java
public class Vehicle {

	double speed;
	
	void go() {
		System.out.println("This vehicle is moving");
	}
	void stop() {
		System.out.println("This vehicle is stopped");
	}
}
```

```java
public class Car extends Vehicle{

	int wheels = 4;
	int doors = 4;
}
public class Bicycle extends Vehicle{

	int wheels = 2;
	int pedals = 2;
}
```

```java

public class Inheritance {
	public static void main(String[] args) {
		Car car = new Car();
		
		Bicycle bike = new Bicycle();
		
        System.out.println(car.speed);
		System.out.println(car.doors);
		System.out.println(bike.pedals);
	}
}
```

vehicle이 부모이고 car와 bicycle은 부모로 부터 speed와 go stop을 받는다. 이들은 공통적으로 사용되고 각 개별로 사용되는 것들은 따로 정의 하면 된다.



### method overriding

```java
public class Animal {
	void speak() {
		System.out.println("the animal speaking");
	}
}

public class Dog extends Animal{
	
	@Override
	void speak() {
		System.out.println("the dog *bark*");
	}
}
```

Animal에서 정의되어있는 speak를 받아 dog에서 재정의가 가능하다

```java
public class MethodOverriding {
	public static void main(String[] args) {
		Animal animal = new Animal();
		
		Dog dog = new Dog();

		dog.speak();
		animal.speak();
	}
}
```

그냥 animal의 speak와 dog의 speak는 다른 결과를 야기



## Abstraction

추상 클래스를 의미

추상클래스로 인스턴스는 생성할 수 없다. 추상 클래스는 상속을 통해서 자손클래스에 의해서만 완성될 수 있다.

추상 클래스는 그 자체로서 클래스의 여할을 못하지만, 새로운 클래스를 작성하는데 있어서 바탕이 되는 조상 클래스로서 중요한 의미를 가짐

추상 메서드 역시 같은 방식이며, 이 또한 이름만 선언하고 바디를 가지지 않는다. 자손에서 오버라이딩을 통해 그 기능을 작성해야만 한다. 메소드에 abstract를 붙이면 자손에서 반드시 그 기능을 작성해야만 함

```java
public abstract class Vehicle {

	abstract void go();
	
}

public class Car extends Vehicle{

	@Override
	void go() {
		System.out.println("The driver is driving the car");
	}
}
```



## Access Modifiers

- public - class / package / subclass / world
  - 접근 제한이 없음

- protected - class / package / subclass
  - 같은 패키지 내에서, 다른 패키지의 자손 클래스에서 접근이 가능
- (no modifier) - class / package
  - 같은 패키지 내에서만 접근이 가능
- private - class
  - 같은 클래스 내에서만 접근이 가능



## Encapsulation(캡슐화)

```java
public class Car {

	private String make;
	private String model;
	private int year;
	
	Car(String make, String model, int year) {
		this.setMake(make);
		this.setModel(model);
		this.setYear(year);
	}
	public String getMake() {
		return make;
	}
	public String getModel() {
		return model;
	}
	public int getYear() {
		return year;
	}
	public void setMake(String make) {
		this.make = make;
	}
	public void setModel(String model) {
		this.model = model;
	}
	public void setYear(int year) {
		this.year = year;
	}
}
```

car class에 저렇게 선언을 한다 get은 해당 속성을 return  해주는 method이고, set은 해당 속성을 설정하게 해주는 method이다.

```java
public class Encapsulations {
	public static void main(String[] args) {
		Car car = new Car("Chevrolet", "Camaro", 2020);
		car.setYear(2022);
		System.out.println(car.getYear());
	}
}
```

위에서 볼 수 있듯이, set을 통해 설정을 해줄 수 있고, get을 통해서 불러올 수 있다.

getter() 와 setter()



## Copy Objects

```java
public class CopyObjects {
	public static void main(String[] args) {
		Car car1 = new Car("chevrolet", "Camaro", 2020);
//		Car car2 = new Car("Ford", "Mustang", 1996);
		
//		car2.copy(car1);
		Car car2 = new Car(car1);
		
		System.out.println(car1);
		System.out.println(car2);
		
		System.out.println(car1.getMake());
		System.out.println(car2.getMake());
	}
}
```

```java
public class Car {

	private String make;
	private String model;
	private int year;
	
	Car(String make, String model, int year) {
		this.setMake(make);
		this.setModel(model);
		this.setYear(year);
	}
	Car(Car x){
		this.copy(x);
	}
	public String getMake() {
		return make;
	}
	public String getModel() {
		return model;
	}
	public int getYear() {
		return year;
	}
	public void setMake(String make) {
		this.make = make;
	}
	public void setModel(String model) {
		this.model = model;
	}
	public void setYear(int year) {
		this.year = year;
	}
	public void copy(Car x) {
		this.setModel(x.getModel());
		this.setMake(x.getMake());
		this.setYear(x.getYear());
	}
}
```

단순히 `car1 = car2`를 하면 얕은 복사로 같은 주소로 복사가 됨

반면 public void copy를 선언하여 각각 할당을 해주면 car2.copy(car1)으로 복사하면 다른 주소로 복사가 됨

여기서 저 copy를 클래스 내에서 Car(car x)메소드로 선언을 해주면 car2를 선언하지 않고 바로 복사가 가능하다.



## Interface

클래스에 적용할 수 있는 템플릿(template)

상속과 비슷하지만 클래스에 필수적인 것을 특정한다.(?)

하나 이상을 가질 수 있음

```java
public interface Prey {

	void flee();
}
//--
public interface Predator {

	void hunt();
}
//--
public class Rabbit implements Prey{
	@Override
	public void flee() {
		System.out.println("The rabbit is fleeing");
	}
}
//--
public class Hawk implements Predator{

	@Override
	public void hunt() {
		System.out.println("The hawk is hunting");
	}
}
//--
public class Fish implements Prey, Predator{

	@Override
	public void hunt() {
		System.out.println("The fish is hunting smaller fish");
	}

	@Override
	public void flee() {
		System.out.println("This fish is fleeing from a larger fish");
	}
}
```



## Polymorphism(다형성)

car bike boat는 모두 vehicle에 속하기 때문에 다 달라도 큰 부모로 부터 접근이 가능하다

```java
public class Polymorphism {
	public static void main(String[] args) {
		
		PolymorphismCar car = new PolymorphismCar();
		PolymorphismBicycle bike = new PolymorphismBicycle();
		PolymorphismBoat boat = new PolymorphismBoat();
		
		PolymorphismVehicle[] racers = {car, bike, boat};

		for(PolymorphismVehicle x : racers) {
			x.go();
		}
	}
}
//--
public class PolymorphismVehicle {

	public void go() {
	}
}
//--
public class PolymorphismCar extends PolymorphismVehicle{
	@Override
	public void go() {
		System.out.println("The car begins moving");
	}
}
//--
public class PolymorphismBicycle extends PolymorphismVehicle{
	@Override
	public void go() {
		System.out.println("The bike begins moving");
	}
}
//--
public class PolymorphismBoat extends PolymorphismVehicle{
	@Override
	public void go() {
		System.out.println("The Boat begins moving");
	}
}
```

### Dynamic Polymorphism

사용자의 입력에 따라 그 종류가 결정되는 코드일 경우.

아직 사용자의 입력을 모를 때 큰 부모의로 선언을 하고 사용하면 된다.

이후 사용자의 입력에 맞춰 그 세부 클래스를 설정하는 것이 가능.

```java
Animal animal;

// 사용자의 입력을 받음
// 아래와 같이 작성 가능

if (choice==1){
    animal = new Dog();
    animal.speak();
}
```



## Exception handling

```java
import java.util.Scanner;

public class Exceptions {
	public static void main(String[] args) {
		
		try {
			Scanner scanner = new Scanner(System.in);
			
			System.out.println("Enter a whole number to divide: ");
			int x = scanner.nextInt();
			System.out.println("Enter a whole number to divide by: ");
			int y = scanner.nextInt();
			
			int z = x / y;
			
			System.out.println("result: "+z);
		}
		catch (ArithmeticException e) {
			System.out.println("You can't divide by zero");
		}
		catch (Exception e) {
			System.out.println("Something went wrong");
		}
		finally {
			System.out.println("This will always print");
		}
	}
}
```

try catch 를 사용하면 try구문 안에서 오류가 발생한 경우 catch를 통해 해당 오류에 동작을 한다. 만약 Exception 으로 선언하면 모든 오류 구문에 대해서 반환한다. finally는 try구문에서 오류가 발생하든 아무일도 없든 그냥 무조건 적으로 동작한다.

## File class

```java
import java.io.File;

public class FileClasses {
	
	public static void main(String[] args) {
		
		File file = new File("secret_message.txt");
		
		if(file.exists()) {
			System.out.println("That file exists!!?!");
		}
		else {
			System.out.println("That file doesn't exist! ");
		}
	}
}
```

위와 같이 작성하여 파일을 조회할 수 있음



### File Writer / Reader

```java
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class FileClasses {
	
	public static void main(String[] args) throws IOException {
		
		try {
			FileWriter writer = new FileWriter("poem.txt");
			writer.write("Roses are red \nViolets are blue");
			writer.append("\n(A poem by doodoo)");
            // append는 이미 작성된 글에 추가할 때 사용
			writer.close();
		}
		catch (IOException e) {
			e.printStackTrace();
		}
		finally {}
		
		try { 
			FileReader reader = new FileReader("art.txt");
			int data = reader.read();
            // 만약 파일이 끝나거나 뒤에 더 없으면 -1을 반환
			while(data != -1) {
				System.out.print((char)data);
				data = reader.read();
			}
			reader.close();
			
		}
		catch (FileNotFoundException e) {
			// TODO: handle exception
			e.printStackTrace();
		}
		catch (IOException e) {
			e.printStackTrace();
		}
		
	}
}
```

Audio 도 읽어올 수 있음



## GUI

```java
import java.awt.Color;

import javax.swing.JFrame;

public class FrameGUI {
	public static void main(String[] args) {
		JFrame frame = new JFrame();
		
		frame.setTitle("JFrame title goes here"); // frame 제목 출력
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // x 눌렀을 때 종료
		frame.setResizable(false); // 크기 조절 불가
		frame.setSize(420, 420); // 초기 크기 설정
		frame.getContentPane().setBackground(new Color(125,125,125)); // 배경 색 0xFFFFFF 도 가능
		frame.setVisible(true); // frame 출력
	}
}
```

Frame 클래스를 통해 생성할 수 있음
