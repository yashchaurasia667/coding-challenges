#include "config.h"

int main() {
  if (!glfwInit()) {
    std::cout << "GLFW couldn't start" << std::endl;
    return -1;
  }

  GLFWwindow *window =
      glfwCreateWindow(800, 600, "hello world", nullptr, nullptr);

  if (!window) {
    std::cout << "GLFW couldn't create a window" << std::endl;
    return -1;
  }

  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    glfwDestroyWindow(window);
    glfwTerminate();
    return -1;
  }

  glClearColor(0.25f, 0.5f, 0.75f, 1.0f);

  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
  }

  glfwTerminate();

  return 0;
}