var http = require('http');
var fs = require('fs');

var server = http.createServer();

server.on(
        'request',
        function(req, res){
		fs.readFile(
			'./fs.html',
			'UTF-8',
			function(err, data){
                		res.writeHead(
					200,
					{'Contet-Type': 'text/html'}
				);
				res.write(data);
				res.end();
			}
		);
        }
).listen(8080);
