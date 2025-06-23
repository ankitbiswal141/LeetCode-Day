function toBaseK(num, k) {
  let res = '';
  while (num > 0) {
      res = (num % k) + res;
      num = Math.floor(num / k);
  }
  return res;
}

function isPalindrome(s) {
  return s === s.split('').reverse().join('');
}

function generatePalindromes(length) {
  const res = [];
  const halfLen = Math.floor((length + 1) / 2);
  const start = 10 ** (halfLen - 1);
  const end = 10 ** halfLen;

  for (let i = start; i < end; i++) {
      let s = i.toString();
      let rs = s.slice(0, length % 2 === 0 ? s.length : s.length - 1).split('').reverse().join('');
      res.push(Number(s + rs));
  }

  return res;
}

function kMirror(k, n) {
  let sum = 0;
  let count = 0;
  let length = 1;

  while (count < n) {
      const pals = generatePalindromes(length);
      for (const num of pals) {
          if (isPalindrome(toBaseK(num, k))) {
              sum += num;
              count++;
              if (count === n) return sum;
          }
      }
      length++;
  }

  return sum;
}

console.log(kMirror(2, 20)); // Example
