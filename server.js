const express = require('express');
const app = express();

// app.use(express.static('public'), {
//     setHeaders: (res, path, stat) => {
//         if (path.endsWith('.wasm')) {
//             res.set('Content-Type', 'application/wasm');
//         }
//     }
// });
app.use(express.static('public'));

app.listen(3333, () => console.log('server running on port 3333'));