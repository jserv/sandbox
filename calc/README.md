# Calculator

Here is a basic implementation of an integer calculator in C.
It utilizes Reverse Polish Notation (RPN) to perform calculations.
For example, `1*(2+3)` is represented as `1 2 3 + *`, which results in the output `5`.

## Usage
To calculate `1*(2+3)`, just run:

```
calc 1*(2+3)
```

Or you might want to view the reverse polish expression:
```
calc 1*(2+3) -c
```

Or just run `calc` to enter input mode:
```
calc
>> 1*(2+3)
5
```
