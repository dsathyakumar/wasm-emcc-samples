## Lesson-2: Call WebAssembly functions (authored in C), in the JS world via the JS Web Assembly API

### Step 1: Inspect the `wasm` object.
Allocate to the window object

```js
window.wasm = wasm;
```
Expanding this object on the window, you will notice there are 2 props
- `module`: the actual wasm module itself.
- `instance`: the current instance of the wasm module. This is what we are interested in durng app runtime. This has the `exports` prop => all exported obj of this module for this instance. in our case we are exporting the `main` method. So it can be accessed as"

```js
window.wasm.instance.exports.main();
// should return 42.
```
