var input1 = document.querySelector("#num1");
var input2 = document.querySelector("#num2");
var result = document.querySelector("#result");
var button = document.querySelector('#calculate');

var addon = require('bindings')('addon');//调用C++扩展
var engine = new addon.Engine();

window.onload = ()=>{
    console.log("hello");
    var input1 = document.querySelector("#num1");
    input1.value = "1";
    button.onclick = ()=>{
        var num1 = Number(input1.value);
        var num2 = Number(input2.value);
        var res = engine.add(num1,num2);
        result.value = res;
    }
}