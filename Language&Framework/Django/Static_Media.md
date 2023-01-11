# Static / Media

> 개발자가 서버에 미리 준비한 혹은 사용자가 업로드한 정적 파일을 클라이언트에게 제공하는 방법



## Static files

파일 자체가 고정되어 있고, 중간에도 변경되지 않고 고정되는 파일들

- Django에서 정적 파일을 구성하고 사용하기

settings/INTALLED_APPS/django.contrib.staticfiles 가 있는지 확인 (기본적으로 있어서 다로 추가 필요 없음)

settings.py에서 STATIC_URL을 정의

앱 폴더 안의 static폴더에 정적 파일을 위치하기

static 탬플릿 태그를 사용하여 지정된 경로에 있는 정적 파일의 URL 만들기

```django
{% load %}
	특정 라이브러리, 패키지에 등록된 모든 템플릿 태그와 필터를 로드
{% static '' %}
	STATIC_ROOT에 저장된 정적 파일에 연결
```



### STATIC_ROOT

default : None

collectstatic이 배포를 위해 정적 파일을 수집하는 디렉토리의 절대 경로

실제 배포 단계에서는  DBUG 속성을 False로 한다

배포를 하게 되면 사용자는 서버를 통해 들어오기 때문에 경로에 오류가 발생, 방지하기 위해 절대 경로를 설정



### STATICFILES_DIRS

default : []

기본 경로 외에 다른 경로를 추가

```python
STATICFILES_DIRS = [
    BASE_DIR / 'static',
]
```



### STATIC_URL

default : None

정적 파일을 참조할 때 사용할 URL

```python
STATIC_URL = '/static/'
```



### Static files 사용하기

- html

```html 
extends 밑에 다음과 같이 작성
{% load static %}
...
<img src="{% static 'articles/sample_img_1.png' %}" alt="sample img">
static 태그를 활용하여 이미지 url경로 설정
<img src="{% static 'sample_img_2.png' %}" alt="sample img">
STATICFILES_DIRS로 상대 경로를 이용하여 이미지 추가
```

이미지를 로드해 주기 위해 만드는 static 주소(request 주소)



### ImageField()

이미지 업로드에 사용하는 모델 필드

업로드 된 객체가 유효한 이미지인지 검사

인스턴스는 최대 길이가 100자인 '문자열'로 DB에 생성



### FileField()

upload_to (경로)/ max_lenth



### MEDIA_ROOT

defaul : ''

사용자가 업로드 한 파일들을 보관할 디렉토리의 절대 경로

STATIC_ROOT와 다른 경로로 지정 / 파일의 저장 경로

```python
MEDIA_ROOT = BASE_DIR / 'media'
```



### MEDIA_URL

default : ''

미디어 파일을 처리하는 URL

업로드 된 파일의 주소를 만들어 주는 역할

```python
MEDIA_URL = '/media/'
```

project/url.py에 가서 추가적으로 입력해 주어야 함

```python
from django.conf import settings
from django.conf.urls.static import static
urlpatterns[
    ...
] + static(settings.MEDIA_URL, document_root=settings.MEDIA_ROOT)
```

------



## IMAGE CREATE



- image 필드 추가

```python
image = models.ImageField(blank=True)
# blank : 비어있어도 되는가?
```

- blank : default '' 빈 문자열 저장
  - is_valid()에 검사됨
- null : default False
  - 빈 값을 Null로 저장

imagefield는 pillow를 설치 해야 함 / 이미지 처리에 관한 라이브러리

```bash
pip install Pillow
```

- form 태그에서 encoding 타입을 바꿔주어야 함

```html
  <form action="{% url 'articles:create' %}" method="POST" enctype="multipart/form-data">
    {% csrf_token %}
    {{ form.as_p }}
    <input type="submit">
  </form>
```

파일 / 이미지 업로드 시 enctype ="multipart/form-data"를 작성해 주어야 함

이미지는 request.FILES에 들어가서 전달 됨

```python
form = ArticleForm(request.POST, request.FILES) 
```

