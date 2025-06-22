function divideString(s, k, fill) {
  let result = [];
  for (let i = 0; i < s.length; i += k) {
      let chunk = s.substring(i, i + k);
      if (chunk.length < k) {
          chunk = chunk.padEnd(k, fill);
      }
      result.push(chunk);
  }
  return result;
}