## Lesson-1: Load a basic wasm file via JS ApI
Steps

### Create a sample WASM file
- A basic C file.
- Copy paste the file contents into WASM Fiddle website
- Click build
- It should output the WASText format and an option to download the wasm file.
- Copy & put the `program.wasm` file into the public folder

### Import it into the JS world via the WebAssembly JS API
- Use the `WebAssembly` module's `instantiateStreaming` method.
- Include the file name of `program.wasm` that resides in the public folder.
- The `instantiateStreaming` method takes a `fetch` function that returns a promise.
- In the `.then` expect a `wasm` object & log it into the console.
