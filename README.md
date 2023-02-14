### A simple example using GUI to integrate with C++ code
1. Electron opens a web browser window
2. Window loads index.html
3. index.html has index.js as javascript actions
4. index.js get num1 and num2 from index.html. Then call c++ add function in src/engine.cpp.
5. Values are displayed in index.html

### Set up gpy build environment
gyp add on is for linking c++ with node and electron

```
npm install -g node-gyp

node-gyp configure

node-gyp build or node-gyp rebuild
```
### Run test
```
npm install
```
```
npm run test
```
you will see num1 + num2  = 3

### Start application
```
npm install
npm start
```