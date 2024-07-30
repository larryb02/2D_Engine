#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aCords;

out vec2 texCords;

uniform mat4 transform;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * model * vec4(aPos, 1.0f); 
    texCords = vec2(aCords.x, aCords.y);
}