# bs-option

Some useful functions for dealing with `Some` and `None`.

# Getting Started

Install `bs-option` using yarn:

```bash
yarn add bs-option
```

Then add `bs-option` to `bs-dependencies` in `bsconfig.json`.

# Usage

```
let someValue = Some(42);
let fourtyTwo = Option.unwrap(someValue);
```

# API

- `Option.isSome(o)` - returns `true` if `o` is `Some(a)`
- `Option.isNone(o)` - returns `true` if `o` is `None`
- `Option.unwrap(o)` - returns `a` in `Some(a)` or raises `Option.UnexpectedNone`
- `Option.expect(o, message)` - returns `a` in `Some(a)` or raises `Option.ExpectedSome(message)`
- `Option.map(o, f)` - returns `Some(f(a))` for `Some(a)`, or `None` if `o` is `None`
- `Option.unwrapOr(o, default)` - same as `unwrap` but returns `default` if `o` is `None`
- `Option.unwrapOrElse(o, f)` - same as `unwrap` but returns the result of the application of `f` if `o` is `None`
- `Option.mapOr(o, default)` - same as `map` but returns `Some(default)` if `o` is `None`
- `Option.mapOrElse(o, f)` - same as `map` but returns `Some(f())` if `o` is `None`
