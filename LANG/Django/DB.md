# DB (DJANGO)

> 외래 키를 사용하여 관계를 설정

외래키 - 다른 테이블의 행을 식별할 수 있는 키

- 1:1 하나가 하나와 관련
- N:1 한 테이블의 0개 이상의 레코드가 다른 테이블의 레코드 한개와 관련된 경우
- N:N 한 테이블의 0개 이상의 레코드가 다른 테이블 0개 이상의 레코드 한개와 관련된 경우



### 외래키

한 테이블의 필드 중 다른 테이블의 행을 식별할 수 있는 키
참조되는 쪽의 PK 값을 가진다

------



### N:1(Comment - Article)

__ForeignKey()__

참조하는 모델의 단수형(소문자)으로 이름을 작성
생성되는 칼럼의 이름이 article_id라고 생성됨!!!

```python
class Comment(models.Model):
    article = models.ForeignKey(Article, on_delete=models.CASCADE)
    content = models.TextField()
    created_at = models.DateTimeField(auto_now_add=True)
    updated_at = models.DateTimeField(auto_now=True)

```

CASCADE = 부모 객체가 삭제 되었을 때 이를 참조하는 객체도 삭제

`python manage.py sqlmigrate articles 0002`
입력하면 sql언어로 만듦

객체 자체를 참조한다...?

```python
comment.article = article
#객체 자체를 넣음
```



### 역참조

나를 참조하는 테이블을 참조하는 것
N:1의 관계에서 1이 N을 참조하는 상황

__article.comment_set 형태로 댓글 객체를 참조할 수 있음__

```
article.comment_set.all()
#게시글에 작성된 모든 댓글
```



### Comment Form 작성

```python
class CommentForm(forms.ModelForm):

    class Meta:
        model = Comment
        exclude = ('article',)
```

외래키는 views함수 내에서 처리가 되어야 한다.



```python
path('<int:pk>/comments/', views.comments_create, name='comments_create'),
```



### Create Comment

```python
def comments_create(request, pk):
    article = Article.objects.get(pk=pk)
    comment_form = CommentForm(request.POST)
    if comment_form.is_valid():
        comment = comment_form.save(commit=False) # 저장을 하지않고 객체를 미리 반환해줌
        comment.article = article # 이것을 작성해 주어야 article.pk가 추가됨
        comment.save()
    return redirect('articles:detail', article.pk)
```

.save(commit=False) - 객체는 생성하지만 저장은 하지 않음



### Delete Comment

```python
path('<int:comment_pk>/comments/delete/', views.comments_delete, name='comments_delete'),
path('<int:article_pk>/comments/<int:comment_pk>/delete/', views.comments_delete, name='comments_delete'),
```

아래로 작성하면 url의 규칙성을 가져갈 수 있음

```python
def comments_delete(request, comment_pk, article_pk):
    comment = Comment.objects.get(pk=comment_pk)
    comment.delete()
    return redirect('articles:detail', article_pk)
```

수정은 JS를 배우면 구현 가능... 페이지가 변하여서 수정하는 방법

#### 댓글 개수 출력

```python
  {% if comments %}
    <p>{{ comments|length }} 개의 댓글이 있습니다. </p>
  {% endif %}
```

```python
  <ul>
    {% for comment in comments %}
    <li>
      {{ comment.content }}
      <form action="{% url 'articles:comments_delete' article.pk comment.pk%}" method="POST">
        {% csrf_token %}
        <input type="submit" value="delete">
      </form>
    </li>
    {% empty %}
      <li>댓글이 없어요</li>
        #comments가 비어있으면 실행되는 부분
    {% endfor %}
  </ul>
```

------



### N:1(Article - User)

settings.AUTH_USER_MODEL - 문자열 반환

```python
from django.conf import settings
class Article(models.Model):
    user = models.ForeignKey(settings.AUTH_USER_MODEL, on_delete=models.CASCADE)
	...
```

모델의 객체가 생성되기 이전에 USER모델을 참조해야 하므로 settings로 부터 참조해온다.
즉 models.py에서만 settings.AUTH_USER_MODEL 사용
나머지 모든 곳에서는 get_user_model() 사용



