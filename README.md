# get_next_line
My third 42 project: create a function get_next_line(int fd) which, at each call, returns a string containing the next line of a file (referenced by fd).

The only allowed functions are malloc, free and read.  The difficulty lies in the fact that "read(int fd, void *buf, size_t count)" read a certain number of bytes at each call (set  by the macro BUFFER_SIZE) and that we can't read what has already been read.  We have to manage a buffer as a static variable, and avoid leaks.

The macro BUFFER_SIZE has to be defined at the compilation.  For example: gcc -D BUFFER_SIZE=42 *.c  
