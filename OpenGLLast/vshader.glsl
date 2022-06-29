#version 330 core

layout (location = 0 ) in vec3 apos;

layout (location = 1 ) in vec2 tcoord;
out vec2 fcoord;

//uniform float xoffset;
//uniform mat4 transform;

uniform mat4 model;
uniform mat4 view;
uniform mat4 perspective;
//same order perspective for depth of shape , model to move object to look more pivoted and to view from distance
void main(){

    gl_Position = perspective * view * model * vec4(apos , 1.0);
    fcoord =tcoord;
    
}