#version 450 core

in vec2 vUV;
out vec4 FragColor;

uniform sampler2D u_ColorTexture;
uniform sampler2D u_DepthTexture;
uniform vec2 u_Resolution;

uniform float u_FocusDepth;   // np. 0.35
uniform float u_BlurStrength; // np. 5.0 – 30.0

void main()
{
    float depth = texture(u_DepthTexture, vUV).r;
    vec3 sharp = texture(u_ColorTexture, vUV).rgb;


    float coc = max(depth - u_FocusDepth, 0.0);

 
    float radiusPx = coc * u_BlurStrength * 20.0;

    if (radiusPx < 0.5)
    {
        FragColor = vec4(sharp, 1.0);
        return;
    }

    vec2 texel = 1.0 / u_Resolution;

    vec3 sum = vec3(0.0);
    float count = 0.0;

    for (int x = -4; x <= 4; ++x)
    {
        for (int y = -4; y <= 4; ++y)
        {
            vec2 offset = vec2(x, y) * texel * radiusPx * 0.15;
            sum += texture(u_ColorTexture, vUV + offset).rgb;
            count += 1.0;
        }
    }

    vec3 blurred = sum / count;

    FragColor = vec4(blurred, 1.0);
}
