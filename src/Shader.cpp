#include "Shader.h"
#include <glad/glad.h>
#include <fstream>
#include <sstream>
#include <iostream>

static bool checkCompileErrors(unsigned int shader, const std::string& type)
{
    int success;
    char infoLog[1024];

    if (type != "PROGRAM")
    {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(shader, 1024, nullptr, infoLog);
            std::cerr << "SHADER COMPILATION ERROR (" << type << ")\n"
                      << infoLog << std::endl;
            return false;
        }
    }
    else
    {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(shader, 1024, nullptr, infoLog);
            std::cerr << "PROGRAM LINKING ERROR\n"
                      << infoLog << std::endl;
            return false;
        }
    }
    return true;
}

std::string Shader::loadFile(const std::string& path)
{
    std::cout << "[SHADER LOAD] " << path << std::endl;

    std::ifstream file(path);
    if (!file.is_open())
    {
        std::cerr << "FAILED TO OPEN SHADER FILE: " << path << std::endl;
        return "";
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}


Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath)
{
    std::string vertSrc = loadFile(vertexPath);
    std::string fragSrc = loadFile(fragmentPath);

    if (vertSrc.empty() || fragSrc.empty())
    {
        std::cerr << "Shader source empty!" << std::endl;
        return;
    }

    const char* vSrc = vertSrc.c_str();
    const char* fSrc = fragSrc.c_str();

    unsigned int vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &vSrc, nullptr);
    glCompileShader(vs);
    if (!checkCompileErrors(vs, "VERTEX")) return;

    unsigned int fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &fSrc, nullptr);
    glCompileShader(fs);
    if (!checkCompileErrors(fs, "FRAGMENT")) return;

    m_ID = glCreateProgram();
    glAttachShader(m_ID, vs);
    glAttachShader(m_ID, fs);
    glLinkProgram(m_ID);
    if (!checkCompileErrors(m_ID, "PROGRAM")) return;

    glDeleteShader(vs);
    glDeleteShader(fs);
}

Shader::~Shader()
{
    glDeleteProgram(m_ID);
}

void Shader::bind() const
{
    glUseProgram(m_ID);
}

void Shader::unbind() const
{
    glUseProgram(0);
}
