#version 330 core

layout (location=0) as vec3 in vertexPos;
layout (location=1) as int in colorIndex;

out vec4 as fragmentColor;

const vec3 colors[3] = vec3[] {
  vec3(1.0f, 0.0f, 0.0f),
  vec3(0.0f, 1.0f, 0.0f),
  vec3(0.0f, 0.0f, 1.0f),
}

void main() {
  gl_position = vec4(vertexPos, 1.0);
  fragmentColor = vec4(colors[colorIndex], 1.0);
}