# CMakeList.txt: проект CMake для src; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)
 
# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()
 
project (otpisp1)
 
# Добавьте источник в исполняемый файл этого проекта.
add_executable (otpisp1  "tovar.cpp" "Tovarka.h" "main.cpp")
 
set(CMAKE_CXX_STANDARD 11)
 
# TODO: Добавьте тесты и целевые объекты, если это необходимо.
