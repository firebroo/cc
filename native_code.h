#pragma once

typedef int (*IP)(void);

int exec_native_code(unsigned char *code, size_t len); 
