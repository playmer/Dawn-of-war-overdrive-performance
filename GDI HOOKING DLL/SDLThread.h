#pragma once
#ifndef SDLTHREAD_H
#define SDLTHREAD_H

#include <SDL3/SDL.h>
#include <SDL3/SDL_vulkan.h>
#include <vulkan/vulkan.h>
#include <windows.h>
#include "ThreadSafeQueue.h"
#include "RenderRequest.h"

// Function declaration
extern "C" __declspec(dllexport) DWORD WINAPI SDLThread(LPVOID lpParam);


// ------------------------------------------------------------------------
// Minimal VulkanContext struct
// ------------------------------------------------------------------------
struct VulkanContext {
  VkInstance       instance;
  VkSurfaceKHR     surface;
  VkPhysicalDevice physicalDevice;
  VkDevice         device;
  VkQueue          graphicsQueue;
  VkSwapchainKHR   swapchain;
};

// Global declarations
extern VkInstance gVkInstance;
extern VkSurfaceKHR gVkSurface;
extern VkPhysicalDevice gVkPhysicalDevice;
extern VkDevice gVkDevice;
extern VkQueue gVkGraphicsQueue;
extern VkSwapchainKHR gVkSwapchain;
extern SDL_Window* g_Window;
extern ThreadSafeQueue gRenderQueue;
extern volatile bool gSDLRunning; // From dllmain.cpp
extern VulkanContext g_VulkanContext; // From dllmain.cpp

void CleanupVulkan();

#endif // SDLTHREAD_H