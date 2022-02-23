cmake_minimum_required(VERSION 3.14.0)

set(vst3sdk_SOURCE_DIR E:/OneDrive/work/music/vst3_sdk/vst-sdk_3.7.2_build-28_2021-03-30/VST_SDK/VST3_SDK)
if(NOT vst3sdk_SOURCE_DIR)
    message(FATAL_ERROR "Path to VST3 SDK is empty!")
endif()

project(matsyn)
  
set(SMTG_VSTGUI_ROOT "${vst3sdk_SOURCE_DIR}")

add_subdirectory(${vst3sdk_SOURCE_DIR} ${PROJECT_BINARY_DIR}/vst3sdk)
smtg_enable_vst3_sdk()

smtg_add_vst3plugin(matsyn     
    source/version.h
    source/ryscids.h
    source/rysprocessor.h
    source/rysprocessor.cpp
    source/ryscontroller.h
    source/ryscontroller.cpp
    source/rysentry.cpp
)

#- VSTGUI Wanted ----
if(SMTG_ADD_VSTGUI)
    target_sources(matsyn
        PRIVATE
            resource/ryseditor.uidesc
    )
    target_link_libraries(matsyn
        PRIVATE
            vstgui_support
    )
    smtg_add_vst3_resource(matsyn "resource/ryseditor.uidesc")
endif()
# -------------------

smtg_add_vst3_snapshot(matsyn resource/9622B1A46C0550A4A7D93578E4C69140_snapshot.png)
smtg_add_vst3_snapshot(matsyn resource/9622B1A46C0550A4A7D93578E4C69140_snapshot_2.0x.png)

target_link_libraries(matsyn
    PRIVATE
        sdk
)

if(SMTG_MAC)
    set(CMAKE_OSX_DEPLOYMENT_TARGET 10.12)
    smtg_set_bundle(matsyn
		BUNDLE_IDENTIFIER com.rys.matsyn
		INFOPLIST "${CMAKE_CURRENT_LIST_DIR}/resource/Info.plist" PREPROCESS
    )
    smtg_set_debug_executable(matsyn
        "/Applications/VST3PluginTestHost.app"
        "--pluginfolder;$(BUILT_PRODUCTS_DIR)"
    )
elseif(SMTG_WIN)
    target_sources(matsyn PRIVATE 
        resource/win32resource.rc
    )
    if(MSVC)
        set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT matsyn)
    
        smtg_set_debug_executable(matsyn
            "$(ProgramW6432)/Steinberg/VST3PluginTestHost/VST3PluginTestHost.exe"
            "--pluginfolder \"$(OutDir)/\""
        )
    endif()
endif()
