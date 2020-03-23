let lineReader = require('readline').createInterface({
  input: require('fs').createReadStream('input.txt')
});

lineReader.on('line', function (line) {
  let n = parseInt(line);
  let count = 0;
  for (let i = 1; i <= n; i *= 2) {
    count++;
  };
  console.log(count);
});
