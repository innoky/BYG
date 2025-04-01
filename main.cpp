#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <iostream>

int main()
{
    // 1. Инициализация GLFW
    if (!glfwInit())
    {
        std::cerr << "Ошибка инициализации GLFW\n";
        return -1;
    }

    // 2. Говорим GLFW, что OpenGL не нужен
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    // 3. Создание окна
    GLFWwindow *window = glfwCreateWindow(800, 600, "Vulkan готов, сэр!", nullptr, nullptr);
    if (!window)
    {
        std::cerr << "Не удалось создать окно\n";
        glfwTerminate();
        return -1;
    }

    // 4. Создание Vulkan Instance
    VkInstance instance;

    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Vulkan Проба";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "Никакого движка";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    // Получаем расширения от GLFW
    uint32_t glfwExtensionCount = 0;
    const char **glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;
    createInfo.enabledExtensionCount = glfwExtensionCount;
    createInfo.ppEnabledExtensionNames = glfwExtensions;
    createInfo.enabledLayerCount = 0;

    if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS)
    {
        std::cerr << "Не удалось создать Vulkan instance\n";
        return -1;
    }

    VkSurfaceKHR surface;
    if (glfwCreateWindowSurface(instance, window, nullptr, &surface) != VK_SUCCESS)
    {
        std::cerr << "Не удалось создать surface!\n";
        return -1;
    }
    // 5. Цикл обработки окна
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
    }

    // 6. Завершение
    vkDestroyInstance(instance, nullptr);
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
