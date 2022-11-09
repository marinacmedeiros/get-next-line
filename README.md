<h1 align="center">
	Get Next Line - 42 Cursus
</h1>

:books: *A function that returns a line read from a
file descriptor.*

## Skills
* Algorithms & AI
* Imperative programming
* Rigor

## Mandatory part
* Repeated calls (e.g., using a loop) to your get_next_line() function should let you read the text file pointed to by the file descriptor, one line at a time.
* Your function should return the line that was read. If there is nothing else to read or if an error occurred, it should return NULL.|
*  Make sure that your function works as expected both when reading a file and when reading from the standard input.
* Please note that the returned line should include the terminating \n character, except if the end of file was reached and does not end with a \n character.
* Your header file get_next_line.h must at least contain the prototype of the get_next_line() function.
* Add all the helper functions you need in the get_next_line_utils.c file.
* Because you will have to read files in get_next_line(), add this option to your compiler call: -D BUFFER_SIZE=n. It will define the buffer size for read().
* We consider that get_next_line() has an undefined behavior if the file pointed to by the file descriptor changed since the last call whereas read() didn’t reach the end of file.

## Bonus part
* Develop get_next_line() using only one static variable.
* Your get_next_line() can manage multiple file descriptors at the same time. For example, if you can read from the file descriptors 3, 4 and 5, you should be able to read from a different fd per call without losing the reading thread of each file descriptor or returning a line from another fd. It means that you should be able to call get_next_line() to read from fd 3, then fd 4, then 5, then once again 3, once again 4, and so forth.

## 🛠️ Usage

### Requirements

The project is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run

## 📋 Testing

### Third-party testers

* [Tripouille/printfTester](https://github.com/Tripouille/printfTester)
