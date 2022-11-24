
#### GET_API.py

```python
import requests
import json

def get_director(movie_id):
    BASE_URL = 'https://api.themoviedb.org/3'
    movie_id = movie_id
    PATH1 = f'/movie/{movie_id}/credits'
    my_params = {
        'api_key' : 'c23cd6fb816b2263bfdfecf34a8a6805',
    }
    response = requests.get(BASE_URL + PATH1, params = my_params).json()
    result = response.get("crew")
    # person id 가져오기
    director = 0
    for p in result:
        if p.get("job") == "Director":
            director = p.get("id")
    # 한글로 이름 가져오기
    PATH2 = f'/person/{director}'
    my_params = {
        'api_key' : 'c23cd6fb816b2263bfdfecf34a8a6805',
        'language' : 'ko-KR'
    }
    response = requests.get(BASE_URL + PATH2, params = my_params).json()
    result = response.get('also_known_as')
    name = []
    if result :
        for r in result:
            if r.isalpha():
                name.append(r)
                return name
            else:
                name = []
                name.append(response.get("name"))
                return name
        return name
    else :
        name.append(response.get("name"))
        return name


def get_movies_detail(movie_id):
    BASE_URL = 'https://api.themoviedb.org/3'
    PATH = f'/movie/{movie_id}'
    my_params = {
        'api_key' : 'c23cd6fb816b2263bfdfecf34a8a6805',
        'language' : 'ko',
    }
    response = requests.get(BASE_URL + PATH, params = my_params).json()
    return response


def get_movies():
    # now playing
    movies = []
    for page in range(1,91):
        BASE_URL = 'https://api.themoviedb.org/3'
        PATH = '/movie/now_playing'
        my_params = {
            'api_key' : 'c23cd6fb816b2263bfdfecf34a8a6805',
            'language' : 'ko',
            'region' : 'KR',
            'page': page
        }
        response = requests.get(BASE_URL + PATH, params = my_params).json()
        result = response.get('results')
        for r in result:
            genres = []
            name = 0
            for n in get_director(r.get('id')):
                name = n
            detail = get_movies_detail(r.get('id'))
            for i, d in enumerate(detail.get("genres")):
                genres.append(d.get("name"))

            objects = {
                "model": "movies.movie",
                "fields": {
                    'movie_id' : r.get('id'),
                    'original_title': r.get('original_title'),
                    'title': r.get('title'),
                    'overview': r.get('overview'),
                    'genres': genres,
                    'release_date': r.get('release_date'),
                    'vote_average': r.get('vote_average'),
                    'backdrop_path': r.get('backdrop_path'),
                    'runtime': detail.get('runtime'),
                    'director': name,
                    'poster_path': r.get('poster_path'),
                }
            }
            if name == None:
                pass
            else:
                flag = False
                for movie in movies:
                    if r.get('id') in movie['fields'].values():
                        flag = True
                        break
                if not flag:
                    movies.append(objects)

    # top rating
    for page in range(1, 170):
        PATH = '/movie/top_rated'
        my_params = {
            'api_key' : 'c23cd6fb816b2263bfdfecf34a8a6805',
            'language' : 'ko',
            'region' : 'KR',
            'page': page
        }
        response = requests.get(BASE_URL + PATH, params = my_params).json()
        result = response.get('results')
        for r in result:
            genres = []
            name = 0
            for n in get_director(r.get('id')):
                name = n
            detail = get_movies_detail(r.get('id'))
            for i, d in enumerate(detail.get("genres")):
                genres.append(d.get("name"))

            objects = {
                "model": "movies.movie",
                "fields": {
                    'movie_id' : r.get('id'),
                    'original_title': r.get('original_title'),
                    'title': r.get('title'),
                    'overview': r.get('overview'),
                    'genres': genres,
                    'release_date': r.get('release_date'),
                    'vote_average': r.get('vote_average'),
                    'backdrop_path': r.get('backdrop_path'),
                    'runtime': detail.get('runtime'),
                    'director': name,
                    'poster_path': r.get('poster_path'),
                }
            }
            if name == None:
                pass
            else:
                flag = False
                for movie in movies:
                    if r.get('id') in movie['fields'].values():
                        flag = True
                        break
                if not flag:
                    movies.append(objects)

    # JSON 으로 저장
    with open('movies.json', 'w', encoding='utf-8') as f :
        json.dump(movies, f, ensure_ascii=False, indent=4)
        
get_movies()
```



