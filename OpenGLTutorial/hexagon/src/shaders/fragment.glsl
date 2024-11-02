#version 330 core

layout (location=0) in vec4 fragmentColor;

out vec4 screenColor;

void main() {
  screenColor = fragmentColor;
}