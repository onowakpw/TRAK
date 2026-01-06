#pragma once
#include <glad/glad.h>
#include <glm/glm.hpp>

struct SceneObject
{

    GLuint vao = 0;

    GLuint vbo = 0;   // POSITION
    GLuint nbo = 0;   // NORMAL
    GLuint tbo = 0;   // TEXCOORD_0 (UV)
    GLuint ebo = 0;   // INDICES


    unsigned int indexCount = 0;
    unsigned int indexType = 0;

    glm::mat4 model = glm::mat4(1.0f);

    GLuint emissiveTexture = 0;
    float emissiveStrength = 1.0f;
    glm::vec3 emissiveColor = glm::vec3(0.0f);




    GLuint albedoTexture = 0;
    GLuint normalTexture = 0;
    GLuint metallicRoughnessTexture = 0;
};
