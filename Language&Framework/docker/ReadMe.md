# Docker

Docker tutorial

------

## Getting start

docker for window를 설치

Microsoft Store에서 Ubuntu 설치

WSL을 2로 업데이트 후 설정



VMware 등을 사용하여 가상환경으로 Ubuntu를 설치하고, docker를 사용할 수 있음

## Errors

### Got permission denied while trying to connect to the Docker

```
sudo usermod -a -G docker $USER
```

관리자 권한으로 powershell을 실행하여 위의 명령어를 입력

