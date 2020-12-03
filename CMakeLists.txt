cmake_minimum_required(VERSION 3.17)
project(POO)

set(CMAKE_CXX_STANDARD 11)

set(SFML_STATIC_LIBRARIES TRUE)


add_executable(POO main.cpp Clase/Harta.cpp)
#Clase/Harta.cpp Clase/Enemy.cpp Clase/Tower.cpp)

set(SFML_DIR C:/Stuff/Programe/SFML-2.5.1/bin)

target_include_directories(POO PUBLIC ${SFML_DIR}/../include)
target_link_directories(POO PUBLIC ${SFML_DIR}/../lib)
target_link_libraries(POO sfml-graphics sfml-window sfml-system )
