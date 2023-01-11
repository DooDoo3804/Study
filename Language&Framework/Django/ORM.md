## ORM

설치 이후 진행

​	`pip install ipython`

​	`pip install django-extensions`

vscode에서 진행은 다음과 같이 입력

​	`python manage.py shell_plus`



`Article.objecets.all()` : 테이블 모든 데이터



#### Create

- article = Article()

- article.title = '<title>'
- article.content = '<content>'
- article.save() : 위에 입력한 값을 DB에 반영/저장
- Article.objects.create() : 위의 과정  / save까지의 동작을 포함한 명령어
- article.pk : id와 같은 고유번호

```django
    # article = Article()
    # article.title = title
    # article.content = content
    # article.save()

    # article = Article( title=title, content=content)
    # article.save()

    # Article.objects.create(title=title, content=content)
```

보통 두 번째를 추천함

#### Read

> Article.objects

.all() : 모든 데이터 조회

.get() : 유일한 데이터를 조회 / 만약 데이터가 없거나 중복되면 오류

.filter() : 조건에 맞는 모든 쿼리를 반환

.filter(content__contains = 'ja') : 'ja'가 포함된 모든 데이터를 반환 / 다른 명령어가 있음



#### Edit

조회 변경 save

수정하면 수정된 시간이 변경된다. 

#### Delete

article.delete() : 삭제

삭제된 pk로 새로 추가되는 것이 아니라 원래 pk순서에 이어서 출력

