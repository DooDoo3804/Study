## Django

### VS Code Django 설정

ctrl + shift + p

```
    // Django
    "files.associations": {
        "**/*.html": "html",
            "**/templates/**/*.html": "django-html",
        "**/templates/**/*": "django-txt",
        "**/requirements{/**,*}.{txt,in}": "pip-requirements"
    },

    "emmet.includeLanguages": {
    "django-html": "html"
    },
```



### 가상 환경 구축

```
python -m venv venv # 가상환경 구축

source venv/Scripts/activate # 가상환경 실행

pip install django==3.2.13 # 최신 버전이 아닌 3.2.13ver

pip freeze > requirements.txt # 자동 설치 목록

pip install -r requirements.txt # 자동 설치


deactiveta # 종료
```



### 장고 시작

```
django-admin startproject firstpjt . # 현재 파일에 프로젝트 생성
django-admin startproject firstpjt # 폴더 구조 안에 프로젝트 생성

python manage.py runserver# 프로젝트 실행
# 실행하면 http://127.0.0.1:8000/ 생성
python manage.py createsuperuser # 프로젝트 실행


```

### 프로젝트 구조

- ```
  __init__.py
  ```

  - Python에게 이 디렉토리를 하나의 Python 패키지([링크](https://docs.python.org/3/tutorial/modules.html#packages))로 다루도록 지시한다.
  - 별도로 추가 코드를 작성하지 않는다.

- ```
  settings.py
  ```

  - Django의 모든 설정을 포함한다.

- ```
  urls.py
  ```

  - 사이트의 url과 적절한 views의 연결을 지정한다.

- ```
  wsgi.py
  ```

  - Web Server Gateway Interface
  - Django 어플리케이션이 웹서버와 연결 및 소통하는 것을 돕는다.
  - 추후 배포 시에 사용하며 지금은 수정하지 않는다.

- ```
  asgi.py
  ```

  - Asynchronous Server Gateway Interface
  - Django 어플리케이션이 비동기식 웹 서버와 연결 및 소통하는 것을 돕는다.
  - 추후 배포 시에 사용하며 지금은 수정하지 않는다.

- ```
  manage.py
  ```

  - Django 프로젝트와 다양한 방법으로 상호작용 하는 커맨드라인 유틸리티이다.
  - 코드는 수정하지 않지만 앞으로 Django와 관련된 명령어를 사용할 때 반드시 등장하기 때문에 꼭 기억해야 한다.

###  세부내용

```
LANGUAGE_CODE = 'ko-KR' # 언어 변경
TIME_ZONE = 'Seoul/Asia' # 시간 변경
```

```
python manage.py startapp {앱이름} # articles 앱 이름은 복수형으로
```

##### 필수

>  ___url 설정 이후 view 이후 template로 가야 빼먹지 않고 작성 가능___



```django
string(default) # 스트링 표기1
string <str:str1> # 스트링 표기2
integer <int:num1> # 인트 표기
```