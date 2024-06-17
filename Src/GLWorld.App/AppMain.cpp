#include "common/common_def.h"
#include "shader/Shader.h"
#include "texture/Texture.h"

float vertices[] = {
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
};

float params[] = {
	1.2f, 2.3f
};

GLuint indices[] = {
	0, 1, 3, // first triangle
	1, 2, 3,  // second triangle
};

glm::vec3 cameraTarget(0.f, 0.f, 0.f);
glm::vec3 cameraPos(0.f, 0.f, 0.f);
glm::vec3 cameraUp(0.f, 1.f, 0.f);
float angle = 0.f;
float fov = FIELD_OF_VIEW_MINIMUM;

bool* did = new bool(0);

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) 
{
	if (yoffset > 0)
	{
		fov += SCROLL_STRIDE;
	}
	else
	{
		fov -= SCROLL_STRIDE;
	}

	if (fov + SCROLL_STRIDE > FIELD_OF_VIEW_MAXIMUM)
	{
		fov = FIELD_OF_VIEW_MAXIMUM;
	}
	else if (fov - SCROLL_STRIDE < FIELD_OF_VIEW_MINIMUM)
	{
		fov = FIELD_OF_VIEW_MINIMUM;
	}
}

void processInput(GLFWwindow* window)
{
	*did = 0;

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		float magnitude = glm::length(cameraPos);
		if (magnitude != 0)
		{
			cameraPos *= (magnitude - MOVE_STRIDE) / magnitude;
		}
		else
		{
			cameraPos.z += MOVE_STRIDE;
		}
		(*did)++;
	}

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		float length = glm::length(cameraPos);
		glm::vec3 cameraDirection = glm::normalize(cameraPos);

		angle += ROTATE_STRIDE;
		cameraDirection.x -= glm::sin(glm::radians(angle));
		cameraDirection.z += glm::cos(glm::radians(angle));

		cameraPos = cameraPos - (cameraDirection * length);

		(*did)++;
	}

	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		float magnitude = glm::length(cameraPos);
		if (magnitude != 0)
		{
			cameraPos *= (magnitude + MOVE_STRIDE) / magnitude;
		}
		else
		{
			cameraPos.z -= MOVE_STRIDE;
		}
		

		(*did)++;
	}

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)	
	{
		float length = glm::length(cameraPos);

		glm::vec3 cameraDirection = glm::normalize(cameraPos);

		angle += ROTATE_STRIDE;
		cameraDirection.x += glm::sin(glm::radians(angle));
		cameraDirection.z += glm::cos(glm::radians(angle));

		cameraPos = cameraPos - (cameraDirection * length);

		(*did)++;
	}

	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
	{
		system("cls");
		cameraPos.x = 0.f;
		cameraPos.y = 0.f;
		cameraPos.z = 0.f;
	}

	if (*did)
	{
		LOG("CameraPosX:" << cameraPos.x << ",CameraPosY:" << cameraPos.y << ",CameraZ:" << cameraPos.z);
	}
}

int main()
{
	if (!glfwInit())
	{
		LOG("Glfw init failed");
	}

	GLFWwindow* window = glfwCreateWindow(
		WINDOW_DEFAULT_WIDTH,
		WINDOW_DEFAULT_HEIGHT,
		APP_TITLE,
		NULL,
		NULL
	);


	glfwMakeContextCurrent(window);
	gladLoadGL(glfwGetProcAddress);
	glfwSwapInterval(1);
	setCallbacks(window);
	glClearColor(0.f, 0.f, 0.f, 1.f);

	Shader defaultShader(DEFAULT_VERTEX, DEFAULT_FRAGMENT);
	Texture defaultTexture(DEFAULT_TEXTURE);
	Texture secondTexture(SECOND_TEXTURE);

	GLuint vbo, vao, ebo;

	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);

	glBindVertexArray(vao);
	
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	int stride[] = {3,2};

	for (int i = 0; i < 2; i++)
	{
		glVertexAttribPointer(
			i, 
			stride[i],
			GL_FLOAT,
			GL_FALSE,
			5 * sizeof(GL_FLOAT),
			(void*)(i * (i  > 0 ? stride[i-1] : 0) * sizeof(float))
		);
		glEnableVertexAttribArray(i);
	}

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glEnable(GL_DEPTH_TEST);
	
	defaultShader.use();
	
	glBindVertexArray(vao);
	
	defaultTexture.use(GL_TEXTURE0);
	secondTexture.use(GL_TEXTURE1);

	defaultShader.setInt("userTex", 0);
	defaultShader.setInt("userTex2", 1);

	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		float time = glfwGetTime();
		float valueX = sin(time) / 0.2f + 0.2f;
		float valueY = sin(time) / 0.2f + 0.3f;
		float valueZ = sin(time) / 0.2f + 0.5f;

		if (valueX < -0.8f)
		{
			valueX = -0.5f;
			valueY = -0.5f;
			valueZ = -0.5f;
		}
		else if (valueX > 0.8)
		{
			valueX = 0.5f;
			valueY = 0.5f;
			valueZ = 0.5f;
		}

		glm::mat4 projection(1.f);
		glm::mat4 trans(1.f);
		float delta = sin(glfwGetTime()) * 2.f;

		projection = glm::perspective(glm::radians(fov), (float)WINDOW_DEFAULT_WIDTH / (float)WINDOW_DEFAULT_HEIGHT, 0.1f, 100.f);

		glm::mat4 view(1.f);

		if (abs(delta) > 1)
		{
			delta = 0.8 * (delta / abs(delta));
		}


		// view = glm::translate(view, glm::vec3(0,0, -abs(delta)));

		view = glm::lookAt(
			cameraPos,
			cameraTarget,
			cameraUp
		);
		
		defaultShader.setFloat3("userColor", 1.f, 1.f, delta);
		defaultShader.setFloatPtr("projection", glm::value_ptr(projection));
		defaultShader.setFloatPtr("view", glm::value_ptr(view));
		defaultShader.setFloatPtr("transform", glm::value_ptr(trans));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}