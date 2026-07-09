*This project was created as part of the curriculum for 42 by antgarci*
# Get Next Line

A 42 School project that consists of writing a program   able to read a file (or any file descriptor) line by line, one call at a time, without reading the whole file into memory at once and without relying on unlimited `read` calls.

## 📋 Description

`get_next_line` returns, on each call, the next line read from a file descriptor, including the `\n` if present. When there are no more lines to read, it returns `NULL`.

The main challenges of this exercise were:
- Reading in fixed-size chunks (`BUFFER_SIZE`) instead of reading the whole file at once.
- Keeping state between calls (`static char *rest`).
- Proper memory management (no leaks, everything freed correctly).

## ⚙️ How it works

- **`read_until_n`**: reads from `fd` in  `BUFFER_SIZE` bytes and appends them to the leftover buffer (`rest`) until a `\n` is found, or until `read` returns 0 (end of file) or -1 (error).
- **`join_free`**: joins the previous leftover (`rest`) with the newly read buffer, freeing the old memory.
- **`search_end`**: finds the first `\n` inside a string.
- **`extract_line`**: extracts the line to return (from the start up to and including the `\n`, or up to the end if there's no `\n`).
- **`extract_rest`**: saves whatever comes after the `\n` for the next call.
- **`get_next_line`**: the main function, coordinating all of the above using a `static` variable to preserve state between calls.

## 🎁 Bonus

This repository includes the bonus part, which adds:
- Support for **handling multiple file descriptors at the same time** without mixing them up (using a static array `rest[1024]`).
- A **single static variable** to manage internal state.

## 📁 Project files

| File | Description |
|---|---|
| `get_next_line.c` / `.h` | Mandatory version (single `fd`). |
| `get_next_line_utils.c` | Helper functions: `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `search_end`. |
| **Bonus Part** |
| `get_next_line_bonus.c` / `.h` | Bonus version (multiple simultaneous `fd`). |
| `get_next_line_utils_bonus.c` | Same functions from `get_next_line_utils.c` |


## 🔧 Compilation

The project is compiled by defining the buffer size with `-D BUFFER_SIZE=n`, or without it since it has a default size 1024.

```bash
# Mandatory version
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```
```bash
# Bonus version
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main.c -o gnl_bonus
```
