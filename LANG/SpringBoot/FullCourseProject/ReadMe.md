# Spring Boot Full Course



만약 메서드의 return 타입을 List로 하면 JSON 형태로 return 해준다

```java
@RequestMapping(value = "/hello")
public List hello() {
    return List.of("Hello World");
}
```



![image-20221224165532727](./assets/image-20221224165532727.png)



## API Layer

```java
package com.example.fullcourseproject.student;

import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import java.time.LocalDate;

@Getter
@Setter
@ToString

public class Student {
    private Long id;
    private String name;
    private String email;
    private LocalDate dob;
    private int age;

    public Student() {
    }

    public Student(Long id, String name, String email, LocalDate dob, int age) {
        this.id = id;
        this.name = name;
        this.email = email;
        this.dob = dob;
        this.age = age;
    }

    public Student(String name, String email, LocalDate dob, int age) {
        this.name = name;
        this.email = email;
        this.dob = dob;
        this.age = age;
    }
}
```

```java
@RequestMapping(value = "/hello")
public List<Student> hello() {
    return List.of(
        new Student(
            1L,
            "Mariam",
            "mariam@email.com",
            LocalDate.of(2000, Month.JANUARY, 5),
            21
        )
    );
}
```

위와 같이 작성하면 아래 처럼 JSON으로 출력됨

![image-20221224164428128](./assets/image-20221224164428128.png)



## Business Layer

![image-20221224165054424](./assets/image-20221224165054424.png)

위처럼 파일 구성 이후

- StudentService.java

```java
package com.example.fullcourseproject.student;

import org.springframework.stereotype.Service;
import org.springframework.web.bind.annotation.RequestMapping;

import java.time.LocalDate;
import java.time.Month;
import java.util.List;

@Service
public class StudentService {
    @RequestMapping
    public List<Student> getStudents() {
        return List.of(
                new Student(
                        1L,
                        "Mariam",
                        "mariam@email.com",
                        LocalDate.of(2000, Month.JANUARY, 5),
                        21
                )
        );
    }
}
```

### @Service

해당 클래스를 루트 컨테이너에 빈(Bean) 객체로 생성해주는 어노테이션 (@Component 도 사용하지만 가시성이 떨어져 사용하지 않음)

이 내부에서 자바 로직을 처리함 / 비즈니스 로직에는 해당 어노테이션을 사용하는 것을 권장

- StudentController.java

```java
package com.example.fullcourseproject.student;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping(path = "api/v1/student")
public class StudentController {

    private final StudentService studentService;

    @Autowired
    public StudentController(StudentService studentService) {
        this.studentService = studentService;
    }

    @RequestMapping
    public List<Student> getStudents() {
        return studentService.getStudents();
    }
}
```

### @Autowired

필요한 의존 객체의 타입에 해당하는 빈(Bean)을 찾아 주입한다. (생성자, setter, 필드)

DI(Dependenct Injection) 의존성 종속 - 클래스간의 의존 관계를 스프링 컨테이너가 자동으로 연결

Autowired를 설정한 메서드가 자동으로 호출되고, 인스턴스가 자동으로 주입됨

### @Qualifier

Autowired로 연결한 빈 목록에서 유일한 빈을 구별함 (예 @Qualifier(value = "빈이름") )

연결할 빈의 값 타입을 지정 (예 @Qualifier("serviceName") )





![image-20221225230804719](./assets/image-20221225230804719.png)
