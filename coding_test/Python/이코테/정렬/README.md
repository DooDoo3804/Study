# 정렬

> 데이터를 특정한 기준에 따라서 순서대로 나열



## 선택 정렬(Selection Sort)

> 가장 작은 데이터를 선택해서 맨 앞에 있는 데이터와 바꾸고, 그다음 작은 데이터를 선택하고 바꾸고 이를 반복한다



```python
array = [7, 5, 9, 0, 3, 1, 6, 2, 4, 8]
for i in range(len(array)):
    min_index = i
    for j in range(i+1, len(array)):
        if array[min_index] > array[j]
	        min_index = j
    array[i], array[min_index] =     array[min_index], array[i]
print(array)      
```

시간 복잡도 O(N^2)



## 삽입 정렬(Insertion Sort)

>  데이터를 하나씩 확인하여 적절한 위치에 삽입한다

맨 처음 값은 정렬이 되어있다고 가정하고 그 다음 두 번째 부터 적절안 위치로 재배열을 한다. 왼쪽으로 옮겨가면서 더 적게 되면 그대로 배치



```python
array = [7, 5, 9, 0, 3, 1, 6, 2, 4, 8]
for i in range(1, len(array)):
    for j in range(i, 0, -1):
        if array[j] < array[j-1]:
            array[j], array[j-1] = array[j-1], array[j] 
        else: break
print(array)
```

시간 복잡도 O(N^2)



## 퀵 정렬(Quick Sort)

> 기준 데이터를 설정하고 그 기준보다 큰 데이터와 작은 데이터의 위치를 바꿈

#### 피벗 Pivot

​	큰 숫자와 작은 숫자를 교환할 때, 교환하기 위한 기준

```python
array = [7, 5, 9, 0, 3, 1, 6, 2, 4, 8]
def quick_sort(array):
    if len(array)<1:
    	return array
    pivot = array[0]
    tail = array[1:]
    
    left_side = [x for x in tail if x <= pivot]
    right_side = [x for x in tail if x > pivot]
    return quick_sort(left_side) + [pivot] + quick_sort(right_side)
print(quick_sort(array))
```

시간 복잡도 O(NlogN)



## 계수 정렬 (Count Sort)

> 조건만 맞으면 매우 빠른 정렬

최악의 경우에도 시간 복잡도 O(N+K)

정수로 딱 떨어지는 경우 각 숫자가 몇 번 나왔는지 횟수를 센 다음 이를 계수에 맞게 한번에 출력한다

```python
array = [7, 5, 9, 0, 3, 1, 6, 2, 9, 1, 4, 8, 0, 5, 2]
count = [0] * (max(array) + 1)
for i in range(len(array)):
    count[array[i]] += 1
for i in range(len(count)):
    for j in range(count[i]):
        print(i, end=' ')
```
