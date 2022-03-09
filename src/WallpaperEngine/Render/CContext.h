#pragma once

#include <vector>
#include <glm/vec4.hpp>

#include "WallpaperEngine/Input/CMouseInput.h"
#include "CWallpaper.h"
#include <X11/Xlib.h>

using namespace WallpaperEngine::Input;

namespace WallpaperEngine::Render
{
    enum DesktopEnvironment
    {
        GNOME = 0,
        KDE = 1,
        i3 = 2,
        UNKNOWN = -1
    };

    class CWallpaper;

    class CContext
    {
    public:
        CContext (DesktopEnvironment de, std::vector <std::string> screens, GLFWwindow* window);
        ~CContext ();
        void render ();
        void setWallpaper (CWallpaper* wallpaper);
        void setDefaultViewport (glm::vec4 defaultViewport);
        CMouseInput* getMouse () const;
        void setMouse (CMouseInput* mouse);

    private:
        void initializeViewports ();
        void detectDesktopEnvironment ();

        DesktopEnvironment m_de;
        Display* m_display;
        Pixmap m_pixmap;
        GC m_gc;
        XImage* m_image;
        GLFWwindow* m_window;
        char* m_imageData;
        CFBO* m_fbo;
        std::vector <std::string> m_screens;
        std::vector <glm::ivec4> m_viewports;
        glm::vec4 m_defaultViewport;
        CWallpaper* m_wallpaper;
        CMouseInput* m_mouse;
        bool m_isRootWindow;
    };
}