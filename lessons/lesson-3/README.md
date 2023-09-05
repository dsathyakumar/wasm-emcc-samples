## Lesson-3: Call JS funcs from C

### Step 1: Introduction of what we are trying to achieve
- Let's assume that we change the functions that we have written so far, to log the output as well, rather than us logging it.
- We know that this function was authored in the C world & exported as a web assembly module. If we have to gain access to be able to log to the browser console, we would need access to the browser's `console.log` function
- Let's see how can the browser's `console.log` function be imported into the C world and be used there.
- This is where the `imports` prop comes into play. `exports` helps us to access functionality exported by wasm, in JS. While, `imports` helps us to access function available in the JS world, to the wasm world. They bring functionality into out module.

### Step 2: The how
- To pass something as the `imports` to the web assembly module, so that it is available in the module, we pass an `imports` object, as the 2nd arg, into `instantiateStreaming` method.
- This arg has all the imports listed into an `env` prop. This is the default env module imported by web assembly.
- Here we include the browser's `console.log` function. We want this to be available in the web assembly module, so that it can be imported and be used by the module.
- Now, we have to inform the web assembly module, in the C world, of the existence of this functionality (from the browser).
- This can be done via a **function header** - we can tell c about a function by declaring what is called a function header. _This is a description of the function, without the body._
- Now we use the function `consoleLog` as if it were available in the C world.
- Re-compile, generate the wasm file and use it now.
- Values are logged to the browser console & they internally use the `console.log`

### Step 3: Viewing the imports
- Like how we viewed the `exports` via the `WebAssembly.module.exports(wasm.module)`, we can also view the `imports` via the `WebAssembly.module.imports(wasm.module)`.