영화의 기본적인 정보 이외에 상영시간, 및 감독의 이름까지 필요하여 get_director() / get_movies_detail()로 모든 정보를 API를 통해 받아온다. 받아온 정보를 우리가 필요한 정보들로 정제(재구성)하여 json 파일로 저장 한다.



#### recommendation

```python
from django.shortcuts import render
from movies.models import Movie
from movies.models import VoteMovie
from django.contrib.auth import get_user_model

import math
from collections import defaultdict
# Create your views here.

user_genre_weight = []
    
## ! 본 장르에 따라 가중치 부여해서 추가하기

def sim_cosine(name1, name2):
    global user_genre_weight
    sum_name1 = 0
    sum_name2 = 0
    sum_name1_name2 = 0
    count = i = 0
    for genres in name1:
        if genres in name2:
            sum_name1 += pow(name1[genres], 2) * user_genre_weight[i]
            sum_name2 += pow(name2[genres], 2) * user_genre_weight[i]
            sum_name1_name2 += name1[genres]*name2[genres] * user_genre_weight[i]
        i += 1
    if math.sqrt(sum_name1)*math.sqrt(sum_name2) != 0:
        return sum_name1_name2 / (math.sqrt(sum_name1)*math.sqrt(sum_name2))
    else: 
        return 0    

def entropy(name1, name2):
    sum_entropy = 0
    name2_lengh = len(name2)
    for genres in name1:
        if genres in name2:
            sum_entropy -= math.log(float(name2[genres]))
            print(name2[genres])
    return sum_entropy/name2_lengh

def index(request, user_pk) :
    print(math.log(10))

    # movies = Movie.objects.all()
    movies1990s = Movie.objects.filter(release_date__range=(0,1999))
    movies2000s = Movie.objects.filter(release_date__range=(2000,2010))
    movies2010s = Movie.objects.filter(release_date__range=(2010,2050))

    movies1990s_rating = defaultdict(int)
    movies2000s_rating = defaultdict(int)
    movies2010s_rating = defaultdict(int)

    user_movie_genres = defaultdict(int)
    user_movie_centries = defaultdict(int)
    user_movie_centries[2010] += 1
    user_movie_centries[2000] += 1
    user_movie_centries[1990] += 1
    user_movie_rankings = defaultdict(int)
    user_movie_rankings_avg = defaultdict(int)

    # 쿼리셋
    get_user_votes = VoteMovie.objects.filter(like_users = user_pk)
    
    # 유저에 대한 기본 데이터 정리
    for get_user_vote in get_user_votes:

        user_vote_year = int(get_user_vote.like_movies.release_date[0:4])
        if user_vote_year >= 2010:
            user_movie_centries[2010] += 1
        elif user_vote_year <= 2000:
            user_movie_centries[1990] += 1
        else:
            user_movie_centries[2000] += 1

        # 장르 출력
        sub_stack = ''
        user_vote = get_user_vote.vote
        get_user_vote_movie_genres = [] 
        for g in get_user_vote.like_movies.genres:
            if g.isalpha():
                sub_stack += g
            elif sub_stack:
                get_user_vote_movie_genres.append(sub_stack)
                sub_stack = ''
        
        # 본 영화는 제외한 데이터 조회
        movies1990s = movies1990s.exclude(pk=get_user_vote.like_movies.pk)
        movies2000s = movies2000s.exclude(pk=get_user_vote.like_movies.pk)
        movies2010s = movies2010s.exclude(pk=get_user_vote.like_movies.pk)

        # 유저의 별점에 따른 모델 생성
        for genre in get_user_vote_movie_genres:
            user_movie_genres[genre] += 1
            user_movie_rankings[genre] += int(user_vote)
            user_movie_rankings_avg[genre] = user_movie_rankings[genre]/user_movie_genres[genre]
    # 영화 별 데이터 셋 정렬
    for m in movies1990s:
        sub_stack = ''
        m_genres = []
        sub_dic = {}
        for g in m.genres:
            if g.isalpha():
                sub_stack += g
            elif sub_stack:
                m_genres.append(sub_stack)
                sub_stack = ''
        for genre in m_genres:
            sub_dic[genre] = m.vote_average/2
        movies1990s_rating[m.pk] = sub_dic

    for m in movies2000s:
        sub_stack = ''
        m_genres = []
        sub_dic = {}
        for g in m.genres:
            if g.isalpha():
                sub_stack += g
            elif sub_stack:
                m_genres.append(sub_stack)
                sub_stack = ''
        for genre in m_genres:
            sub_dic[genre] = m.vote_average/2
        movies2000s_rating[m.pk] = sub_dic

    for m in movies2010s:
        sub_stack = ''
        m_genres = []
        sub_dic = {}
        for g in m.genres:
            if g.isalpha():
                sub_stack += g
            elif sub_stack:
                m_genres.append(sub_stack)
                sub_stack = ''
        for genre in m_genres:
            sub_dic[genre] = m.vote_average/2
        movies2010s_rating[m.pk] = sub_dic

    movies1990s_result = defaultdict(int)
    movies2000s_result = defaultdict(int)
    movies2010s_result = defaultdict(int)

    global user_genre_weight
    for i, v in user_movie_genres.items():
        user_genre_weight.append(v/sum(user_movie_genres.values()))

    # 코사인 유사도
    for name2_pk, name2_value in movies2010s_rating.items():
        movies2010s_result[name2_pk] = sim_cosine(user_movie_rankings_avg, name2_value)
    sorted_dict2010s = sorted(movies2010s_result.items(), key = lambda item: item[1], reverse = True)

    for name2_pk, name2_value in movies2000s_rating.items():
        movies2000s_result[name2_pk] = sim_cosine(user_movie_rankings_avg, name2_value)
    sorted_dict2000s = sorted(movies2000s_result.items(), key = lambda item: item[1], reverse = True)

    for name2_pk, name2_value in movies1990s_rating.items():
        movies1990s_result[name2_pk] = sim_cosine(user_movie_rankings_avg, name2_value)
    sorted_dict1990s = sorted(movies1990s_result.items(), key = lambda item: item[1], reverse = True)

    # 비율에 따라서 년도별 영화 추천 리스트 생성

    total_rating = 0
    total_rating_1990 = 0
    total_rating_2000 = 0
    total_rating_2010 = 0
    rating_1990 = rating_2000 = rating_2010 = 0
    for key, value in user_movie_centries.items():
        if int(key) == 1990:
            total_rating += int(value)
            total_rating_1990 += int(value)
        if int(key) == 2000:
            total_rating += int(value)
            total_rating_2000 += int(value)
        if int(key) == 2010:
            total_rating += int(value)
            total_rating_2010 += int(value)
    result_movie_pk_sim = []

    rating_1990 = math.ceil(total_rating_1990/total_rating*10)
    rating_2000 = math.ceil(total_rating_2000/total_rating*10)
    rating_2010 = math.ceil(total_rating_2010/total_rating*10)
    
    for i in range(0, rating_2010*3):
        result_movie_pk_sim.append([sorted_dict2010s[i][0], Movie.objects.get(pk=sorted_dict2010s[i][0]).vote_average])
    for i in range(0, rating_2000*3):
        result_movie_pk_sim.append([sorted_dict2000s[i][0], Movie.objects.get(pk=sorted_dict2000s[i][0]).vote_average])
    for i in range(0, rating_1990*3):
        result_movie_pk_sim.append([sorted_dict1990s[i][0], Movie.objects.get(pk=sorted_dict1990s[i][0]).vote_average])

    result_movie_pk_sim.sort(key=lambda x:x[1], reverse=True)
    result_movies = []

    for i in result_movie_pk_sim[0:10]:
        item = {
            'title' : Movie.objects.get(pk=i[0]).title,
            'poster_path' : Movie.objects.get(pk=i[0]).poster_path,
            'pk' : Movie.objects.get(pk=i[0]).pk,
        }
        result_movies.append(item)
    
    context = {
        'items': result_movies
    }

    return render(request, 'recommendations/index.html', context)
```



