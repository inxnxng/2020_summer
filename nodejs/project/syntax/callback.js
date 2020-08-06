function a(){
    console.log('A');
}

//함수는 값이다
var b = function () {
    console.log('b');
}

//callback
function showfunc(callback) {
    callback();
}

showfunc(b);