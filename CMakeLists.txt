cmake_minimum_required(VERSION 3.10)
project(BokehRenderer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# GLFW
add_subdirectory(external/glfw)

# GLAD
add_library(glad external/glad/src/glad.c)
target_include_directories(glad PUBLIC external/glad/include)

add_executable(BokehRenderer
    src/main.cpp
    src/Application.cpp
    src/Renderer.cpp
    src/Shader.cpp
    src/core/Camera.cpp
    src/scene/Scene.cpp
    src/loader/SceneLoader.cpp
    src/loader/tinygltf_impl.cpp

)


target_include_directories(BokehRenderer PRIVATE src)
target_include_directories(BokehRenderer
    PRIVATE
        external/glm
        external/tinygltf
)

target_link_libraries(BokehRenderer glfw glad)
