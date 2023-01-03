enable_testing()

add_executable(ExampleTest ExampleTest.c)
target_link_libraries(ExampleTest ${PROJECT_NAME} Unity)

target_compile_options(ExampleTest PUBLIC
	"$<$<COMPILE_LANG_AND_ID:CXX,Clang,AppleClang>:"
    -O3
	">"
)

add_test(ExampleTestTest ExampleTest)

