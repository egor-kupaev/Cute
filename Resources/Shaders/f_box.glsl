#version 330 core

// FRAGMENT SHADER

in vec3 VertexCoordinate;

out vec4 FragmentColor;

void main()
{
    FragmentColor = vec4(VertexCoordinate, 1.0);
}
