# REST API



### HTTP의 특징

연결이 유지되어 있지 않고 응답을 마치면 연결을 끊는다



### 웹에서 리소스 식별

URI로 식별됨



### URI(Uniform Resource Identifier)

리소스를 가리키는 문자열

웹주소는 URL(Uniform Resource Locator) - 통합 자원 위치

- Scheme
  - 브라우저가 리소스를 요청하는 데 사용해야 하는 프로토콜
- Authority
  - domain과 port이고 :로 구분
    - domain : domain 이름
    - port : 생략이 가능
- path
  - 추상화된 상대 경로
- parameters
  - 웹 서버에 제공하는 추가적인 데이터
- Anchor
  - 북마크를 의미
  - 하나의 리소스 안에서의 북마크
  - '#' 로 작성 : 이는 서버에 전송되지 않음

특정 이름으로 식별하는 URN

- 이름만으로 데이터를 찾을 수 있음 / 보편적이지 않음



## REST API

애플리켓이션과 프로그래밍적으로 소통하는 방법

###  Web API

open API를 활용하는 추세

- 개발자라면 누구나 사용할 수 있는 공개 API

### REST(Representational State Transfer)

일종의 스프트웨어 설계 방법론

자원을 정의하고 자원의 주소를 지정하는 방법

- URI로 식별
- HTTP Method로 행위 결정
- JSON으로 표현



### JSON

단순 문자열 key-value 형태의 구조를 가짐(dict)

JSON을 데이터로 받아서 Front-end Framework(Vue.js)를 통해 구성

------



## Response

##### 1. HTML 응답

##### 2. JsonResponse()를 사용한 응답

##### 3. Django Serializer를 사용한 응답

##### 4. Django REST framework를 사용한 응답



### 1. HTML 응답

html을 만들어서 렌더링 하는 방법



### 2. JsonResponse()를 사용한 응답

- **views.py**

```python
from django.http.response import JsonResponse
def article_json_1(request):
    articles = Article.objects.all()
    articles_json = []
    for article in articles:
        articles_json.append(
            {
                'id' : article.pk,
                'title' : article.title,
                'content' : article.content,
                'create_at' : article.created_at,
                'update_at' : article.updated_at,
            }
        )
    return JsonResponse(articles_json, safe=False)
```

보내는 데이터가 dictionary가 아니라면 safe=False 해야함

모든 데이터를 입력해야 함



### 3. Django Serializer를 사용한 응답

- **views.py**

```python
from django.http.response import HttpResponse
from django.core import serializers
def article_json_2(request):
    articles = Article.objects.all()
    data = serializers.serialize('json', articles)
    return HttpResponse(data, content_type='application/json')
```

2번 처럼 보든 칼럼을 입력하지 않아도 JSON 불러오기 가능

Serialization을 거치면 다른 환경으로 포멧을 변경할 수 있음



### 4. Django REST framework를 사용한 응답

- **settings.py**

```python
INSTALLED_APPS = [
	'rest_framework',
	...
]
```

rest framework 설치해야함

```python
from django.core import serializers
from rest_framework.response import Response

@api_view()
def article_json_3(request):
    articles = Article.objects.all()
    serializer = ArticleSerializer(articles, many=True)
    return Response(serializer.data)
```

탬플릿에 맞게 JSON을 출력함



```python
import requests

response = requests.get('http://127.0.0.1:8000/api/v1/json-3/')
result = response.json()
```

response 로 API 응답 받아서 json으로 출력

------



## DRF

### ModelSerializer

- **serializers.py**

```python
from rest_framework import seralizers
from .models import Article

class ArticleListSerializer(seralizers.ModelSerializer):
    class Meta:
        model = Article
        fields = ('id', 'title', 'content',)
```

Model의 정보에 따라 자동으로 필드를 생성해줌



#### 생성

```shell
article =Article.objects.all()
serializer = ArticleListSerializer(article, many=True)
serializer.data
```

단일 객체가 아니라 쿼리 셋을 넣어 주려면 many = True를 해주어야 함



### Article

#### 조회

- **views.py**
- 다수

```python
from rest_framework.response import Response
from rest_framework.decorators import api_view

from .models import Article
from .serializers import ArticleListSerializer


@api_view(['GET'])
def article_list(request):
    articles =  Article.objects.all()
    serializer = ArticleListSerializer(articles, many=True)
    return Response(serializer.data)
```

api_view decorator를 반드시 작성해야 함 / default가 GET이지만 작성해주는 것이 좋음

list로 작성

- **serializers.py**

```python
from rest_framework import serializers
from .models import Article

class ArticleListSerializer(serializers.ModelSerializer):
    class Meta:
        model = Article
        fields = ('id', 'title', 'content',)
```



- **views.py**
- 단일

```python
@api_view(['GET'])
def article_detail(request, article_pk):
    articles =  Article.objects.get(pk=article_pk)
    serializer = ArticleSerializer(articles)
    return Response(serializer.data)
```

- **serializers.py**

```python
class ArticleSerializer(serializers.ModelSerializer):
    class Meta:
        model = Article
        fields = '__all__'
```



#### 생성

생성이 성공하면 201 Created 상태 코드를 / 실패 하면 400 Bad request를 응답

- **views.py**