유저가 평가한 영화의 평점 및 장르를 기반으로 가지고 있는 영화의 데이터 테이블에서 유저가 평가한 영화를 제외한 영화들 중 가장 유사한 영화를 추천해준다. 추천 알고리즘은 코사인 유사도를 기반으로 유저가 평가한 장르에 따라 가중치를 다르게 주어서 장르 유사도가 높은 영화를 추천할 수 있게 설계를 하였다. 데이터 군을 2000년대 이전, 2010년대 이후 , 2000년대~2010년대로 나누어 유저가 평가한 영화들의 년도 분포를 비율로 환산하여 추천 시 보여주는 영화들의 비율을 결정하였다.

유저가 평가한 영화가 적을 수록 단순히 평점 높은 영화를 보여준다는 단점이 있다.



#### StarRating

```javascript
// 별 마우스 오버로 선택
const one = document.querySelector('#first')
const two = document.querySelector('#second')
const three = document.querySelector('#third')
const four = document.querySelector('#fourth')
const five = document.querySelector('#fifth')

const arr = [one, two, three, four, five]

const form = document.querySelector('#star-check-form')
const csrftoken = document.querySelector('[name=csrfmiddlewaretoken]').value

var countChecked = null

// 윈도우 시작하자마자 유저 평점 매기기
window.addEventListener("load", (event) => {
  const uservote = document.querySelector("#uservote").innerText
  handleStarSelect(`${uservote}`)
})
const handleStarSelect = (size) => {
  const children = form.children
  for (let i=0; i < children.length; i++ ) {
    if (i <= size) {
      children[i].classList.add('checked')
      countChecked = i
    }
    else{
      children[i].classList.remove('checked')
    }
  }
}
const handleStar = (selection) => {
  switch(selection) {
    case 'first' : {
      handleStarSelect(1)
      break
    }
    case 'second' : {
      handleStarSelect(2)
      break
    } 
    case 'third' : {
      handleStarSelect(3)
      break
    }
    case 'fourth' : {
      handleStarSelect(4)
      break
    }
    case 'fifth' : {
      handleStarSelect(5)
      break
    }
  }
}
function star(event) {
  handleStar(event.target.id)
}
function initstar() {
  const uservote = document.querySelector("#uservote").innerText
  handleStarSelect(`${uservote}`)
}
// 별 개수 동적으로 보이게 함
arr.forEach(item => 
  item.addEventListener('mouseover', star)
)
form.addEventListener('mouseout', initstar)
// 병가한 별의 개수를 바탕으로 평점 매기기
// 선택시 동작
form.addEventListener('submit', (event) => {
  event.preventDefault()

  const movieId = event.target.dataset.movieId
  const userId = event.target.dataset.userId
  var vote = countChecked

  handleStarSelect(vote)

  // 기존 이벤트 지우기
  arr.forEach(item => 
    item.removeEventListener('mouseover', star)
  )
  // 만약 다시 누르는 경우라면 투표 초기화
  form.removeEventListener('mouseout', initstar)

  if (Number(vote) === Number(document.querySelector("#uservote").innerText)){
    vote = 0
  }
  // 전달할 데이터 저장
  var content_data = {
    'movieId': movieId,
    'userId': userId,
    'vote': vote,
    'csrftoken': csrftoken,
  }

  axios({
    method: 'post',
    url: `http://127.0.0.1:8000/movies/${movieId}/detail/${userId}/uservote`,
    headers: {'X-CSRFToken': csrftoken},
    data: JSON.stringify(content_data),
  })
    .then(response => {
      console.log(response)
      // 이벤트 다시 추가
      document.querySelector("#uservote").innerText = vote
      arr.forEach(item => 
        item.addEventListener('mouseover', star)
      )
      form.addEventListener('mouseout', initstar)
      })
      .catch(err => {
        console.log(err)
      })
})
```

페이지 로드 시 유저의 평가가 있으면 이를 먼저 반영해 준다. 유저가 별점을 누르면 이를 반영하고 별점을 고정시켜 시각적으로 보이게 해준다. 이를 기본값으로 이후 바뀌는 별점의 모습을 볼 수 있다. 기존과 다른 별점을 누르게 되면, 기존의 데이터를 지우고 새로운 별점을 반영한다. 만약 같은 별점을 누르게 되면 데이터를 지우는 초기화가 된다.



#### movies

```javascript
const loadForm = document.querySelector('#load-form')
const csrftoken = document.querySelector('[name=csrfmiddlewaretoken]').value
const movieList = document.querySelector('.movie-list')

