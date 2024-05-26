cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Поиск пакета OpenCV
find_package(OpenCV REQUIRED)

# Добавление подпроектов
include_directories(include)

# Добавление исполняемого файла
add_executable(MyExecutable
	sources/main.cpp 
	sources/skelet.cpp 
	sources/findconturs.cpp
	sources/zhang_suen.cpp
	sources/sum.cpp
)

# Подключение OpenCV
target_link_libraries(MyExecutable ${OpenCV_LIBS})	
