cmake_minimum_required(VERSION 3.15)
project(app)

# 搜索源文件
aux_source_directory(./ SRC)
# 头文件包含路径
include_directories(${HEADPATH})
# 指定动/静态库路径
link_directories(${LIBPATH})
# 可执行文件输出路径
set(EXECUTABLE_OUTPUT_PATH ${EXECPATH})
# 生成可执行文件
add_executable(${APPNAME} ${SRC})
# 链接动态库
target_link_libraries(${APPNAME} ${FILELIB} ${COSTRUCTLIB})