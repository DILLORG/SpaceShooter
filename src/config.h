#ifndef CONFIG_H
#define CONFIG_H
//Window
const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;
const char GAME_NAME [14] = "Space Shooter";
const char FONT[21] = ":/assets/Thintel.ttf";
const int FONT_SIZE = 35;
const int ANIMATION_SPEED = 25;
const int UPDATE_SPEED = 20;
const char PLAY_BUTTON[25] = ":/assets/play_button.png";

//Bullet
const int BULLET_WIDTH = 5;
const int BULLET_HEIGHT = 10;
const int BULLET_SPEED = 20;
const char BULLET_SOUND[26] = ":/assets/bullet_sound.wav";
const char BLOW_UP [21] = ":/assets/blow_up.wav";

//Enemy
const int ENEMY_SPEED = 50;
const int ENEMY_SPAWN_FREQUENCY = 500;
const char ENEMY_SPRITE[32] = ":/assets/enemy_sprite_sheet.png";

//Stars
const int NUM_STARS = 10;
const int STAR_WIDTH = 3;
const int STAR_HEIGHT = 3;
const int STAR_SPAWN_FREQUENCY = 100;

//Explosion
const char EXPLOSION_SPRITE[36] = ":/assets/explosion_sprite_sheet.png";
const int SMALL_FONT_SIZE = 20;

//Player
const char PLAYER_SPRITE[31] = ":/assets/ship_sprite_sheet.png";
const int SHIP_SPEED_FACTOR = 30;

#endif // CONFIG_H
