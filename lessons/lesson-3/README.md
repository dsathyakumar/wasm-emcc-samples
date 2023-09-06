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

### Step 4: So far we have been accessing numbers. Floats are similar. But What about Strings?
- Lets update the code to use `numLog` to log numbers and `strLog` to log characters.
- Notice that the earlier methods are all `void` return type now, as we are logging the output and not returning anthing.
- In the func header, notice the 
```js
void strLog(char * x);
```
The `char *` is indicative of a character pointer. What a pointer is that, its not going to hold the actual string , but, rather a pointer to a location (it points to & so has the value of that) in memory, where the string is stored. So its basically telling us, **_where to go read the value, rather than the actual value itself._**
- we update the code a lil but, fixing the return type for the `main` method which returns an integer => 42 now and has a return type `int` as main method in C must return an int.
- We are able to log everything. But notice, the output is not the string we were tring to log, but some arbitrary integer. Why? This is because, what is logged is the memory location where the strin / char is stored.