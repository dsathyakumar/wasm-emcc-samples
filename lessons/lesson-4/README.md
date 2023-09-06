## Lesson-3: Reading the actual string from the memory location

### Step 1
- Note that we earlier mentioned a `memory` prop that is also exported and available
as part of the wasm `instance`. This is tied to the runtime instance of the `module` and can be accessed as `wasm.instance.exports.memory`.
- The `memory` prop contains all runtime allocations of variables that are part of a `module`, when the `instance` of the `module` is created. This is of type `ArrayBuffer`. Its used to store Binary data. They are of fixed size - 65536 bytes ~ 64X1000 decimal byte or 64KB - called a **page of memory** in Web Assembly
- The char pointer points to a memory location - that contains the char / string we want. It basically is the location / memory address. This can be considered as our starting point. If we knew the length of the string, then we could basically offset the start location (given by the char pointer) & the string length, to find the end char pointer & thus get full details on the location of the string / char in memory. We are doing this exercise, because we do not know where the data ends & would like to compute that.

