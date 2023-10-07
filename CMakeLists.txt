# https://subingwen.cn/cmake/CMake-primer/
cmake_minimum_required(VERSION 3.15)
project(CStruct)   # 工程名
# 定义变量
# 静态库生成路径
set(LIBPATH ${PROJECT_SOURCE_DIR}/lib)
# 可执行程序的存储路径
set(EXECPATH ${PROJECT_SOURCE_DIR}/bin)
# 头文件路径
set(HEADPATH ${PROJECT_SOURCE_DIR}/include)
# 库文件名字
set(FILELIB file)
set(COSTRUCTLIB commonstruct)
# set(CH5LIB ch5)
# set(CH6LIB ch6)
# set(CH8LIB ch8)
# 可执行程序的名字
set(APPNAME app)

# 给当前节点添加子目录
add_subdirectory(File)
add_subdirectory(app)
add_subdirectory(commonstruct)
# add_subdirectory(ch5)
# add_subdirectory(ch6)
# add_subdirectory(ch8)