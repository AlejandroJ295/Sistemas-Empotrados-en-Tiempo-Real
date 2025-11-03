/*
 * sensors.c
 *
 *  Created on: Oct 27, 2025
 *      Author: pinkyflowy
 *
 *      void Temperature_Test(void);
		void Humidity_Test(void);
		void Pressure_Test(void);
		void Gyro_Test(void);
		void Magneto_Test(void);
		void Accelero_Test(void);
 */



#include "main.h"

void Sensors_Init(){
	float press_value =0;
	float humidity_value =0;
	float temperature_value =0;
	int16_t pDataXYZ[3] = {0};
	int16_t pGyroDataXYZ[3] = {0};

	BSP_PSENSOR_Init();
	BSP_HSENSOR_Init();
	BSP_TSENSOR_Init();
	BSP_ACCELERO_Init();
	BSP_GYRO_Init();
	while(1){
		HAL_Delay(5000);
		press_value =BSP_PSENSOR_ReadPressure();
		printf("PRESSURE is= %.2f mBar \n", press_value);
		humidity_value =BSP_HSENSOR_ReadHumidity();
		printf("HUMIDITY is= %.2f mBar \n", humidity_value);
		temperature_value =BSP_TSENSOR_ReadTemp();
		printf("TEMPERATURE is= %.2f mBar \n", temperature_value);
		BSP_ACCELERO_AccGetXYZ(pDataXYZ);
		printf("X= %d, Y=%d, Z=%d \n\r", pDataXYZ[0],pDataXYZ[1],pDataXYZ[3]);
		BSP_GYRO_GetXYZ(pGyroDataXYZ);
		printf("X= %d, Y=%d, Z=%d \n\r", pGyroDataXYZ[0],pGyroDataXYZ[1],pGyroDataXYZ[3]);
	}
	BSP_ACCELERO_DeInit();
	BSP_GYRO_DeInit();
	printf("\n*** End of the Test ***\n\n");
	return;
}

void Pressure_Test(void){
	float press_value =0;

	BSP_PSENSOR_Init();
	while(1){
		HAL_Delay(5000);
		press_value =BSP_PSENSOR_ReadPressure();
		printf("PRESSURE is= %.2f mBar \n", press_value);
	}
}

void Humidity_Test(void){
	float humidity_value =0;

	BSP_HSENSOR_Init();
	while(1){
		humidity_value =BSP_HSENSOR_ReadHumidity();
		printf("HUMIDITY is= %.2f mBar \n", humidity_value);
		HAL_Delay(1000);
	}
}

void Temperature_Test(void){
	float temperature_value =0;

		BSP_TSENSOR_Init();
	while(1){
		temperature_value =BSP_TSENSOR_ReadTemp();
		printf("TEMPERATURE is= %.2f mBar \n", temperature_value);
	}
}

void Accelero_Test(void){
	int16_t pDataXYZ[3] = {0};


	BSP_ACCELERO_Init();
	while(1){
		BSP_ACCELERO_AccGetXYZ(pDataXYZ);
		printf("X= %d, Y=%d, Z=%d \n\r", pDataXYZ[0],pDataXYZ[1],pDataXYZ[3]);
	}

	BSP_ACCELERO_DeInit();
	printf("\n*** ENd of Accelerometer Test ***\n\n");
	return;
}

void Gyro_Test(void){
	int16_t pGyroDataXYZ[3] = {0};


	BSP_GYRO_Init();
	while(1){
		BSP_GYRO_GetXYZ(pGyroDataXYZ);
		printf("X= %d, Y=%d, Z=%d \n\r", pGyroDataXYZ[0],pGyroDataXYZ[1],pGyroDataXYZ[3]);
	}

	BSP_GYRO_DeInit();
	printf("\n*** End of Gyro Test ***\n\n");
	return;
}



