cmake_minimum_required(VERSION 3.14)

set(LIB_NAME QtExceptions)

project(${LIB_NAME} LANGUAGES CXX)

find_package(Qt5 COMPONENTS Core REQUIRED)

add_library(${LIB_NAME} STATIC
	${CMAKE_CURRENT_SOURCE_DIR}/include/QtExceptions/qt_exceptions.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/QtExceptions/runtime_error.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/runtime_error.cpp
)

include(GNUInstallDirs)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
	enable_testing()
endif()

target_include_directories(${LIB_NAME} PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_link_libraries(${LIB_NAME} PUBLIC
	Qt5::Core
)

install(TARGETS ${LIB_NAME}
	EXPORT ${LIB_NAME}-config
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(EXPORT ${LIB_NAME}-config
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${LIB_NAME}
)

install(
	DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
	DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

set_property(TARGET ${LIB_NAME} PROPERTY AUTOMOC ON)
set_property(TARGET ${LIB_NAME} PROPERTY AUTORCC ON)
set_property(TARGET ${LIB_NAME} PROPERTY CXX_STANDARD 11)
set_property(TARGET ${LIB_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET ${LIB_NAME} PROPERTY COMPILE_FLAGS -Wall)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/test)
