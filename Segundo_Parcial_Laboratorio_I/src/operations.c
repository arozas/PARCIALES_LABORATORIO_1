/*
 * Operations.c
 *
 *  Created on: 1 abr. 2022
 *      Author: Alejandro Alberto Martín Rozas
 *      Biblioteca de operaciones matématicas
 *      Versión 0.5 del 14 de abril de 2022
 */
#include "operations.h"

/// @fn int operations_Add(float, float, float*)
/// @brief 						Esta función suma 2 números.
/// @param numero1				Es el primer número a sumar.
/// @param numero2				Es el segundo número a sumar.
/// @param pResultadoOperacion	Es el puntero donde se guarda el valor de la operación.
/// 							en el caso que esta haya sido exitosa.
/// @return						El retorno devolvera 0 por si hay un error, 1 en el caso que la función no haya tenido errores.
int operations_Add(float numero1, float numero2, float* pResultadoOperacion)
{
	float resultado;
	int rtn = 0;

	if(pResultadoOperacion!=NULL )
	{
		resultado=numero1+numero2;
		(*pResultadoOperacion)=resultado;
		rtn = 1;
	}

	return rtn;
}
/// @fn int operations_Subtract(float, float, float*)
/// @brief 						Esta función realiza una resta entre dos numeros.
/// @param numero1				Es el primer número a restar.
/// @param numero2				Es el segundo número a restar.
/// @param pResultadoOperacion	Es el puntero donde se guarda el valor de la operación.
/// @return						El retorno devolvera 0 por si hay un error, 1 en el caso que la función no haya tenido errores.
int operations_Subtract(float numero1, float numero2, float* pResultadoOperacion)
{
	float resultado;
	int rtn = 0;

	if(pResultadoOperacion!=NULL)
	{
		resultado=numero1-numero2;
		(*pResultadoOperacion)=resultado;
		rtn = 1;
	}
	return rtn;

}
/// @fn int operations_Mulptiply(float, float, float*)
/// @brief 						Esta función calcula el producto de 2 numeros.
/// @param numero1				Es el primer número a multiplicar.
/// @param numero2				Es el segundo número a multiplicar.
/// @param pResultadoOperacion	Es el puntero donde se guarda el valor de la operación.
/// @return						El retorno devolvera 0 por si hay un error, 1 en el caso que la función no haya tenido errores.
int operations_Mulptiply (float numero1, float numero2, float* pResultadoOperacion)
{
	float resultado;
	int rtn = 0;

	if(pResultadoOperacion!=NULL)
	{
		resultado=numero1*numero2;
		(*pResultadoOperacion)=resultado;
		rtn = 1;
	}

	return rtn;
}
/// @fn int operations_Split(float, float, float*)
/// @brief 						Esta función divide dos numeros.
/// @param dividendo			Es el numero a dividir de la operación.
/// @param divisor				Es el número que va a dividir al dividendo.
/// @param pResultadoOperacion	Es el puntero donde se guarda el valor de la operación.
/// @return						El retorno devolvera 0 por si hay un error, 1 en el caso que la función no haya tenido errores.
int operations_Split(float dividendo, float divisor, float* pResultadoOperacion)
{
	float resultado;
	int rtn=0;

	if(divisor!=0 && pResultadoOperacion!=NULL)
	{
		resultado = dividendo/divisor;
		(*pResultadoOperacion) = resultado;
		rtn = 1;
	}

	return rtn;
}
/// @fn int operations_RuleOfThree(float, float, float, float*)
/// @brief 						Esta función realiza una operación de regla de tres simples.
/// @param numero1				Valor de comparación para la operación.
/// @param numero2				Valor de comparación para la operación.
/// @param divisor				Valor divisor para la comparación.
/// @param pResultadoOperacion	Es el puntero donde se guarda el valor de la operación.
/// @return						El retorno devolvera 0 por si hay un error, 1 en el caso que la función no haya tenido errores.
int operations_RuleOfThree (float numero1, float numero2, float divisor, float* pResultadoOperacion)
{

	float resultado;
	float resultadoDos;
	int rtn = 0;

	if(divisor!=0 && pResultadoOperacion!=NULL)
	{
		if(operations_Mulptiply(numero1, numero2, &resultado)==1)
		{
			if(operations_Split(resultado, divisor, &resultadoDos)==1)
			{
				(*pResultadoOperacion)=resultadoDos;
				rtn = 1;

			}
		}
	}
	return rtn;
}
/// @fn int operations_CalcPriceVarations(float, int, char[], float*)
/// @brief 						Esta función calcula incrementos o descuentos sobre precios.
/// @param precioIngresado		El precio sobre el que va generarse la variación.
/// @param variacionPrecio		El % a aumentar o descontar, expresado en numeros enteros.
/// @param mensajeError			Mensaje de error en el caso que no pueda generar la operación.
/// @param pPrecioConDescuento	Es el puntero donde se guarda el valor de la operación.
/// @return						El retorno devolvera 0 por si hay un error, 1 en el caso que la función no haya tenido errores.
int operations_CalcPriceVarations(float precioIngresado, int variacionPrecio, char mensajeError[], float* pPrecioConDescuento)
{
	int rtn;
	float variablePrecio;

	if(pPrecioConDescuento!=NULL && mensajeError!=NULL)
	{
		if(operations_RuleOfThree(precioIngresado, variacionPrecio, 100, &variablePrecio)==1)
		{
			*pPrecioConDescuento = precioIngresado + variablePrecio;
			rtn=1;
		}
		else
		{
			printf("\n%s", mensajeError);
			rtn=0;
		}
	}
	return rtn;
}
/// @fn int operations_ExchangeRate(float, float, float*)
/// @brief 						Es un convertidor de monedas simple, devuelve la tasa de la
/// 							moneda  con la que se comprara al agregar el valor de embas.
/// @param monedaUno			Primer valor a convertir.
/// @param monedaDos			El valor de la moneda a la que se quire convertir.
/// @param pResultadoOperacion	Es el puntero donde se guarda el valor de la operación.
/// @return						El retorno devolvera 0 por si hay un error, 1 en el caso que la función no haya tenido errores.
int operations_ExchangeRate(float monedaUno, float monedaDos, float* pResultadoOperacion)
{
	int rtn =0;
	float auxiliarTasa;
	if(monedaUno>0 && monedaDos >0)
	{
		if(operations_Split(monedaUno, monedaDos, &auxiliarTasa)==1)
		{
		*pResultadoOperacion=auxiliarTasa;
		rtn=1;
		}
	}
	return rtn;
}
