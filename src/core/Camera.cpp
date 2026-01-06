#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(float fov, float aspect, float nearPlane, float farPlane)
    : m_FOV(fov),
      m_Aspect(aspect),
      m_Near(nearPlane),
      m_Far(farPlane),
      m_Position(0.0f, 0.0f, 5.0f),
      m_Target(0.0f, 0.0f, 0.0f),
      m_Up(0.0f, 1.0f, 0.0f)
{
    updateView();
    updateProjection();
}

void Camera::setPosition(const glm::vec3& pos)
{
    m_Position = pos;
    updateView();
}

void Camera::setTarget(const glm::vec3& target)
{
    m_Target = target;
    updateView();
}

const glm::mat4& Camera::getView() const
{
    return m_View;
}

const glm::mat4& Camera::getProjection() const
{
    return m_Projection;
}


void Camera::updateProjection()
{
    m_Projection = glm::perspective(
        glm::radians(m_FOV),
        m_Aspect,
        m_Near,
        m_Far
    );
}
void Camera::processMouse(float dx, float dy)
{
    float sensitivity = 0.1f;
    dx *= sensitivity;
    dy *= sensitivity;

    m_Yaw += dx;
    m_Pitch += dy;

    // ograniczenie patrzenia w górę/dół
    if (m_Pitch > 89.0f) m_Pitch = 89.0f;
    if (m_Pitch < -89.0f) m_Pitch = -89.0f;

    updateView();
}
void Camera::processKeyboard(float forward, float right, float dt)
{
    float speed = 3.0f * dt;

    glm::vec3 front{
        cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch)),
        sin(glm::radians(m_Pitch)),
        sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch))
    };
    front = glm::normalize(front);

    glm::vec3 rightVec = glm::normalize(glm::cross(front, glm::vec3(0,1,0)));

    m_Position += front * forward * speed;
    m_Position += rightVec * right * speed;

    updateView();
}
void Camera::updateView()
{
    glm::vec3 front{
        cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch)),
        sin(glm::radians(m_Pitch)),
        sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch))
    };

    m_View = glm::lookAt(
        m_Position,
        m_Position + glm::normalize(front),
        glm::vec3(0, 1, 0)
    );
}