var pageCount = null

loadForm.addEventListener('submit', function(event) {
  event.preventDefault()
  pageCount += 1
  var content_data = {
    'pageCount': pageCount,
  }
  axios({
    method: 'post',
    url: `http://127.0.0.1:8000/movies/`,
    headers: {'X-CSRFToken': csrftoken},
    data: JSON.stringify(content_data),
  })
  .then((res) => {
    console.log(res)  
    movies = res.data
    console.log(typeof(movies))
    for (let i=0; i<20; i++) {
      movie = movies[i]
      movieList.innerHTML += `
      <a href='http://127.0.0.1:8000/movies/${movie.pk}/detail/' class="movie-a">
        <img src="https://image.tmdb.org/t/p/w500${movie.poster_url}" alt="movie img" class="movie-img">
        <div class="info">${movie.title}</div>
      </a>
      `
    }
  })
  .catch((err) => {
    console.log(err)
  })
})
```

영화 데이터가 3000개가 넘기 때문에 이를 다 보여주면 렌더링에 많은 시간이 걸린다. 이를 막기 위해 처음 20개의 영화만 출력하고, 유저가 view more movies를 누르게 되면 그 다음 20개의 영화를 추가로 보여주게 했다. 



#### sign up 및 log in

- backend.py

```python
from django.contrib.auth.backends import ModelBackend
from django.contrib.auth import get_user_model
from django.db.models import Q


