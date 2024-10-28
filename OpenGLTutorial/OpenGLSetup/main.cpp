#include<GLFW/glfw3.h>

int main() {
	if (!glfwInit())
		return -1;

	GLFWwindow* window = glfwCreateWindow(640, 480, "OpenGL Tutorial", NULL, NULL);
	if (!window) {
		glfwTerminate();
		return -1;
	}


	return 0;
}