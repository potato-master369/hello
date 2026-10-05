// hello.c
// -------------------------
// From the helloworld project.
// See README.txt for licensing.

// Include the header for standard
// C Input and Output, according to
// ISO C
#include <stdio.h>
#include <string.h>

#define HELLOWORLD_REQUIRED_VERSION 1
#define HELLOWORLD_MAX_VERSION 3
#if defined(__STDC_HOSTED__) && (__STDC_HOSTED__ == 0)
    #error " helloworld build system: cannot build freestanding."
#endif

#ifdef HELLOWORLD_TARGET_VERSION
#if HELLOWORLD_TARGET_VERSION < HELLOWORLD_REQUIRED_VERSION
  #error " helloworld build system: helloworld too old for use."
#else
  #if HELLOWORLD_TARGET_VERSION > HELLOWORLD_MAX_VERSION
    #error " helloworld build system: helloworld too new for use."
  #endif
#endif
#endif

#if defined(__STDC_VERSION__)
    #if __STDC_VERSION__ >= 202311L
        #define PRINTF_DIALECT_C23 1
    #elif __STDC_VERSION__ >= 201112L
        #define PRINTF_DIALECT_C11 1
    #elif __STDC_VERSION__ >= 199901L
        #define PRINTF_DIALECT_C99 1
    #else
        #define PRINTF_DIALECT_C89 1
    #endif
#else
    // how did we even compile the // comments
    #define PRINTF_DIALECT_LEGACY 1
#endif

#if defined(__has_builtin)
    #if __has_builtin(__builtin_printf)
        #define HAS_BUILTIN_PRINTF 1
    #endif
#endif

#if defined(__GNUC__) || defined(__clang__)
    #define PRINTF_ATTRIBUTE_CHECK __attribute__((format(printf, 1, 2)))
#else
    #define PRINTF_ATTRIBUTE_CHECK
#endif

#if defined(__linux__)
    #include <features.h>
    #if defined(__GLIBC__)
        /* GNU C Library guarantees printf, but check for modern POSIX compliance */
        #if defined(_POSIX_C_SOURCE) && (_POSIX_C_SOURCE < 200809L)
            #warning " helloworld build system: POSIX source under 2008."
        #endif
        #define PRINTF_BACKEND_GLIBC 1
    #elif defined(__UCLIBC__)
        #define PRINTF_BACKEND_UCLIBC 1
    #else
        /* Assume Musl or other lean Linux libcs */
        #define PRINTF_BACKEND_MUSL 1
    #endif

#elif defined(_WIN32) || defined(_WIN64)
    /* Windows brings legacy MSVCRT vs modern UCRT drama */
    #include <corecrt.h>
    #if defined(_UCRT)
        #define PRINTF_BACKEND_WINDOWS_UCRT 1
    #else
        #define PRINTF_BACKEND_WINDOWS_LEGACY_MSVCRT 1
        #warning " helloworld build system: legacy MSVCRT!"
    #endif

#elif defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
    #define PRINTF_BACKEND_BSD_DERIVATIVE 1
#else
    #define PRINTF_BACKEND_UNKNOWN 1
#endif

#if defined(PRINTF_DIALECT_C89) || defined(PRINTF_DIALECT_LEGACY)
    #include <stdio.h>
#else
    #ifndef _STDIO_H
        #include <stdio.h>
    #endif
#endif

// Main function.
//   @param argc - number of arguments passed
//   @argv - argument vector
int main(int argc, char* argv[]) {
    // Print our desired string. This utilises glibc
    // to print out the string to standard output.
    // Buffer to store the string
    // and result buffer.
    //
    // Defined at the top for legacy compatibility.
    int com_example_hello_res;
    char com_example_hello_buf[256];
    // initialize our buffer
    strncpy(com_example_hello_buf, "Hello, world\n", sizeof(com_example_hello_buf));
    // Print the buffer.
    com_example_hello_res = printf("%s", com_example_hello_buf);
    if (com_example_hello_res < 1) { // Buffer <1: Write fail
      perror(" helloworld: printf has unfortunately failed. (E0001)");
    }
    else if (com_example_hello_res != strlen(com_example_hello_buf)) { // Buffer >= STRING_SIZE: Wrote too many characters/ if <= STRING_SIZE wrote too few characters
      perror(" helloworld: write match fail (E0002)");
    }
    // Return EXIT_SUCCESS.
    return 0;
}

