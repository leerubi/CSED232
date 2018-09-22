var express = require('express');
const translate = require('google-translate-api');
var querystring = require('query-string');
var router = express.Router();

router.get('/', function(req, res, next) {
  var parsed = querystring.parse(req.url.split("?")[1], null, null);
  var transQuery = "";
  var result;
  var temp = parsed.content;
  if(temp == "" || temp == null) res.render('translateMode', {title: ""});
  else {
    var plusVal = temp.split("+");
    for (var j=0; j<plusVal.length; j++) {
      if(j == 0) transQuery = plusVal[j];
      else transQuery = transQuery + " " + plusVal[j];
    }
    console.log(transQuery);
    translate(transQuery, {from: parsed.from, to: parsed.to}).then(res2 => {
    result = res2.text;
    res.render('translateMode', { title: result});
    }).catch(err => {
      console.error(err);
    });
  }
});

module.exports = router;
