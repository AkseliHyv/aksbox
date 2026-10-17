#include "include/aks_engine.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_timer.h"

static uint16_t held, prev;
static uint16_t band[320 * AKS_BAND_H];
extern aks_game game;

void app_main(void)
{
    aks_engine_init();
    
    int64_t prev_time = esp_timer_get_time();
    game.init();
    
    while (1)
    {
        int64_t curr_time = esp_timer_get_time();
        float dt = (curr_time - prev_time) / 1000000.0f;
        prev_time = curr_time;

        aks_get_input();
        game.update(dt);
        game.draw();
        aks_set_display();

        vTaskDelay(1);
    }

}

static void aks_engine_init(void)
{
    
}

static void aks_get_input(void)
{
    prev = held;
    held = read_gpios();

}

static void aks_set_display(void)
{

}

uint16_t aks_held(void)
{
    return held;
}

uint16_t aks_pressed(void)
{
    return held & ~prev;
}