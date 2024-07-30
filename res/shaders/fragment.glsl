#version 330 core

out vec4 FragColor;

in vec3 color;
in vec2 texCords;

uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{
    FragColor = mix(texture(texture1, texCords), texture(texture2, texCords), 0.2);
}