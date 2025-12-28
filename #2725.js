var cancellable = function (fn, args, t) {
  let timerid = setInterval(() => fn(...args), t);

  return function () {
    clearInterval(timerid);
  };
};

const caller = cancellable(
  () => {
    console.log("hehe");
  },
  [],
  200
);

setTimeout(() => caller(45), 1000);
