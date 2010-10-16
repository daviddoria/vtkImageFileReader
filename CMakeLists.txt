CMAKE_MINIMUM_REQUIRED(VERSION 2.4.5)

PROJECT(vtkImageFileReader)

FIND_PACKAGE(VTK REQUIRED)
INCLUDE(${VTK_USE_FILE})

ADD_EXECUTABLE(vtkImageFileReaderExample vtkImageFileReaderExample.cxx vtkImageFileReader.cxx)
TARGET_LINK_LIBRARIES(vtkImageFileReaderExample vtkHybrid)

