## Django

### VS Code Django 설정

ctrl + shift + p

```json
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



block 작업시 extends가 반드시 필요

include는 원하는 위치에 작성하면 고대로 가져옴 

- 계속 가져오는 형식일 경우
- __include할 파일은 파일 앞에 _를 붙여주면 include임을 명시__



처음 개발 당시

app을 만들고 model을 짠다. urls은 나중에 만들어도 된다.

urls을 먼저 만들고 하면 



#### 작성 순서(예시일 뿐)

- 가상 환경 구축
- 가상 환경 실행
- 프로젝트 생성 .
- 앱 추가/생성
- 프로젝트 urls먼저 세팅

```django
path('<앱경로>', include(<앱의 urls로 연결>))
```

- 프로젝트 settings 에 installed_APPS 추가
- 앱 폴더에 앱.urls 생성

```django
from django.urls import path
from . import views
app_name = '<앱이름>'
urlpatterns[
    path('', <탬플릿이름 or 경로>),
    ]
```

- views에 탬플릿 생성

```django
def <탬플릿이름>(request):
    return render(request, '')
```

- article 앱에 templates 생성하기
  - templates/<앱이름>/<탬플릿>.html

++ Base.html

- 최상단에 templates/base.html 생성
- extend를 통해 base.html을 불러오면 뼈대를 그대로 사용할 수 있음
- 프로젝트 settings에서 template에 다음과 같이 작성

```django
'DIRS' : [BASE_DIR / 'templates',]
```

++ Catch/Throw

- throw.html 생성
- view에 throw 탬플릿 생성

```django
<form action="<catch로 이동 경로>" method="GET">
    <input name="<들어가는 변수 이름>"> # 주소 뒤에 다음이 붙음 ?<변수이름>=<>
</form>
```

- catch.html 생성
- view에 catch 탬플릿 생성

```django
def catch(request):
	a = request.GET.get('<변수이름>')
    context = {
        'a' = a
        } # 변수는 익셔너리에 담아서 사용한다
return render(request, 'articles/catch.html', context)
```

```django
{{<변수명>}} # 변수 사용은 다음과 같이 한다
{% for  in  %}{% endfor %} # for 문은 다음과 같이 사용 가능
```



### Models

schema 를 models에 작성

```django
class Article(models.Model):
    title = models.CharField(max_length=10) # 제목이라서 길이 제한이 필요
    content = models.TextField() # 더 긴 글
```



이후 `python manage.py makemigrations` migration진행

`python manage.py migrate` sqlite로 읽을 수 있게 됨

```django
create_at = models.DateTimeField(auto_now_add=True) # 최초의 생성 일자 자동으로 초기화
update_at = models.DateTimeField(auto_now=True) # 데이터가 수정될 때 마다 자동으로 초기화
```
