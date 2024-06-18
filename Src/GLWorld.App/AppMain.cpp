#include "common/common_def.h"
#include "shader/Shader.h"
#include "texture/Texture.h"
#include "asset/Asset.h"
#include "model/Model.h"

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

float vertices2[] = {
		-0.25f, -0.25f, -0.25f,
		 0.25f, -0.25f, -0.25f,
		 0.25f,  0.25f, -0.25f,
		 0.25f,  0.25f, -0.25f,
		-0.25f,  0.25f, -0.25f,
		-0.25f, -0.25f, -0.25f,

		-0.25f, -0.25f,  0.25f,
		 0.25f, -0.25f,  0.25f,
		 0.25f,  0.25f,  0.25f,
		 0.25f,  0.25f,  0.25f,
		-0.25f,  0.25f,  0.25f,
		-0.25f, -0.25f,  0.25f,

		-0.25f,  0.25f,  0.25f,
		-0.25f,  0.25f, -0.25f,
		-0.25f, -0.25f, -0.25f,
		-0.25f, -0.25f, -0.25f,
		-0.25f, -0.25f,  0.25f,
		-0.25f,  0.25f,  0.25f,

		 0.25f,  0.25f,  0.25f,
		 0.25f,  0.25f, -0.25f,
		 0.25f, -0.25f, -0.25f,
		 0.25f, -0.25f, -0.25f,
		 0.25f, -0.25f,  0.25f,
		 0.25f,  0.25f,  0.25f,

		-0.25f, -0.25f, -0.25f,
		 0.25f, -0.25f, -0.25f,
		 0.25f, -0.25f,  0.25f,
		 0.25f, -0.25f,  0.25f,
		-0.25f, -0.25f,  0.25f,
		-0.25f, -0.25f, -0.25f,

		-0.25f,  0.25f, -0.25f,
		 0.25f,  0.25f, -0.25f,
		 0.25f,  0.25f,  0.25f,
		 0.25f,  0.25f,  0.25f,
		-0.25f,  0.25f,  0.25f,
		-0.25f,  0.25f, -0.25f,
};

glm::vec3 cameraTarget(0.f, 0.f, 0.f);
glm::vec3 cameraPos(0.f, 0.f, 0.f);
glm::vec3 cameraUp(0.f, 1.f, 0.f);

glm::vec3 lightColor(0.33f, 0.42f, 0.18f);
glm::vec3 myColor(1.f, 0.5f, 0.31f);

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

void processMovement(GLFWwindow* window)
{
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
}

void processColorChange(GLFWwindow* window, glm::vec3* objectColor, glm::vec3* lightColor)
{
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
	{
		lightColor->x += 0.01f;
	}

	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
	{
		lightColor->x -= 0.01f;
	}
}

void processInput(GLFWwindow* window)
{
	*did = 0;

	processMovement(window);
	processColorChange(window, &myColor, &lightColor);

	if (*did)
	{
		LOG("CameraPosX:" << cameraPos.x << ",CameraPosY:" << cameraPos.y << ",CameraZ:" << cameraPos.z);
	}
}

int main()
{
	for (int i = 0; i < array_size(vertices2); i++)
	{
		vertices2[i] += 1.f;
	}

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
	Model* model1 = new Model("item1", vertices, array_size(vertices));
	Model* model2 = new Model("item2", vertices2, array_size(vertices2));
	

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glEnable(GL_DEPTH_TEST);
	
	

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

		view = glm::lookAt(
			cameraPos,
			cameraTarget,
			cameraUp
		);
		
		defaultShader.setFloat3Ptr("userColor", glm::value_ptr(myColor));
		defaultShader.setFloat3Ptr("lightColor", glm::value_ptr(lightColor));
		defaultShader.setFloatPtr("projection", glm::value_ptr(projection));
		defaultShader.setFloatPtr("view", glm::value_ptr(view));
		defaultShader.setFloatPtr("transform", glm::value_ptr(trans));
		model1->use(&defaultTexture, &defaultShader);
		glDrawArrays(GL_TRIANGLES, 0, 36);
		model2->use(&defaultTexture, &defaultShader);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}