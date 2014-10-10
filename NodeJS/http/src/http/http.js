var http = require('http');

var server = http.createServer();

server.on(
	'request',
	function(req, res){
		res.writeHead(
			200,
			{'Contet-Type': 'text/plain'}
		);
		res.end('http\n');
	}
).listen(8080);
