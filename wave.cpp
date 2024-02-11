#include <fmt/ranges.h>
#include <algorithm>
#include <array>
#include <numeric>
#include <ranges>
#include <vector>
#include <cmath>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <chrono>
#include <random>


#include "shader.h"
#include "resource_manager.h"
#include "textRenderer.h"

namespace stdv = std::ranges::views;
namespace rng = std::ranges;
template<typename T> struct Point
{
    T x,y,z,d;
    Point normalize() const
    {
        using std::sqrt;
        const auto scale = 1/sqrt(x*x + y*y + z*z);
        return {x*scale, y*scale, z*scale};
    }
};

template<typename T>
std::vector<Point<T>> generateRandomPoints(std::size_t n)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<T> dis(-10.0, 10.0);
    std::uniform_real_distribution<T> dis2(-100, 100);
    std::vector<Point<T>> points(n);

    auto generatePoint = [&]() -> Point<T> {
        return {dis2(gen), dis2(gen), dis(gen), 0};
    };

    std::generate(points.begin(), points.end(), generatePoint);

    return points;
}



void processInput(GLFWwindow *window, float &distanceCamera, float &angleRotateXachsis, float &angleRotateYachsis, double &gameTimeFactor )
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
    {
        distanceCamera += 1.0f; // change this value accordingly (might be too slow or too fast based on system hardware)
        
    }
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
    {
        distanceCamera -= 1.0f; // change this value accordingly (might be too slow or too fast based on system hardware)
    }
     if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    {
        angleRotateXachsis -= 1.0f; // change this value accordingly (might be too slow or too fast based on system hardware)
        
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    {
        angleRotateXachsis += 1.0f; // change this value accordingly (might be too slow or too fast based on system hardware)
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    {
        angleRotateYachsis -= 1.0f; // change this value accordingly (might be too slow or too fast based on system hardware)
        
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
        angleRotateYachsis += 1.0f; // change this value accordingly (might be too slow or too fast based on system hardware)
    }
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
    {
        gameTimeFactor /= 1.1f; // change this value accordingly (might be too slow or too fast based on system hardware)
        
    }
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
    {
        gameTimeFactor *= 1.1f; // change this value accordingly (might be too slow or too fast based on system hardware)
    }
}
// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}


template <typename T> struct fmt::formatter<Point<T>> {
  // Presentation format: 'f' - fixed, 'e' - exponential.
  char presentation = 'f';

  // Parses format specifications of the form ['f' | 'e'].
  constexpr auto parse(format_parse_context& ctx) -> format_parse_context::iterator {
    // [ctx.begin(), ctx.end()) is a character range that contains a part of
    // the format string starting from the format specifications to be parsed,
    // e.g. in
    //
    //   fmt::format("{:f} - point of interest", point{1, 2});
    //
    // the range will contain "f} - point of interest". The formatter should
    // parse specifiers until '}' or the end of the range. In this example
    // the formatter should parse the 'f' specifier and return an iterator
    // pointing to '}'.

    // Please also note that this character range may be empty, in case of
    // the "{}" format string, so therefore you should check ctx.begin()
    // for equality with ctx.end().

    // Parse the presentation format and store it in the formatter:
    auto it = ctx.begin(), end = ctx.end();
    if (it != end && (*it == 'f' || *it == 'e')) presentation = *it++;

    // Check if reached the end of the range:
    if (it != end && *it != '}') throw_format_error("invalid format");

    // Return an iterator past the end of the parsed range:
    return it;
  }

  // Formats the point p using the parsed format specification (presentation)
  // stored in this formatter.
  auto format(const Point<T>& p, format_context& ctx) const -> format_context::iterator {
    // ctx.out() is an output iterator to write to.
    return presentation == 'f'
              ? fmt::format_to(ctx.out(), "({:.1f}, {:.1f}, {:.1f})", p.x, p.y, p.z)
              : fmt::format_to(ctx.out(), "({:.1e}, {:.1e}, {:.1e})", p.x, p.y, p.z);
  }
};

int main() 
{ 
    std::vector v1 = {1, 2};
    std::vector v2 = {'a', 'b', 'c'};
    std::vector v3 = {3, 4, 5};
        // {(1, 'a'), (2, 'b')}
    fmt::print("{}\n", std::views::zip(v1, v2));
    // {3, 8}
    fmt::print("{}\n", std::views::zip_transform(std::multiplies(), v1, v3));
    // {('a', 'b'), ('b', 'c')}
    fmt::print("{}\n", v2 | std::views::pairwise);
    // {7, 9}
    fmt::print("{}\n", v3 | std::views::pairwise_transform(std::plus()));

    std::vector<int> v4 { 0, 1 };
    std::vector<int> v5 { 2, 3 };
    for (auto&& [a,b] : stdv::cartesian_product(v4, v5))
    {
        fmt::print("{} {}\n", a, b);
    }

    auto un_even = [](int i) { return 1 == i % 2; };
    auto square = [](int i) {return i*i;};
    // view on stack with adaptor
    auto evens_squared = v3 | rng::views::filter( un_even ) | stdv::transform(square);
    fmt::print("{}\n", evens_squared);


    std::vector<Point<float>> a = { {1.0f, 2.0f, 3.0f}, {4.0f, 5.0f, 6.0f}, {7.0f, 8.0f, 9.0f}, {10.0f, 11.0f, 12.0f}, {13.0f, 14.0f, 15.0f}, {16.0f, 17.0f, 18.0f} , {0.0f, 0.0f, 0.0f},  {0.0f, 1.0f, 0.0f}, {0.0f, 2.0f, 0.0f},  {0.0f, 4.0f, 0.0f} };
    std::vector<Point<float>> b = { {10.0f, 11.0f, 12.0f}, {13.0f, 14.0f, 15.0f}, {16.0f, 17.0f, 18.0f} };


    std::vector<Point<float>> random_points = generateRandomPoints<float>(10000);


    float simTime = 0;
    float A1 = 0;
    float A2 = 2;
    float B1 = 0;
    float B2 = 1;
    float omega = 1;
    float c = 10;
    auto wave_equation = [&simTime,omega,c, A1, A2, B1, B2](Point<float> i) -> Point<float> {
        float u = (B1*std::cos(omega*i.x/c) + B2*std::sin(omega*i.x/c)) * (A1*std::cos(omega*simTime) + A2*std::sin(omega*simTime));
        return {i.x + u, i.y,i.z, u/((A1+A2)*(B1+B2))};
        };

    auto u = [&simTime,omega, c, A1, A2, B1, B2](Point<float> i) -> Point<float> {
        float u = std::sin(omega*i.y/c)  * std::sin(omega*i.x/c) * (A1*std::cos(omega*simTime) + A2*std::sin(omega*simTime));
        return {i.x , i.y,i.z + u, u/(A1+A2)};
        };
    auto moved_points = random_points | stdv::transform(u);
    // for (size_t i = 0; i < 10; i++, simTime+=0.1f)
    // {
    //     fmt::print("{}\n", moved_points);
    //     fmt::print("{}\n", simTime);
    // }
    

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
    int SCR_width = 1000;
    int SCR_height = 800;
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

    glewInit();    
    
     // build and compile our shader program
    // ------------------------------------
    Shader ourShader = ResourceManager::LoadShader("shader.vs", "shader.fs", nullptr, "wave");
     ourShader.Use();

   
    
    TextRenderer  *Text;
    Text = new TextRenderer(1000, 1000);
    Text->Load("a_ReportSansRgh.ttf", 24);
   
    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    float vertices[] = {
        -0.5f, -0.5f, -0.5f,  
         0.5f, -0.5f, -0.5f,  
         0.5f,  0.5f, -0.5f,  
         0.5f,  0.5f, -0.5f,  
        -0.5f,  0.5f, -0.5f,  
        -0.5f, -0.5f, -0.5f,  

        -0.5f, -0.5f,  0.5f,  
         0.5f, -0.5f,  0.5f,  
         0.5f,  0.5f,  0.5f,  
         0.5f,  0.5f,  0.5f,  
        -0.5f,  0.5f,  0.5f,  
        -0.5f, -0.5f,  0.5f,  

        -0.5f,  0.5f,  0.5f,  
        -0.5f,  0.5f, -0.5f,  
        -0.5f, -0.5f, -0.5f,  
        -0.5f, -0.5f, -0.5f,  
        -0.5f, -0.5f,  0.5f,  
        -0.5f,  0.5f,  0.5f,  

         0.5f,  0.5f,  0.5f,  
         0.5f,  0.5f, -0.5f,  
         0.5f, -0.5f, -0.5f,  
         0.5f, -0.5f, -0.5f,  
         0.5f, -0.5f,  0.5f,  
         0.5f,  0.5f,  0.5f,  

        -0.5f, -0.5f, -0.5f,  
         0.5f, -0.5f, -0.5f,  
         0.5f, -0.5f,  0.5f,  
         0.5f, -0.5f,  0.5f,  
        -0.5f, -0.5f,  0.5f,  
        -0.5f, -0.5f, -0.5f,  

        -0.5f,  0.5f, -0.5f,  
         0.5f,  0.5f, -0.5f,  
         0.5f,  0.5f,  0.5f,  
         0.5f,  0.5f,  0.5f,  
        -0.5f,  0.5f,  0.5f,  
        -0.5f,  0.5f, -0.5f
    };

   
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

    float distanceCamera = 45.0;
    float angleRotateXachsis = 0.0;
    double gameTimeFactor = 1;
    float angleRotateYachsis = 0.0;
    double targetFrameTime = 0.1;
    double gameDeltaTime;
    double realDeltaTime;
    double simDeltaTime;
    
    auto time_stamp = std::chrono::high_resolution_clock::now();
    while(!glfwWindowShouldClose(window)){
        // input
        // -----
        processInput(window, distanceCamera, angleRotateXachsis, angleRotateYachsis, gameTimeFactor);
        realDeltaTime = std::chrono::duration<float>(std::chrono::high_resolution_clock::now() - time_stamp).count();
        time_stamp = std::chrono::high_resolution_clock::now();
        simDeltaTime = realDeltaTime * gameTimeFactor;
        simTime += simDeltaTime;

      // Render outputs
       // render
        // ------
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // also clear the depth buffer now!
        std::stringstream ss;
        ss << gameTimeFactor;
        Text->RenderText("gameTimeFactor: "+ss.str(), 5.0f, 5.0f, 1.0f);

        // activate shader
        ourShader.Use();


        // create transformations
        glm::mat4 view          = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
        glm::mat4 projection    = glm::mat4(1.0f);
        projection = glm::perspective(glm::radians(distanceCamera), (float)SCR_width / (float)SCR_height, 0.1f, 100.0f);
        view       = glm::translate(view, glm::vec3(0.0f, 0.0f, -50.0f));
        view       = glm::rotate(view, glm::radians(angleRotateXachsis) , glm::vec3(1.0f , 0.0f, 0.0f));
        view       = glm::rotate(view, glm::radians(angleRotateYachsis) , glm::vec3(0.0f , 1.0f, 0.0f));
        // pass transformation matrices to the shader
        ourShader.SetMatrix4("projection", projection); // note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
        ourShader.SetMatrix4("view", view);

        // render boxes
        glBindVertexArray(VAO);
        for (auto i : moved_points)
        {
            // calculate the model matrix for each object and pass it to shader before drawing
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model,glm::vec3(i.x,i.y, i.z) );
            ourShader.SetMatrix4("model", model);
            ourShader.SetVector4f("ourColor", {std::abs(i.d), 0.5f, 0.5f, 1.0f}, false);
            glDrawArrays(GL_TRIANGLES, 0, 36);
        }



         // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();

        if (std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - time_stamp).count() < targetFrameTime - 0.01)
        {
            sleep(targetFrameTime - std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - time_stamp).count());
        }
        
    }

        // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
}