//array, object
//function

//자바스크립트에서 함수는 값이다
var q = {
    v1:'v1',
    v2:'v2',
    f1:function (){
      console.log(this.v1);
    },
    f2:function(){
      console.log(this.v2);
    }
  }
   
q.f1();
q.f2();