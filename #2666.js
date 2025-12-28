const once = function (fn) {
  let count = 1;
  return function (...args) {
    if (count == 1) {
      count++;
      return fn(...args);
    }
  };
};
const fn = (a, b, c) => a + b + c;

const oncefn = once(fn);
console.log(oncefn(1, 2, 3));
console.log(oncefn(1, 2, 3));
