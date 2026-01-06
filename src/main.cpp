#include "Application.h"
#include "scene/Scene.h"
#include "loader/SceneLoader.h"

int main()
{
    Application app;
    app.run();

    Scene scene = SceneLoader::loadGLTF("../assets/Duck/Duck.gltf");


    return 0;
}
