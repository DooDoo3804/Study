## Authentication(인증)

`startapp accounts`

앱 등록 진행



### 커스텀 user 모델로 대체

개발마다 요구하는 식별 값이 다르기 때문에 애초에 설정하고 진행한다

built-in이 진행되면 바꾸기 매우 어렵기 때문에 이를 바꾸고 진행한다.



DB를 초기화 하고 진행해야함

### settings.py

pjt settings에 추가

```python
AUTH_USER_MODEL = '<모델명>.User'
```



### account/admin.py

```python
from django.contrib import admin
from django.contrib.auth.admin import UserAdmin
from .models import User
admin.site.register(User, UserAdmin)
```



### account/models.py

```python
from django.db import models
from django.contrib.auth.models import AbstractUser
class User(AbstractUser):
    pass
```



### account/urls.py

```python
from django.shortcuts import render, redirect
from django.contrib.auth.forms import AuthenticationForm
from django.contrib.auth import login as auth_login
def login(request):
    if request.method == "POST":
        form = AuthenticationForm(request, request.POST)
        if form.is_valid():
            auth_login(request, form.get_user())
            return redirect('articles:index')
    else:
        form = AuthenticationForm()
    context = {
        'form' : form
    }
    return render(request, "accounts/login.html", context)
```



### Login

urls에 작성 이후

html생성 작성 이후

views 작성(아래)

```python
from django.contrib.auth.forms import AuthenticationForm
from django.contrib.auth import login as auth_login
def login(request):
    if request == "POST":
        form = AuthenticationForm(request, request.POST)
        if form.is_valid():
            auth_login(request, form.get_user())
            return redirect('articles:index')
    else:
        form = AuthenticationForm()
    context = {
        'form' : form
    }
    return render(requqest, 'accounts/login.html', context)
```



### 로그인 되어있는 유저의 정보 출력

html에서 또는 base.html에서 `{{ user }}` 으로 출력 가능

인증된 사용자 : User()

인증되지 않은 사용자 : AnonymousUser()



### Logout

```python
from django.contrib.auth import logout as auth_logout
def logout(request):
    auth_logout(request)
    return redirect("articles:index")
```

html에서 views함수 호출하면 된다. POST 방식으로 제출



### 회원가입

login페이지와 동일함

```python
from .forms import CustonUserCreationForm, CustonUserChangeForm
def signup(request):
    if request.method == "POST":
        form = CustomUserCreationForm(request.POST)
        if form.is_valid():
            form.save()
            return redirect("articles:index")
    else:
        form = CustomUserCreationForm()
    context = {
        'form' : form
    }
    return render(request, "accounts/signup.html", context)
```

#### models.py

제공해 주는 UserCreationForm은 우리가 커스텀을 통해 바꿨기 떄문에 이를 상속받아서 model을 바꿔주어야 함

이후 UserChangeForm 역시 바꿔주어야 함

```python
from django.contrib.auth.forms import UserCreationForm, UserChangeForm
from django.contrib.auth import get_user_model #직접 참조하지 않고 get_user_model을 통해 가져옴

class CustonUserCreationForm(UserCreationForm):
    class Meta(UserCreationForm.Meta):
        model = get_user_model()
        fields = UserCreationForm.Meta.fields + ('email',) # 필요한 필드는 이와 같이 추가 가능
class CustonUserChangeForm(UserChangeForm:
    class Meta(UserChangeForm.Meta):
        model = get_user_model()
```

Custom 이 붙은 재정의된 form으로 사용

#### 회원가입 이후 바로 로그인 해주기

```python
 user = form.save()
auth_login(request, user) # signup view함수에 다음과 같이 작성 바로 로그인 시켜줌
```



### 회원탈퇴

```python
def delete(request):
    request.user.delete()
    return redirect("articles:index")
```

위의 코드는 세션을 지우지 못함

아래의 코드를 추가하여 세션을 지울 수 있음

```python
auth_logout(request)
```



### 회원정보 수정

계속 같은 방법으로 작성하면 된다 

회원 정보 같은 경우 form field에서 `'__all__'`을 하면 모든 필드를 불러와서 적합하지 않음으로 field를 재정의 해주어야 함

```python
def update(request):
    if request.method == "POST":
        form = CustonUserChangeForm(request.POST, instance=request.user)
        if form.is_valid():
            user = form.save()
            return redirect("articles:index")
    else:
        form = CustonUserChangeForm(instance=request.user)
    context = {
        'form' : form
    }
    return render(request, 'accounts/update.html', context)
```

```python
class CustonUserChangeForm(UserChangeForm:
    class Meta(UserChangeForm.Meta):
        model = get_user_model()
        field = ('email', 'first_name', 'last_name') # 필요한 field를 골라서 작성
```



### 비밀번호 변경

비밀번호는 암호화의 과정이 필요하기 때문에 회원 정보 수정과는 다른 작업이 필요하다

```python
from django.contrib.auth import update_session_auth_hash
def change_password(request):
    if request.method == "POST":
        form = PasswordChangeForm(request.user, request.POST)
        if form.is_valid():
            form.save()
            update_session_auth_hash(request, form.user)
            return redirect("articles:index")
    else:
        form = PasswordChangeForm(request.user)
    context = {
        'form' : form
    }
    return render(request, 'accounts/change_password.html', context)
```

비밀번호를 바꾸면 세션이 바뀌기 때문에 로그인이 풀린다 / 기존의 정보와 다르기 때문

update_session_auth_hash()를 사용하여 세션을 바꿔준다

```
update_session_auth_hash(request, form.user) # user의 정보를 받아온다.
```



### 유저의 상태에 따라 화면 제한

	#### is_authenticated

request.user에서 이를 접근할 수 있음 / 그냥 로그인이 되어있는 사용자인가를 확인만 함

```django
{% if request.user.is_authenticated %}
      <h3>{{ user }}</h3>
      <form action="{% url "accounts:logout" %}" method="POST">
        {% csrf_token %}
        <input type="submit" value="Logout">
      </form>
      <form action="{% url "accounts:delete" %}" method="POST">
        {% csrf_token %}
        <input type="submit" value="회원탈퇴">
      </form>
      <a href="{% url "accounts:update"%}">회원정보수정</a>
    {% else %}
      <a href="{% url 'accounts:login' %}">Login</a>
      <a href="{% url "accounts:signup" %}">Signup</a>
    {% endif %}
```

그냥 화면상으로 보이는 부분만 제한을 건 것

___유효성이 하나도 없음!!___

#### decoration

```python
from django.contrib.auth.decorators import login_required
@login_required # decoration은 작성 순서에 따라 우선 순위 실행
@require_http_methods(['GET', 'POST'])
```

login_required 통과를 못하면 accounts/login/으로 보낸다. 일괄적으로

form 의 action주소가 비어있으면 브라우저에 표시되어있는 주소로 연결해줌

```python
return redirect(request.GET.get('next') or 'articles:index') # 단출평가를 통해 작성 if else가능
```

삭제 delete의 경우 post만 처리가 가능한데 decoration is_authenticated를 통과하면 post를 잃어버리기 때문에 함수 안쪽에 넣어서 처리를 해주어야함 / 구조적인 문제

```python
@require_POST
def delete(request, pk):
    if request.user.is_authenticated:
        article = Article.objects.get(pk=pk)
        article.delete()
    return redirect('articles:index')
```

