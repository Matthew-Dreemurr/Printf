# Printf

## Why does the code look weird ?

The 42 curriculum asks us to code according to the `Norme`, this standard forbids us certain control structures (like `do while`, `for`, ...), a limit of 25 lines and 5 variables per function, 5 function max per `.c` and and other constraints.

This project has been coded according to the `NormeV3` standard.

[NormeV3 PDF](https://github.com/Matthew-Dreemurr/Media-Stock/blob/master/norm/en.normV3.pdf) used in this projetc

[Norme repo](https://github.com/42School/norminette)

## Convertions

| Type character | WIP | Output |
|:-----|:---|:--------------------------------------------------------|
| `%c` | ✅ | Print a singlecharacter |
| `%s` | ✅ | Print astring of characters |
| `%p` | ✅ | Print the argument as an address in hexadecimal digits. |
| `%d` | ✅ | Print a decimal (base 10) number |
| `%i` | ✅ | print an integer in base 10 |
| `%u` | ✅ | print an unsigned decimal (base 10) number |
| `%x` | ✅ | Unsigned hexadecimal integer; uses `abcdef` |
| `%X` | ✅ | Unsigned hexadecimal integer; uses `ABCDEF` |
| `%%` | ✅ | Print `%` |

<!--
## Flags

| Flag | WIP | Meaning                                                |
|------|:----|:-------------------------------------------------------|
| `%ft_isdigit();` | 🔧 | Right align the result within the given field width     |
| `%-` | 🔧 | Left align the result within the given field width     |
| `%0` | 🔧 | Shorter numbers are padded out with leading zeros      |
| `%.` | 🔧 | How many placesshould be shown after the decimal point |

| **Bonus**     | WIP |              |
| ------------- |:----|:-------------|
| `%#`          | 🔧 |   When it's used with the `o`, `x`, or `X` format, the `#` flag uses `0`, `0x`, or `0X`, respectively, to prefix any nonzero output value |
| `% `          | 🔧 |   Use a blank to prefix the output value if it's signed and positive. The blank is ignored if both the blank and + flags appear |
| `%+`          | 🔧 |   Use a sign (`+` or `-`) to prefix the output value if it's of a signed type. |
--->

## Sources

Secrets of “printf” Professor Don Colton <https://www.cypress.com/file/54441/download>

This work is published under the terms of **[42 Unlicense](https://github.com/gcamerli/42unlicense)**.
