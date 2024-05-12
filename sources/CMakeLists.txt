# Добавление исполняемого файла
add_executable(MyExecutable main.cpp)

# Подключение OpenCV
target_link_libraries(MyExecutable ${OpenCV_LIBS})