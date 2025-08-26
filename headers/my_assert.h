#ifndef MY_ASSERT_H
#define MY_ASSERT_H

void my_assert(void* ptr/*, char* name_file, int line_of_file*/);

#ifndef NDEBUG
#define MY_ASSERT(ptr) my_assert(ptr/*, __FILE__, __LINE__*/);
#else
#define MY_ASSERT(ptr)
#endif

#endif