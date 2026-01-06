#version 450 core

in vec2 vUV;
out vec4 FragColor;

uniform sampler2D u_SceneTexture;
uniform float u_Threshold;   // np. 2.0 – 8.0

float luminance(vec3 c)
{
    return dot(c, vec3(0.2126, 0.7152, 0.0722));
}

void main()
{
    vec3 color = texture(u_SceneTexture, vUV).rgb;
    float lum = luminance(color);

    //HDR highlight extraction
    float highlight = max(lum - u_Threshold, 0.0);


    FragColor = vec4(color * highlight*2.5, 1.0);
}
