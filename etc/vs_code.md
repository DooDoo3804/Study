## 설정 Json

> ctr + shift + p

### 확장자마다 들여쓰기 다르게 설정

preferences: open settings (Json)

아래 설정을 추가한다

```python
"[python]": {
        "editor.insertSpaces": true,
        "editor.tabSize": 4  
    }, #python 대신에 원하는 확장자를 입력할 수 있다.
```

---

### ! tab 자동완성 변경하기

왼쪽 하단 톱니바퀴 모양 누르고 코드 블럭 수정에 들어간다

html을 선택한다.

나온 화면에 {} 안에 아래의 코드를 입력한다.

```html
	"html-skeleton":{
		"prefix": "!!",
		"body": [
			"<!DOCTYPE html>",
			"<html lang=\"en\">",
			"<head>",
			"\t<meta charset=\"UTF-8\">",
			"\t<meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">",
			"\t<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">",
			"\t<title>$1</title>",
			"\t<link href=\"https://cdn.jsdelivr.net/npm/bootstrap@5.2.0/dist/css/bootstrap.min.css\" rel=\"stylesheet\" integrity=\"sha384-gH2yIJqKdNHPEq0n4Mqa/HGKIhSkIHeL5AyhkYV8i59U5AR6csBvApHHNl/vI1Bx\" crossorigin=\"anonymous\">",
			"</head>",
			"<body>",
			"\t$2",
			"",
			"\t<script src=\"https://cdn.jsdelivr.net/npm/bootstrap@5.2.0/dist/js/bootstrap.bundle.min.js\" integrity=\"sha384-A3rJD856KowSb7dwlZdYEkO39Gagi7vIsF0jrRAoQmDKKtQBHUuLZ9AsSv4jD4Xa\" crossorigin=\"anonymous\"></script>",
			"</body>",
			"</html>",
		]
	}
```

