## 데이터 구조

1. 문자열

   - ```python
     s.find(x) # x의 첫 번째 위치를 반환, 없으면 -1을 반환
     s.index(x) # x의 첫번째 위치를 반환, 없으면 오류
     s.isalpha() # 문자 여부
     s.isupper() # 대문자 여부
     s.islower() # 소문자 여부
     .istitle() # 타이틀 형식 여부
     ```

   - ```python
     s.replace(old, new[,count]) #바꿀 대상을 새로운 글자로 반환
     s.strip([]) # 공백이나 특정 문자 제거
     s.split(setp=None, maxsplit=-1) # 공백이나 특정 문자 기준 분리
     'separator'.jain([iterable]) # 구분자로 iterable을 합침
     s.capitalize() # 가장 첫 번째 글자를 대문자로 변경
     s.title() # 띄어쓰기 기주능로 첫글자는 대문자, 나머지 소문자
     s.upper() # 모두 대문자
     s.lower() # 모두 소문자
     s.swapcase() #대소문자 서로 변경
     ```

   - 문자열은 할당하면 id가 부여되어서 할당

2. 리스트 메서드

   - ```python
     L.append(x) # 리스트 마지막에 x 추가
     L.insert(i, x) # 리스트 인덱스 i에 x추가
     L.remove(x) # 가장 왼쪽에서 첫번째 x를 제거 없으면 ValueError
     L.pop() # 리스트 가장 오른쪽 항목을 반환 후 제거
     L.pop(i) # 리스트 인덱스 i에 있는 항목을 반환 후 제거
     L.extend(m) # 순회형 m의 모든 항목을 추가
     L.index(x, start, end) # 리스트 가장 왼쪽에 있는 x의 인덱스 반환
     L.reverse() # 거꾸로 정렬
     L.sort() # 정렬
     L.count(x) # 리스트에서 x 갯수 반환
     ```

3. 셋 메서드

   - ```python
     s.discard(x) #항목 x가 셋 s에 있는 경우 삭제
     s.update(t) # 셋 t에 있는 항목 중 s에 없는 항목을 추가
     s.clear() # 모든 항목 제거
     s.isdisjoint(t) # 셋 s가 셋 t의 서로 같은 항목을 하나라도 갖고 있지 않은 경우, True
     s.issubset(t) # 셋 s가 셋 t의 하위 셋인 경우 True
     s.issuperset(t) # 셋 s가 셋 t의 상위 셋인 경우 True
     ```

4. 얕은 복사와 깊은 복사

- = 대입 연산자

  - = 를 통한 복사는 행당 객체에 대한 객체 참조를 복사
  - 해당 주소의 일부 값을 변경하는 경우 이를 참조하는 모든 변수에 영향

- slice 를 통한 복사

  - 같은 원소를 가진 리스트지만 연산된 결과를 복사(다른 주소)

- deep copy

  - 완전한 깊은 복사

  - ```python
    import copy
    a = [1, 2, ['a', 'b']]
    b = copy.deepcopy(a)
    b[2][0] = 0
    print(a,b)
    #a = [1, 2, ['a', 'b']]
    #b = [1, 2, ['0', 'b']]
    ```

