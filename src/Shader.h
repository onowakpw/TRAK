#pragma once
#include <string>

class Shader
{
public:
    Shader(const std::string& vertexPath,
           const std::string& fragmentPath);
    ~Shader();

    void bind() const;
    void unbind() const;
    unsigned int getID() const { return m_ID; }


private:
    unsigned int m_ID;
    std::string loadFile(const std::string& path);
};
