#include "utils.h"
#include <string.h>

// creating shader
unsigned int make_module(const char *filepath, unsigned int module_type)
{
  FILE *file = fopen(filepath, "r");

  char buffer[256];
  char *shaderSrc = malloc(1);

  shaderSrc[0] = '\0';

  if (shaderSrc == NULL)
  {
    fprintf(stderr, "Failed to allocate memory");
    fclose(file);
    return -1;
  }

  while (fgets(buffer, sizeof(buffer), file) != NULL)
  {
    size_t clen = strlen(shaderSrc);
    size_t llen = strlen(buffer);

    char *tmp = realloc(shaderSrc, clen + llen + 1);
    if (tmp == NULL)
    {
      fprintf(stderr, "Error reallocating memory\n");
      fclose(file);
      return -1;
    }

    shaderSrc = tmp;
    strcat(shaderSrc, buffer);
  }

  fclose(file);

  unsigned int shaderModule = glCreateShader(module_type);
  glShaderSource(shaderModule, 1, (const char **)&shaderSrc, NULL);
  glCompileShader(shaderModule);

  int success;
  glGetShaderiv(shaderModule, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    char errorLog[1024];
    glGetShaderInfoLog(shaderModule, 1024, NULL, errorLog);
    fprintf(stderr, "Failed to compile shaders\n");
  }
  return shaderModule;
}

// using shader
unsigned int make_shader(const char *vertex_filepath, const char *fragment_filepath)
{
}

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

  make_module("../src/shaders/vertex.glsl", GL_VERTEX_SHADER);

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
