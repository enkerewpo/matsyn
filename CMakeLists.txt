cmake_minimum_required(VERSION 3.14.0)

set(vst3sdk_SOURCE_DIR E:/vst3_sdk/vst-sdk_3.7.2_build-28_2021-03-30/VST_SDK/VST3_SDK)
if(NOT vst3sdk_SOURCE_DIR)
    message(FATAL_ERROR "Path to VST3 SDK is empty!")
endif()

project(mathsynth)
  
set(SMTG_VSTGUI_ROOT "${vst3sdk_SOURCE_DIR}")

add_subdirectory(${vst3sdk_SOURCE_DIR} ${PROJECT_BINARY_DIR}/vst3sdk)
smtg_enable_vst3_sdk()

smtg_add_vst3plugin(mathsynth     
    source/version.h
    source/rys_cids.h
    source/rys_processor.h
    source/rys_processor.cpp
    source/rys_controller.h
    source/rys_controller.cpp
    source/rys_entry.cpp
)

#- VSTGUI Wanted ----
if(SMTG_ADD_VSTGUI)
    target_sources(mathsynth
        PRIVATE
            resource/rys_editor.uidesc
    )
    target_link_libraries(mathsynth
        PRIVATE
            vstgui_support
    )
    smtg_add_vst3_resource(mathsynth "resource/rys_editor.uidesc")
endif()
# -------------------

smtg_add_vst3_snapshot(mathsynth resource/DA1D0743FA2B5A1D9B752478B829C861_snapshot.png)
smtg_add_vst3_snapshot(mathsynth resource/DA1D0743FA2B5A1D9B752478B829C861_snapshot_2.0x.png)

target_link_libraries(mathsynth
    PRIVATE
        sdk
)

if(SMTG_MAC)
    set(CMAKE_OSX_DEPLOYMENT_TARGET 10.12)
    smtg_set_bundle(mathsynth
		BUNDLE_IDENTIFIER com.rys.mathsynth
		INFOPLIST "${CMAKE_CURRENT_LIST_DIR}/resource/Info.plist" PREPROCESS
    )
    smtg_set_debug_executable(mathsynth
        "/Applications/VST3PluginTestHost.app"
        "--pluginfolder;$(BUILT_PRODUCTS_DIR)"
    )
elseif(SMTG_WIN)
    target_sources(mathsynth PRIVATE 
        resource/win32resource.rc
    )
    if(MSVC)
        set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT mathsynth)
    
        smtg_set_debug_executable(mathsynth
            "$(ProgramW6432)/Steinberg/VST3PluginTestHost/VST3PluginTestHost.exe"
            "--pluginfolder \"$(OutDir)/\""
        )
    endif()
endif()
