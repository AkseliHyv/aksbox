#ifndef ENGINE
#define ENGINE
#include <stdint.h>
#include <stdio.h>

#define AKS_BUTTON_A 1 << 0
#define AKS_BUTTON_B 1 << 1
#define AKS_BUTTON_C 1 << 2
#define AKS_BUTTON_D 1 << 3
#define AKS_BUTTON_LEFT 1 << 4
#define AKS_BUTTON_RIGHT 1 << 5
#define AKS_BUTTON_UP 1 << 6
#define AKS_BUTTON_DOWN 1 << 7

#define AKS_GAME_NAME_LEN 32
#define AKS_FIFO_LEN 16
#define AKS_BAND_H 20

typedef struct {
  char name[AKS_GAME_NAME_LEN];
  void (*init)(void);
  void (*update)(int64_t);
  void (*draw)(void);
} aks_game;

static void aks_engine_init(void);
static void aks_get_input(void);
static void aks_set_display(void);

uint16_t aks_held(void);
uint16_t aks_pressed(void);

#endif // ENGINE