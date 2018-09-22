var dictionary = {};   // 사전 데이터 객체
var index;            // 현재 출력되는 단어의 인덱스 
var init_startTime;      // 첫 문자 입력 시간
var startTime;         // 입력 시작 시간
var endTime;         // 입력 완료 시간
var randomWord;         // 현재 출력되는 단어 
var randomWord_meaning;   // 현재 출력되는 단어의 뜻 
var soundplay;         // 현재 출력되는 단어의 발음 
var n = 0;
var index_new = new Array();
var soundbutton = new Array();

// 텍스트 파일을 한 줄씩 처리하여 단어와 뜻을 담은 객체를 생성하는 함수
//var r = document.getElementById("read");
//r.addEventListener("change", function(event){
//   var file = event.target.files[0];
//    var reader = new FileReader();
//    reader.readAsText(file);
    // 텍스트 파일을 한 줄씩 처리하여 단어와 뜻을 담은 객체를 생성한다.
//    reader.onload = function(event) {
//       var text = reader.result;      // 데이터를 text에 담는다.
var text = document.getElementById("read").value;
console.log("text");
var lines = text.split("\t");    // 데이터를 각 행 별로 분리한다.

for (var i = 0; i < lines.length; i++) {
   var fields = lines[i].split(" : ");   // " : "로 구분
   var b_word = {
      en_word: fields[0],            // 영어 단어 저장
      ko_meaning: fields[1]         // 한국어 뜻 저장
   }
   dictionary[i] = b_word;
}
showRandomWord();
//   };
//}, false);
var soundbutton = document.getElementById("sound");
soundbutton.addEventListener("click", function (event) {
    //var soundReplay = document.getElementById("playbuttonID");
    soundPlay(dictionary[index].en_word);
    soundplay.load();
}, false);


function showList(index) {
    var list_ = document.getElementById("list");
    soundbutton[n] = document.createElement("IMG");
    soundbutton[n].setAttribute("src", "/images/sound.png");
    soundbutton[n].setAttribute("width", "1");
    soundbutton[n].setAttribute("height", "30");
    soundbutton[n].setAttribute("alt", "soundbutton");
    soundbutton[n].addEventListener("click", function (event) {
        //var soundReplay = document.getElementById("playbuttonID");
        soundPlay(dictionary[index].en_word);
        soundplay.load();
    }, false);
    /*var sound = document.createElement("BUTTON");
    //sound.setAttribute("value","play");
    sound.addEventListener("click",function(event)
    {
       var soundReplay = document.getElementById("playbuttonID");
       soundPlay(dictionary[index].en_word);
       soundplay.load();
       //soundReplay.setAttribute
       //sound.setAttribute("src","https://translate.google.com/translate_tts?ie=UTF-8&tl=en&client=tw-ob&q="+dictionary[index].en_word);
        //sound.setAttribute("autoplay","autoplay");
 
    }, false);*/

    //sound.addEventListener("click",click_playbutton);
    var word = document.createTextNode(dictionary[index].en_word);
    //meaning = document.createTextNode(" : "+randomWord_meaning);
    var meaning1 = dictionary[index].ko_meaning;
    var meaning = document.createTextNode(" : " + dictionary[index].ko_meaning);


    index_new[n] = dictionary[index].en_word + ': ' + meaning1;

  /*  var node = document.createElement("LI");
    var textnode = document.createTextNode(index_new[i]);
    node.appendChild(textnode);
    document.getElementById("list").appendChild(node);
    */
    //$('#list').empty();
    document.getElementById("list").innerHTML = "";
    var node1 = new Array();
    var textnode1 = new Array();
    for (var k = n; k >= 0; k--) {
        if (k == n - 8)
            break;
        //    $('#output').text(line.join(""));
        node1[k] = document.createElement("LI");
        textnode1[k] = document.createTextNode(index_new[k]);
        var enter = document.createElement("BR");
        node1[k].appendChild(soundbutton[k]);
        node1[k].appendChild(textnode1[k]);
        node1[k].appendChild(enter);
        document.getElementById("list").appendChild(node1[k]);
    }
    n++;




    //var right = document.getElementById("right");
    //document.body.appendChild(list);

    //list.appendChild(sound);


    //list_.innerHTML = sound+word + meaning;


}
var i = document.getElementById("input");
// 입력창에 포커싱되었을 때 발생하는 이벤트를 처리한다.
i.addEventListener("focus", function (event) {
    startTime = performance.now();
    init_startTime = startTime;
}, false);
// 입력창에 문자가 입력되었을 때마다 발생하는 이벤트를 처리한다.
i.onkeyup = function (event) {
    if (event.keyCode == 13) {   // 엔터키 누른 경우
        // WPM을 측정하고 출력한다.
        endTime = performance.now();
        document.getElementById("WPM").innerHTML = "WPM: " + speed(init_startTime, endTime) + " 타";
        init_startTime = performance.now();
        // charCheck();    // 문자 일치 여부를 확인하고 색을 변경한다.
        check();       // 정답 여부를 확인하고 결과를 출력한다.   
    }
    else {
        // CPM을 측정하고 출력한다.
        endTime = performance.now();
        charCheck(event.keyCode);    // 문자 일치 여부를 확인하고 색을 변경한다.
        document.getElementById("CPM").innerHTML = "CPM: " + speed(startTime, endTime) + " 타";
        startTime = endTime;
    }
}