```python
from rest_fromework import status

@api_view(['GET', 'POST'])
def article_list(request):
    if request.method == 'GET':
        articles =  Article.objects.all()
        serializer = ArticleListSerializer(articles, many=True)
        return Response(serializer.data)

    elif request.method == 'POST':
        serializer = ArticleSerializer(data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data, status=status.HTTP_201_CREATED)
        return Response(serializer.data, status=status.HTTP_400_BAD_REQUEST)
```

ArticleSerializer 를 쓰는 이유는 출력되는 데이터를 전체 확인하기 위함 LIST써도 상관없음(출력되는 데이터가 바뀜)

```python
        if serializer.is_valid(raise_exception=True):
        # Response(serializer.data, status=status.HTTP_400_BAD_REQUEST)와 같은 코드 이지만 is_value 안에 작성하여 코드를 줄일 수 있음
```



#### 삭제

- **views.py**

```python
@api_view(['GET', 'DELETE'])
def article_detail(request, article_pk):
    articles =  Article.objects.get(pk=article_pk)
    if request.method == 'GET':
        serializer = ArticleSerializer(articles)
        return Response(serializer.data)
    elif request.method == 'DELETE':
        article.delete()
        return Response(status=status.HTTP_204_NO_CONTENT)
# 목록 조회 / 게시글 생성
```

삭제가 완료되면 204를 응답함



#### 수정

- **views.py**

```python
@api_view(['GET', 'DELETE', 'PUT'])
def article_detail(request, article_pk):
    articles =  Article.objects.get(pk=article_pk)
    if request.method == 'GET':
        serializer = ArticleSerializer(articles)
        return Response(serializer.data)
    elif request.method == 'DELETE':
        articles.delete()
        return Response(status=status.HTTP_204_NO_CONTENT)
    elif request.method == 'PUT':
        serializer = ArticleSerializer(article, data=request.data)
        if serializer.is_valid(raise_exception=True):
            serializer.save()
            return Response(serializer.data)
# 단일 조회 / 수정 / 삭제
```

------



## Comments

#### 조회

- **views.py**
- 다수

```python
@api_view(['GET'])
def comment_list(request):
    if request.method == 'GET':
        comments =  Comment.objects.all()
        serializer = CommentSerializer(comments, many=True)
        return Response(serializer.data)
```

- **serializers.py**

```python
class CommentSerializer(serializers.ModelSerializer):
    class Meta:
        model = Comment
        fields = '__all__'
```



- 단일

```python
@api_view(['GET'])
def comment_detail(request, comment_pk):
    comment =  Comment.objects.get(pk=comment_pk)
    if request.method == 'GET':
        serializer = CommentSerializer(comment)
        return Response(serializer.data)
```



#### 생성

```python
@api_view(['POST'])
def comment_create(request, article_pk):
    article = Article.objects.get(pk=article.pk)
    serializer = CommentSerializer(data=request.daga)
    if serializer.is_valid(raise_exception=True):
        serializer.save(article=article)
        return Response(serializer.data, status=status.HTTP_201_CREATED)
```

이대로 댓글을 작성하면 400 Bad request를 응답

외래키가 들어가기 전에 is_valid를 수행하기 때문에 이를 제외 해주어야함

- **serializers.py**

```
class CommentSerializer(serializers.ModelSerializer):
    class Meta:
        model = Comment
        fields = '__all__'
        read_only_field = ('article',)
```

'읽기 전용 필드'로 작성을 해주면 유효성 검사를 통과하고 출력이 가능



#### 삭제와 수정

```python
@api_view(['GET', 'DELETE', 'PUT'])
def comment_detail(request, comment_pk):
    comment =  Comment.objects.get(pk=comment_pk)
    if request.method == 'GET':
        serializer = CommentSerializer(comment)
        return Response(serializer.data)
    elif request.method == 'DELETE':
        comment.delete()
        return Response(status=status.HTTP_204_NO_CONTENT)
    elif request.method == 'PUT':
        serializer = CommentSerializer(comment, data=request.data)
        if serializer.is_valid(raise_exception=True):
            serializer.save()
            return Response(serializer.data)
```

Article에서 작성한 것과 동일함

------



## 역참조 데이터 조회

### 1. 특정 게시글에 작성된 댓글 목록 출력

- serializers.py

```python
class ArticleSerializer(serializers.ModelSerializer):
    comment_set = serializers.PrimaryKeyRelatedField(many=True, read_only=True)
    # 역참조 하는 대상의 PK만 가져옴
    comment_set = CommentSerializer(many=True, read_only=True)
    # 요청하는 필드를 전체 가져올 수 있음
    class Meta:
        model = Article
        fields = '__all__'
```

필드를 추가하거나 수정하는 것이기 때문에 read_only를 내부에 작성

### 2. 특정 게시글에 작성된 댓글의 갯수 출력

- 갯수도 출력

```python
class ArticleSerializer(serializers.ModelSerializer):
	comment_count = serializers.IntegerField(source='commnet_set.count')
    ...
```

source : 필드를 채우는데 사용할 속성의 이름



### 3. 객체와 리스트를 404에러 없이 가져오기

```python
from django.shortcuts import get_object_or_404, get_list_or_404
get_object_or_404(클래스, pk=article_pk) # 단일 데이터 조회
get_list_or_404(클래스) # 쿼리 셋 전체 반환
```

만약 객체가 없으면 404를 응답함
