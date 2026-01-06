#version 450 core

in vec2 vUV;
out vec4 FragColor;


uniform sampler2D u_ScreenTexture;

void main()
{
    FragColor = texture(u_ScreenTexture, vUV);
}
