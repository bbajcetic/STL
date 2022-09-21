add_executable(vector_test vector_test.cpp)
target_link_libraries(vector_test gtest pthread)
add_test(NAME vector_test COMMAND vector_test)
add_custom_target(vector_test_custom COMMAND ${CMAKE_CTEST_COMMAND} DEPENDS vector_test)
