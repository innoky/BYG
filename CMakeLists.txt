cmake_minimum_required(VERSION 3.10)
project(Parametric3D)

set(CMAKE_CXX_STANDARD 17)

# Находим Vulkan (это работает)
find_package(Vulkan REQUIRED)

# Жестко подключаем GLFW (заголовки уже у тебя есть)
include_directories(/usr/include/GLFW)
link_libraries(glfw)

# Основной исполняемый файл
add_executable(Parametric3D
    main.cpp
)

# Линкуем Vulkan и GLFW
target_link_libraries(Parametric3D
    Vulkan::Vulkan
    glfw
)