UserModel = get_user_model()


class EmailBackend(ModelBackend):
    def authenticate(self, request, username=None, password=None, **kwargs):
        try:
            user = UserModel.objects.get(Q(username__iexact=username) | Q(email__iexact=username))
        except UserModel.DoesNotExist:
            UserModel().set_password(password)
            return
        except UserModel.MultipleObjectsReturned:
            user = UserModel.objects.filter(Q(username__iexact=username) | Q(email__iexact=username)).order_by('id').first()

        if user.check_password(password) and self.user_can_authenticate(user):
            return user
```

기본 적인 django form에서는 로그인이 username과 password로만 이루어 진다. 위와 같이 작성을 하여 유저가 username 이외에도 email로 로그인을 할 수 있게 해준다.

유저 nickname은 입력하지 않으면 자동으로 username과 동일하게 생성되게 해주었다.  profile_imge는 맨 처음 기본적으로 주어지는 이미지를 사용하게 되고 이후 수정 페이지에서 이미지를 바꿔줄 수 있다. 

모든 유저는 처음 behind에 글을 쓸 수 있는 권한이 없다. 회원가입시 공지되어있는 이메일로 감독임을 인증하게 되면 behind에 글을 쓸 수 있는 권한이 생긴다.

에러 메세지는 모달 창으로 띄워 알려준다.



#### behind

- search.js

```javascript
const searchInput = document.querySelector('#search-input')
const csrftokenS = document.querySelector('[name=csrfmiddlewaretoken]').value
const resultBox = document.querySelector('#result-Box')

searchInput.addEventListener('keyup', function (event) {
  // const allBehinds = event.target.dataset.behindContent

  const inputContent = event.target.value

  if (resultBox.classList.contains('not-visible')){
    resultBox.classList.remove('not-visible')
  }

  var content_data = {
    'inputContent': inputContent,
    'csrftoken': csrftokenS,
  }
  axios({
    method: 'post',
    url: `http://127.0.0.1:8000/behinds/`,
    headers: {'X-CSRFToken': csrftokenS},
    data: JSON.stringify(content_data),
  })
  .then((res) => {
    const searchResult = res.data.searchResult
    console.log(searchResult)
    resultBox.innerHTML += ``
    if (Array.isArray(searchResult)){
      resultBox.innerHTML = ``
      searchResult.forEach(result => {
        resultBox.innerHTML += `
          <a href='http://127.0.0.1:8000/behinds/${result.pk}/detail/' class='link'>
            <div style='width: 90%; max-height: fit-content; margin-top:15px; margin-bottom:2px; padding: 15px; background-color: white; border-radius: 20px; box-shadow: 5px 5px #5d5d5d; border: 2px solid black;'>
              <p style='text-decoration: underline;'>${result.username} 감독</p>
              <p style='font-size: small;'>${result.title}</p>
            </div>
          </a>
        `
      })
    }
    else{
      console.log('no results')
      if (searchResult.length > 0){
        resultBox.innerHTML = `<b>${searchResult}</b>`
      }
      else{
        resultBox.classList.add('not-visible')
      }
    }

  })
  .catch((err) => {
    console.log(err)
  })
})
```

비하인드 그 안에서 검색을 진행하면 작성자, title, content 순으로 일치하는 게시글들을 최신 순으로 보여준다. 검색 결과는 live로 반영이 되며 결과를 클릭시  해당 게시글의 데테일 페이지로 이동한다.
