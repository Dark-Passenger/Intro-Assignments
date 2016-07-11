#include <iostream>
#include <string>
#include <sys/stat.h>
#include <sys/mman.h> 
#include <errno.h>

#include <stdarg.h>
#include <fcntl.h>

#include <stdlib.h>
#include <ctype.h>

int main (int argc, char *argv[])
{
    /* The file name to open. */
    if(argc < 3)
    {
        cout <<"Usage : " << argv[0] <<" <file name>\n";
        return 0;
    }
    string file_name = argv[1];
    /* The file descriptor. */
    int fd;
    /* Information about the file. */
    struct stat s;
    size_t size;
    /* The memory-mapped thing itself. */
    char * mapped;

    /* Open the file for reading. */
    fd = open (argv[1], O_RDONLY);
    
    /* Get the size of the file. */
    size = s.st_size;

    /* Memory-map the file. */
    mapped = mmap (0, size, PROT_READ, 0, fd, 0);

    /* Now do something with the information. */
    for (int i = 0; i < size; i++) {
        cout << mapped[i];
    }

    return 0;
}
