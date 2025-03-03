#include "raylib.h"
#include <cmath>
#include <string>

// window
int width{1600};
int height{900};
Color background_color = WHITE;

// circle
Color circle_color = BLUE;

int radius_of_circle = 30;
int circle_x{static_cast<int>(ceil(static_cast<double>(width) / 2))};
int circle_y{static_cast<int>(ceil(static_cast<double>(height) / 2))};
int circle_movement = 10;
int start_point = 0;

int l_circle_x;
int r_circle_x;
int u_circle_y;
int b_circle_y;

void assign_circle_edges()
{
    l_circle_x = {circle_x - radius_of_circle};
    r_circle_x = {circle_x + radius_of_circle};
    u_circle_y = {circle_y - radius_of_circle};
    b_circle_y = {circle_y + radius_of_circle};
};

// axe
Color axe_color = RED;

int axe_x{400};
int axe_y{0};
int axe_width{50};
int axe_height{50};
int direction{10};

// axe edges

int l_axe_x;
int r_axe_x;
int u_axe_y;
int b_axe_y;

void assign_axe_edges()
{
    l_axe_x = {axe_x};
    r_axe_x = {axe_x + axe_height};
    u_axe_y = {axe_y};
    b_axe_y = {axe_y - axe_height};
};

bool collision_with_axe = {};

void check_collision()
{
    if ((b_axe_y >= u_circle_y) && (u_axe_y <= b_circle_y) && (r_axe_x >= l_circle_x) && (l_axe_x <= r_circle_x))
    {
        collision_with_axe = true;
    }
};

int main()
{

    InitWindow(width, height, "Kevin's game");

    SetTargetFPS(60);

    int game_over_text_x_position{400};
    int game_over_text_y_position{200};
    int game_over_text_font_size{20};
    Color game_over_text_font_color{RED};

    // collision

    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(background_color);

        if (collision_with_axe)
        {
            DrawText("Game Over", game_over_text_x_position, game_over_text_y_position, game_over_text_font_size, game_over_text_font_color);
        }

        else
        {

            assign_circle_edges();
            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_height;
            u_axe_y = axe_y;
            b_axe_y = axe_y + axe_height;

            check_collision();

            DrawCircle(circle_x, circle_y, radius_of_circle, circle_color);
            DrawRectangle(axe_x, axe_y, axe_width, axe_height, axe_color);

            axe_y += direction;
            if (axe_y > height || axe_y < 0)
            {

                direction = -direction;
            }

            if (IsKeyDown(KEY_D) && circle_x < width)
            {
                circle_x += circle_movement;
            }

            if (IsKeyDown(KEY_A) && circle_x > start_point)
            {
                circle_x -= circle_movement;
            }

            if (IsKeyDown(KEY_W) && circle_y > start_point)
            {
                circle_y -= circle_movement;
            }

            if (IsKeyDown(KEY_S) && circle_y < height)
            {
                circle_y += circle_movement;
            }
        }

        EndDrawing();
    }
}