같은 이름의 이미지가 추가가 되면 django가 뒤에 난수 값을 추가해준다.

- detail에 이미지 보이기

```html
  {% if article.image %}
    <img src="{{ article.image.url }}" alt="{{ article.image }}">
  {% endif %}
# 이미지가 있을 때만 출력
```

------



## UPDATE

> 이미지는 텍스트라서 일부만 수정 불가능 / 즉 수정하는 기능

- html 수정

```html
  <form action="{% url 'articles:update' article.pk %}" method="POST" enctype="multipart/form-data">
    {% csrf_token %}
    {{ form.as_p }}
    <input type="submit">
  </form>
```

- views.py 수정

```python
...
form = ArticleForm(request.POST, request.FILES, instance=article)
...
```

새로운 이미지 텍스트로 대체해서 수정하는 방법



### 'upload_to' argument

- model field에 작성

```python
image = models.ImageField(blank=True, upload_to='images/')
```

이미지 파일 업로드 하여 저장 시 upload_to 의 경로에 저장함

media/images에 저장

```python
image = models.ImageField(blank=True, upload_to='%Y/%m/%d/')
```

'년월일' 폴더에 저장

- 함수 호출 방법

models.py에 작성

```python
def articles_image_path(instance, filename):
    return f'images/{instace.user.username}/{filename}'
image = models.ImageField(blank=True, upload_to=articles_image_path)
```



## Image Resizing

```bash
pip install django-imagekit
```

app에 등록

```python
INSTALLED_APPS = [
    'imagekit',
	...
]
```

```python
from imagekit.processors import Thumbnail
from imagekit.models import ProcessedImageField

image = ProcessedImageField(
        blank = True,
        upload_to='thombnails/',
        processors=[Thumbnail(200,300)],
        format='JPEG',
        options={'quality' : 80},
)
```

다른 여러 옵션이 있지만 이는 imagekit 홈페이지에 들어가서 확인하여 사용

ProcessedImageField 는 이미지 파일을 저장하지 않고 게시글 작성



```python
from imagekit.processors import Thumbnail
from imagekit.models import ProcessedImageField, ImageSpecField

image = models.ImageField(blank=True)
image_thumbnail = ImageSpecField(
        source='image',
        processors=[Thumbnail(200,300)],
        format='JPEG',
        options={'quality' : 80},
    )
```

ImageSpecField은 원본을 저장

출력 할 때 Thumbnail을 생성

CACHE에 이미지 파일이 생성됨



## QuarySet API Advanced

- __objects.count()__
  - 젠체 갯수 확인 가능
- .values('')
  - 원하는 값만 출력
- .order_by('')
  - 괄호 안의 key 값으로 정렬
  - '?'를 사용하면 랜덤하게 정렬함
  - -을 사용하면 역순으로 정렬 가능 ex) '-age' : 나이가 많은 순서

여러 조건으로 정렬을 할 경우 order_by() 괄호 안에 , 를 활용하여 작성

- .distinct()

  - 중복 없이 모든 값 조회

- .filter()

  - filter를 이용하여 조회를 할 때 데이터가 없으면 빈 쿼리를 반환 (에러가 발생하지 않는다)
  - filter(age__gte=30) : 서른 살 이상
  - (https://docs.djangoproject.com/en/4.1/ref/models/querysets/) 다음의 문서를 참고
  - 포함 : first_name__contains='호'
  - ~로 시작하는 조회 : phone__startswith='011-'
  - ~로 끝나는 조회 : first_name__endswith='준'

- .exclude('')

  - 주어진 매개 변수와 일치하지 않는 객체를 반환

- 파이썬의 slicing을 이용하여 데이터 자를 수 있음

- ```python
  from django.db.models import Q
  ```

  - ```
    User.objects.filter(Q(age=30) | Q(last_name='김'))
    ```

  - 위와 같이 작성하여 and / or의 조건 연산이 가능

- .aggregate()
  - Count / Sum / Min / Max / Avg 등 사용할 수 있음
- .annotate()
  - group by와 같은 동작
  - User.objects.values('country').annotate(Count('country'))
