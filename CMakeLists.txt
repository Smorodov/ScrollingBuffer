# ----------------------------------------------------------------------------
# ����������� ������ CMake, ��������� ���������� ���� ����
# ----------------------------------------------------------------------------
cmake_minimum_required(VERSION 2.8)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}) 

set(project_name ScrollingBufferExample)

project(${project_name})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fPIC -std=c++11")
#----------------------------------------------------------------------------  
# ���� ��� .cpp � .h ����� � ��������� �� � ��� ������ 
# ----------------------------------------------------------------------------
SET(SOURCE
src/main.cpp
)

SET(HEADERS
src/ScrollingBuffer.h
)

SOURCE_GROUP("Source Files" FILES ${SOURCE})
SOURCE_GROUP("Header Files" FILES ${HEADERS})
# ----------------------------------------------------------------------------   
# ��������� include ����������
# ----------------------------------------------------------------------------
include_directories(${CMAKE_SOURCE_DIR}/src)
# ----------------------------------------------------------------------------  
# ������� ������
# ----------------------------------------------------------------------------
  ADD_EXECUTABLE( ${project_name}
  				  ${SOURCE}
  				  ${HEADERS}
  				  )
