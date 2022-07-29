1. __Mutable / Immutable__

   - Mutable

     ```
     list dictionary set
     ```

   - Immutable

     ```
     tuple string range
     ```

     __string은 할당할 때 id값이 할당이 되어서 불변__

2. __enumerate__

   - ```python
     idx, value = enumerate(list)
     ```

3. __for 문__

   - ```python
     for _ in range():
     ```

     __\_ 를 쓰면 for 문 안에서만 반복하는 변수.__

     __변수 i와 같이 사용하지 않을 경우에 사용가능 __

   - ```python
     for key, value in list.items():
     for key, value in set.items():    
     for key, value in dict.items():    
     ```

     __item() 을 쓰면 key와 value 값을 가져온다__

4. __Calendar method__ 

   - ``` python
     import calendar
     calendar.isleap(year) #True /False 반환
     ```