### CREATE

인증된 회원이 댓글 작성
user의 정보를 가려줌

```python
class ArticleForm(forms.ModelForm):

    class Meta:
        model = Article
        # fields = '__all__'
        exclude = ('user',)
```

```python
@login_required
@require_http_methods(['GET', 'POST'])
def create(request):
    if request.method == 'POST':
        form = ArticleForm(request.POST)
        if form.is_valid():
            
            #
            article = form.save(commit=False)
            article.user = request.user
            article.save()
            # article:comments 부분에서 했듯이 commit옵션을 False로 객체만 생성하고 user의 정보를 받아 이후 저장을 함
            ...
```



### DELETE

```python
@require_POST
def delete(request, pk):
    if request.user.is_authenticated:
        article = Article.objects.get(pk=pk)
        ##
        if request.user == article.user:
            article.delete()
            return redirect('article:index')
	return redirect('articles:detail', article.pk)
```



### UPDATE

```python
def update(request, pk):
    article = Article.objects.get(pk=pk)
    if request.user == article.user:
        if request.method == 'POST':
            form = ArticleForm(request.POST, instance=article)
            # form = ArticleForm(data=request.POST, instance=article)
            if form.is_valid():
                form.save()
                return redirect('articles:detail', article.pk)
        else:
            form = ArticleForm(instance=article)
    else:
        return redirect('articles:index')
	...
```

detail.html에 if문으로 request와 article의 user가 같으면 update와 delete 버튼을 보이게 할 수 있음

------



### N:1(Comment- User)

settings.AUTH_USER_MODEL - 문자열 반환

```python
user = models.ForeignKey(settings.AUTH_USER_MODEL, on_delete=models.CASCADE)
```

model.py에서 변경을 진행하였으므로 migrate를 다시 진행해야 함
model에서 새로운 필드를 작성했으므로, 이를 form에서 exclude해주어야 함

```python
exclude = ('article', 'user',)
```

views.py comment_create에서 댓글작성 시 객체를 받아옴

```python
comment.user = request.user
```

### DELETE

삭제 요청 사람과 작성한 사람이 일치하는지 확인

```python
def comments_delete(request, comment_pk, article_pk):
    comment = Comment.objects.get(pk=comment_pk)
    if request.user == comment.user:
        comment.delete()
    return redirect('articles:detail', article_pk)
```

```python
{% if comment.user == request.user %}
# 버튼을 가려주기 위한 조건문
```

------

### 인증된 사용자에 대한 접근

```python
def comments_create(request, pk):
    if request.user.is_authenticated:
        ...
    return redirect('accounts:login')
```

```python
  {% if request.user.is_authenticated %}
  <form action="{% url 'articles:comments_create' article.pk %}" method="POST">
    {% csrf_token %}
    {{ comment_form }}
    <input type="submit">
  </form>
  {% else %}
    <a href="{% url 'accounts:login' %}">댓글을 작성하려면 로그인 하세요</a>
  {% endif %}
# 인증된 사용자가 아니라면 로그인 페이지로 이동할 하이퍼 링크를 줌
```

모든 동작을 작성한 다음에 decoration같은 부가 항목을 작성한다

------

### Import 작성 가이드

standard library

third-party

django 내장

local 함수



### HTTP response status cords

비인증 401

```python
from django.http import HttpResponse

def delete :
...
    return HttpResponse(status=401)
```

인증된 사용자 이지만 권한이 없는 사용자 403

```
from django.http import HttpResponseForbidden
```

------



### M:N (Articles:User)

- models.py

```python
user = models.ForeignKey(settings.AUTH_USER_MODEL, on_delete=models.CASCADE)
like_users = models.ManyToManyField(settings.AUTH_USER_MODEL, related_name='like_articles')
```

위의 코드를 작성한다면 역참조의 이름이 같아지기 때문에 related_name으로 역참조의 이름을 바꿔야함 (보통 M:N에서 바꿔줌)

