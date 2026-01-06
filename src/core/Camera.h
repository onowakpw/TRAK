#pragma once
#include <glm/glm.hpp>

class Camera
{
public:
    Camera(float fov, float aspect, float nearPlane, float farPlane);

    // update
    void setPosition(const glm::vec3& pos);
    void setTarget(const glm::vec3& target);

    // ⬇️ NOWE
    void processMouse(float dx, float dy);
    void processKeyboard(float forward, float right, float deltaTime);

    // matrices
    const glm::mat4& getView() const;
    const glm::mat4& getProjection() const;

private:
    void updateView();
    void updateProjection();

private:
    float m_FOV;
    float m_Aspect;
    float m_Near;
    float m_Far;
    float m_Yaw = -90.0f;   // patrzy w -Z
    float m_Pitch = 0.0f;

    glm::vec3 m_Position;
    glm::vec3 m_Target;
    glm::vec3 m_Up;

    glm::mat4 m_View;
    glm::mat4 m_Projection;
};
