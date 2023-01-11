# Axios



## 동기 (Synchronous)

모든 일을 순서대로 하나씩 처리하는 것

python이 이와 같은 방식



## 비동기 (Asynchronous)

작업을 시작한 후 결과를 기다리지 않고 다음 작업을 처리하는 것(병렬적 수행)

요청을 보낸 뒤 빨리 응답 오는 작업부터 시행

```javascript
function slowRequest(callBack) {
  console.log('1')
  setTimeout(function() {
    callBack()
  }, 3000);
}
function myCallBack() {
  console.log('2')
}

slowRequest(myCallBack)
console.log('3')

// 1 3 2 순서로 출력
// 2의 경우 3초 뒤에 실행하므로 console.log('3')이 먼저 출력된다
```

#### 사용자 경험 

앞부분이 처리되지 않으면 사용자가 확인을 할 수 없기 때문에

비동기로 처리한다면 먼저 처리되는 부분부터 보여줄 수 있으므로, 긍정적인 효과를 볼 수 있음



### JavaScrip

JS는 한 번에 하나의 일만 수행할 수 있는 Single Thread언어로 요청한 순서대로 처리할 수 밖에 없음

비동기와 관련한 작업은 브라우저 또는 Node 환경에서 처리

**브라우저 환경에서의 비동기 동작**

- Call Stack (LIFO)
- Web API - 오래 걸리는 작업이 들어오면 API로 처리
- Task Queue - API로 처리된 작업들이 들어감 (FIFO)
- Event Loop - CallStack이 비어있는 것을 확인하고 Task Queue에서 가장 오래된 작업을 Call Stack으로 보냄



## Axios 라이브러리

> JS의 HTTP 웹 통신을 위한 라이브러리

인터페이스와 쉽게 사용할 수 있는 비동기 통신 기능을 제공

- then
  - 성공하면 수행할 로직 작성
- catch
  - 실패하면 수행할 로직 작성

script로 사용 가능 (CDN)

```html
<script src="https://cdn.jsdelivr.net/npm/axios/dist/axios.min.js"></script>
```

```html
<script>
    console.log('냐옹')
    const catImageSearchURL = 'https://api.thecatapi.com/v1/images/search'
    const btn = document.querySelector('button')

    btn.addEventListener('click', function() {
        axios.get(catImageSearchURL)
            .then((response) => {
            console.log(response.data[0].url)
        })
            .catch((error) => {
            console.log('실패')
        })
        console.log('냐옹냐용')
    })
</script>
```

.then 과 .catch 를 벗어난 코드부터 실행하고 then과 catch를 실행

고양이 이미지 주소에서 요청을 보내 가져온다

성공하면 .then의 함수 response를 응답

실패하면 .catch의 함수 실패를 반환



response.data를 하면 데이터 어레이를 반환

위의 예시에서는 response.data[0].URL을 하면 주소를 반환 / API로 부터 받아오는 데이터를 확인하면서 진행

**이미지를 처리하는 작업은 시간이 오래걸리기 때문에 비동기식 코드인 JS는 뒤에부터 출력이 된다**



### Callback과 Promise

#### Callback

작업이 완료되는 순서에 따라 처리

이는 작업이 어떤 순서로 진행되는지 예측하기 어려움

:arrow_forward: Call Back함수를 활용

비동기 콜백 - 비동기 작업이 완료된 후 실행할 작엄을 명시하는데 사용

비동기 처리를 순처적으로 동작할 수 있게 함

#### Promise

비동기 작업의 완료 또는 실패를 나타내는 함수

axios 의 .then과 .catch가 이에 해당

```javascript
axios.get('요청 url')
	.then(성공하면 수행)
	.then(1 성공하면 수행)
	.then(1과 2를 성공하면 수행)
	.....
	.catch(하나라도 실패하면 수행)
```

```javascript
// 권장 표기 방식
axios({
	method : 'post',
	url: '요청 url'
}) // 이렇게도 작성 가능
```

------



## AJAX

- profile.html

```html
<div>
    {% comment %} 팔로워 : {{ person.followers.all|length }} / 팔로잉 : {{ person.followings.all|length }} {% endcomment %}
    팔로워: <span id="followers-count">{{ person.followers.all|length }}</span>
    팔로잉: <span id="followings-count">{{ person.followings.all|length }}</span>
  </div>

  {% if request.user != person %}
  <div>
    {% comment %} <form action="{% url 'accounts:follow' person.pk %}" method="POST"> {% endcomment %}
    <form id="follow-form" data-user-id={{ person.pk }}>
      {% csrf_token %}
      {% if request.user in person.followers.all %}
        <input type="submit" value="언팔로우">
      {% else %}
        <input type="submit" value="팔로우">
      {% endif %}
    </form>
  <div>
  {% endif %}

{% block scripts %}
    <script src="https://cdn.jsdelivr.net/npm/axios/dist/axios.min.js"></script>
    <script>
      const form = document.querySelector('#follow-form')
      const csrftoken = document.querySelector('[name=csrfmiddlewaretoken]').value
      form.addEventListener('submit', function(event){
        event.preventDefault()
        axios({
          method: 'post',
          url: `/accounts/${event.target.dataset.userId}/follow/`,
          headers: {'X-CSRFToken': csrftoken},
        })
          .then((response) => {
            const isFollowed = response.data.is_followed
            const followBtn = document.querySelector('#follow-form > input[type=submit]')
            
            if (isFollowed){
              followBtn.value = '언팔'
            } else {
              followBtn.value = '팔로우'
            }
            const followersCountTag = document.querySelector('#followers-count')
            const followingsCountTag = document.querySelector('#followings-count')

            followers_count = response.data.followers_count
            followings_count = response.data.followings_count

            followersCountTag.innerText = followers_count
            followingsCountTag.innerText = followings_count
            })
          .catch((error) => {
            console.log(error)
          })
      })
    </script>
{% endblock scripts %}
```

- views.py

```python
def follow(request, user_pk):
    if request.user.is_authenticated:
        User = get_user_model()
        me = request.user
        you = User.objects.get(pk=user_pk)
        if me != you:
            if you.followers.filter(pk=me.pk).exists():
                you.followers.remove(me)
                is_followed = False
            else:
                you.followers.add(me)
                is_followed = True
            context = {
                'is_followed' : is_followed,
                'followers_count' : you.followers.count(),
                'followings_count' : you.followings.count(),
            }
            return JsonResponse(context)
        return redirect('accounts:profile', you.username)
    return redirect('accounts:login')
```

