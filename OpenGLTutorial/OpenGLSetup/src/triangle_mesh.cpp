#include "triangle_mesh.h"

TriangleMesh::TriangleMesh()
{
    // In openGL a vertex is the collection of all the attributes needed to draw a point
    std::vector<float> positions = {
        -1.0f, -1.0f, 0.0f,
        1.0f, -1.0f, 0.0f,
        -1.0f, 1.0f, 0.0f};

    std::vector<float> colorIndices = {0, 1, 2};
    vertex_count = 3;

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    VBOs.resize(2);

    glGenBuffers(1, &VBOs[0]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
    glBufferData(GL_ARRAY_BUFFER, positions.size() * sizeof(float), positions.data(), GL_STATIC_DRAW);

    // Position
    // position is attribute 0, stride = 3 * sizeof(float) = 12
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 12, (void *)0);
    glEnableVertexAttribArray(0);

    glGenBuffers(1, &VBOs[1]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
    glBufferData(GL_ARRAY_BUFFER, colorIndices.size() * sizeof(float), colorIndices.data(), GL_STATIC_DRAW);

    // Color
    // color is attribute 1
    glVertexAttribIPointer(1, 1, GL_INT, 4, (void *)0);
    glEnableVertexAttribArray(1);
}

void TriangleMesh::draw()
{
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, vertex_count);
}

TriangleMesh::~TriangleMesh()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(VBOs.size(), VBOs.data());
}