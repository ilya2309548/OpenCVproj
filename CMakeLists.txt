cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Поиск пакета OpenCV
find_package(OpenCV REQUIRED)

# Добавление подпроектов
add_subdirectory(sources)
