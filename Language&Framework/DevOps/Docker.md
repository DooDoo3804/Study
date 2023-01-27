# Docker



## Docker vs VM

VM은 무거움 / os 때문에 많은 시간이 걸릴 수 있음

Docker는 os를 설치하지 않고 진행한다



## Getting start

docker for window를 설치

Microsoft Store에서 Ubuntu 설치

WSL을 2로 업데이트 후 설정

VMware 등을 사용하여 가상환경으로 Ubuntu를 설치하고, docker를 사용할 수 있음



Dockerfile을 만들고 Image를 만든다음 container에 등록하여 사용

## Errors

### docker for windows 실행시 getting start 계속 나올 때

아래 두 줄을 관리자 권한으로 실행한 powershell에 입력

```powershell
wsl --unregister docker-desktop
wsl --unregister docker-desktop-data
```

![image-20230126214018462](./assets/image-20230126214018462.png)

```powershell
dism.exe /online /enable-feature /featurename:Microsoft-Windows-Subsystem-Linux /all /norestart
dism.exe /online /enable-feature /featurename:VirtualMachinePlatform /all /norestart

wsl --set-default-version 2
```

### Got permission denied while trying to connect to the Docker

```
sudo usermod -a -G docker $USER
```

관리자 권한으로 powershell을 실행하여 위의 명령어를 입력



## Dockerfile

```dockerfile
FROM {baseImage}
# 맨 처음에는 baseImage를 설정해야 함
WORKDIR {directory}
# 어떤 directory에 application을 복사해 올 것인지 작성

```

변경이 잦은 layer는 낮은(밑에) 작성하면 된다.

dockerfile 작성에 대한 문서는 다음을 참고

http://docs.docker.com/develop/develop-images/dockerfile_best-practices/



