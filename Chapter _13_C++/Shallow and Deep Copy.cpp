// this is a c style program

#include<string.h>
#include<stdlib.h>

struct Test {
	char *ptr;
};

void shallow_copy(Test &src, Test &dest) {
	dest.ptr = src.ptr;
}

void deep_copy(Test &src, Test &dest) {
	dest.ptr = (char *)malloc(sizeof(src.ptr));
	memcpy(dest.ptr, src.ptr, sizeof(src.ptr));
}