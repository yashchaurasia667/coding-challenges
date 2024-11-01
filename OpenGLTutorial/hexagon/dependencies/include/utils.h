#include <stdio.h>
#include <stdlib.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#ifndef UTILS_H
#define UTILS_H

void errorCallback(int error, const char *description);
int initGLFW(GLFWwindow **window);
int initGlad();
void frameBufferCallback(GLFWwindow *window, int width, int height);

#endif