# Spring

based on IntelliJ

## Maven과 Gradle

**빌드 관리 도구**

### Maven

프로젝트의 외부 라이브러리를 쉽게 참조할 수 있게 pom.xml 파일로 명시하여 관리

- XML 기반의 빌드 스크립트

- 라이프 사이클 도입

대표 태그들

- modelVersion
  - maven의 버전
- version
  - 프로젝트 버전
- dependency
  - 의존성을 부여

### Gradle

멀티 프로젝트의 빌드에 최적화하여 설계

Maven 보다 빠른 처리 속도를 가지고 있음

Maven이 더 높은 점유율을 가지고 있음

대규모 프로젝트에서 성능이 좋음



## Starting

spring initializr를 체크하여 생성

Maven / Gradle 빌드 베포 툴



### 파일 구조

#### pom.xml

```xml
<parent>
    <groupId>org.springframework.boot</groupId>
    <artifactId>spring-boot-starter-parent</artifactId>
    <version>3.0.0</version>
    <relativePath/> <!-- lookup parent from repository -->
</parent>
```

parent에 잡힌 dependency 같은 것들을 상속을 받아 사용할 수 있게 함 -> 코드 중복을 피할 수 있음

```xml
<dependencies>
    <dependency>
        <groupId>org.springframework.boot</groupId>
        <artifactId>spring-boot-starter-web</artifactId>
    </dependency>

    <dependency>
        <groupId>org.springframework.boot</groupId>
        <artifactId>spring-boot-configuration-processor</artifactId>
        <optional>true</optional>
    </dependency>
    <dependency>
        <groupId>org.projectlombok</groupId>
        <artifactId>lombok</artifactId>
        <optional>true</optional>
    </dependency>
    <dependency>
        <groupId>org.springframework.boot</groupId>
        <artifactId>spring-boot-starter-test</artifactId>
        <scope>test</scope>
    </dependency>
</dependencies>
```

추가한 open API들을 기재하는 부분

```xml
<build>
    <plugins>
        <plugin>
            <groupId>org.springframework.boot</groupId>
            <artifactId>spring-boot-maven-plugin</artifactId>
            <configuration>
                <excludes>
                    <exclude>
                        <groupId>org.projectlombok</groupId>
                        <artifactId>lombok</artifactId>
                    </exclude>
                </excludes>
            </configuration>
        </plugin>
    </plugins>
</build>
```

build안에는 plug-in들이 기재됨

