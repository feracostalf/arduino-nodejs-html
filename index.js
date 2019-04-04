
const serialPort = require("serialport");
var app = require("express")();
var server = require("http").Server(app);
var  io = require("socket.io")(server);
const Readline=require("@serialport/parser-readline");


const serial = new serialPort('/dev/ttyACM0', {
  baudRate: 9600});

const parser = serial.pipe(new Readline({ delimiter: '\n' }))

serial.on('open',function(err){
	
	if(err != null){
		console.log("error");
	}else{
		
		console.log("Conexcion lista");
	}
});



app.get('/',function(req,res){
	
	res.sendfile("index.html");
	
});



io.on('connection', function (socket) {
  
	parser.on('data', function (data) {
  console.log(data.toString()),
  socket.emit('news', { serial: data.toString()})
})

  
});

server.listen(80);
