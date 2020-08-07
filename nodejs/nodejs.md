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

## 파일 읽기 기능

CRUD
Create Read Update Delete

[fileread](https://nodejs.org/api/fs.html#fs_fs_readfile_path_options_callback)

```javascript
const fs = require('fs');
fs.readFile(path,(err,data)){
        if(err) throw err;
        console.log(data);
}
```
`fs.readFile('/etc/passwd', 'utf8', callback);` 처럼 encoding 옵션을 넣어줄 수도 있다.

`cd ..` 하면 부모 디렉토리로 옮길 수 있다

## Boolean

```javascript
console.log(1==1); //true
console.log(1==2); //false
console.log(1>2); //false
console.log(1<2); //true
console.log(1===1); //true
console.log(1===2); //false
```

결국 하고 싶은 말은 datatype까지 엄격하게 비교하는 방식의 `===`을 기억하자.

## 제어문

flow control statements
[process.argv](https://nodejs.org/api/process.html#process_process_argv)

```javascript
process.argv.forEach((val,index)=>{
        console.log(`${index}:${val}`);
})
```

결국 변수 넣는 것을 `${sth}`으로 접근해야 한다는 것.

## 동기(synchronous)와 비동기(asynchronous)

```javascript
var b = function () {
    console.log('b');
}

//callback
function showfunc(callback) {
    callback();
}

showfunc(b);
```

`b();` 한 값과 `showfunc(b);`한 값은 동일한 결과값을 도출해낸다.

## package manager

NPM -> nodejs에서 쓰는 것

## HTML Form

HTTP method : 오픈소스 수업 시간에 배웠고 썼지만 공부를 안한 내가 잘못 이 바보 멍청이ㅣㅣㅣㅣ

***
[참고](https://www.zerocho.com/category/HTTP/post/5b344f3af94472001b17f2da)

## HTTP란 무엇인가

Hyper Text Transfer Protocol, 인터넷에서 데이터를 주고 받을 수 있는 프로토콜(규칙).
**서버의 역할은 요청에 대한 응답을 보내준다는 것**

### 요청

시작줄, 헤더, 본문

```http
GET https://www.zerocho.com HTTP/1.1
User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) ...
Upgrade-Insecure-Requests: 1
```

```http
HTTP/1.1 200 OK
Connection: keep-alive
Content-Encoding: gzip
Content-Length: 35653
Content-Type: text/html;

<!DOCTYPE html><html lang="ko" data-reactroot=""><head><title...
```
[HTTP 상태(응답) 코드](https://www.zerocho.com/category/NodeJS/post/579b4ead062e76a002648af7)

### HTTP method

REST : 주소를 자원이라고 보고 메서드를 동사라고 보는 개발 방식
`POST action주소 HTTP/1.1`

GET POST(create) DELETE PUT(update)

***

callback 함수도 중요

## nodejs redirection

302는 redirection을 위함 (200은 성공)

[HTTP 상태 코드](https://ko.wikipedia.org/wiki/HTTP_%EC%83%81%ED%83%9C_%EC%BD%94%EB%93%9C)

* 1xx(정보) : 요청을 받았으며 프로세스를 계속한다
* **2xx(성공)** : 요청을 성공적으로 받았으며 인식했고 수용하였다
* **3xx(리다이렉션)** : 요청 완료를 위해 추가 작업 조치가 필요하다
* **4xx(클라이언트 오류)** : 요청의 문법이 잘못되었거나 요청을 처리할 수 없다
* 5xx(서버 오류) : 서버가 명백히 유효한 요청에 대해 충족을 실패했다

```javascript
response.writeHead(302,{Location : `/?id=${title}`});
```

[파일 생성, 삭제, 수정, 동기와 비동기](https://dydals5678.tistory.com/96)

## 정보 보안 for 입력 & 출력

