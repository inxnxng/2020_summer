const fs = require('fs');
fs.readFile('sample.txt','utf-8',function(err,data){
    if(err) throw err;
    console.log(data);
});