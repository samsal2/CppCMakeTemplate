cmake_minimum_required(VERSION 3.23.1)

project(CppCMakeTemplate)

# find external libraries
# eg.
# find_package(Vulkan REQUIRED)

# declare the library 
add_library(${PROJECT_NAME})

# features
set_target_properties(${PROJECT_NAME} 
  PROPERTIES 
    CXX_STANDARD          20
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS        OFF)

# link libraries
# eg.
# target_link_libraries(${PROJECT_NAME} 
#   PUBLIC ${Vulkan_LIBRARIES})

# includes
# eg .
# target_include_directories(${PROJECT_NAME} 
#   PUBLIC ${Vulkan_INCLUDE_DIR} Source)

# compile options
target_compile_options(${PROJECT_NAME} PUBLIC
  "$<$<COMPILE_LANG_AND_ID:CXX,Clang,AppleClang>:"
    -Wall
    -Wshadow
    -Wextra
    -Werror
    -Wpedantic
    -pedantic-errors
    -Walloca 
    -Wvla 
    -fdiagnostics-color=always
  ">"
  "$<$<AND:$<COMPILE_LANG_AND_ID:CXX,Clang,AppleClang>,$<CONFIG:Debug>>:"
    -O0
    -g
    -fsanitize=address
    -fsanitize=undefined
    -fsanitize=bounds
  ">"
  "$<$<AND:$<COMPILE_LANG_AND_ID:CXX,Clang,AppleClang>,$<CONFIG:Release>>:"
    -Ofast
  ">")

# link options
target_link_options(${PROJECT_NAME} PUBLIC
  "$<$<AND:$<COMPILE_LANG_AND_ID:CXX,Clang,AppleClang>,$<CONFIG:Debug>>:"
    -fsanitize=address
    -fsanitize=undefined
    -fsanitize=bounds
  ">")

# add sources
add_subdirectory(Dependencies)
add_subdirectory(Source)
add_subdirectory(Tests)

add_executable("${PROJECT_NAME}Main" Source/main.cpp)

set_target_properties("${PROJECT_NAME}Main"
  PROPERTIES 
    CXX_STANDARD          20
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS        OFF)

target_link_libraries("${PROJECT_NAME}Main" PRIVATE ${PROJECT_NAME})


