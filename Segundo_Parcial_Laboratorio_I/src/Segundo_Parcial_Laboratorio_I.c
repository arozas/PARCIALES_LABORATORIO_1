/*
 ============================================================================
 Name        : Segundo_Parcial_Laboratorio_I.c
 Author      : Alejandro Alberto Martín Rozas
 Version     : DIVISIÓN H
 Copyright   : Your copyright notice
 Description : Segundo Parcial de Laboratorio I.
 ============================================================================
 */
/*
CREAR LINKED LIST FILTER
AGREGAR BINARIOS
 */
#include "controller.h"

#define TEXT 1
#define BINARY 2
#define NO_MODE 3

int main(void)
{
	int menu[4]= {0,0,0,0};

	LinkedList* salonList =ll_newLinkedList();
	LinkedList* arcadeList =ll_newLinkedList();
	LinkedList* gameList =ll_newLinkedList();

	int saveLoadMode = BINARY;

	switch(saveLoadMode)
	{
	case TEXT:
		controller_loadSalon("salones.csv", salonList);
		controller_loadArcade("arcade.csv", arcadeList);
		controller_loadGame("juegos.csv", gameList);
		break;
	case BINARY:
		//controller_loadSalonFromBinary("salones.bin", salonList);
		controller_loadArcadeFromBinary("arcade.bin", arcadeList);
		controller_loadGameFromBinary("juegos.bin", gameList);
		break;
	}

	do{
		menu[0]=menu_menu("SEGUNDO PARCIAL LABORATORIO",
				"\n1.  MENU SALONES."
				"\n2.  MENU ARCADES."
				"\n3.  MENU JUEGOS."
				"\n4.  MENU INFORMES."
				"\n5.  LISTAR ARCADES FILTRADOS"
				"\n6.  FINALIZAR EL PROGRAMA.",
				"ERROR, INTENTE OPCION <1-5>:", RETRIES, 6);
		switch(menu[0])
		{
		case -1:
			controller_msgErroMenu();
			break;
		case 1:
			do{
				menu[1]=menu_menu("MENU SALONES",
						"\n1.  ALTA SALONES."
						"\n2.  ELIMINAR SALONES."
						"\n3.  LISTAR SALONES."
						"\n4.  SALIR.",
						"ERROR, INTENTE OPCION <1-4>:", RETRIES, 4);
				switch(menu[1])
				{
				case -1:
					controller_msgErroMenu();
					break;
				case 1:
					controller_addSalon(salonList);
					break;
				case 2:
					controller_removeSalon(salonList, arcadeList, gameList);
					break;
				case 3:
					controller_listSalon(salonList);
					break;
				}
			}while(menu[1]<4);
			break;
		case 2:
			do{
				menu[2]=menu_menu("MENU ARCADE",
						"\n1.  ALTA ARCADE."
						"\n2.  MODIFICAR ARCADE."
						"\n3.  ELIMINAR ARCADE."
						"\n4.  LISTAR ARCADES."
						"\n5.  SALIR.",
						"ERROR, INTENTE OPCION <1-5>:", RETRIES, 5);
				switch(menu[2])
				{
				case -1:
					controller_msgErroMenu();
					break;
				case 1:
					controller_addArcade(arcadeList, salonList, gameList);
					break;
				case 2:
					controller_editArcade(arcadeList, salonList, gameList);
					break;
				case 3:
					controller_removeArcade(arcadeList, salonList, gameList);
					break;
				case 4:
					controller_ListArcade(arcadeList, salonList, gameList);
					break;
				}
			}while(menu[2]<5);
			break;
		case 3:
			do{
				menu[3]=menu_menu("MENU JUEGOS",
						"\n1.  ALTA JUEGO."
						"\n2.  LISTAR JUEGOS."
						"\n3.  SALIR.",
						"ERROR, INTENTE OPCION <1-3>:", RETRIES, 3);
				switch(menu[3])
				{
				case -1:
					controller_msgErroMenu();
					break;
				case 1:
					controller_addGame(gameList);
					break;
				case 2:
					controller_sortGame(gameList);
					controller_listGames(gameList);
					break;
				}
			}while(menu[3]<3);
			break;
		case 4:
			do{
				menu[4]=menu_menu("INFORMES",
						"\n1.  INFORME A."
						"\n2.  INFORME B."
						"\n3.  INFORME C."
						"\n4.  INFORME D."
						"\n5.  INFORME E."
						"\n6.  INFORME F."
						"\n7.  INFORME G."
						"\n8.  SALIR INFORMES",
						"ERROR, INTENTE OPCION <1-8>:", RETRIES, 8);
				switch(menu[4])
				{
				case -1:
					controller_msgErroMenu();
					break;
				case 1:
					controller_reportA(arcadeList, salonList, gameList);
					break;
				case 2:
					controller_reportB(arcadeList, salonList, gameList);
					break;
				case 3:
					controller_reportC(salonList, arcadeList, gameList);
					break;
				case 4:
					controller_reportD(arcadeList, salonList, gameList);
					break;
				case 5:
					controller_reportE(salonList, arcadeList, gameList);
					break;
				case 6:
					controller_reportF(arcadeList, salonList, gameList);
					break;
				case 7:
					controller_reportG(arcadeList, salonList, gameList);
					break;
				}
			}while(menu[4]<8);
			break;
		case 5:
			controller_listFilteredArcadeList(arcadeList, salonList, gameList);
			break;
		}
	}while(menu[0] < 6);

	switch(saveLoadMode)
	{
	case TEXT:
		controller_saveSalon("salones.csv", salonList);
		controller_saveArcade("arcade.csv", arcadeList);
		controller_saveGame("juegos.csv", gameList);
		break;
	case BINARY:
		controller_savesSalonAsBinary("salones.bin", salonList);
		controller_savesArcadeAsBinary("arcade.bin", arcadeList);
		controller_savesGameAsBinary("juegos.bin", gameList);
		break;
	}

	return EXIT_SUCCESS;
}
