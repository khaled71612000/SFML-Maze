#version 330 core

out vec4 fragColor;
in vec2 fcoord;

uniform vec3 fcolor;

//sampler 2d a built in varaible 
uniform sampler2D texture1;

void main()
{

    fragColor = texture(texture1 ,  fcoord);
    //fragColor = vec4(fcoord.x , fcoord.y , 1 , 1.0);

}