# 데이터 베이스

여러 사람이 공유하고 사용할 목적으로 통합 관리되는 정보의 집합

##### DBMS : 이러한 데이터 베이스를 관리하는 시스템 / SQLite



### RDB

대규모 동시 처리 작업에는 적합하지 않음
호환성 좋음
Django Framework의 기본 데이터베이스

#### 스키마

​	데이터 베이스에서 자료의 구조, 표현 방법, 관계등 전반적인 명세

#### 테이블

관계(Relation)
필드(Field) - 컬럼
레코드(record) - 행

#### PK

Primary Key - 기본키 / 단일 값



## SQL

------



> 특수 목적의 프로그래밍 언어
>
> 동적 타입



### DDL

> Data deficition language
>
> 데이터 정의 언어



#### CREATE TABLE statement

데이터 베이스에 새 테이블을 만듦
따로 설정하지 않아도 입력되는 데이터에 따라서 타입이 결정

```sqlite
CREATE TABLE contacts (
    name TEXT NOT NULL,
    age INT NOT NULL,
    email TEXT NOT NULL UNIQUE
);
```

추가적으로 입력하지 않으면 rowid는 자동으로 생성

- 값을 둘러싸는 따옴표 소수점 또는 지수가 없으면 INTEGER
- 값이 작은 따옴표나큰 따옴표로 묶이면 TEXT
- 값에 따옴표나 소수점, 지수가 없으면 REAL
- 값이 따옴표 없이 NULL이라면 NULL

데이터 타입 선호도 (호환성을 위해)

1. INTEGER
2. TEXT
3. BLOB
4. REAL
5. NUMERIC



### CONSTRAINTS

데이터 무결성
정확성 / 일관성을 보장하기 위함

#### NOT NULL

컬럼이 NULL을 허용하지 않음
만약 없으면 NULL값을 허용

#### CONSTRAINTS

중복된 데이터를 방지하기 위함

#### PRIMARY KEY

NOT NULL 제약 조건이포함되어 있음

```sqlite
CREATE TABLE table_name (
	id INTEGER PRIMARY KEY,
	...
)
```

#### AUTOINCREMENT

삭제된 데이터의 PK를 제외하고 다음 PK를 사용함
이미 사용된 PK를 재활용하여 생성하지 않음

##### rowid

자동적으로 증가하는 컬럼
1부터 시작하여 전 값보다 하나 큰 rowid가 생성



### ALTER TABLE

기존 테이블의 구조를 수정

1. RENAME TABLE
2. RENAME COLUMN
3. ADD NEW COLUMN
4. DELETE COLUMN
   1. 다른 테이블이 참조하고 있는 경우 칼럼 지울 수 없음
   2. PRIMARY KEY를 지울 수 없음
   3. UNIQUE 제약 조건이면 지울 수 없음

```sqlite
ALTER TABLE table_name RENAME TO new_table_name;
--테이블 이름을 변경

ALTER table table_name RENAME COLUMN name TO last_name;
--테이블 COLUMN의 이름을 변경

ALTER table new_contracts ADD COLUMN address TEXT NOT NULL DEFAULT 'default_data';
--테이블에 새로운 COLUMN을 생성
--뒤에 NOT NULL의 조건이 있어서 테이블에 데이터가 이미 있는 경우 추가가 되지 않는다
--이때 맨 뒤에 DEFAULT 값을 추가해 주면 해결 가능

ALTER table new_contracts DROP COLUMN address;

DROP TABLE table_name;
--테이블 존재 자체를 지워버림
--복구가 불가능
```

------



### DML

> 테이블의 데이터를 조작하는 언어



#### SELECT statement

```sqlite
SELECT column1, column2 FROM table_name;
```

```sqlite
SELECT first_name, age FROM users;
--users 테이블에서 first_name, age를 조회하기

SELECT * FROM users;
--users 테이블에서 전체 데이터 조회

SELECT rowid FROM users;
--users 테이블에서 rowid조회 / rowid는 이렇게 해야지만 조회가능/전체 조회에서 안나옴
```

#### ORDER BY clause

```sqlite
SELECT select_list FROM table_name
ORDER BY column1 ASC, column_2 DESC
--ASC:오름차순
--DESC:내림차순
```

```sqlite
SELECT first_name, age, balance FROM users
ORDER BY age ASC, balance DESC;
--ORDER BY 뒤쪽에 두개 이상이 있으면 앞에꺼 우선 정렬하고, 이후 뒤를 정렬

--NULL은 가장 작은 값으로 취급
```

#### SELECT DISTINCT clause

> 중복되는 값을 제외하고 모든 값을 조회
>
> like dictionary in python (?)

```sqlite
SELECT DISTINCT country FROM users;
```

모든 지역을 내림차순으로 정렬

````sqlite
SELECT DISTINCT country FROM users
ORDER BY country;
````

NULL역시 중복으로 간주

#### WHERE clause

> 조회 시 특정 검색 조건을 지정
>
> FROM 뒤에 작성 

```sqlite
SELECT first_name, age FROM users WHERE age >= 30;
```

##### LIKE operator

> WHERE 절에서 사용 / 패턴 일치
>
> 대소문자 구분 안함 

- % : 0개 이상의 문자가 올 수 있음을 의미
- _ : 뒤에 단 하나의 문자가 있음을 의미

```sqlite
SELECT first_name, last_name FROM users WHERE first_name LIKE '%호%';
```

##### IN operator

> WHERE 절에서 사용
>
> 값이 모록 결과에 있는 값과 일치하는지 확인

```sqlite
SELECT first_name, country FROM users WHERE country IN ('서울', '경기도');
```

##### BETWEEN operator

> WHERE 절에서 사용
>
> 범위 내에 있는 값인지 조회

```sqlite
SELECT first_name, age FROM users WHERE age BETWEEN 20 AND 30;
```

##### LIMIT operator

> WHERE 절에서 사용
>
> 행의 개수를 제한 가능

#### GROUP BY

```sqlite
SELECT country, COUNT(*) FROM users GROUP BY country;
```

------



### CHANGIGN DATA

#### INSERT

```sqlite
INSERT INTO table_name(column1, column2, ...) VALUES (value1, value2, ...);
```

입력해줄 column과 value를 입력해야함

column 을 생략하면 모든 value를 입력해야함

#### UPDATE

```sqlite
UPDATE table_name
SET column1 = new_value_1,
	column2 = new_value_2
WHERE
	search_condition; --EX) rowid = 2
	--만약 CONDITION이 없으면 모든 TABLE에 대해 변경 진행
```

#### DELETE

```sqlite
DELETE FROM table_name
WHERE search_condition;
--WHERE가 없으면 TABLE 모든 행을 삭제
```