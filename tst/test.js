var addon = require('bindings')('addon');//调用C++扩展
var engine = new addon.Engine();
console.log( `num1 + num2  = ${engine.add(1,2)}`);//输出3