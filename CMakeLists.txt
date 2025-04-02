cmake_minimum_required(VERSION 3.10)
project(Parametric3D)

set(CMAKE_CXX_STANDARD 17)

# Находим Vulkan
find_package(Vulkan REQUIRED)

# Указываем папку с заголовками (включая vulkan/VulkanApp.hpp)
include_directories(include)

# Добавляем GLFW (если не через find_package)
include_directories(/usr/include/GLFW)
link_libraries(glfw)

# Добавляем исходники
add_executable(Parametric3D
    main.cpp
    src/vulkan/VulkanApp.cpp   # ← вот это обязательно!
)

# Линкуем Vulkan и GLFW
target_link_libraries(Parametric3D
    Vulkan::Vulkan
    glfw
)
