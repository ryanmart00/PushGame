#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP

#include <vector>
#include "light.hpp"
#include "inputs.hpp"
#include "game_object.hpp"
#include "player.hpp"
#include "dynamics.hpp"
#include "text.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Gameplay : public Input
{
private:
    AssetManager& manager_;
    Shader* shader_;
    Shader* lampShader_;
    Text* text_;
    Player* player_;
    Dynamics* world;
    StaticObject* floor;
    std::vector<BaseObject*> objects;
    std::vector<DirectionalLight> dirLights;
    std::vector<PointLight> pointLights;

    glm::vec3 getCenter();
    int bone;
    glm::mat4 projection;
#define NUMCUBES 10
    DynamicObject* dynamicCubes[NUMCUBES];
    bool firstMouse = true;
    double lastX;
    double lastY;
 
public:

    Gameplay(GameState& state, Input** input, AssetManager& man);
    ~Gameplay();

    virtual void mouseCallback(GLFWwindow*, double xpos, double ypos);
    virtual void mouseButtonCallback(GLFWwindow*, int, int, int);
    virtual void pollInput(GLFWwindow*, float); 
    virtual void characterCallback(GLFWwindow*, unsigned int); 
    virtual void hardInit();
    void softInit();
    virtual void stop();
    virtual void update(float dt);
};

#endif
