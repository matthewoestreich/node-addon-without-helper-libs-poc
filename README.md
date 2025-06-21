# node-addon-without-helper-libs-poc
Create a Node.js addon in C++ without helper libraries - just native Node.js C++ libraries

This is just a test project to learn Node.js addons.

# Install

```bash
npm i node-addon-without-helper-libs-poc
```

# Usage

```js
// cjs
const { Greeter } = require("node-addon-without-helper-libs-poc");
const greeter = new Greeter("Foo");
const greeting = greeter.greet();
console.log(greeting);

// esm
import { Greeter } from "node-addon-without-helper-libs-poc";
const greeter = new Greeter("Bar");
const greeting = greeter.greet();
console.log(greeting);
```

# Create Release

Which builds the project and publishes it to NPM.

```bash
# Bumps version and creates Git tag
# Commits the change
npm version (patch|major|minor)
# Pushes commit + new tag
git push origin main --tags
```