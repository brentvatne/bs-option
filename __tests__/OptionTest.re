open Jest;

open Expect;

type nonsense =
  | A
  | B
  | C;

test("isSome returns true with Some", () =>
  expect(Option.isSome(Some(A))) |> toBe(true)
);

test("isSome returns false with None", () =>
  expect(Option.isSome(None)) |> toBe(false)
);

test("isNone returns true with None", () =>
  expect(Option.isNone(None)) |> toBe(true)
);

test("isNone returns false with Some", () =>
  expect(Option.isNone(Some(A))) |> toBe(false)
);

test("unwrap moves the value out of Some", () =>
  expect(Option.unwrap(Some(A))) |> toEqual(A)
);

test("unwrap fails with None", () =>
  expect(() =>
    Option.unwrap(None)
  )
  |> toThrowException(Option.UnexpectedNone)
);

test("expect fails with None and raises message", () =>
  expect(() =>
    Option.expect(None, "uh oh!")
  )
  |> toThrowException(Option.ExpectedSome("uh oh!"))
);

test("unwrapOr returns a default value if option is None", () =>
  expect(Option.unwrapOr(None, B)) |> toEqual(B)
);

test("unwrapOr moves the value out of Some", () =>
  expect(Option.unwrapOr(Some(A), B)) |> toEqual(A)
);

test("unwrapOrElse moves the value out of Some", () =>
  expect(Option.unwrapOrElse(Some(A), () => B)) |> toEqual(A)
);

test("unwrapOrElse invokes a function and returns its value if None", () =>
  expect(Option.unwrapOrElse(None, () => B)) |> toEqual(B)
);

test("map applies function to Some value", () =>
  expect(Option.map(Some(A), (_) => B)) |> toEqual(Some(B))
);

test("map returns None for None", () =>
  expect(Option.map(None, (_) => B)) |> toEqual(None)
);

test("mapOr returns default for None", () =>
  expect(Option.mapOr(None, A, (_) => B)) |> toEqual(Some(A))
);

test("mapOr applies function to Some value", () =>
  expect(Option.mapOr(Some(A), A, (_) => B)) |> toEqual(Some(B))
);

test("mapOrElse applies function to Some value", () =>
  expect(Option.mapOrElse(Some(A), () => C, (_) => B))
  |> toEqual(Some(B))
);

test("mapOrElse returns result of function application", () =>
  expect(Option.mapOrElse(None, () => C, (_) => B)) |> toEqual(Some(C))
);