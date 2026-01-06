#version 450 core

in vec2 vUV;
out vec4 FragColor;

uniform sampler2D u_DOFTexture;
uniform sampler2D u_BokehTexture;

void main()
{
    vec3 dofColor   = texture(u_DOFTexture, vUV).rgb;
    vec3 bokehColor = texture(u_BokehTexture, vUV).rgb;


    vec3 color = dofColor + bokehColor;

    FragColor = vec4(color, 1.0);
}
