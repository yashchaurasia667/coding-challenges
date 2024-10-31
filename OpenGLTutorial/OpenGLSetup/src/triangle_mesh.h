#include "config.h"

class TriangleMesh
{
public:
    TriangleMesh();
    void draw();
    ~TriangleMesh();

    // VBO -> Vertex Buffer Object
    // VAO -> Vertex Array Object
private:
    unsigned int VAO, vertex_count;
    std::vector<unsigned int> VBOs;
};