cmake_minimum_required(VERSION 3.29)
project(test)

set(CMAKE_CXX_STANDARD 20)

# Find SDL2 library
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(test main.cpp
        View/View.cpp
        View/View.h
        Controller/Controller.cpp
        Controller/Controller.h
        Model/Model.cpp
        Model/Model.h
        Model/World/World.cpp
        Model/World/World.h
        Model/World/Cell.cpp
        Model/World/Cell.h
        Model/World/Food.cpp
        Model/World/Food.h
        Model/World/Brain/Layer.cpp
        Model/World/Brain/Layer.h
        Model/World/Brain/Neuron.cpp
        Model/World/Brain/Neuron.h
        Model/World/Brain/Network.cpp
        Model/World/Brain/Network.h
        Model/World/Brain/ReceptiveField.cpp
        Model/World/Brain/ReceptiveField.h
        Model/World/Brain/Connection.cpp
        Model/World/Brain/Connection.h
        Model/World/Utils.cpp
        Model/World/Utils.h)

target_link_libraries(test ${SDL2_LIBRARIES})