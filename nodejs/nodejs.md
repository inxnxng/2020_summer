# 잉크 with NODE.JS

Node.js Application --> Node.js runtime --> javascript

WEB BROWSER <--> WEB SERVER by apache
WEB BROWSER <--> WEB SERVER by Node.js

## URL

```
        host(domain)           path              query string
https://opentutorials.org:3000/course/3332/21046?id=HTML&page=12
protocol                  port(기본 값은 80)
```

## 변수 바꾸기
html의 내용을 \`\`을 통해 붙여넣고 바꾸고 싶은 변수를 `${변수}`를 통해 바꿔주기</br>
EX) `${queryData.id}`