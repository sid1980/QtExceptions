cmake_minimum_required(VERSION 3.0)

set(TEST_NAME QtExceptionsTest)

project(${TEST_NAME} LANGUAGES CXX)

find_package(Qt5 COMPONENTS Core Test REQUIRED)

add_executable(${TEST_NAME}
	${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/run_time_error_test.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/run_time_error_test.hpp
)

target_link_libraries(${TEST_NAME} PRIVATE 
	Qt5::Core
	Qt5::Test
	QtExceptions
)

target_include_directories(${TEST_NAME} PRIVATE 
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
	enable_testing()
endif()

add_test(
	NAME ${TEST_NAME} 
	COMMAND $<TARGET_FILE:${TEST_NAME}>
	WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

set_property(TARGET ${TEST_NAME} PROPERTY AUTOMOC ON)
set_property(TARGET ${TEST_NAME} PROPERTY AUTORCC ON)
set_property(TARGET ${TEST_NAME} PROPERTY CXX_STANDARD 11)
set_property(TARGET ${TEST_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET ${TEST_NAME} PROPERTY COMPILE_FLAGS -Wall)
install(TARGETS ${TEST_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX})

if(WIN32)
	add_custom_command(TARGET ${TEST_NAME} POST_BUILD 
		COMMAND windeployqt 
			--verbose 0 
			--plugindir ${CMAKE_CURRENT_BINARY_DIR}/plugins 
			${CMAKE_CURRENT_BINARY_DIR} 
	)
endif()
