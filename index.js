const loader = require('node-gyp-build');
const native = loader(__dirname);

console.log('✅ Loaded native addon from:', loader.path());
module.exports = native;
