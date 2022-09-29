### OOP

```python
class Dog1:
    # 클래스는 파스칼 케이스 MyList
    # 함수, 변수는 카멜 케이스 myList
    
    kind = 'canine' # 클래스 변수
    
    def __init__(self, name):
        self.name = name # 인스턴스 변수
             
```

---

```python
class Dog2:
    tricks = [] # 추가 예정
    def __init__(self, name):
        self.name = name

    def add_trick(self, trick):
        self.tricks.append(trick)
```

```python
hb_cat1 = Cat('milk')
hb_cat2 = Cat('cream')
print(hb_cat1) # type
print(hb_cat2) # type
print(hb_cat1.name) # cat1의 name
print(hb_cat2.name) # cat2의 name
```

```python
hb_cat1.add_trick('hi') # tricks = ['hi', 'hello']
hb_cat2.add_trick('hello') # tricks = ['hi', 'hello']
```

____

```python
def Tiger:
    def __init__(self, name):
        self.name = name
        self.tricks = [] # 인스턴스마다 각각 값을 가져가기 위함
    def add_trick(self, trick):
		self.tricks.append(trick)
```

```python
my_tiger = Tiger('Ccobi')
your_tiger = Tiger('싸버지')
my_tiger.add_trick('어흥') # tricks = ['어흥']
your_tiger.add_trick('크항') # tricks = ['크항']
```

---

#### 절차지향과 객체지향

##### 절차 지향



```python
def greeting(name):
 	return f'hello, {name}'
print(greeting('youjin'))  
```

##### 객체 지향

```python
class Person :
    def __init __(self, name ):
		self.name = name
        
        def greeting(self):
		return f'hello, {self.name}'
my_name = Person('jihye')
print(my_name.name) # jihye
print(my_name.greeting()) # hello jihye
```

```python
class Hello : # 좋지 않은 예

class Greeting :
    def __init__(self, name):
        self.name = name
    
    def hello(self):
        return f'hello, {self.name}'
    
    def hihi(self)
        return f'hello, {self.name}'
```

- SRP(Single Responsibility Principle) 단일 책임원칙
  - 분리해서 관리하기 편함