cmake_minimum_required(VERSION 3.5)

project(qt-mvvm LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)


add_executable(qt-mvvm
    src/main.cpp
    src/view.cpp
    src/model.cpp
    src/view_model.cpp
    src/vm_helper.cpp
    src/app_manager.cpp
    src/config.cpp
)

target_link_libraries(qt-mvvm PRIVATE Qt5::Widgets)
