## Form

유효성 검사를 단순화하고 자동화 한다

1. 렌더링을 위한 데이터 준비 및 재구성
2. 데이터에 대한 HTML forms 생성
3. 클라이언트로부터 받은 데이터 수신 및 처리



앱폴더안에 forms.py를 생성하여 작성



views. 함수 안에 필요한 부분에 아래와 같이 작성

```python
def new(request):
    form = ArticleForm()
    context = {
        'form' : form
    }
    return render(request, "articles/new.html", context)
```



html의 다음의 내용이 바뀐다

```django
<p><label for="title">Title: </label>
        <input type="text" id="title" name="title"></p>
        <p><label for="content">Content: </label>
        <textarea name="content" id="content"></textarea></p>
```

```django
{{ form }}
{{ form.as_p }} # p태그로 감싸져서 렌더링
{{ form.as_ul }} # list 태그로 감싸져서 렌더링
{{ form.as_table }} # tr 태그로 감싸져서 렌더링
```



Formfields : 유효성 검사 로직을 처리

Widgets 단순하게 출력 부분을 담당(form fields에 할당 해야함)

​	`  content = forms.CharField(widget=forms.Textarea)`



### Widget

> 다양한 위젯은 검색을 하여 찾아볼 수 있음

forms.ChoiceFieldchoices=(NATIONS_CHOICES)



### Meta

Meta를 이용하여 더 간단하게 작성할 수 있음

```python
class ArticleForm(forms.ModelForm):
	class Meta: # 모델폼의 정보를 작성하는 곳
        model = Articles # 참조값
        fields = '__all__' # 사용자로 부터 받은 모든 필드를 포함
        exclued = ('title') # title을 제외한 모든 필드
```

form을 활용하면 create도 다음과 같이 작성할 수 있음

```python
def create(request):
    form = ArticleForm(request.POST)
    if form.is_valid():
        form.save()
        return redirect("articles:index")
    return redirect("articles:new")
```

form 안에 `instance=`를작성하면 디폴트 값을 넣은 채 반환 가능



### Form 과 ModelForm

- Form
  - 사용자로부터 받는 데이터가 DB와 연관되어 있지 않는 경우에 사용
  - DB에 영향을 미치지 않고 단순 데이터만 사용되는 경우
- ModelForm
  - 사용자로부터 받는 데이터가 DB와 연관되어 있는 경우에 사용
  - 데이터의 유효성 검사가 끝나면 데이터를 각각 어떤 레코드에 맵핑해야 할지 이미 알고 있기 때문에 바로 save()호출이 가능

아래와 같이 작성이 가능

```python
class ArticleForm(forms.ModelForm):
    title = forms.CharField(
        label="제목",
        widget=forms.TextInput(
            attrs={
                'class' : 'my-title',
                'placeholder' : 'enter the title',
                'maxlength' : 10,
            }
        )
    )

    content = forms.CharField(
        label='내용',
        widget=forms.Textarea(
            attrs={
                'class': 'my-content',
                'placeholder': 'Enter the content',
                'rows': 5,
                'cols': 50,
            }
        ),
        error_messages={
            'required': '내용 입력하라고..',
        }
    )

    class Meta:
        model = Article
        fields = '__all__'
```



### New와 Create 합치기 

GET/POST 모두 처리 가능

New는 GET method를 사용 / Create는 POST method 사용

```python
def create(request):
    if request.method == 'POST':
        # create
        form = ArticleForm(request.POST)
        if form.is_valid():
            article = form.save()
            return redirect('articles:detail', article.pk)
    else:
        # new
        form = ArticleForm()
    context = {
        'form': form,
    }
    return render(request, 'articles/create.html', context)
```

### Update와 Edit 합치기

GET/POST 모두 처리 가능

위와 같은 방법으로 합치면 된다.

```python
def update(request, pk):
    article = Article.objects.get(pk=pk)
    if request.method == 'POST':
        form = ArticleForm(request.POST, instance=article)
        # form = ArticleForm(data=request.POST, instance=article)
        if form.is_valid():
            form.save()
            return redirect('articles:detail', article.pk)
    else:
        form = ArticleForm(instance=article)
    context = {
        'article': article,
        'form': form,
    }
    return render(request, 'articles/update.html', context)

```

### Allowed HTTP methods

`fomr django.views.decorators.http import require_safe`

`@require_safe` # GET에 대해서만 처리

이후 index 작성



`fomr django.views.decorators.http import require_http_methods`

`@require_http_methods(['GET', 'POST'])` # GET과 POST에 대해서만 처리

update와 create위에 작성



`fomr django.views.decorators.http import require_POST`

`@require_POST` # POST에 대해서만 처리

delete위에 작성



### Bootstrap v5 사용

pip install하고 settings에 추가

`pip install django-bootstrap-v5`

```python
{% load bootstrap5 %}
  <h2>bootstrap v5 사용</h2>
  <form action="">
    {% bootstrap_form form %}
  </form>
```

