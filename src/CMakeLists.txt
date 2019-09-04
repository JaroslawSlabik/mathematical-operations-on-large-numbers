set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

set(STATIC_LIB_SOURCE_FILES
    addition.cpp
    addition.h
    addition_operation_with_sign.cpp
    addition_operation_with_sign.h
    addition_operation_without_sign.cpp
    addition_operation_without_sign.h
    subtraction.cpp
    subtraction.h
    subtraction_operation_with_sign.cpp
    subtraction_operation_with_sign.h
    subtraction_operation_without_sign.cpp
    subtraction_operation_without_sign.h
    mathematical_operations_template.h
    performs_mathematical_operations.cpp
    performs_mathematical_operations.h
)

add_library (${CMAKE_PROJECT_NAME}Lib ${STATIC_LIB_SOURCE_FILES})

add_executable(${CMAKE_PROJECT_NAME} main.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME} ${CMAKE_PROJECT_NAME}Lib)
