let lineReader = require('readline').createInterface({
  input: require('fs').createReadStream('input.txt')
});

lineReader.on('line', (line) => {
  if (line !== '') {
    let haveAns = false;
    let row_input = line.split(' ');

    const s = parseInt(row_input[0]),
          l1 = parseInt(row_input[1]),
          r1 = parseInt(row_input[2]),
          l2 = parseInt(row_input[3]),
          r2 = parseInt(row_input[4]);

    for (let i = l1; i <= r1; i++) {
      let tmp = binarySearch(l2, r2, s - i);
      if (tmp !== -1) {
        console.log(i, tmp);
        haveAns = true;
        break;
      }
    }

    if (!haveAns) console.log(-1);
  }
});

const binarySearch = (start, finish, value) => {
  let guess;
  let min = start;
  let max = finish;

  while (min <= max)
  {
    guess = Math.floor((min + max) / 2);
    if (guess === value) return guess;
    else if (guess < value) min = guess + 1;
    else max = guess - 1;
  }
  return -1;
};
