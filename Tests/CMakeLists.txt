enable_testing()

add_executable(ExampleTest ExampleTest.cpp)

target_compile_options(ExampleTest PUBLIC
	"$<$<COMPILE_LANG_AND_ID:CXX,Clang,AppleClang>:"
    -O3
	">"
)

add_test(ExampleTestTest ExampleTest)

