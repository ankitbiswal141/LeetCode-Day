function minimumDeletions(word, k) {
  let freq = Array(26).fill(0);
  for (let ch of word) {
      freq[ch.charCodeAt(0) - 'a'.charCodeAt(0)]++;
  }
  freq.sort((a, b) => a - b);

  let i = 0;
  while (i < 26 && freq[i] === 0) i++;

  let ans = Infinity;
  for (; i < 26; i++) {
      let x = freq[i];
      let ops = 0;
      for (let j = i; j < 26; j++) {
          let y = freq[j];
          if (y === 0) continue;
          if (y - x > k) {
              ops += y - x - k;
          } else if (y < x) {
              ops += y;
          }
      }
      ans = Math.min(ans, ops);
  }
  return ans;
}

let word = "aabbcc";
let k = 1;
console.log("Minimum deletions:", minimumDeletions(word, k));