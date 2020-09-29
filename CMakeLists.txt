cmake_minimum_required(VERSION 3.17)
project(BlackHole)

set(CMAKE_CXX_STANDARD 17)

set(SFML_DIR "C:/Libraries/SFML-2.5.1/lib/cmake/SFML")
set(SFML_STATIC_LIBRARIES TRUE)

find_package(SFML 2.5 COMPONENTS system window graphics)

add_executable(${PROJECT_NAME} main.cpp Drawer.cpp Drawer.h Utilities/Vector2.cpp Utilities/Vector2.h Objects/BlackHole.cpp Objects/BlackHole.h Objects/Photon.cpp Objects/Photon.h)

target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics -static)