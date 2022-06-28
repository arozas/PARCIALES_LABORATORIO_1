/*
 * Operations.h
 *
 *  Created on: 1 abr. 2022
 *      Author: Alejandro Alberto Martín Rozas
 *      Biblioteca de operaciones matématicas
 *      Versión 0.5 del 13 de abril de 2022
 */

#ifndef OPERATIONS_H_
#define OPERATIONS_H_
#include "input.h"

int operations_Add(float numero1, float numero2, float* pResultadoOperacion);
int operations_Subtract (float numero1, float numero2, float* pResultadoOperacion);
int operations_Mulptiply (float numero1, float numero2, float* pResultadoOperacion);
int operations_Split(float dividendo, float divisor, float* pResultadoOperacion);
int operations_RuleOfThree (float numero1, float numero2, float divisor, float* pResultadoOperacion);
int operations_CalcPriceVarations(float precioIngresado, int variacionPrecio, char mensajeError[], float* pPrecioConDescuento);
int operations_ExchangeRate(float monedaUno, float monedaDos, float* pResultadoOperacion);

#endif /* OPERATIONS_H_ */
