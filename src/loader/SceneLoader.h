#pragma once
#include <string>
#include "scene/Scene.h"

class SceneLoader
{
public:
    static Scene loadGLTF(const std::string& path);
};
