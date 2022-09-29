### Fork Repo 동기화 하기

> Fork한 레포 최신으로 동기화 하기

```gitbash
git remote add upstream '포크한 원래 원본 레포주소'
//원본 주소를 upstream으로 추가

git fetch upstream
//업데이트 할 내용 불러오기

git merge upstream/'내 레포 브랜치 이름'
//내 브랜치에 머지 시키기

git push origin '내 브랜치'
//로컬에서의 머지 파일들을 내 git 브랜치에 업로드
```

