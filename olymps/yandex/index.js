let lineReader = require('readline').createInterface({
  input: require('fs').createReadStream('input.txt')
});

let n = null;
lineReader.on('line', function (line) {
  let data = line.split(' ');
  if(data.length === 1) {
    n = parseInt(data);
  } else {
    let current = [];
    for (let i = 0; i < n; i++) {
      if (i < 5) {
        console.log(data.slice(0, i+1).map(Number).sort((a, b) => {return a-b}).reverse().join(' '));
        console.log(data.slice(0, i+1))
      } else {
        console.log(data.slice(0, i+1).map(Number).sort((a, b) => {return a-b}).slice(0, 5).reverse().join(' '));
        console.log(data.slice(0, i+1))
      }
    };
  };
});
