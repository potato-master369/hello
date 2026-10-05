AC_PREREQ([2.69])

AC_INIT(
    [helloworld],
    [1.0.0],
    [random.nonprivate.email@gmail.com],
    [helloworld],
    [https://example.com]
)
AM_INIT_AUTOMAKE([foreign])

AC_CONFIG_SRCDIR([configure.ac])
AC_CONFIG_HEADERS([config.h])

AC_CANONICAL_HOST
AC_CANONICAL_BUILD

AC_LANG([C])

dnl ============================================================
dnl  Compiler discovery
dnl ============================================================

AC_MSG_NOTICE([Beginning integration test...])

AC_PROG_CC

AS_IF(
    [test "x$CC" = "x"],
    [
        AC_MSG_FAILURE([
            A C compiler could not be located.
            This is unfortunate because the entire purpose of this
            configure script is to complain about the absence of one.
        ])
    ],
    [
        AC_MSG_NOTICE([C compiler found: $CC])
    ]
)

dnl ============================================================
dnl  Compiler sanity test
dnl ============================================================

AC_CACHE_CHECK(
    [whether the C compiler can compile a completely pointless program],
    [ac_cv_c_compiler_is_actually_alive],
    [
        AC_COMPILE_IFELSE(
            [
                AC_LANG_PROGRAM(
                    [[]],
                    [[
                        return 0;
                    ]]
                )
            ],
            [
                ac_cv_c_compiler_is_actually_alive=yes
            ],
            [
                ac_cv_c_compiler_is_actually_alive=no
            ]
        )
    ]
)

AS_IF(
    [test "x$ac_cv_c_compiler_is_actually_alive" != "xyes"],
    [
        AC_MSG_FAILURE([
            The compiler exists, but apparently refuses to compile
            the world's least interesting C program.
        ])
    ]
)

dnl ============================================================
dnl  stdio.h
dnl ============================================================

AC_CHECK_HEADERS(
    [stdio.h],
    [],
    [
        AC_MSG_FAILURE([
            stdio.h could not be found.
        ])
    ]
)

dnl ============================================================
dnl  printf()
dnl ============================================================

AC_CACHE_CHECK(
    [whether printf exists and can theoretically be invoked],
    [ac_cv_func_printf_really_exists],
    [
        AC_LINK_IFELSE(
            [
                AC_LANG_PROGRAM(
                    [[
                        #include <stdio.h>
                    ]],
                    [[
                        int result;

                        result = printf("%s", "hello from configure");

                        return result < 0;
                    ]]
                )
            ],
            [
                ac_cv_func_printf_really_exists=yes
            ],
            [
                ac_cv_func_printf_really_exists=no
            ]
        )
    ]
)

AS_IF(
    [test "x$ac_cv_func_printf_really_exists" != "xyes"],
    [
        AC_MSG_FAILURE([
            printf() was not successfully linked.
        ])
    ]
)

dnl ============================================================
dnl  int
dnl ============================================================

AC_CACHE_CHECK(
    [whether the language contains the int type],
    [ac_cv_c_has_int_because_obviously],
    [
        AC_COMPILE_IFELSE(
            [
                AC_LANG_PROGRAM(
                    [],
                    [[
                        int completely_unnecessary_integer;

                        completely_unnecessary_integer = 42;

                        return completely_unnecessary_integer != 42;
                    ]]
                )
            ],
            [
                ac_cv_c_has_int_because_obviously=yes
            ],
            [
                ac_cv_c_has_int_because_obviously=no
            ]
        )
    ]
)

AS_IF(
    [test "x$ac_cv_c_has_int_because_obviously" != "xyes"],
    [
        AC_MSG_FAILURE([
            int does not appear to exist.
        ])
    ]
)

dnl ============================================================
dnl  char
dnl ============================================================

AC_CACHE_CHECK(
    [whether the language contains the char type],
    [ac_cv_c_has_char_for_some_reason],
    [
        AC_COMPILE_IFELSE(
            [
                AC_LANG_PROGRAM(
                    [],
                    [[
                        char completely_unnecessary_character;

                        completely_unnecessary_character = 'X';

                        return completely_unnecessary_character != 'X';
                    ]]
                )
            ],
            [
                ac_cv_c_has_char_for_some_reason=yes
            ],
            [
                ac_cv_c_has_char_for_some_reason=no
            ]
        )
    ]
)

AS_IF(
    [test "x$ac_cv_c_has_char_for_some_reason" != "xyes"],
    [
        AC_MSG_FAILURE([
            char does not exist.
        ])
    ]
)

dnl ============================================================
dnl  Pointer support
dnl ============================================================

AC_CACHE_CHECK(
    [whether the implementation supports pointers],
    [ac_cv_c_has_pointers_despite_the_fact_everything_does],
    [
        AC_COMPILE_IFELSE(
            [
                AC_LANG_PROGRAM(
                    [],
                    [[
                        int value = 123;
                        int *pointer_to_value = &value;

                        return *pointer_to_value != value;
                    ]]
                )
            ],
            [
                ac_cv_c_has_pointers_despite_the_fact_everything_does=yes
            ],
            [
                ac_cv_c_has_pointers_despite_the_fact_everything_does=no
            ]
        )
    ]
)

AS_IF(
    [test "x$ac_cv_c_has_pointers_despite_the_fact_everything_does" != "xyes"],
    [
        AC_MSG_FAILURE([
            Pointers appear not to exist.
        ])
    ]
)

dnl ============================================================
dnl  return statement
dnl ============================================================

AC_CACHE_CHECK(
    [whether functions can return using the return statement],
    [ac_cv_c_return_statement_is_present_somehow],
    [
        AC_COMPILE_IFELSE(
            [
                AC_LANG_PROGRAM(
                    [],
                    [[
                        return 0;
                    ]]
                )
            ],
            [
                ac_cv_c_return_statement_is_present_somehow=yes
            ],
            [
                ac_cv_c_return_statement_is_present_somehow=no
            ]
        )
    ]
)

AS_IF(
    [test "x$ac_cv_c_return_statement_is_present_somehow" != "xyes"],
    [
        AC_MSG_FAILURE([
            The return statement appears to be unavailable.
        ])
    ]
)

dnl ============================================================
dnl  The Ultimate Completely Unnecessary Integration Test
dnl ============================================================

AC_CACHE_CHECK(
    [whether all required components can coexist in one program],
    [ac_cv_c_everything_is_somehow_fine],
    [
        AC_LINK_IFELSE(
            [
                AC_LANG_PROGRAM(
                    [[
                        #include <stdio.h>

                        static int
                        demonstrate_everything(int value)
                        {
                            char character = 'A';
                            int local_value = value;
                            int *pointer = &local_value;

                            printf(
                                "character=%c value=%d\n",
                                character,
                                *pointer
                            );

                            return *pointer;
                        }
                    ]],
                    [[
                        int result;

                        result = demonstrate_everything(42);

                        return result != 42;
                    ]]
                )
            ],
            [
                ac_cv_c_everything_is_somehow_fine=yes
            ],
            [
                ac_cv_c_everything_is_somehow_fine=no
            ]
        )
    ]
)

AS_IF(
    [test "x$ac_cv_c_everything_is_somehow_fine" != "xyes"],
    [
        AC_MSG_FAILURE([
            The individual components appeared to work,
            but they have collectively failed to cooperate.
        ])
    ]
)

dnl ============================================================
dnl  Configuration summary
dnl ============================================================

AC_MSG_NOTICE([])
AC_MSG_NOTICE([ helloworld: OK])

AC_DEFINE(
    [C_ENVIRONMENT_IS_ABSURDLY_CAPABLE],
    [1],
    [Environment integration test PASS]
)

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
