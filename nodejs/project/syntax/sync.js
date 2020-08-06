var fs = require('fs');


// ABC
console.log('A');
var result = fs.readFileSync('sample.txt', 'utf-8');
console.log(result);
console.log('c');


console.log('--------');

// ACB
console.log('A');
fs.readFile('sample.txt','utf-8',function(err,result){
    console.log(result);
})
console.log('C')