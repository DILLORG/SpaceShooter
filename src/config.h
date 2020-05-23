#ifndef CONFIG_H
#define CONFIG_H
const int SHIP_SPEED_FACTOR = 30;
const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;
const int CHARACTER_WIDTH = 50;
const int CHARACTER_HEIGHT = 50;
const int BULLET_WIDTH = 5;
const int BULLET_HEIGHT = 10;
const int BULLET_SPEED = 20;
const int ENEMY_SPEED = 50;
const int ENEMY_SPAWN_FREQUENCY = 500;
const int NUM_STARS = 10;
const int STAR_WIDTH = 3;
const int STAR_HEIGHT = 3;
const int STAR_SPEED = 20;
const int STAR_SPAWN_FREQUENCY = 100;

const int FONT_SIZE = 20;
const int ANIMATION_SPEED = 25;
const char GAME_NAME [14] = "Space Shooter";
const char BLOW_UP [21] = ":/assets/blow_up.wav";
const char BULLET_SOUND[26] = ":/assets/bullet_sound.wav";
const char PLAYER_SPRITE[31] = ":/assets/ship_sprite_sheet.png";
const char ENEMY_SPRITE[32] = ":/assets/enemy_sprite_sheet.png";
const char EXPLOSION_SPRITE[36] = ":/assets/explosion_sprite_sheet.png";
const char FONT[21] = ":/assets/Thintel.ttf";
#endif // CONFIG_H
