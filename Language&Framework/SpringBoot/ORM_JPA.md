# 자바 ORM 표준 JPA 프로그래밍



## 04 엔티티 매핑

### @Entity

- 속성
  - name - 사용할 엔티티 이름
    - default - 클래스 이름

- 기본 생성자는 필수
- final  enum interface inner 클래스에는 사용 불가
- 저장할 필드에 final을 사용하면 안됨

### @Table

- 속성
  - name - 사용할 테이블 이름
    - default - 엔티티 이름을 사용
  - catalog - catalog 기능이 있는 DB에서 catalog를 매핑
  - schema - schema 기능이 있는 DB에서 schema를 매핑

### Schema 생성

```properties
spring.jpa.hibernate.ddl-auto = {속성 값}
```

- create - 기존 테이블을 삭제하고 새로 생성 (drop + create)
- create-drop - create + 종료시 생성한 테이블 drop
- update - DB 테이블과 엔티티 매핑 정보를 비교해서 변경 사항만 수정
- validate - 차이가 있으면 경고를 남기고 애플리케이션을 실행하지 않음 (DDL 변화 없음)

서버 운영 시에는 validate나 none으로 해야 운영되는 데이터가 날아가지 않는다

DB에는 언더_바로 이름을 생성

java는 camelCase로 이름을 생성

### @Column

- 속성
  - nullable - false 이면 not null
  - length - 길이 제한

### @Id

기본 키 매핑

### @GeneratedValue

식별자가 생성되는 경우에는 생성 전략을 선택해야 함

```java
@GeneratedValue(strategy = GenerationType.IDENTITY)
```

Sequence의 경우에는 조건에 따라 순차적으로 id를 생성 / 각각의 generator가 필요함

### 필드와 칼럼 매핑 : 레퍼런스

#### @Column

- 속성
  - name - 필드와 테이블의 Column이름을 매핑
  - nullable - null 허용 여부
  - unique - uniqueConstraints와 같음
  - length - String에서만 사용

#### @Enumerated

enum을 매핑할 때 사용

- 속성
  - value
    - EnumType.STRING - 이름을 DB에 저장
    - EnumType.ORDINAL - 순서를 DB에 저장

> enumeration type : 열거 타입
>
> 관레적으로 모두 알파벳으로 정의, 모두 대문자로 작성
>
> 단어 사이는 언더바(_)로 연결
>
> null도 값으로 대입 가능 

#### @Temporal

날짜 타입을 매핑할 때 사용

#### @Lob

DB의 BLOB CLOB과 매핑

#### @Transient

이 필드의 값을 매핑하지 않음 / DB에 저장하지도 조회하지도 않는다.

임시로 값을 저장할 때 사용

#### @Access

접근하는 방식을 지정

- 필드 접근 - AccessType.FIELD
- 프로퍼티 접근 - AccessType.PROPERTY
  - 접근자 Getter를 사용

### 데이터 중심 설계 vs 객체 지향 설계

데이터 중심 설계는 지양해야 함

특히 테이블에서 외래키를 그대로 가져오면 문제가 있다.

관계형 데이터베이스는 연관 된 객체를 가져올 때  외래 키를 사용해서 조인하면 되지만, 객체에는 조인 기능이 없어 객체를 찾을 때 참조를 사용해야 함

따라서 객체는 외래키 대신 참조를 사용해야 함

아래 처럼 외래키를 통한 재 조회를 하는 것이 아니라 참조를 한다.

```java
Order order = em.find(Order.class, orderId);
Member member = order.getMember();
```

## 05 연관 관계 매핑

객체의 참조와 테이블의 외래 키를 매핑

- 방향(direction)
  - 객체 관계에서만 존재하고, 테이블은 항상 양방향
  - 단방향 : 둘 중 한 쪽만 참조
  - 양방향 : 양쪽 모두 서로 참조

- 다중성(Multiplicity)
  - 다대일 / 일대다 / 일대일 / 다대다
- 연관 관계의 주인
  - 객체를 양방향 연관관계로 만들면 연관관계의 주인을 정해야 함

참조를 통한 연관관계는 언젠나 단방향

객체간에 연관관계를 양방향으로 만들고 싶으면 반대쪽에도 필드를 추가해서 참조를 보관해야함. 이는 양방향 관계가 아니라 서로 다른 단방향 관계 2개

### 객체 관계 매핑

#### @ManyToOne

연관관계를 매핑할 때 다중성을 나타내는 어노테이션을 필수로 사용해야 함

- 속성
  - optional
    - false로 설정하면 연관된 엔티티가 항상 있어야 함
      - default : true
  - fetch
    - 글로벌 fetch 전략 사용
  - cascade
    - 영속성 전이 기능
  - targetEntity
    - 연관된 엔티티의 타입 정보를 설정

#### @JoinColumn(name="TEAM_ID")

외래 키를 매핑할 때 사용

이 어노테이션은 생략 가능

- 속성
  - name
    - 매핑할 외래 키 이름
      - default : 필드명 + _ + 참조하는 테이블의 기본 키 칼럼명
  - referencedColumnName
    - 외래 키가 참조하는 대상 테이블의 칼럼명
      - 참조하는 테이블의 기본 키 칼럼명
  - ForeignKey
    - 외래 키 제약 조건

### 연관관계 사용

연관관계의 주인만이 데이터베이스 연관관계와 매핑되고 외래 키를 관리할 수 있다. 반면 주인이 아닌 다른 쪽은 읽기만 가능

주인이 아니면 `mappedBy`속성을 사용해야함

연관관계의 주인은 테이블에 외래 키가 있는 곳으로 정해야 함

만약 연관관계 주인을 주인이 아닌 곳에 입력을 하게 되면 아래와 같은 문제가 발생한다.

```sql
SELECT * FROM MEMBER;
```

| MEMBER_ID | USERNAME | TEAM_ID |
| --------- | -------- | ------- |
| member1   | 회원1    | null    |
| member2   | 회원2    | null    |



## 06 다양한 연관관계 매핑

### 다대일

#### 단방향

주인에 @JoinColumn만 있는 경우

#### 양방향

주인에 @JoinColumn을 작성하고 반대편에 mappedBy를 작성

양방향 연관관계는 항상 서로를 참조해야 함 / 연관관계 편의 메소드를 작성해 주는 것이 좋다. 편의 메소드는 한 곳에만 작성하거나 양쪽 다 작성할 수 있는데, 양쪽 다 작성하면 무한 루프에 빠질 수 있으므로 주의



### 일대다

#### 단방향

일대다 단방향 매핑 보다는 다대일 양방향이 권장됨

#### 양방향

존재하지 않음 (하지마라)

