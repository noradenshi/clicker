#include "particles.h"
#include <stdlib.h>
#include <raymath.h>

#define MAX_PARTICLES 1024

struct particle {
    Vector2 pos;
    Vector2 dir;
    float speed;
    Color color;
} particles[MAX_PARTICLES];

int active_particles = 0;

void createParticle(const Vector2 center) {
    if (active_particles == MAX_PARTICLES)
        return;

    particles[active_particles] = (struct particle){
        center, (Vector2){(rand() % 50 - 25), (rand() % 50 - 25)},
        .color = (Color){rand() % 256, rand() % 256, rand() % 256, 50}};
    active_particles++;
}

void updateParticles() {
    for (int i = 0; i < active_particles; i++) {
        particles[i].pos = Vector2Add(particles[i].pos, particles[i].dir);
        if (particles[i].pos.x < 0 || particles[i].pos.x > 1280)
            particles[i].dir.x *= -1;
        if (particles[i].pos.y < 0 || particles[i].pos.y > 720)
            particles[i].dir.y *= -1;
        DrawCircleV(particles[i].pos, 20.f, particles[i].color);
    }
}
