# Source Documentation

The docs is compiled directly using the source code.

## Tooling

We use [`NPM`](https://www.npmjs.com/) to compile the source to Markdown documentation.  Neither `NPM` or `Javascript` are used in the library - it's solely used for docs generation.

To initialize NPM on the root folder *(and create `node_modules`)* use:
```bash
npm install
```

### Requirements

* [`Doxygen`](https://www.doxygen.nl/) is used to compile CPP to XML files.
  - To install *(on macOS)* use:
     ```bash
     brew install doxygen
     ```

* [`sourcey/moxygen`](https://www.npmjs.com/package/moxygen) *(NPM tool)* is used to compile XML to MD files.
* [`isaacs/rimraf`](https://www.npmjs.com/package/rimraf) *(NPM tool)* is used to clean up the interim XML

### Generate docs

To compile use [`NPM Scripts`](https://docs.npmjs.com/cli/v7/using-npm/scripts) command line:

```bash
npm run docs
```

----------
<p align="center" style="color:#069">&#9733;</p>
