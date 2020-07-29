# 잉크 with JAVASCRIPT

## 객체

```javascript
var grades = {
    'list': {'egoing': 10, 'k8805': 6, 'sorialgi': 80},
    'show' : function(){
        for(var name in this.list){
            document.write(name+':'+this.list[name]+"<br />");
        }
    }
};
grades.show();

```

var grades 라는 이름의 객체를 만들겠다.
그 안에는 'list'라는 아이가 있는데 걔는 배열이다.
'show'라는 아이가 있는데 얘는 function이다.
`: function(){}` 을 통해 function으로만 선언하지 않고 함수의 이름을 붙여준 것과 같다. 여기서는 'show'가 function의 이름.


## 모듈

* 호스트 환경이란?
자바스크립트가 구동되는 환경을 의미한다. 예를 들어 node.js는 서버 측에서 실행되는 자바스크립트다. 이 언어는 자바스크립트의 문법을 따르지만 이 언어가 구동되는 환경은 브라우저가 아니라 **서버측 환경**이다.

```javascript
<!DOCTYPE html>
<html>
<head>
    <meta charset = 'utf-8'/>
    <script src = "greeting.js"></script>
</head>
<body>
    <script>
        alert(welcome());
    </script>
</body>
</html>
```

`<script src = "greeting.js"></script>`는 src속성을 가져와 다운하여 소스 안에 있는 함수를 쓸 수 있음. 즉 main.html안에 이 함수가 정의되어 있지 않음에도 실행할 수 있음.

### nodejs 맛보기

```javascript
var PI = Math.PI;

exports.area = function(r){
    return PI  *r *r;
};

export.circumference = function(r ){
    return 2*PI*r;
}
```

```javascript
var circle  = require('./node.circle.js'); //import 느낌인거지
console.log( 'The area of a circle of radius 4 is '+ circle.area(4));
```

### 라이브러리

라이브러리는 모듈과 비슷한 개념. 모듈이 프로그램을 구성하는 작은 부품으로서의 로직이라면 라이브러리는 자주 사용되는 로직을 재사용하기 편리하도록 잘 정리한 일련의 코드들의 집합.

#### jQuery VS Javascript

순수 자바스크립트에서 이벤트 핸들러 사용시 번거로움을 제이쿼리로 줄일 수 있음

### API

application programming interface. 프로그램이 동작하는 환경을 제어하기 위해서 환경에서 제공되는 조작 장치

#### UI? API?

