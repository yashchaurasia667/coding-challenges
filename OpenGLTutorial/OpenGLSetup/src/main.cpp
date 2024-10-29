#include "config.h"

void frameBufferSizeCallback(GLFWwindow *window, int width, int height) {
  glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true);
  }
}

unsigned int make_modules(const std::string &filepath,
                          unsigned int module_type) {
  std::ifstream file;
  std::stringstream bufferedLines;
  std::string line;

  file.open(filepath);
  while (std::getline(file, line)) {
    bufferedLines << line << "\n";
  }
  std::string shaderSource = bufferedLines.str();
  const char *shaderSrc = shaderSource.c_str();
  bufferedLines.str("");
  file.close();

  unsigned int shaderModule = glCreateShader(module_type);
  glShaderSource(shaderModule, 1, &shaderSrc, NULL);
  glCompileShader(shaderModule);

  int success;
  glGetShaderiv(shaderModule, GL_COMPILE_STATUS, &success);
  if (!success) {
    char errorLog[1024];
    glGetShaderInfoLog(shaderModule, 1024, NULL, errorLog);
    std::cout << "Shader Module compilation error: \n" << errorLog << std::endl;
  }

  return shaderModule;
}

int main() {
  std::ifstream file;
  std::string line;

  file.open("../src/shaders/vertex.txt");
  while (std::getline(file, line)) {
    std::cout << line << std::endl;
  }

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
  glfwSetFramebufferSizeCallback(window, frameBufferSizeCallback);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to load OpenGL function pointers" << std::endl;
    glfwDestroyWindow(window);
    glfwTerminate();
    return -1;
  }

  glClearColor(0.25f, 0.5f, 0.75f, 1.0f);

  while (!glfwWindowShouldClose(window)) {
    processInput(window);
    glfwPollEvents();
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
  }

  glfwTerminate();

  return 0;
}