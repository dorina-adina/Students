cmake_minimum_required(VERSION 3.24)
project(untitled1)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled1 main.cpp Models/Entitate.h Models/Entitate.cpp Repos/Repository.h Repos/Repository.h Repos/Repository.cpp Repos/RepoFile.h Repos/RepoFile.cpp Servicies/Service.cpp Servicies/Service.h UI/UI.cpp UI/UI.h Utils/Validator.cpp Utils/Validator.h Utils/MyCustomNumberException.h Utils/MyCustomNumberException.cpp Utils/MyGeneralException.cpp Tests/Tests.h Tests/Tests.cpp Tests/Tests.cpp)
