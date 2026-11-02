#include "semg.h"

const int DAC_PIN = 25;
int i = 0;
unsigned long tiempo_anterior = 0;

// El periodo para 2048 Hz es aproximadamente 488 us
const unsigned long periodo_us = 1000000 / FS_SEMG;

void setup() {
  tiempo_anterior = micros();
}

void loop() {
  unsigned long tiempo_actual = micros();

  if (tiempo_actual - tiempo_anterior >= periodo_us) {
    // Sumar el periodo al instante programado para evitar la acumulación de error
    tiempo_anterior += periodo_us;

    // Escribir el valor en el puerto GPIO25
    dacWrite(DAC_PIN, SEMG[i]);

    // Incrementar el índice y reiniciar la secuencia al terminar
    i++;
    if (i >= N_SEMG) {
      i = 0;
    }
  }
}