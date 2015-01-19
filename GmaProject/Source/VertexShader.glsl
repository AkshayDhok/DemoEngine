#version 330 core

layout(location = 0) in vec3 vertexPosition_modelspace;

// "1" here equals the "1" in glVertexAttribPointer
layout(location = 1) in vec3 vertexColor;

// Output data
out vec3 fragmentColor;

// Model View Project values.
uniform mat4 MVP;

void main(){

	// Output position of the vertex is : MVP * position
	vec4 v = vec4(vertexPosition_modelspace, 1); // 1 indicate identity matrix
    gl_Position =  MVP * v;  

	fragmentColor = vertexColor;
 }