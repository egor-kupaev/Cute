#version 330 core

// VERTEX SHADER

layout (location = 0) in vec3 Position;

uniform mat4 u_Model;
uniform mat4 u_View;
uniform mat4 u_Projection;

out vec3 VertexCoordinate;

void main()
{
    gl_Position = u_Projection * u_View * u_Model * vec4(Position, 1.0);
    VertexCoordinate = max(Position, 0.1);
}
