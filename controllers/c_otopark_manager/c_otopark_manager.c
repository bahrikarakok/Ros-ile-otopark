#include <webots/robot.h>
#include <webots/distance_sensor.h>
#include <stdio.h>

#define TIME_STEP 32

int main(int argc, char **argv) {
  wb_robot_init();

  // 10 adet sensörümüzü tanımlıyoruz
  WbDeviceTag sensors[10];
  char sensor_names[10][20];
  
  for (int i = 0; i < 10; i++) {
    sprintf(sensor_names[i], "sensor_slot%d", i + 1);
    sensors[i] = wb_robot_get_device(sensor_names[i]);
    wb_distance_sensor_enable(sensors[i], TIME_STEP);
  }

  printf("--- C TABANLI AKILLI OTOPARK SISTEMI AKTIF ---\n");

  while (wb_robot_step(TIME_STEP) != -1) {
    for (int i = 0; i < 10; i++) {
      double deger = wb_distance_sensor_get_value(sensors[i]);
      
      // 1.8 metrenin altı DOLU, üstü BOS
      if (deger < 1.8) {
        printf("Slot %d: DOLU (Mesafe: %.2f)\n", i + 1, deger);
      } else {
        printf("Slot %d: BOS (Mesafe: %.2f)\n", i + 1, deger);
      }
    }
    printf("----------------------------------------\n");
  }

  wb_robot_cleanup();
  return 0;
}