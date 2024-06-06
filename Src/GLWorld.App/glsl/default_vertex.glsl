#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 colorInfo;
layout (location = 2) in vec2 aTexCoord;

out vec4 vertexColor;
out vec2 texCoord;

void main()
{
	mat4x4 scaleMat;
	float rotation = 3.14f;

	scaleMat[0].xyzw = vec4(1,0,0,0);
	scaleMat[1].xyzw = vec4(0,cos(rotation),-sin(rotation),0);
	scaleMat[2].xyzw = vec4(0,sin(rotation),cos(rotation),0);
	scaleMat[3].xyzw = vec4(0,0,0,1);


	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0) * scaleMat;
	vertexColor = vec4(colorInfo, 1);
	texCoord = vec2(aTexCoord);
}