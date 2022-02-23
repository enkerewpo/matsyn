# Install script for directory: E:/OneDrive/work/music/vst3_sdk/vst-sdk_3.7.2_build-28_2021-03-30/VST_SDK/VST3_SDK

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/matsyn")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("E:/OneDrive/work/music/matsyn/build/vst3sdk/VSTGUI.build/cmake_install.cmake")
  include("E:/OneDrive/work/music/matsyn/build/vst3sdk/pluginterfaces/cmake_install.cmake")
  include("E:/OneDrive/work/music/matsyn/build/vst3sdk/base/cmake_install.cmake")
  include("E:/OneDrive/work/music/matsyn/build/vst3sdk/public.sdk/cmake_install.cmake")
  include("E:/OneDrive/work/music/matsyn/build/vst3sdk/public.sdk/source/vst/interappaudio/cmake_install.cmake")
  include("E:/OneDrive/work/music/matsyn/build/vst3sdk/public.sdk/samples/vst-hosting/cmake_install.cmake")

endif()

