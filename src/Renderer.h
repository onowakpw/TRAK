#pragma once
#include "Shader.h"
#include "core/Camera.h"
#include "scene/Scene.h"


class Renderer
{
public:
    Renderer();
    ~Renderer();

    void init();
    void render();

    unsigned int m_VAO;
    unsigned int m_VBO;

    Camera* getCamera() { return m_Camera; }
    Shader* m_BokehShader = nullptr;



    unsigned int m_CubeVAO;
    unsigned int m_CubeVBO;
    Shader* m_Scene3DShader;
    Shader* m_FinalShader;
    unsigned int m_BokehFBO;
    unsigned int m_BokehTexture;
        

    Shader* m_SceneShader;
    Shader* m_ScreenShader;

    unsigned int m_FBO;
    unsigned int m_ColorTexture;
    unsigned int m_DepthTexture;

    unsigned int m_HighlightFBO;
    unsigned int m_HighlightTexture;
    Shader* m_HighlightShader;

    unsigned int m_DOFFBO;
    unsigned int m_DOFTexture;
    Shader* m_DOFShader;
    GLuint m_ApertureTexture;

    GLuint m_SceneFBO;
    GLuint m_SceneColor;
    GLuint m_SceneDepth;




private:
    Camera* m_Camera;
    Scene m_Scene;
    
};
