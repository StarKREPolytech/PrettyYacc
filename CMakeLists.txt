cmake_minimum_required(VERSION 3.12)

project(yaccExmpl)

set(CMAKE_CXX_STANDARD 17)

include_directories(main generated)

set(prefix calc_)

#Find yacc:
find_package(BISON REQUIRED)

#Find lex:
find_package(FLEX REQUIRED)

function(generate)
    if (BISON_FOUND)
        set(yaccout ../generated/calc/calc_parser.cpp)
        add_custom_command(
                OUTPUT ${yaccout}
                COMMAND ${BISON_EXECUTABLE}
                --defines=../generated/calc/calc_token.h
                --output=${yaccout}
                -p ${prefix}
                ../main/calc/calc.y
        )
    endif ()
    if (FLEX_FOUND)
        set(flexout ../generated/calc/calc_lexer.cpp)
        add_custom_command(
                OUTPUT ${flexout}
                COMMAND ${FLEX_EXECUTABLE}
                --outfile=${flexout}
                -P${prefix}
                ../main/calc/calc.l
        )
    endif ()
endfunction()

generate()

add_executable(
        yaccExmpl
        #main:
        main/main.cpp

        #calc:
        main/calc/calc.h
        generated/calc/calc_parser.cpp
        generated/calc/calc_token.h
        generated/calc/calc_lexer.cpp
        generated/calc/calc_parser.cpp generated/calc/calc_parser.cpp
)