app = require('express')();

app.get(
	'/',
	function(req,res){
		res.send('express');
	}
);

app.listen(8080);
