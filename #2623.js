function memoize(fun) {
  const cache = {};
  return function (...args) {
    if (args.join(" ") in cache) return cache[args.join(" ")];
    return (cache[args.join(" ")] = fun(...args));
  };
}

const builtfun = memoize((a, b) => a + b);
console.log(builtfun(5, 5));
