#include <iostream>
#include <array>
#include <sstream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "shader.h"
#include "resource_manager.h"
#include "textRenderer.h"

#ifndef GRAPHICSMANAGER_HPP
#define GRAPHICSMANAGER_HPP


class GraphicsManager {
public:
    GraphicsManager(int width, int height, const char* title);
    ~GraphicsManager();
    void init();
    void processInput();
    template<typename T>
    void render(T  moved_points);

private:
    int SCR_width = 1000;
    int SCR_height = 800;
    GLFWwindow* window;
    int width, height;
    const char* title;

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    std::array<float,6*6*3> const vertices = {
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
    
    Shader ourShader = ResourceManager::LoadShader("shader.vs", "shader.fs", nullptr, "wave");
    TextRenderer  *Text;
    
    float distanceCamera = 45.0;
    float angleRotateXachsis = 0.0;
    double gameTimeFactor = 1;
    float angleRotateYachsis = 0.0;

   
    void framebuffer_size_callback(GLFWwindow* window, int width, int height);
};

template<typename T>
    // requires Regular<T>
void GraphicsManager::render( T moved_points)
{
  
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

}
#endif