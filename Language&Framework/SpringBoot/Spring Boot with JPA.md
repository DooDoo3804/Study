# Spring Boot with JPA

단점 : 특정 데이터베이스에 종속된 기능은 사용하기 어려움

## MyBatis vs JPA

### MyBatis

SQL-Mapping을 사용하여 영속성을 구현

테이블 변경이나 모델 DTO가 변경 시 매팅을 다시 수정해야 함

### JPA

객체와 DB간의 Mapping을 위한 프레임워크

설정 해야 할 것이 많음



Spring Boot는 준비된 메인 페이지가 없음 -> Whitelabel Error Page를 맨 처음 보게 됨



정적 파일 static 폴더 안에 html을 작성하면 재시작 없이 반영?

요새는 gradle을 많이 사용하는 추세 / 이는 안드로이드에서도 사용 가능



## model

### @Controller

templates에 있는 view page를 리턴

보통 thymleaf에서 사용?

### @RestController

어떤 값을 return



스프링 부트 프레임워크 MVC 패턴



