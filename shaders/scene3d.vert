#version 450 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoord;

uniform mat4 u_MVP;
uniform mat4 u_Model;   

out vec3 vNormal;
out vec2 vUV;

void main()
{
   
    vNormal = mat3(transpose(inverse(u_Model))) * aNormal;

    vUV = aTexCoord;
    gl_Position = u_MVP * vec4(aPos, 1.0);
}
