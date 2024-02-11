#include "graphics_manager.hpp"


GraphicsManager::GraphicsManager(int width_, int height_, const char* title_)
width(width_), height(height_), title(title_) {}

void GraphicsManager::init()
{
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        exit(EXIT_FAILURE);
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

     GLFWwindow* window = glfwCreateWindow(SCR_width, SCR_height, "Wave animation", nullptr, nullptr); // Window
    //GLFWwindow* window2 = glfwCreateWindow(800, 600, "OpenGL", glfwGetPrimaryMonitor(), nullptr); // Fullscreen
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    framebuffer_size_callback(window, SCR_width, SCR_height);
    glewExperimental = GL_TRUE;
    if (!glewInit())
    {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        exit(EXIT_FAILURE);
    }

      // build and compile our shader program
    // ------------------------------------
    Shader ourShader = ResourceManager::LoadShader("shader.vs", "shader.fs", nullptr, "wave");
     ourShader.Use();

   
    
    TextRenderer  *Text;
    Text = new TextRenderer(1000, 1000);
    Text->Load("a_ReportSansRgh.ttf", 24);


    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glEnable(GL_DEPTH_TEST); 
    // -------------------------------------------------------------------------------------------

    //shader uniform 
    ourShader.SetVector4f("ourColor", {0.0f, 0.8f, 1.0f, 1.0f}, true);

    
}


GraphicsManager::~GraphicsManager()
{
    glfwTerminate();
}
