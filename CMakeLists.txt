cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Поиск пакета OpenCV
find_package(OpenCV REQUIRED)

# Добавление подпроектов
include_directories(${CMAKE_SOURCE_DIR}/include)

# Добавление исполняемого файла
add_executable(MyExecutable
	sources/main.cpp  
	sources/zhang_suen.cpp
	sources/my_function.cpp
	sources/skeletonization.cpp
	sources/zhang_suen.cpp
	sources/remove_corner_pixels.cpp
	sources/guo_hall.cpp

)

# Подключение OpenCV
target_link_libraries(MyExecutable ${OpenCV_LIBS})	
