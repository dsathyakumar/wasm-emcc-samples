# wasm-emcc-samples

> This is a sample course to learn the basics of web assembly & employs the emscripten toolset for advanced examples & the sample project. This uses wasm compiled from C. This does not use Rust.

## Introduction

### What is web assembly?
WebAssembly is one of the most promising technologies to hit the web in recent years, that allows us to: 
- _write code for the browser, using compiled languages like C, C++, Rust etc.,_

### Definition of web assembly per MDN
- A new type of code that can be run on the browser.
- Its a low level assembly-like language, with a compact binary format, that can run with near native performance like compiled languages, such as C, C++ etc., 
- It offers such compiled languages, a compilation target for the web, so that, they can be run along side JS, on the web platforms.
- It offers new features and unlocks new performance gains.
- Its not intended to be written by hand. But Rather, a compilation target for other compiled languages like C, C++, Rust
- The implications for the web are huge, because, it provides a way to run code written in multiple other compiled languages, on the web, at near native speeds
- Web assembly modules can be imported into web, exposing web assembly functions for use, via JS. JS frameworks can make use of web assembly to confer massive perf advantages.

### Goals of web assembly
- Be fast, efficient, and portable
- Be readable and debuggable
- Keep secure

### What does it achieve by doing so?
By doing so, it results in
- _incredibly fast JS modules, in raw binary format._

### How does web assembly fit into the web platform
The web platform can be thought of as having 2 parts:
- A VM, that runs the web app code. eg) the JS code that powers your app. This may include the JS interpreter & the JS runtime env.
- A set of web api's that the web app can call & make use of to control the web browser / device functionality & make things happen. These include API's liek WebGL, DOM, CSSOM etc., 

Before the advent of web assembly, the VM can only load and execute JS. This worked well & was enough, as JS is powerful enough to solve most problems people have on the web today. But, we are running into perf problems and bottlenecks, because, when trying to use JS for performance intensive tasks, like VR / AR, 3D games etc., (and a number of usecases that demand near native performance), JS can be found wanting.

Also, there is the cost of downloading parsing & compiling large JS apps. 

Web assembly comes in to fill in these gaps. With the advent of WebAssembly appearing in browsers, the virtual machine will now be able to load and run two types of code — JavaScript AND WebAssembly

_These 2 different types of codes can call & talk with each other. The web assembly JS API, wraps page exported web assembly code with JS functions that can be called from the JS world. In the same way, web assembly code can import & **synchronously** call JS functions_

## Purpose of this course
- Understand what is web assembly?
- Create & Use web assembly modules from scratch using both the native JS Api for webassembly and using the emscripten toolset.

## Part A: Pre-requisites
This lesson is divided into multiple parts as outlined below. But some of the basics needed are
- install NodeJS
- ensure you can access WASM fiddle
- install Emscripten (requires prior install of Git, Node & python)
- install CMake

## Part B: Loading web assembly modules via the JS api manually with help from wasm fiddle
1. Lesson-1: Load a basic wasm file via JS ApI
2. Lesson-2: Call WebAssembly functions (authored in C), in the JS world via the JS Web Assembly API.

## Part C: Installing emscripten

## Part D: Loading web assembly Modules that is compiled via emscripten

## Part E: Final Project

## Part F: References
