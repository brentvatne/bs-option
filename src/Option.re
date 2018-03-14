exception UnexpectedNone;

exception ExpectedSome(string);

let isSome =
  fun
  | None => false
  | Some(_) => true;

let isNone =
  fun
  | None => true
  | Some(_) => false;

let unwrap =
  fun
  | None => raise(UnexpectedNone)
  | Some(a) => a;

let expect = (opt, message) => {
  if (isNone(opt)) {
    raise(ExpectedSome(message));
  };
  unwrap(opt);
};

let unwrapOr = (opt, default) =>
  switch (opt) {
  | None => default
  | Some(a) => a
  };

let unwrapOrElse = (opt, f) =>
  switch (opt) {
  | None => f()
  | Some(a) => a
  };

let map = (opt, f) =>
  switch (opt) {
  | None => None
  | Some(a) => Some(f(a))
  };

let mapOr = (opt, default, f) =>
  switch (opt) {
  | None => Some(default)
  | Some(a) => Some(f(a))
  };

let mapOrElse = (opt, f, mapf) =>
  switch (opt) {
  | None => Some(f())
  | Some(a) => Some(mapf(a))
  };