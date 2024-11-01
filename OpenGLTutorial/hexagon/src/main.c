#include "utils.h"

int main()
{
  int width = 800, height = 600;
  GLFWwindow *window;

  glfwSetErrorCallback(errorCallback);

  if (initGLFW(&window) != 0)
  {
    fprintf(stderr, "Something went wrong");
    return -1;
  }

  if (initGlad(&window) != 0)
  {
    fprintf(stderr, "Couldn't initialize glad\n");
    return -1;
  }

  glClearColor(0.0235f, 0.2784f, 0.1098f, 1.0f);

  while (!glfwWindowShouldClose(window))
  {
    glClear(GL_COLOR_BUFFER_BIT);
    glfwPollEvents();
    glfwSwapBuffers(window);
  }

  glfwDestroyWindow(window);
  glfwTerminate();

  return 0;
}
