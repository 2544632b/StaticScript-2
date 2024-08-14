set(BUILTIN_LIB_SOURCES lib_error.c lib_string.c lib_array.c lib_io.c lib_math.c lib_thread.cpp lib_input.cpp lib_curl.cpp lib_loop.c lib_socket.cpp)
set(BUILTIN_LIB_BITCODES lib_error.bc lib_string.bc lib_array.bc lib_io.bc lib_math.bc lib_thread.bc lib_input.bc lib_curl.bc lib_loop.bc lib_socket.bc)

# BitCodes
add_custom_command(
        OUTPUT ${BUILTIN_LIB_BITCODES}
        COMMAND clang -c -emit-llvm ${PROJECT_SOURCE_DIR}/lib/lib_error.c -std=c99 -O2 -o lib_error.bc
        COMMAND clang -c -emit-llvm ${PROJECT_SOURCE_DIR}/lib/lib_string.c -std=c99 -O2 -o lib_string.bc
        COMMAND clang -c -emit-llvm ${PROJECT_SOURCE_DIR}/lib/lib_array.c -std=c99 -O2 -o lib_array.bc
        COMMAND clang -c -emit-llvm ${PROJECT_SOURCE_DIR}/lib/lib_io.c -std=c99 -O2 -o lib_io.bc
        COMMAND clang -c -emit-llvm ${PROJECT_SOURCE_DIR}/lib/lib_math.c -std=c11 -O2 -o lib_math.bc
        COMMAND clang++ -c -emit-llvm ${PROJECT_SOURCE_DIR}/lib/lib_thread.cpp -std=c++17 -O2 -o lib_thread.bc
        COMMAND clang++ -c -emit-llvm ${PROJECT_SOURCE_DIR}/lib/lib_input.cpp -std=c++17 -O2 -o lib_input.bc
        COMMAND clang++ -c -emit-llvm ${PROJECT_SOURCE_DIR}/lib/lib_curl.cpp -std=c++17 -I/usr/local/Cellar/curl/8.8.0/include/ -O2 -o lib_curl.bc
        COMMAND clang -c -emit-llvm ${PROJECT_SOURCE_DIR}/lib/lib_loop.c -std=c11 -I/Users/chan/Desktop/libuv-1.x/include/ -O2 -o lib_loop.bc
        COMMAND clang++ -c -emit-llvm ${PROJECT_SOURCE_DIR}/lib/lib_socket.cpp -I/Users/chan/Desktop/libuv-1.x/include/ -std=c++17 -O2 -o lib_socket.bc
        DEPENDS ${BUILTIN_LIB_SOURCES}
)

add_custom_target(
        lib
        DEPENDS ${BUILTIN_LIB_BITCODES}
)