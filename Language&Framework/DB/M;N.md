# M:N

> 한 테이블의 0개 이상의 레코드가 다른 테이블의 0개 이상의 레코드와 관련된 경우



- target model
  - 관계 필드를 가지지 않은 모델
- source model
  - 관계 필드를 가진 모델(ForeignKey)



### 중개 모델

각 테이블의 ForeignKey 만 저장하여 반영하는 모델



### ManyToManyField

patient의 모델에 작성

```python
doctors = models.ManyToManyField(Doctor, related_name='patients', through='Reservation')
```

다대다 관계인 경우 manytomanyfield는 아무 곳에나 작성 가능

하지만 작성하는 곳에 따라서 참조와 역참조의 관계만 달라짐



```shell
patient1.doctors.add(doctor1)
```

.add() 를 통해 관계형 관계를 형성



```shell
doctor1.patient_set.remove(patient1)
```

.remove를 를 통해 관계 삭제

___관계에 따라 참조와 역참조는 각 그냥 objects와 objects_set의 구조를 가져야 함___



#### related_name

````python
related_name='patients'
````

역참조의 명령어 '_set' 이 설정한 related_name으로 변경됨 > patients



#### through

중개 테이블에 추가 데이터를 입력해야 하는 경우 사용

ManyToManyField로 생성되는 참조형 테이블을 through를 통해 다음의 테이블로 대체함

- reservation class 를 통한 생성

  - ```python
    reservation1 = Reservation(doctor=doctor1, patient=patient1, symptom='headache')
    reservation1.save()
    ```

- Patient를 통한 생성

  - ```python
    patient2.doctors.add(doctor1, through_defaults={'symptom':'flu'})
    ```



### Symmetrical

> 재귀 참조

기본값 : True

​	관계 1:arrow_right:2 가 되면 1:arrow_left:2 도 자동으로 생성

False로 끄면 한쪽의 관계만 추가됨

​	ex) 인스타그램 팔로워와 팔로우