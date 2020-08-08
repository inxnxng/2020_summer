//배열은 순서가 존재함
var members = ['ink','2241', 'yall'];


var i = 0 ; 
/*
while(i < members.length){
    console.log(members[i]);
    i =i+1;
}
*/

//객체는 순서 상관없다
//고유한 이름을 주는 것
var roles = {
    'programmer' : 'ink',
    'number' : '2241',
    'with' : 'yall'
}

for(var name in roles){
    console.log(name, roles[name]);
}
