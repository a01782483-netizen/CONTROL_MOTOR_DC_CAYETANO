#include "definition.h"

extern "C" void app_main()
{
    //esp_task_wdt_init();
    //encoder
    encoder.setup(pins, degrees_per_edge);

    //H_bridge 
    motor.setup(in, ch, timer, threshold);
    motor.setDuty(0);

    prev_time = esp_timer_get_time();
    while (1)
    {

        current_time = esp_timer_get_time();
        if (current_time - prev_time >= dt_us)
        {
            
            float rpm = encoder.getSpeed()/6.0f;

            printf("RPM: %.1f | Angle: %.1f Degrees | Direction: %d\n", rpm, encoder.getAngle(), encoder.getDirection());

            prev_time = current_time;
            // //len = uart.available();

            // if (len)
            // {
            //     uart.read(message, len);
            //     sscanf(message, "%f\n", &duty);
            // }
            
            //printf("%.1f, %.2f\n", );

        }
    }
}