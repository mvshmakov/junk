let lineReader = require('readline').createInterface({
  input: require('fs').createReadStream('input.txt')
});

let n = null;
let lineNum = 0;
lineReader.on('line', function (line) {
  let data = line.split(' ');
  if(lineNum === 0) {
    n = parseInt(data);
    lineNum++;
  } else {
    let unique = [...new Set(data.slice(0, n))];
    console.log(unique.length)
  }
});
