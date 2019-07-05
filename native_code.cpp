#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

#include "native_code.h"
 
int
exec_native_code(unsigned char *code, size_t len)
{
    void *ptr = mmap(0, 10000, PROT_EXEC | PROT_WRITE | PROT_READ, 
        MAP_ANON | MAP_PRIVATE, -1, 0);
 
    if (ptr == MAP_FAILED) {
        return 1;
    }
 
    memcpy(ptr, code, len);
    ((IP)ptr)();
 
    return 0;
}
