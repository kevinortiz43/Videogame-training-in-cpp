#include "raylib.h"
#include <cmath>
#include <string>

// window
int width{800};
int height{450};
Color background_color = WHITE;

// float root_beer = 1.99;
// int cheese_burger = 5.99;
// bool should_have_lunch = true;

// circle
Color circle_color = BLUE;

int radius_of_circle = 30;
int circle_x{static_cast<int>(ceil(static_cast<double>(width) / 2))};
int circle_y{static_cast<int>(ceil(static_cast<double>(height) / 2))};
int circle_movement = 10;
int start_point = 0;

int l_circle_x{circle_x - radius_of_circle};
int r_circle_x{circle_x + radius_of_circle};
int u_circle_y{circle_y - radius_of_circle};
int b_circle_y{circle_y + radius_of_circle};

// rectangle
Color rectangular_color = RED;

int rectangular_x{400};
int rectangular_y{0};
int rectangular_width{50};
int rectangular_height{50};
int direction{10};

// rectungalr adges
int l_rectangle_x{rectangular_x};
int r_rectangle_x{rectangular_x + rectangular_width};
int u_rectangle_y{rectangular_y};
int b_rectangle_y{rectangular_y - rectangular_height};

int main()
{

    // bool equal{4 == 9};
    // bool not_equal{4 != 9};
    // bool less{4 < 9};
    // bool greater{4 > 9};

    InitWindow(width, height, "Kevin's game");

    SetTargetFPS(60);

    int game_over_text_x_position{400};
    int game_over_text_y_position{200};
    int game_over_text_font_size{20};
    Color game_over_text_font_color{RED};

    // collision

    bool collision_with_axe{};

    // if (b_rectangle_y >= u_circle_y)
    // {
    //     collision_with_axe = true;
    // }
    // else if (u_rectangle_y <= b_circle_y)
    // {
    //     collision_with_axe = true;
    // }

    // else if (l_rectangle_x <= r_circle_x)
    // {
    //     collision_with_axe = true;
    // }
    // else if (r_rectangle_x >= l_circle_x)
    // {
    //     collision_with_axe = true;
    // }

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
            DrawCircle(circle_x, circle_y, radius_of_circle, circle_color);
            DrawRectangle(rectangular_x, rectangular_y, rectangular_width, rectangular_height, rectangular_color);

            rectangular_y += direction;
            if (rectangular_y > height || rectangular_y < 0)
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
