#include "cookie.h"
#include "particles.h"
#include <memory.h>
#include <raylib.h>
#include <raymath.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void strrev(char *str) {
    const int length = strlen(str);
    char t; // memory optimizacione
    for (int i = 0; i < length / 2; i++) {
        t = str[0];
        str[0] = str[length - 1 - i];
        str[length - 1 - i] = t;
    }
}

void strnumber(char *str, int n) {
    int i = 0;
    while (n > 0) {
        str[i] = n % 10 + '0';
        n /= 10;
        i++;
    }
    strrev(str);
    str[i] = 0;
}

int main() {
    SetTraceLogLevel(LOG_NONE);
    srand(time(NULL));

    const int width = 1280;
    const int height = 720;
    const Vector2 screenCenter = {width / 2.f, height / 2.f};
    char clicksText[16] = "clicks: ";

    InitWindow(width, height, "Clicker");
    SetTraceLogLevel(LOG_DEBUG);
    SetTargetFPS(60);

    Texture kirby = LoadTexture("resources/kirby.gif");
    initCookie(screenCenter);

    while (!WindowShouldClose()) {
        updateCookieState();
        strnumber(&clicksText[8], getClickCounter());

        BeginDrawing();
        ClearBackground(DARKGRAY);
        DrawTextureEx(kirby, (Vector2){0}, 0.f, 2.6f, DARKGRAY);
        updateParticles();
        DrawText(clicksText, width / 2 - 100, height - 100, 50,
                 getClickCounter() == 0 ? (Color){.a = 0} : WHITE);
        drawCookie();
        EndDrawing();
    }

    deleteCookie();
    CloseWindow();
    return 0;
}