// 랜덤으로 단어를 선택하여 문자마다 컬러링을 위한 태그를 달아주고 화면에 보여주는 함수
function showRandomWord() {
    var output = document.getElementById("output");
    output.innerHTML = "";   // 초기화
    var text = "";         // 초기화
    var size = Object.keys(dictionary).length;      // 단어의 개수를 size에 저장
    index = Math.floor(Math.random() * size);         // 랜덤으로 인덱스 값 생성
    var word = dictionary[index].en_word;
    // 출력할 단어의 문자마다 태그를 추가한다.
    var baseColor = "black";
    text = '<font color="' + baseColor + '">';
    for (var i = 0; i < word.length; i++) {
        text += '<span id="oneChar' + i + '">' + word.charAt(i) + '</span>';
    }
    text += ('</font>');
    output.innerHTML = text;
}

// 타수를 계산하는 함수
function speed(sTime, eTime) {;
    var term = (eTime - sTime) / 1000 / 60;   // 시작시간과 끝시간의 차이를 분 단위로 환산
    var speed = Math.round(1 / term);      // 타수로 변환 (소수점은 반올림)
    return speed;
}

// 입력 문자의 일치 여부를 확인하고 문자의 색을 변경하는 함수
function charCheck(keycode) {
    randomWord = dictionary[index].en_word;
    var input = document.getElementById("input");
    var userInput = input.value;
    var baseColor = "black";
    var correctColor = "#1e90ff";
    var incorrectColor = "red";

    if (userInput.length <= randomWord.length) {
        for (var i = 0; i < userInput.length; i++) {
            var onechar = document.getElementById("oneChar" + i);
            if (keycode == 8) {
                onechar.style.color = baseColor;
            }
            if (randomWord.charAt(i) == userInput.charAt(i)) {
                onechar.style.color = correctColor;
            }
            else {
                onechar.style.color = incorrectColor;
            }
        }
        for (var i = userInput.length; i < randomWord.length; i++) {
            var onechar = document.getElementById("oneChar" + i);
            onechar.style.color = baseColor;
        }
    }
    else {
        for (var i = 0; i < randomWord.length; i++) {
            var onechar = document.getElementById("oneChar" + i);
            if (keycode == 8) {
                onechar.style.color = baseColor;
            }
            if (randomWord.charAt(i) == userInput.charAt(i)) {
                onechar.style.color = correctColor;
            }
            else {
                onechar.style.color = incorrectColor;
            }
        }
    }
}

// 입력 단어의 정답 여부를 확인하고 결과를 출력하는 함수
function check() {
    // 입출력 엘리먼트를 찾는다.
    var tag = document.getElementById("here");
    randomWord = dictionary[index].en_word;
    var input = document.getElementById("input");
    var userInput = input.value;
    randomWord_meaning = document.getElementById("result");
    // 결과 출력 필드 초기화
    tag.innerHTML = "";
    randomWord_meaning.innerHTML = "";
    if (randomWord == userInput) {
        randomWord_meaning.appendChild(document.createTextNode("[정답] " + dictionary[index].en_word + ": " + dictionary[index].ko_meaning));
        // 댕댕콘 정답

        var text = '<img id="siba" src="/images/siba_correct.gif">';
        tag.innerHTML = text;

        showList(index);
        soundPlay(randomWord);
        showRandomWord();
    }
    else {
        randomWord_meaning.appendChild(document.createTextNode("[오답] 다시 입력하세요"));
        // 댕댕콘 오답
        var text = '<img id="siba" src="/images/siba_incorrect.gif">';
        tag.innerHTML = text;
    }
    // 입력 필드 초기화
    input.value = "";
}
function soundPlay(randomwordSound) {
    console.log(randomwordSound);
    var lang = window.location.href.split("?")[1].split("&")[1].split("=")[1];
    soundplay = document.createElement("VIDEO");
    soundplay.setAttribute("width", "0");
    soundplay.setAttribute("height", "0");
    soundplay.setAttribute("src", "/sound/?content=" + randomwordSound + "&lang=" + lang);
    //soundplay.setAttribute("src", "https://translate.google.com/translate_tts?ie=UTF-8&tl=en&client=tw-ob&q=" + randomwordSound);
    soundplay.setAttribute("autoplay", "autoplay");
    document.body.appendChild(soundplay);

    //var playbutton = document.getElementById("playbuttonID");
    //playbutton.setAttribute("onclick","https://translate.google.com/translate_tts?ie=UTF-8&tl=en&client=tw-ob&q="+randomwordSound);
}
/*function click_playbutton()
{
   var playbutton = document.getElementById("playbuttonID");
   soundplay.load();
   //playbutton.setAttribute("onclick","https://translate.google.com/translate_tts?ie=UTF-8&tl=en&client=tw-ob&q="+randomwordSound);
}*/
/*function click_sound_img(index)
{
   /*var map = document.createElement("MAP");
   map.setAttribute("id","soundbutton");
   map.setAttribute("name","soundButton");
   document.
   var area = document.createElement("AREA");
   area.setAttribute("shape","rect");
   area.setAttribute("coords","0,0,50,50");
   area.setAttribute("href","https://translate.google.com/translate_tts?ie=UTF-8&tl=en&client=tw-ob&q="+dictionary[index].en_word);
   soundPlay(dictionary[index].en_word);
   soundplay.load();
   document.getElementById("soundbutton").appendChild(area);

}*/