- - article.user
    - 게시글을 작성한 유저 - N:1
  - user.article_set
    - 유저가 작성한 게시글(역참조) - N:1
  - article.like_users
    - 게시글을 좋아요한 유저 - M:N
  - user.like_articles
    - 유저가 좋아요한 게시글(역참조) - M:N



- articles/urls.py

  - ```python
    urlpatterns=[
    	...
    	path('<int:article_pk>/likes/', views.likes, name='likes'),
    ]
    ```

- articles/views.py

  - ```python
    def likes(request, article_pk):
        article = Article.objects.get(pk=article_pk)
        if request.user in article.like_users.all():
            article.like_users.remove(request.user)
        else:
            article.like_users.add(request.user)
        return redirect('articles:index')
    ```

```pyhton
if article.like_users.filter(pk=article_pk).exists():
```

.filter().exists() 를 사용하면 많은 데이터에서 빠른 결과를 불러올 수 있음 / True / False 반환

- index.html

  - ```html
    <div>
        <form action="{% url 'articles:likes' article.pk %}" method="POST">
            {% csrf_token %}
            {% if request.user in article.like_users.all %}
            <input type="submit" value="좋아요 취소">
            {% else %}
            <input type="submit" value="좋아요">
            {% endif %}
        </form>
    </div>
    ```

------



### M:N (User:User)

- accounts/urls.py

  - ```python
    path('profile/<str:username>', views.profile, name='profile'),
    ```

- accounts/views.py

  - ```python
    def profile(request, username):
        User = get_user_model()
        person = User.objects.get(username=username)
        context = {
            'person' : person
        }
        return render(request, 'accounts/profile.html', context)
    ```

- profile.html

  - ```html
    {% extends 'base.html' %}
    
    {% block content %}
        <h1>{{ person.username }}의 프로필</h1>
        <hr>
    
        <h2>{{ person.username }}이 작성한 게시글</h2>
        {% for article in person.article_set.all %}
            <div>{{ article.title }}</div>
        {% endfor %}
        <hr>
    
        <h2>{{ person.username }}이 작성한 댓글</h2>
        {% for comment in person.comment_set.all %}
            <div>{{ comment.content }}</div>
        {% endfor %}
        <hr>
    
        <h2>{{ person.username }}이 좋아요한 게시글</h2>
        {% for article in person.like_articles.all %}
            <div>{{ article.title }}</div>
        {% endfor %}
        <hr>
        <a href="{% url 'articles:index' %}">back</a>
    {% endblock content %}
    ```

- articles/index.html

  - ```html
        <p>
          <b>작성자 : <a href="{% url 'accounts:profile' article.user.username%}">{{ article.user }}</b></a>
        </p>
    ```

  다음과 같이 작성하여 작성자의 프로필로 이동할 수 있게 함

------



### Follow 기능

- accounts/models.py

  - ```python
    class User(AbstractUser):
        followings = models.ManyToManyField('self', symmetrical=False, related_name='followers')
    ```

- accounts/urls.py

  - ```python
    path('<int:user_pk>/follow/', views.follow, name='follow'),
    ```

- accounts/profile.html

  - ```html
        {% if request.user != person %}
            <div>
                <form action="{% url 'accounts:follow' person.pk%}" method="POST">
                    {% csrf_token %}
                    {% if request.user in person.followers.all %}
                        <input type="submit" value="언팔">
                    {% else %}
                        <input type="submit" value="팔로우">
                    {% endif %}
                </form>
            </div>
        {% endif %}
    ```

- accounts/views.py

  - ```python
    def follow(request, user_pk):
        User = get_user_model()
        person = User.objects.get(pk=user_pk)
        if request.user != person:
            if request.user in person.followers.all():
                person.followers.remove(request.user)
            else:
                person.followers.add(request.user)
        return redirect('accounts:profile', person.username)
    ```

- articles/index.html

  - ```html
    <p>좋아요 수: {{ article.like_users.all | length }}</p>
    ```

  위와 같이 작성하면 길이를 출력할 수 있음

  
