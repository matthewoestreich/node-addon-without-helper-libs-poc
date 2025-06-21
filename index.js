const path = require("path");
const packagePath = path.resolve(__dirname);
module.exports = require("node-gyp-build")(packagePath);
