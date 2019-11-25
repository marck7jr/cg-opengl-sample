#include <GLFW/glfw3.h>

void my_draw(void (*f)()) {
	(*f)();
}

void my_ScreenCordinates() {
	float positions[7][2] = {
		{0, 0.9}, // superior
		{-0.9, 0.9}, // superior esquerdo
		{0.9, 0.9}, // superior direito
		{0, 0}, // centro
		{0, -0.9}, // inferior
		{-0.9, -0.9}, // inferior esquerdo
		{0.9, -0.9} // inferior direito
	};

	glColor3f(1, 1, 1);
	glPointSize(10);
	for (int i = 0; i < 7; i++) {
		glBegin(GL_POINTS);
		glVertex2f(positions[i][0], positions[i][1]);
		glEnd();
	}
}

void my_House_Window_Detail(float x, float y, float height, float width) {
	glBegin(GL_QUADS);
	glVertex2f(x, y);
	glVertex2f(x + width, y);
	glVertex2f(x + width, y + height);
	glVertex2f(x, y + height);
	glEnd();
}

void my_House_Window(float x, float y) {
	float z1 = 0.4, z2 = 0.2, z3 = 0.1;

	glColor3ub(197, 91, 17);
	my_House_Window_Detail(x, y, z1, z2);
	glColor3ub(248, 203, 172);
	my_House_Window_Detail(x, y, z2, z3);
	my_House_Window_Detail(x + z3, y + z2, z2, z3);
}

void my_House() {

	glColor3f(1, 1, 1); // Background branco
	glBegin(GL_QUADS);
	glVertex2f(-1, -1);
	glVertex2f(-1, 1);
	glVertex2f(1, 1);
	glVertex2f(1, -1);
	glEnd();

	glColor3ub(248, 203, 172); 
	glBegin(GL_QUADS); // Casa - entrada
	glVertex2f(-0.9, -0.9);
	glVertex2f(-0.9, 0);
	glVertex2f(-0.5, 0);
	glVertex2f(-0.5, -0.9);
	glEnd();

	glBegin(GL_TRIANGLES); // Casa - entrada - telhado
	glVertex2f(-0.9, 0);
	glVertex2f(-0.7, 0.4);
	glVertex2f(-0.5, 0);
	glEnd();

	glColor3ub(197, 91, 17);
	glBegin(GL_QUADS); // Casa - porta
	glVertex2f(-0.8, -0.9);
	glVertex2f(-0.6, -0.9);
	glVertex2f(-0.6, -0.1);
	glVertex2f(-0.8, -0.1);
	glEnd();

	glPointSize(10);
	glColor3ub(248, 203, 172); 
	glBegin(GL_POINTS); // Casa - porta - maçaneta
	glVertex2f(-0.62, -0.45);
	glEnd();
	
	glColor3ub(244, 177, 132); // Casa - lateral
	glBegin(GL_QUADS);
	glVertex2f(-0.5, -0.9);
	glVertex2f(0.9, -0.9);
	glVertex2f(0.9, 0);
	glVertex2f(-0.5, 0);
	glEnd();

	glColor3ub(197, 91, 17);
	glBegin(GL_QUADS); // Casa - telhado
	glVertex2f(-0.7, 0.4);
	glVertex2f(0.9, 0.4);
	glVertex2f(0.9, 0);
	glVertex2f(-0.5, 0);
	glEnd();

	glColor3ub(197, 91, 17);
	glBegin(GL_QUADS); // Casa - Janela - base
	glVertex2f(-0.4, -0.5);
	glVertex2f(-0.2, -0.5);
	glVertex2f(-0.2, -0.1);
	glVertex2f(-0.4, -0.1);
	glEnd();

	my_House_Window(-0.4, -0.5);
	my_House_Window(0, -0.5);
	my_House_Window(0.4, -0.5);
}

int main(void)
{
	/* Initialize the library */
	if (!glfwInit())
		return -1;


	GLFWmonitor* monitor = glfwGetPrimaryMonitor();

	const GLFWvidmode* mode = glfwGetVideoMode(monitor);
	glfwWindowHint(GLFW_RED_BITS, mode->redBits);
	glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
	glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
	glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
	GLFWwindow* window = glfwCreateWindow(mode->width, mode->height, "OpenGL", monitor, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		my_draw(my_House);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}