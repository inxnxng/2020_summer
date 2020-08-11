var http = require('http');
var fs = require('fs');
var url = require('url');
var qs = require('querystring');
var path = require('path');
var template = require('./template');
 
var app = http.createServer(function(request,response){
    var _url = request.url;
    var queryData = url.parse(_url, true).query;
    var pathname = url.parse(_url, true).pathname;
    if(pathname === '/'){
      var html =`
      <!doctype html>
        <html>
          <head>
            <meta charset ="utf-8">
            <title>loginpage </title>
          </head>
          <body>
            <h1>Login Page</h1>
            <h2>로그인하세요</h2>
              <form action = "/login_process" method ="post">
                <p>ID<br><input type = "text" name = "id" ></p>
                <p>PASSWORD<br><input type ="password" name ="password"></p>
                <p>
                  <input type ="submit" value ="Login">
                </p>
              </form>
          </body>
        </html>
        `
        ;
      response.writeHead(200);
      response.end(html);
    }else if(pathname === "/login_process") {
      var body ='';
      request.on('data',function(data){
        body = body + data;
      });
      console.log(body);
      request.on('end',function(){
        var login = qs.parse(body);
        var id = login.id;
        var password = login.password;
        console.log(id,password);
        fs.readdir(`./account`,function(error,filelist){
          console.log(filelist.length)
          var key = -1;
          for(var i =0; i <filelist.length; i++){ if(filelist[i]===id){ key = i ;}}
          console.log(filelist[key]);
          if(key >-1){
              console.log("find id");
              fs.readFile(`account/${id}`,'utf8',function(err,realpassword){
                console.log(realpassword,password);
                if(realpassword == password){
                  var html = 
                  `<!DOCTYPE html>
            <html>
            <head>
            <meta charset="utf-8" />
            <title>login</title>
            </head>
            <body>
              <form id = "logindata" action = "/myhome" method ="post">
              <input type = "hidden" name ="userid" value = ${id} />
              </form>
            </body>
            </html>
            `
                  response.writeHead(302,{Location : `/myhome`});
                  response.end();
                  console.log('login success');
                }else{
                  var html = 
                  `<!DOCTYPE html>
            <html>
            <head>
            <meta charset="utf-8" />
            <title>login</title>
            </head>
            <body>
            <script>
                    alert('비밀번호 오류입니다');
                    <body onload="name.reset();id.reset();">
            </script>
            </body>
            </html>
            `;
                  console.log('login failed');
                  response.writeHead(302,{Location:`/`});
                  response.end(html);
                }
              });
            }else{
              var html = 
              `<!DOCTYPE html>
            <html>
            <head>
            <meta charset="utf-8" />
            <title>login</title>
            </head>
            <body>
            <script>
                    alert('아이디 오류입니다');
                    <body onload="name.reset();id.reset();">
            </script>
            </body>
            </html>
            `;
            console.log('login failed');
            response.writeHead(302,{Location:`/`});
            response.end(html);
          }        
        });
      });
    }else if(pathname === `/myhome`){
      var body='';
      request.on('data',function(data){
        body = body + data;
      });
      console.log(body);
      request.on('end',function(){
        var post = qs.parse(body);
        var id = post.userid;
      var html = 
      `<!DOCTYPE html>
      <html>
      <head>
      <meta charset="utf-8" />
      <title>myhome</title>
      </head>
      <body> you finally reach here user ${id}</body>
      </html>
      `
      response.writeHead(200);
      response.end(html);
      /*

        fs.readdir(`./data`, function(error, filelist){
          fs.readFile(`data/${id}`, 'utf8', function(err, description){

            var html =  `<!DOCTYPE html>
            <html>
            <head>
            <meta charset="utf-8" />
            <title>${id}</title>
            </head>
            <body>
              ${description}
            </body>
            </html>
            `
            response.writeHead(200);
            response.end(html);
          });
        });
      })*/
    });
  }
    else {
      response.writeHead(404);
      response.end('Not found');
    }
});

app.listen(3000);