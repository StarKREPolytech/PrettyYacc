cmake_minimum_required(VERSION 3.12)

project(yaccExmpl)

set(CMAKE_CXX_STANDARD 17)

include_directories(main generated)

#Find yacc:
find_package(BISON REQUIRED)

#Find lex:
find_package(FLEX REQUIRED)

function(generate path name)
    set(prefix ${name}_)
    if (BISON_FOUND)
        set(yaccout ../generated/${name}/${name}_parser.cpp)
        add_custom_command(
                OUTPUT ${yaccout}
                COMMAND ${BISON_EXECUTABLE}
                --defines=../generated/${name}/${name}_token.h
                --output=${yaccout}
                -p ${prefix}
                ../${path}/${name}/${name}.y
        )
    else ()
        message(ERROR "Cannot find YACC!")
    endif ()
    if (FLEX_FOUND)
        set(flexout ../generated/${name}/${name}_lexer.cpp)
        add_custom_command(
                OUTPUT ${flexout}
                COMMAND ${FLEX_EXECUTABLE}
                --outfile=${flexout}
                -P${prefix}
                ../${path}/${name}/${name}.l
        )
    else ()
        message(ERROR "Cannot find LEX")
    endif ()
endfunction()

generate(main calc)

add_executable(
        yaccExmpl
        #main:
        main/calc/calc.cpp

        #calc:
        main/calc/calc.h
        generated/calc/calc_parser.cpp
        generated/calc/calc_token.h
        generated/calc/calc_lexer.cpp
)