[참고](https://estelar.tistory.com/66)

공통점 : interface 제공
차이점 : USER / APPLICATION PROGRAMMING

* UI : 컴퓨터 시스템과 컴퓨터를 사용하는 사람 사이의 접점에 위치하면서 입력장치, 출력장치들에 해당되는 접점/중계자에 해당함. 사용자를 대면하는 접점이 되는 지점을 포괄적으로 이야기하는 것.

## 정규표현식 

[참고](https://developer.mozilla.org/ko/docs/Web/JavaScript/Guide/%EC%A0%95%EA%B7%9C%EC%8B%9D)

compile execution 으로 이루어진다.

문자열에 나타나는 특정 문자 조합과 대응시키기 위해 사용되는 패턴. 자바스크립트에서는 정규 표현식 또한 객체다. 

* compile : 검출하고자 하는 패턴을 만드는 일. 우선 정규표현식 객체를 만들어야 함.

    * 정규표현식 리터럴 : `var pattern = /a/`
        * 정규식 리터럴(슬래쉬 / 로 감싸는 패턴)
        * 정규식이 상수라면 성능 향상
        * 스크립트가 불러와질 때 컴파일 된다 
  
    * 정규표현식 객체 생성자 : `var pattern = new RegExp('a');`
        * RegExp 객체의 생성자 함수를 호출하는 방법 
        * 정규식이 실행 시점에 컴파일 된다
        * 정규식의 패턴이 변경될 수 있는 경우 혹은 사용자 입력과 같이 다른 출처로부터 패턴을 가져와야하는 경우 생성자 함수를 사용하라

이거 이산구조 마지막 단원쯤에 돌고도는 맵 그거임
이거는 url 검색할 때 검색 단어 찾기에 쓰일 듯

## 함수지향

자바 스크립트에서 함수는 객체를 이해하는 데 가장 중요한 기초를 이룬다. 
내 문제 : 오픈소스 수업 프로젝트에 전역변수를 남발함

### 유효범위

```javascript
var scope = 'global';
function fscope(){
    alert(vscope);
}
fscope();
```

결과는 global이다.

```javascript
var vscope = 'global';
function fscope(){
    var vscope = 'local';
    alert('함수안 ' + vscope);
}
fscope();
alert('함수 밖 '+vscope);
```

내가 파악해야하는 것은 변수를 선언할 때는 꼭 var을 붙이는 것, 전역변수를 사용해야한다면 그것을 사용하는 이유가 명확해야하고, 함수를 저렇게 선언하는 구나 이 정도?

### 값으로서 함수와 콜백


객체의 속성 값으로 담겨진 함수를 method라고 부른다

```javascript

a = {
    b: function(){}
};
```

함수는 함수의 리턴 값으로도 사용할 수 있다

```javascript
function cal(mode) {
    var funcs = {
        'plus': function(left,right){return left+right;},
        'minus': function(l,r){return l-r;}
    }
    return funcs[mode];
}

alert(cal('plus')(2,1));
alert(cal('minus')(2,1));  
```

배열 값으로도 사용할 수 있다
왜 아래 값이 60.5이 나오는지 think
[참고](https://youtu.be/1pqJphcounU)

```javascript
var process = [
    function(input){return input +10;},
    function(i){return i*i;},
    function(i){return i/2;}
];

var input = 1;

for(var i = 0 ; i < process.length; i++){
    input = process[i]\(input\);
}
alert(input);
```

[콜백 - 비동기 처리](https://youtu.be/NDFjwybbong)

Ajax (Asynchronous : 비동기 javascript and XML)

값으로서의 함수

$ : jQuery에서 객체로 받는 부분

get : 요청한다!!!! 오픈소스 수업

1번째 인자 : 주소

2번째 인자 : 주소에서 받아온 값을 result에 넣는다

3번째 인자 : 파일 형식

```javascript
$.get('./datasource.json.js', function(result){
        console.log(result);
    }, 'json');
```

### 클로져

**let**과 **const**를 이용하자~ :)

내부함수는 외부함수의 지역변수에 접근할 수 있는데 외부함수의 실행이 끝나서 외부함수가 소멸된 이후에도 내부함수가 외부함수의 변수에 접근할 수 있다.

```javascript
function outter(){
    var title = 'coding everybody';  
    return function(){        
        alert(title);
    }
}
inner = outter();
inner();
```

1. 함수 outter의 호출 -> 결과는 변수 inner에 담김
2. inner의 호출 하지만 outter 함수는 실행이 끝났기 때문에 이 함수의 지역변수는 소멸되는 것이 자연스럽다. 하지만 inner 실행시 coding everybody가 출력된다
3. 외부함수의 지역변수 title이 소멸되지 않았다는 것

**클로저**란 내부함수가 외부함수의 지역변수에 접근할 수 있고, 외부함수는 외부함수의 지역변수를 사용하는 내부함수가 소멸될 때까지 소멸되지 않는다.

```javascript
function factory_movie(title){
    return {
        get_title : function (){
            return title;
        },
        set_title : function(_title){
            title = _title
        }
    }
}
ghost = factory_movie('Ghost in the shell');
matrix = factory_movie('Matrix');
 
alert(ghost.get_title());
alert(matrix.get_title());
 
ghost.set_title('공각기동대');
 
alert(ghost.get_title());
alert(matrix.get_title());
```

```javascript
var arr = []
for(var i = 0; i < 5; i++){
    arr[i] = function(id) {
        return function(){
            return id;
        }
    }(i);
}
for(var index in arr) {
    console.log(arr[index]());
}
```

밑 for문에 arr\[index]() 를 하면 외부함수만 넣을 때와 달리 첫 for문의 i에 접근할 수 있다.

### arguments

```javascript
function sum() {
    var i, _sum = 0; 
    for(i = 0 ; i<arguments.length; i++){
        document.write(i + ' : '+arguments[i]='\n');
        _sum+= arguments[i];
    }
    return _sum;
}
document.write('result :'+sum(1,2,3,4));
```

sum은 인자로 전달된 값을 모두 더해서 리턴하는 함수인데 첫 행에서의 함수는 인자에 대한 정의가 없다. 하지만 마지막 라인에서는 4개의 인자를 sum함수에게 전달하고 있다.
-->arguments라는 특수 배열이 있기 때문!!!!!<--
사실 arguments는 사실 배열이 아님. 객체의 인스턴스임.

### 매개변수

arguments.length는 **전달된 실제 인자의 수**
함수.length는 **함수에 정의된 인자의 수**

[참고](https://opentutorials.org/course/743/6548)

```javascript
function zero(){
    console.log(
        'zero.length', zero.length,
        'arguments', arguments.length
    );
}
function one(arg1){
    console.log(
        'one.length', one.length,
        'arguments', arguments.length
    );
}
function two(arg1, arg2){
    console.log(
        'two.length', two.length,
        'arguments', arguments.length
    );
}
zero(); // zero.length 0 arguments 0 
one('val1', 'val2');  // one.length 1 arguments 2 
two('val1');  // two.length 2 arguments 1
```

### 함수 호출

함수는 객체이다.

```javascript
function sum(arg1, arg2){
    return arg1+arg2;
}
alert(sum.apply(null, [1,2]))
```

sum은 Function 객체의 인스턴스다. 따라서 객체 Function의 메소드 apply를 호출할 수 있다. apply 메소드는 2개의 인자를 갖는다.

* 첫번째 인자 : 함수가 실행될 맥락.
* 두번째 인자 : 배열. 배열에 담겨있는 원소가 함수의 인자로 순차적으로 대입된다.

만약 apply의 첫번째 인자로 null을 전달하면 apply가 실행된 함수 인스턴스는 전역객체(브라우저에서는 window)를 맥락으로 실행되게 된다.

```javascript
o1 = {val1:1, val2:2, val3:3}
o2 = {v1:10, v2:50, v3:100, v4:25}
function sum(){
    var _sum = 0;
    for(name in this){
        _sum += this[name];
    }
    return _sum;
}
alert(sum.apply(o1)) // 6
alert(sum.apply(o2)) // 185
```

두 개의 객체를 만들었다. o1는 3개의 속성을 가지고 있고 각각의 이름은 val1, val2, val3이다. o2는 4개의 속성이고 o1과 다른 속성의 이름과 속성의 수도 다르다.

다음으로 함수 sum을 만들었다. for in문을 이용해 객체 자신(this)의 값을 열거한 후에 각 속성의 값을 지역변수 _sum에 저장한 후에 이를 리턴하고 있다.

Function의 메소드 apply의 첫번째 인자는 함수가 실행될 맥락이므로 위의 방법은 함수 sum을 객체 o1의 메소드로 만들고 sum을 호출한 후에 sum을 삭제한다. 

```javascript
o1.sum = sum;
alert(o1.sum());
delete o1.sum();
```

여기서는 sum의 o1 소속의 메소드가 된다는 것을 다르게 표현한 것이다. 함수 sum에서 this의 값이 전역객체가 아니라 o1이 된다는 의미이다.

이거는 공부 좀 더 필요할 듯

## 객체지향

객체는 변수와 메소드를 구룹핑한 것이다.

### 생성자와 new

객체란 서로 연관된 변수와 함수를 구룹핑한 그릇. 객체 내의 변수를 property, 함수를 method라고 부른다.

```javascript
var person = {}
person.name='ink';
person.introduce = function(){
    return "My name is " + this.name;
}
document.write(person.introduce());
```

```javascript
var person = {
    'name' : 'ink'
    'introduce' : function(){
        return 'My name is ' + this.name;
    }
}
document.write(person.introduce());
```

#### 생성자

생성자(constructor)는 객체를 만드는 역할을 하는 함수. **자바스크립트에서 함수는 재사용이 가능한 로직의 묶음이 아니라 객체를 만드는 창조자임.**

```javascript
function Person() {}    //함수를 선언한 것이 아니라 객체를 선언한 것
var p = new Person();
p.name  = 'inkky';
p.introduce = function (){
    return 'My name is '+this.name;
}
document.write(p.introduce());
```

```javascript
function Person(name){
    this.name = name;
    this.introduce = function(){
        return 'My name is '+this.name; 
    }   
}
var p1 = new Person('egoing');
document.write(p1.introduce()+"<br />");
 
var p2 = new Person('leezche');
document.write(p2.introduce());
```

일반적인 객체지향 언어에서 생성자는 클래스의 소속이지만 자바스크립트에서 객체를 만드는 주체는 함수다. 

### 전역객체

모든 객체는 전역 객체의 프로퍼티이다. </br>
`func();`나 `window.func();`나 똑같다는 의미

전역객체의 이름도 호스트환경에 따라서 다른데, 웹브라우저에서 전역객체는 window이지만 node.js에서는 global이다.

### this
```javascript
function func(){
    if(window===this){
        document.write("window === this");
    }
}
func(); //결과는 window === this
```

### method의 호출

```javascript
var o = {
    func : function(){
        if(o === this){
            document.write("o === this");
        }
    }
}
o.func(); //결과는 o === this
```

### 생성자의 호출

```javascript
var funcThis = null; 
 
function Func(){
    funcThis = this;
}
var o1 = Func();//결과는 window
if(funcThis === window){
    document.write('window <br />');
}
 
var o2 = new Func();//결과는 o2
if(funcThis === o2){
    document.write('o2 <br />');
```

생성자는 빈 객체를 만든다. 그리고 이 객체내에서 this는 만들어진 객체를 가르킨다. 생성자가 실행되기 전까지 객체는 변수에도 할당될 수 없기 때문에 this가 아니면 객체에 대한 어떠한 작업을 할 수 없다.

[참조](https://webclub.tistory.com/309) 어쨌든 간에 new를 통해서 생성자 함수를 호출하면 함수 안에서
* 빈 객체가 생성된다. 이 객체는 this라는 변수로 참조할 수 있고, 해당 함수의 프로토타입을 상속받는다.
* this로 참조되는 객체에 프로퍼티와 메소드가 추가된다.
* 마지막에 다른 객체가 명시적으로 반환되지 않을 경우, this로 참조된 이 객체가 반환된다.

### prototype

[참고](https://medium.com/@bluesh55/javascript-prototype-%EC%9D%B4%ED%95%B4%ED%95%98%EA%B8%B0-f8e67c286b67)
[참고](http://insanehong.kr/post/javascript-prototype/)

자바스크립트에는 클래스가 없으니 상속기능도 없어서 프로토타입을 기반으로 상속을 흉내낸다. 하지만 최근에 class문법이 추가 되었는데 자바스크크립트가 클래스 기반으로 바뀌었다는 것은 아니다.

```javascript
function Person() {
    this.eyes = 2;
    this.nose = 1;
}

var kim = new Person();
var park = new Person();

console.log(kim.eyes);
console.log(park.nose);
```

이렇게 되면 kim과 park 각각 eyes와 nose가 할당되어 메모리에는 총 4개가 할당된다. 객체 1000개를 만들면 2000개의 변수가 메모리에 할당되는데 이게 메모리를 많이 차지하니

```javascript
function Person(){}

Person.prototype.eyes = 2;
Person.prototype.nose = 1;

var kim = new Person();
var park = new Person();

console.log(kim.eyes);
```

`Person.prototype`이라는 빈 Object가 어딘가 에 존재하게 되고 Person 함수로부터 생성된 객체(kim, park)들은 어딘가에 존재하는 Object에 들어가 있는 값을 모두 가져다 쓸 수 있다.</br>
**즉, eyes와 nose를 어딘가에 있는 빈 공간에 넣어놓고 kim과 park이 공유해서 가져다 쓰는 것.**

#### prototype object

객체는 언제나 함수로 생성된다!!!! `var kim = new Person();`이 이와 같음.</br>
`var obj = {};`는 사실 `var obj = new Object();`와 같다</br>
놀랍게도 Object는 자바스크립트에서 기본적으로 제공하는 함수이다.</br>

`function Person() {}`을 선언하게 되면(정의하게 되면) 함수만 생성되는 것이 아니라 prototype object도 같이 생성된다. 이렇게 생성된 함수는 prototype이라는 속성을 통해 prototype object에 접근할 수 있는데 이는 일반적인 객체와 같으며 기본적인 속성으로 constructor과 \_\_proto\_\_를 가지고 있다.

* constructor : prototype object와 같이 생성되었던 함수를 가리키고 있다
* \_\_proto\_\_ : prototype link

그니까 쓸수 있는 공용레고를 미리 만들어놓고 new를 통해 접근 허가증을 kim과 park에게 나눠준 것 그래서 쓰고 싶을 때 새로 만드는게 아니라 공용 레고를 가져다가 보여주는 것! 그렇게 되면 메모리를 덜 쓰겠지 kim과 park에게 각자의 레고를 만들어주는게 아니니까

그리고 이렇게 가져다 쓰는 허용증은 자기가 무엇으로 정의내렸냐에 따라 가질 수 있는데 toString함수의 경우 Person의 eyes와 nose도 쓸 수 있지만 string 요소를 가질 수 있다는 것.

### 참조

```javascript
var a = {'id' : 1};
var b = a;
b.id = 2;
console.log(a.id);  //결과는 2
```
이것은 변수 b와 변수 a에 담긴 객체가 서로 같다는 것을 의미한다.

여기서 주의점
`a = 1;` : 이건 데이터형이 숫자. 숫자는 원시 데이터형(기본 데이터형)이고 </br>
`a = {'id': 1};` : 이건 데이터형이 객체이다.</br>
원시 데이터형을 제외한 모든 데이터 타입은 객체이다. 객체를 다른 말로는 참조 데이터 형이라고 부르는데 **기본 데이터형은 위와 같이 복제**되지만 **참조 데이터형은 참조** 된다.</br>

**모든 객체는 참조 데이터형이다.**

1. 원시 데이터 타입을 인자로 넘겼을 때

```javascript
var a = 1;
function func(b){
    b = 2;          // 복제가 이뤄졌으므로 변경되지 않겠구나 새로운 애만 생겼겠구나
}
func(a);
console.log(a);     // 1
```

2. 참조 데이터 타입을 인자로 넘겼을 때

```javascript
var a = {'id':1};
function func(b){
    b = {'id':2};   // 아 a의 데이터가 func 함수 안에서 복사가 되어 새로 들어갔구나 약간 전역 변수가 아니라 지역 변수처럼 작용하는 구나
}
func(a);
console.log(a.id);  // 1
```

3. 파라미터 b가 객체 a의 레퍼런스 일 때

```javascript
var a = {'id':1};
function func(b){
    b.id = 2;       // 전역 변수를 수정한 느낌인 것
}
func(a);
console.log(a.id);  // 2
```
