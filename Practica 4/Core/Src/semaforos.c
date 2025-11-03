/*
 * semaforos.c
 *
 *  Created on: Nov 3, 2025
 *      Author: pinkyflowy
 */

#include "main.h"

SemaphoreHandle_t xSemaphore;
QueueHandle_t xQueue;
extern UART_HandleTypeDef huart1;
void CreateSerialObjects()
{
	//Crear un semaforo.
	xSemaphore = xSemaphoreCreateBinary();
	xSemaphoreGive(xSemaphore);
}


void CreateSerialTask()
{
	xTaskCreate(SerialTaskTx, "SerialTaskTx", NULL, 128, 1, NULL);
}

void SerialTaskTx(void* pArgs){
	for(;;){

		SerialSendByte("h");
		vTaskDelay(100);
		SerialSendByte("o");
		vTaskDelay(100);
		SerialSendByte("l");
		vTaskDelay(100);
		SerialSendByte("a");
		vTaskDelay(100);
	}
}

void SerialSendByte(char data){
	BaseType_t status = xSemaphoreTake(xSemaphore, -1);
	HAL_UART_Transmit_IT(&huart1, &data, 1);

}

void HAL_UART_TxCpltCallback (UART_HandleTypeDef* huart)
{
	xSemaphoreGiveFromISR(xSemaphore, pdFALSE);
}

