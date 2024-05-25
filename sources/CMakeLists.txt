# Добавление исполняемого файла
add_executable(MyExecutable
	main.cpp 
	skelet.cpp 
	findconturs.cpp
	zhang_suen.cpp)

# Подключение OpenCV
target_link_libraries(MyExecutable ${OpenCV_LIBS})