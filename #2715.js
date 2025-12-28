const fn = () => {
  console.log("hello workd");
};

var cancellable = function (fn, args, t) {
  const timeoutId = setTimeout(() => {
    fn(...args);
  }, t);
  return function () {
    clearTimeout(timeoutId);
  };
};

const cancel = cancellable(fn, [], 1000);

setTimeout(cancel, 500);
