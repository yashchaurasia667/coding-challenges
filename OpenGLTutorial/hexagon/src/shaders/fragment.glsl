#version 330 core

layout (location=0) as vec4 in fragmentColor;

out vec4 as screenColor;

void main() {
  screenColor = fragmentColor;
}