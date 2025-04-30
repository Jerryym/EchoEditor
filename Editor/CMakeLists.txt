# CMakeList.txt: Editor 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required(VERSION 3.16)

project(Editor VERSION ${EDITOR_VERSION} LANGUAGES CXX)

# 定义头文件列表
set(EDITOR_HEADERS
	# GUI
	src/GUI/MainWindow.h
)

# 定义源文件列表
set(EDITOR_SOURCES
	# GUI
	src/GUI/MainWindow.cpp

	src/main.cpp
)

# 定义资源文件
SET(EDITOR_RESOURCE
    res/Resource.qrc
)

add_executable(Editor
	${EDITOR_HEADERS}
	${EDITOR_SOURCES}
	${EDITOR_RESOURCE}
)

set_target_properties(Editor PROPERTIES OUTPUT_NAME "EchoEditor")

# 预编译头文件
target_precompile_headers(Editor PRIVATE src/editorpch.h)

# 添加目录
target_include_directories(Editor PUBLIC
	${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(Editor PUBLIC NestApp)
target_link_libraries(Editor PUBLIC NestUI)
target_link_libraries(Editor PUBLIC
    Qt${QT_VERSION_MAJOR}::Core 
    Qt${QT_VERSION_MAJOR}::Gui
    Qt${QT_VERSION_MAJOR}::Widgets
)

# 设置目标属性
include(GNUInstallDirs)
set_target_properties(Editor PROPERTIES
	AUTOMOC ON
    AUTORCC ON
    AUTOUIC ON
	CXX_EXTENSIONS OFF
	DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX}
	VERSION ${EDITOR_VERSION}
	EXPORT_NAME EchoEditor
	
	# Debug
	RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/../bin/Debug-windows-x86_64/EchoEditor
	ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/../bin/Debug-windows-x86_64/EchoEditor
	LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/../bin/Debug-windows-x86_64/EchoEditor

	# Release
	RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/../bin/Release-windows-x86_64/EchoEditor
	ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/../bin/Release-windows-x86_64/EchoEditor
	LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/../bin/Release-windows-x86_64/EchoEditor
)

# 设置Visual Studio的文件树结构
file(GLOB Base_SRC "src/*.h" "src/*.cpp")
file(GLOB GUI_SRC "src/GUI/*.h" "src/GUI/*.cpp")
source_group("src" FILES ${Base_SRC})
source_group("src/GUI" FILES ${GUI_SRC})

# 设置生成后事件
add_custom_command(
    TARGET Editor POST_BUILD

    # 复制NestApp的DLL文件到相应的文件夹
    COMMAND ${CMAKE_COMMAND} -E copy
    $<TARGET_FILE:NestApp> # 获取生成的 DLL 文件
    $<IF:$<CONFIG:Debug>,${CMAKE_BINARY_DIR}/bin/Debug-windows-x86_64/EchoEditor/NestAppd.dll,${CMAKE_BINARY_DIR}/bin/Release-windows-x86_64/EchoEditor/NestApp.dll>

	# 复制SARibbon的DLL文件到相应的文件夹
	COMMAND ${CMAKE_COMMAND} -E copy
    $<TARGET_FILE:SARibbonBar> # 获取生成的 DLL 文件
    $<IF:$<CONFIG:Debug>,${CMAKE_BINARY_DIR}/bin/Debug-windows-x86_64/EchoEditor/SARibbonBard.dll,${CMAKE_BINARY_DIR}/bin/Release-windows-x86_64/EchoEditor/SARibbonBar.dll>

    # 复制NestUI的DLL文件到相应的文件夹
    COMMAND ${CMAKE_COMMAND} -E copy
    $<TARGET_FILE:NestUI> # 获取生成的 DLL 文件
    $<IF:$<CONFIG:Debug>,${CMAKE_BINARY_DIR}/bin/Debug-windows-x86_64/EchoEditor/NestUId.dll,${CMAKE_BINARY_DIR}/bin/Release-windows-x86_64/EchoEditor/NestUI.dll>

    VERBATIM
)
