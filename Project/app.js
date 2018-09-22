var express = require('express');
var path = require('path');
var favicon = require('serve-favicon');
var logger = require('morgan');
var cookieParser = require('cookie-parser');
var bodyParser = require('body-parser');
var fs = require("fs");
var url = require("url");
var mysql = require('mysql');
var bkfd2Password = require("pbkdf2-password");
var assert = require("assert");
var util = require('util');
var tts = require('simple-tts');
var querystring = require('query-string');
var shell = require('shelljs');

var index = require('./routes/index');
var users = require('./routes/users');
var mode = require('./routes/mode_select');
var lang = require('./routes/lang_select');
var search = require('./routes/searchMode');
var test = require('./routes/practiceMode_test');
var voca = require('./routes/VocabularyMode');
var translate = require('./routes/translateMode');
var practice = require('./routes/practiceMode_practice');
var join = require('./routes/join');

var connection = mysql.createConnection({
  host     : 'localhost',
  user     : 'root',
  password : '11lization',
  database : 'userinfo'
});
var hasher = bkfd2Password({saltLength: 5, iterations: 5, keyLength: 64});

connection.connect();
var app = express();

app.use(bodyParser.urlencoded({
  extended: true
}));
app.use(bodyParser.json());

// view engine setup
app.set('views', path.join(__dirname, 'views'));
app.set('view engine', 'ejs');

// uncomment after placing your favicon in /public
//app.use(favicon(path.join(__dirname, 'public', 'favicon.ico')));
app.use(logger('dev'));
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

var index = require('./routes/index');
var mode = require('./routes/mode_select');
var lang = require('./routes/lang_select');
var search = require('./routes/searchMode');
var test = require('./routes/practiceMode_test');
var voca = require('./routes/VocabularyMode');
var translate = require('./routes/translateMode');
var practice = require('./routes/practiceMode_practice');
var join = require('./routes/join');

var from = "ko";
var to = "en";

app.use('/', index);
app.use('/mode', mode);
app.use('/lang', lang);
app.use('/search', search);
app.use('/practice', practice);
app.use('/test', test);
app.use('/voca', voca);
app.use('/translate', translate);
app.use('/join', join);

app.get('/set_lang', function(req, res) {
  var parsed = querystring.parse(req.url.split("?")[1], null, null);
  from = parsed.from;
  to = parsed.to;
  res.redirect("/mode/?from=" + from + "&to=" + to);
});

app.get('/sound', function(req, res) {
  var parsed = querystring.parse(req.url.split("?")[1], null, null);
  //res.writeHead(200, {'Content-Type': 'audio/ogg'});
  tts(parsed.content, {lang: parsed.lang, format: 'mp3', stream: res});
  //res.send("content: " + parsed.content);
});

app.post('/upload', function(req, res) {
  var filePath = __dirname + req.body.upPath;
  fs.writeFile(filePath, req.body.upData, function(error) {
    //if (error) throw error
    res.redirect("/mode/?from=" + from + "&to=" + to);
  });
});

app.post('/read', function(req, res) {
  var filePath = __dirname + req.body.readPath;
  fs.readFile(filePath, function (err, data) {
    //if(err) throw err;
    res.redirect(307, '');
  });
});

app.post('/validate', function(req, res) {
  var usnm = req.body.uid;
  var pswd = req.body.upw;
  var cur_hash;
  var slt;
  var mySql = util.format('select `username`, `password`, `salt` from members where `username` = "%s"', usnm);
  connection.query(mySql, function(err, rows, fields) {
    if (err || !rows.length) res.redirect('back');
    else {
      cur_hash = rows[0].password;
      slt = rows[0].salt;
      return hasher({password:pswd, salt:slt}, function(err, pass, salt, hash) {
        if(hash === cur_hash){
          res.redirect('/lang');
        } else {
          res.redirect('back');
        }
      });
    }
  });
});

app.post('/register', function(req, res) {
  var usnm = req.body.uid;
  var pswd = req.body.upw;
  var cpswd = req.body.c_upw;
  var slt;
  if(pswd == cpswd) {
    hasher({password: pswd}, function (err, pass, salt, hash) {
      var mySql = util.format('insert into members (`username`, `password`, `salt`) values ("%s", "%s", "%s")', usnm, hash, salt);
      connection.query(mySql, function(err) {
        if (err) throw err;
      });
      shell.cp('~/OOP11lization/public/file/defaultSet.txt', '~/OOP11lization/public/file/uid=' + usnm +'koen.txt');
    });
  res.redirect('../');
  }
  else res.redirect('back');
});

// catch 404 and forward to error handler
app.use(function(req, res, next) {
  var err = new Error('Not Found');
  err.status = 404;
  next(err);
});

// error handler
app.use(function(err, req, res, next) {
  // set locals, only providing error in development
  res.locals.message = err.message;
  res.locals.error = req.app.get('env') === 'development' ? err : {};

  // render the error page
  res.status(err.status || 500);
  res.render('error');
});

module.exports = app;
