#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "file_operations.h"

int create_and_write_file(const char *filename, const char *content) {

//Declare file descriptor and counters

int fd;
ssize_t bytes_written;
ssize_t total_written = 0;
size_t to_write = strlen(content);

//Print what we're doing

printf("Creating file: %s\n",filename);
printf("Content to write %s\n", content);

//Open or create file for writing; truncate existing; perms 0644
fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
if (fd == -1) {
	perror("open");
	return -1;
}

printf("File descriptor: %d\n", fd);


//Robust write loop (handles partial writes)

while (total_written < (ssize_t)to_write) {
	bytes_written=write(fd, content + total_written, to_write - total_written);
if (bytes_written == -1) {
perror ("write");
if (close(fd) == -1) perror("close");
return -1;
}
total_written += bytes_written;
} 

printf("Successfully wrote %zd bytes to '%s'\n", total_written, filename);

//Close file

if (close(fd) == -1) {
	perror("close");
	return -1;
}

   printf("File closed successfully\n")
    return 0;
}

int read_file_contents(const char *filename) {

	int fd;
	char buffer[1024];
	ssize_t bytes_read;

	printf("Reading file: %s\n",filename);

	//Open for read-only

fd = open(filename, O_RDONLY);
if (fd == -1) {
	perror("open");
	return -1;
}

	printf("File descriptor: %d\n", fd);


//Robust write loop (handles partial writes) 

	while (total_written < (ssize_t)to_write {
	bytes_written = write(fd, content + total_written, to_write - total_written);
	if (bytes_written == -1) {
	perror("write");
	if (close(fd) == -1) perror("close");
	return -1;

}

	total_written += bytes_written;
}

printf("Successfully wrote %zd bytes to '%s'\n", total_written, filename);

//close file

	if (close(fd) == -1) {
	perror("close")
	return -1;
}


	printf("File closed successfully\n");
	return 0;
}

	int read_file_contents(const char *filename) {
	int fd;
	char buffer[1024];
	ssize_t bytes_read;

	printf("Reading file: %s\n" filename);

	fd = open(filename, O_RDONLY);
	if (fd == -1) {
	perror("open");
	return -1;
}

printf("File descriptor: %d\n", fd);
printf("\n--- Contents of '%s' ---\n" filename);

//Read Loop

while ((bytes_read = read(fd, buffer, sizeof(buffer) -1)) > 0) {
	buffer[bytes_read] = '\0';
	printf("%s", buffer);
}

if (bytes_read == -1) {
	perror("read");
	if (close(fd) == -1) perror("close");
	return -1;

}

printf("\n--- End of file ---\n");

if (close(fd) == -1) {
	perror("close");
	return -1;
}

printf("File closed successfully\n");

return 0;

} 

    // TODO: Declare an integer 'fd' for the file descriptor.
    // TODO: Create a buffer array of size 1024 to store the file data.
    // TODO: Declare a variable 'bytes_read' of type ssize_t to store how many bytes are read.

    // TODO: Print a message showing which file is being read.

    // TODO: Open the file for reading using the open() system call.
    // TODO: Use the O_RDONLY flag.
 

   // TODO: Check if open() failed (fd == -1). If so, print an error using perror and return -1.

    // TODO: Print the file descriptor value.
    // TODO: Print a header for the file contents.

    // TODO: Read the file contents using the read() system call in a loop.
    // TODO: Use sizeof(buffer) - 1 for the buffer size.
    // TODO: Null-terminate the buffer after each read.
    // TODO: Print the contents of the buffer.
    // TODO: Continue reading until read() returns 0.

    // TODO: Check if read() failed (bytes_read == -1). If so, print an error using perror, close the file, and return -1.

    // TODO: Print a footer for the end of the file.

    // TODO: Close the file using close(fd).
    // TODO: Check if close() failed. If so, print an error using perror and return -1.

    // TODO: Print a message that the file was closed successfully.
    
