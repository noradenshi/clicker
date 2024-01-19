#include "cookie.h"
#include "particles.h"

#define COOKIE_RADIUS 120.f

enum { COOKIE_IDLE, COOKIE_HOVER, COOKIE_CLICK } CookieState = COOKIE_IDLE;

float cookieScale[] = {15.f, 16.f, 15.5f};
int clickCounter = 0;
Vector2 cookiePosition = {0};
Texture cookieTexture;

int getClickCounter() { return clickCounter; }

void initCookie(const Vector2 center) {
    cookiePosition = center;
    cookieTexture = LoadTexture("resources/cookie.png");
}

void deleteCookie() { UnloadTexture(cookieTexture); }

void drawCookie() {
    DrawTextureEx(
        cookieTexture,
        (Vector2){cookiePosition.x -
                      cookieTexture.width * cookieScale[CookieState] / 2,
                  cookiePosition.y -
                      cookieTexture.height * cookieScale[CookieState] / 2},
        0.f, cookieScale[CookieState], WHITE);
}

void updateCookieState() {
    switch (CookieState) {
    case COOKIE_CLICK:
        if (IsMouseButtonReleased(0))
            CookieState = COOKIE_IDLE;
        return;
    case COOKIE_HOVER:
        if (IsMouseButtonPressed(0)) {
            CookieState = COOKIE_CLICK;
            clickCounter++;
            createParticle(cookiePosition);
            return;
        }
    default:
        if (CheckCollisionPointCircle(GetMousePosition(), cookiePosition,
                                      COOKIE_RADIUS)) {
            CookieState = COOKIE_HOVER;
            return;
        }
    }
    CookieState = COOKIE_IDLE;
}
