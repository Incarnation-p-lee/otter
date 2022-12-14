#ifndef TYPES_H
#define TYPES_H

typedef signed char sint8;
typedef unsigned char uint8;
typedef unsigned int bool;
typedef signed short sint16;
typedef unsigned short uint16;
typedef signed int sint32;
typedef unsigned int uint32;

#if defined X86_32 || defined RV32
typedef signed long long sint64;
typedef unsigned long long uint64;
#endif

#if defined X86_64 || defined RV64
typedef signed long sint64;
typedef unsigned long uint64;
#endif

#if defined RV32

typedef uint32 xlen_t;

#endif

#ifdef RV64

typedef uint64 xlen_t;

#endif

typedef struct validate_result {
  bool is_supported;
  char *extension_name;
  char *description;
} s_validate_result_t;

typedef struct validate_result_collection {
  uint32 count;
  uint32 capacity;
  s_validate_result_t *results;
} s_validate_result_collection_t;

#endif
