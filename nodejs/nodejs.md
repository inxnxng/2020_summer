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

## 