## Lesson-2: Call WebAssembly functions (authored in C), in the JS world via the JS Web Assembly API

### Step 1: Inspect the `wasm` object.
Allocate to the window object

```js
window.wasm = wasm;
```
Expanding this object on the window, you will notice there are 2 props
- `module`: the actual wasm module itself. It represents a web assembly binary that has been compiled by the browser into executable machine code. A module is **stateless** & therefore can be shared between `window` and `workers` (via `postMessage` api). A module declares `imports` and `exports` just like any other ES Module. Note that the `module` does not have a `table`, `memory` etc.,

- `instance`: the current instance of the wasm module. This is what we are interested in durng app runtime. This has the `exports` prop => all exported obj of this module for this instance. in our case we are exporting the `main` method. So it can be accessed as"

```js
window.wasm.instance.exports.main();
// should return 42.
```
Besides this, an `instance` can therefore be thought of a module with **state**. This includes the `table`, `memory` & the set of imported values. _An instance is like a module that has been loaded into a particular global JS env, with a particular set of imports_.

- `memory`: A resizable **_array buffer_** that has a linear array of bytes that was read and written by Web Assembly's low level memory access instructions. Its usually found with an instance of a module.

- `table`: This is also usually found with an instance of a module. Its a resizable **_typed array_** of references (eg: references to functions), that could otherwise not be stored as raw bytes in Memory (for safety and portability reasons)

### WHat does the JS Web Assembly API offer ?
It provides dev's with the ability to create `modules`, `memory`, `tables` and `instances`. When a webassembly instance is given, JS code can **synchronously** call its exports, which are now exposed as normal JS functions. Arbitrary JS functions can also be called **synchronously** by Web assembly code, by passing in those JS functions as imports to the web assembly instance. 