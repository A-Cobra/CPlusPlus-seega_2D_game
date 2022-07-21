#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
using namespace std;
using namespace System;

int x, y, x_1, y_1;
int eatenby2 = 0;//Contador de piezas comidas por el jugador 2 //Contador de piezas comidas del jugador 3 
int eatenby3 = 0;//Contador de piezas comidas por el jugador 3 Contador de piezas comidas del jugador 2 
int counter2 = 0;
int counter3 = 0;
bool keepPlaying = true;
int matrix[7][7] = {
	{8,8,8,8,8,8,8},
	{8,0,1,0,1,0,8},
	{8,1,0,1,0,1,8},
	{8,0,1,0,1,0,8},
	{8,1,0,1,0,1,8},
	{8,0,1,0,1,0,8},
	{8,8,8,8,8,8,8}
};
void new_matrix() {
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			if (i == 0 || j == 0 || i == 6 || j == 6) {
				matrix[i][j] = 8;
			}
			else if ((i + j) % 2 == 0) {
				matrix[i][j] = 0;
			}
			else {
				matrix[i][j] = 1;
			}
		}
	}
}

int matrixg[25][80] = { {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,2,2,2,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,1,1,2,2,2,1,0,1,2,2,1,1,2,2,2,2,2,1,1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,1,1,2,2,2,1,0,1,2,2,1,2,2,2,1,1,2,2,1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,2,2,2,1,1,1,1,1,1,1,2,2,1,1,1,1,2,2,0,1,2,2,2,1,1,1,2,2,1,2,1,1,1,1,1,2,1,1,2,2,1,1,1,1,1,2,2,2,2,2,2,2,2,1,2,2,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,2,2,2,1,0,0,0,0,1,1,2,2,1,0,0,1,2,2,1,1,2,2,2,1,1,1,2,2,1,2,1,1,1,1,1,2,1,1,2,2,1,1,1,1,1,1,1,2,2,2,2,1,1,1,2,2,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,2,2,2,1,1,1,1,1,1,1,2,2,1,1,1,1,2,2,1,1,2,2,1,2,2,1,2,2,1,2,2,2,2,2,2,2,1,1,2,2,2,2,2,1,1,0,1,2,2,2,2,1,0,1,2,2,2,2,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,2,2,2,1,1,2,2,2,2,1,2,2,2,2,2,2,2,2,1,1,2,2,1,2,2,1,2,2,1,2,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,0,1,2,2,2,2,1,0,1,2,2,2,2,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,2,2,2,1,1,1,1,2,2,1,2,2,2,2,2,2,2,2,1,1,2,2,1,1,2,1,2,2,1,2,2,2,2,2,2,2,1,1,1,1,1,1,1,2,1,1,1,2,2,2,2,1,0,1,2,2,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,2,2,2,1,1,1,1,2,2,1,2,2,1,1,1,1,2,2,1,1,2,2,1,1,2,2,2,2,1,2,1,1,1,1,1,2,1,1,1,1,1,1,1,2,1,1,1,2,2,2,2,1,0,1,2,2,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,2,2,2,2,2,2,2,2,2,1,2,2,1,0,1,1,2,2,1,1,2,2,1,1,1,2,2,2,1,2,1,0,0,0,1,2,1,1,2,2,2,2,2,2,1,0,1,2,2,2,2,1,0,1,2,2,2,2,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,2,2,2,2,2,2,2,2,2,1,2,2,1,0,0,1,2,2,1,1,2,2,1,0,1,2,2,2,1,2,1,0,0,0,1,2,1,1,2,2,2,2,2,2,1,0,1,2,2,2,2,1,0,1,2,2,2,2,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} };

void ganador() {
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 80; j++) {
			if (matrixg[i][j] == 2) {
				Console::ForegroundColor = ConsoleColor::Green;
				_sleep(1);
				cout << (char)219;
			}
			if (matrixg[i][j] == 0) {
				Console::ForegroundColor = ConsoleColor::Black;
				_sleep(1);
				cout << (char)219;
			}
			if (matrixg[i][j] == 1) {
				Console::ForegroundColor = ConsoleColor::White;
				_sleep(1);
				cout << (char)219;
			}
		}
		cout << endl;
	}
	Console::ForegroundColor = ConsoleColor(3);
}

int Logo[25][74] = {

		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

void imprimir_Logo() {
	_sleep(800);

	for (int i = 0; i < 25; i++)
	{
		_sleep(300);
		for (int j = 0; j < 74; j++) {
			if (Logo[i][j] == 1) {
				Console::ForegroundColor = ConsoleColor::Red;
				cout << char(219);
			}
			if (Logo[i][j] == 0) {
				cout << " ";
			}
		}
		cout << endl;
	}

}
void draw() {
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			if (matrix[i][j] == 8) {
				Console::ForegroundColor = ConsoleColor(4);
				cout << (char)219 << (char)219 << (char)219;
			}
			//La comparación de matrix[i][j] == 0 es para cuando no está ocupado
			//También para piezas ocupadas del primer jugador, sin embargo, va a ser considerado como ocupado
			else if (matrix[i][j] == 0) {
				Console::ForegroundColor = ConsoleColor(15);
				cout << (char)219 << (char)219 << (char)219;
			}
			//La comparación de matrix[i][j] == 2 es para cuando está ocupado
			else if (matrix[i][j] == 2) {
				//Si el módulo es 0, el color de fondo será el mismo que si matrix[i][j] == 0
				if ((i + j) % 2 == 0) {
					Console::ForegroundColor = ConsoleColor(15);
					cout << (char)219;
					//Color elegido por el usuario, en este caso le pongo 3
					Console::ForegroundColor = ConsoleColor(3);
					cout << (char)35;
					Console::ForegroundColor = ConsoleColor(15);
					cout << (char)219;
				}
				else {
					Console::ForegroundColor = ConsoleColor(8);
					cout << (char)219;
					//Color elegido por el usuario, en este caso le pongo 3
					Console::ForegroundColor = ConsoleColor(3);
					cout << (char)35;
					Console::ForegroundColor = ConsoleColor(8);
					cout << (char)219;
				}
			}
			//También para piezas ocupadas del segundo jugador, sin embargo, va a ser considerado como ocupado
			else if (matrix[i][j] == 1) {
				Console::ForegroundColor = ConsoleColor(8);
				cout << (char)219 << (char)219 << (char)219;
			}
			else if (matrix[i][j] == 3) {
				if ((i + j) % 2 == 0) {
					Console::ForegroundColor = ConsoleColor(15);
					cout << (char)219;
					//Color elegido por el usuario, en este caso le pongo 5
					Console::ForegroundColor = ConsoleColor(5);
					cout << (char)64;
					Console::ForegroundColor = ConsoleColor(15);
					cout << (char)219;
				}
				else {
					Console::ForegroundColor = ConsoleColor(8);
					cout << (char)219;
					//Color elegido por el usuario, en este caso le pongo 5
					Console::ForegroundColor = ConsoleColor(5);
					cout << (char)64;
					Console::ForegroundColor = ConsoleColor(8);
					cout << (char)219;
				}
			}
		}
		cout << endl;
	}
	Console::ForegroundColor = ConsoleColor(1);
}
bool validate_placement(int& player) {
	if (x_1 < 0 || y_1 < 0 || x_1>6 || y_1>6) {
		system("cls");
		cout << "Las fichas no pueden ser colocadas afuera del tablero" << endl;
		cout << "Presione cualquer tecla para continuar" << endl;
		_getch();
		system("cls");
		draw();
		return false;
	}
	else if (x_1 == 0 || y_1 == 0 || x_1 == 6 || y_1 == 6) {
		system("cls");
		cout << "Las fichas no pueden ser posicionadas en los bordes del tablero" << endl;
		cout << "Presione cualquer tecla para continuar" << endl;
		_getch();
		system("cls");
		draw();
		return false;
	}
	else if (x_1 == 3 && y_1 == 3) {//Se usará las coordenadas destino : x_1 y y_1 para la colocación de fichas.
		system("cls");
		cout << "Las fichas no pueden ser posicionadas en el centro del tablero" << endl;
		cout << "Presione cualquer tecla para continuar" << endl;
		_getch();
		system("cls");
		draw();
		return false;
	}
	else if (matrix[y_1][x_1] == 2 || matrix[y_1][x_1] == 3) {//Valida que las casillas no estén ocupadas
		system("cls");
		cout << "No se pueden poner dos fichas en la misma casilla" << endl;
		cout << "Presione cualquier tecla para continuar" << endl;
		_getch();
		system("cls");
		draw();
		return false;
	}
	else {
		matrix[y_1][x_1] = player;
		system("cls");
		draw();
		return true;
	}
}
bool validate_selfPiece(int& player) {//Esta funcion verifica si la ficha seleccionada le corresponde al jugador, si es así retorna verdadero y permite seguir jugando
									 //Sino retornará falso, en ese caso el juego seguirá pidiendo coordenadas de la ficha del jugador hasta que sea una que le corresponde
	if (matrix[y][x] == player) {
		return true;
	}
	else {
		return false;
	}
}
bool validate_premovement() {//Después de haber seleccionado una pieza propia, verificará si es que la pieza se puede mover
	if ((matrix[y - 1][x] == 2 || matrix[y - 1][x] == 3 || matrix[y - 1][x] == 8) && (matrix[y + 1][x] == 2 || matrix[y + 1][x] == 3 || matrix[y + 1][x] == 8) &&
		(matrix[y][x - 1] == 2 || matrix[y][x - 1] == 3 || matrix[y][x - 1] == 8) && (matrix[y][x + 1] == 2 == 2 || matrix[y][x + 1] == 3 || matrix[y][x + 1] == 8)) {
		return false;
	}
	else {
		return true;
	}
}
bool validate_movement(int player) {//Valida si el movimiento introducido por el jugador es permitido
	if ((abs(x_1 - x) > 1 || abs(y_1 - y) > 1)) {
		system("cls");
		cout << "La ficha se puede mover solamente 1 casilla de forma ortogonal" << endl;
		cout << "Presione cualquier tecla para continuar" << endl;
		_getch();
		system("cls");
		draw();
		return false;
	}
	else if ((abs(x_1 - x) == 1) && (abs(y_1 - y) == 1)) {
		system("cls");
		cout << "La ficha no se puede moverse de forma diagonal" << endl;
		cout << "Presione cualquier tecla para continuar" << endl;
		_getch();
		system("cls");
		draw();
		return false;
	}
	else if (matrix[y_1][x_1] == 2 || matrix[y_1][x_1] == 3 || matrix[y_1][x_1] == 8) {//La casilla destino está ocupada
		system("cls");
		cout << "No se puede mover la ficha seleccionada a la casilla introducida (destino)" << endl;
		cout << "Presione cualquier tecla para continuar" << endl;
		_getch();
		system("cls");
		draw();
		return false;
	}
	else {
		matrix[y_1][x_1] = player; //Verifica y determina que es correcto el movimiento, por lo cual coloca la nueva ficha
		if ((x + y) % 2 == 0) {
			matrix[y][x] = 0; //Borra la ficha de la casilla anterior
		}
		else {
			matrix[y][x] = 1;
		}
		system("cls"); //Borra la pantalla para actualizar
		draw();
		return true;
	}
}
void validateKeepPlaying(int& a, int& player) {
	if (a == -1) {//Si presiona -1 acaba el juego
		system("cls");
		if (player == 2) {
			cout << "felicidades Jugador 1, usted gano" << endl;
			ganador();
			counter3 += 1;
		}
		if (player == 1) {
			cout << "felicidades Jugador 2, usted gano" << endl;
			ganador;
			counter2 += 1;
		}

		cout << "Gracias por jugar el juego, presiona cualquier tecla para salir" << endl;
		_getch();
		keepPlaying = false;
		system("cls");
	}
}

void validaCapturaFila(int player) {
	bool first;
	bool second;
	//Vamos en orden
	if (x_1 == 1) {
		if ((matrix[y_1][x_1 + 2] == player) && (matrix[y_1][x_1 + 1] != player && matrix[y_1][x_1 + 1] != 0 && matrix[y_1][x_1 + 1] != 1)) {
			//Comprueba si la pieza que está 2 a la derecha es la misma que la que se movió
			//También que la intermedia sea diferente
			if ((y_1 + x_1 + 1) % 2 == 0) {
				matrix[y_1][x_1 + 1] = 0;
			}
			else if ((y_1 + x_1 + 1) % 2 != 0) {
				matrix[y_1][x_1 + 1] = 1;
			}
		}
		if (player == 3) {
			eatenby3 += 1;
		}
		else if (player == 3) {
			eatenby2 += 1;
		}
		system("cls");
		draw();
	}
	if (x_1 == 2) {
		if (y_1 != 3) {//Primero que compruebe que no es en la tercera fila
			if ((matrix[y_1][x_1 + 2] == player) && (matrix[y_1][x_1 + 1] != player && matrix[y_1][x_1 + 1] != 0 && matrix[y_1][x_1 + 1] != 1)) {
				//Comprueba si la pieza que está 2 a la derecha es la misma que la que se movió
								//También que la intermedia sea diferente
				if ((y_1 + x_1 + 1) % 2 == 0) {
					matrix[y_1][x_1 + 1] = 0;
				}
				else if ((y_1 + x_1 + 1) % 2 != 0) {
					matrix[y_1][x_1 + 1] = 1;
				}
				if (player == 3) {
					eatenby3 += 1;
				}
				else if (player == 2) {
					eatenby2 += 1;
				}
				system("cls");
				draw();
				//return true;
			}
		}
		else if (y_1 == 3) {//No se puede comer al centro
			//return false;//sea cual sea la situación no hay captura
		}
	}
	if (x_1 == 3) {
		//Verificamos por el lado izquierdo
		if ((matrix[y_1][x_1 - 2] == player) && (matrix[y_1][x_1 - 1] != player && matrix[y_1][x_1 - 1] != 0 && matrix[y_1][x_1 - 1] != 1)) {
			if ((y_1 + x_1 - 1) % 2 == 0) {//Para que verifique si el casillero es negro o blanco
				matrix[y_1][x_1 - 1] = 0;
			}
			else if ((y_1 + x_1 - 1) % 2 != 0) {
				matrix[y_1][x_1 - 1] = 1;
			}
			if (player == 3) {//Para que cuente las fichas comidas por el jugador 3 (1)
				eatenby3 += 1;
			}
			else if (player == 2) {
				eatenby2 += 1;
			}
			first = true;
		}
		//Verificamos por el lado derecho
		if ((matrix[y_1][x_1 + 2] == player) && (matrix[y_1][x_1 + 1] != player && matrix[y_1][x_1 + 1] != 0 && matrix[y_1][x_1 + 1] != 1)) {
			if ((y_1 + x_1 + 1) % 2 == 0) {//Para que verifique si el casillero es negro o blanco
				matrix[y_1][x_1 + 1] = 0;
			}
			else if ((y_1 + x_1 + 1) % 2 != 0) {
				matrix[y_1][x_1 + 1] = 1;
			}
			if (player == 3) {//Para que cuente las fichas comidas por el jugador 3 (1)
				eatenby3 += 1;
			}
			else if (player == 2) {
				eatenby2 += 1;
			}
			second = true;
		}
		if (second == true || first == true) {
			system("cls");
			draw();
			//return true;
		}
	}
	if (x_1 == 4) {
		if (y_1 != 3) {//Primero que compruebe que no es en la tercera fila
			if ((matrix[y_1][x_1 - 2] == player) && (matrix[y_1][x_1 - 1] != player && matrix[y_1][x_1 - 1] != 0 && matrix[y_1][x_1 - 1] != 1)) {
				//Comprueba si la pieza que está 2 a la derecha es la misma que la que se movió
								//También que la intermedia sea diferente
				if ((y_1 + x_1 - 1) % 2 == 0) {
					matrix[y_1][x_1 - 1] = 0;
				}
				else if ((y_1 + x_1 - 1) % 2 != 0) {
					matrix[y_1][x_1 - 1] = 1;
				}
				if (player == 3) {
					eatenby3 += 1;
				}
				else if (player == 2) {
					eatenby2 += 1;
				}
				system("cls");
				draw();

				//return true;
			}
		}
		else if (y_1 == 3) {//No se puede comer al centro
			//return false;//sea cual sea la situación no hay captura
		}
	}
	if (x_1 == 5) {
		if ((matrix[y_1][x_1 - 2] == player) && (matrix[y_1][x_1 - 1] != player && matrix[y_1][x_1 - 1] != 0 && matrix[y_1][x_1 - 1] != 1)) {
			if ((y_1 + x_1 - 1) % 2 == 0) {//Para que verifique si el casillero es negro o blanco
				matrix[y_1][x_1 - 1] = 0;
			}
			else if ((y_1 + x_1 - 1) % 2 != 0) {
				matrix[y_1][x_1 - 1] = 1;
			}
			if (player == 3) {//Para que cuente las fichas comidas por el jugador 3 (1)
				eatenby3 += 1;
			}
			else if (player == 2) {
				eatenby2 += 1;
			}
			system("cls");
			draw();
		}
	}
	//limitaremos que la captura en el centro no sea posible
}

void validaCapturaColumna(int player) {
	bool first;
	bool second;
	//Vamos en orden
	if (y_1 == 1) {
		if ((matrix[y_1 + 2][x_1] == player) && (matrix[y_1 + 1][x_1] != player && matrix[y_1 + 1][x_1] != 0 && matrix[y_1 + 1][x_1] != 1)) {
			if ((y_1 + x_1 + 1) % 2 == 0) {
				matrix[y_1 + 1][x_1] = 0;
			}
			else if ((y_1 + x_1 + 1) % 2 != 0) {
				matrix[y_1 + 1][x_1] = 1;
			}
		}
		if (player == 3) {
			eatenby3 += 1;
		}
		else if (player == 3) {
			eatenby2 += 1;
		}
		system("cls");
		draw();
	}
	if (y_1 == 2) {
		if (x_1 != 3) {//Primero que compruebe que no es en la tercera columna
			if ((matrix[y_1 + 2][x_1] == player) && (matrix[y_1 + 1][x_1] != player && matrix[y_1 + 1][x_1] != 0 && matrix[y_1 + 1][x_1] != 1)) {
				if ((y_1 + x_1 + 1) % 2 == 0) {
					matrix[y_1 + 1][x_1] = 0;
				}
				else if ((y_1 + x_1 + 1) % 2 != 0) {
					matrix[y_1 + 1][x_1] = 1;
				}
				if (player == 3) {
					eatenby3 += 1;
				}
				else if (player == 2) {
					eatenby2 += 1;
				}
				system("cls");
				draw();
				//return true;
			}
		}
		else if (x_1 == 3) {//No se puede comer al centro
			//return false;//sea cual sea la situación no hay captura
		}
	}
	if (y_1 == 3) {
		//Verificamos por arriba
		if ((matrix[y_1 - 2][x_1] == player) && (matrix[y_1 - 1][x_1] != player && matrix[y_1 - 1][x_1] != 0 && matrix[y_1 - 1][x_1] != 1)) {
			if ((y_1 + x_1 - 1) % 2 == 0) {//Para que verifique si el casillero es negro o blanco
				matrix[y_1 - 1][x_1] = 0;
			}
			else if ((y_1 + x_1 - 1) % 2 != 0) {
				matrix[y_1 - 1][x_1] = 1;
			}
			if (player == 3) {//Para que cuente las fichas comidas por el jugador 3 (1)
				eatenby3 += 1;
			}
			else if (player == 2) {
				eatenby2 += 1;
			}
			first = true;
		}
		//Verificamos por abajo
		if ((matrix[y_1 + 2][x_1] == player) && (matrix[y_1 + 1][x_1] != player && matrix[y_1 + 1][x_1] != 0 && matrix[y_1 + 1][x_1] != 1)) {
			if ((y_1 + x_1 + 1) % 2 == 0) {//Para que verifique si el casillero es negro o blanco
				matrix[y_1 + 1][x_1] = 0;
			}
			else if ((y_1 + x_1 + 1) % 2 != 0) {
				matrix[y_1 + 1][x_1] = 1;
			}
			if (player == 3) {//Para que cuente las fichas comidas por el jugador 3 (1)
				eatenby3 += 1;
			}
			else if (player == 2) {
				eatenby2 += 1;
			}
			second = true;
		}
		if (second == true || first == true) {
			system("cls");
			draw();
			//return true;
		}
	}
	if (y_1 == 4) {
		if (x_1 != 3) {//Primero que compruebe que no es en la tercera columna
			if ((matrix[y_1 - 2][x_1] == player) && (matrix[y_1 - 1][x_1] != player && matrix[y_1][x_1 - 1] != 0 && matrix[y_1][x_1 - 1] != 1)) {
				//Comprueba si la pieza que está 2 a la derecha es la misma que la que se movió
								//También que la intermedia sea diferente
				if ((y_1 + x_1 - 1) % 2 == 0) {
					matrix[y_1 - 1][x_1] = 0;
				}
				else if ((y_1 + x_1 - 1) % 2 != 0) {
					matrix[y_1 - 1][x_1] = 1;
				}
				if (player == 3) {
					eatenby3 += 1;
				}
				else if (player == 2) {
					eatenby2 += 1;
				}
				system("cls");
				draw();

				//return true;
			}
		}
		else if (x_1 == 3) {//No se puede comer al centro
			//return false;//sea cual sea la situación no hay captura
		}
	}
	if (y_1 == 5) {
		if ((matrix[y_1 - 2][x_1] == player) && (matrix[y_1 - 1][x_1] != player && matrix[y_1 - 1][x_1] != 0 && matrix[y_1 - 1][x_1] != 1)) {
			if ((y_1 + x_1 - 1) % 2 == 0) {//Para que verifique si el casillero es negro o blanco
				matrix[y_1 - 1][x_1] = 0;
			}
			else if ((y_1 + x_1 - 1) % 2 != 0) {
				matrix[y_1 - 1][x_1] = 1;
			}
			if (player == 3) {//Para que cuente las fichas comidas por el jugador 3 (1)
				eatenby3 += 1;
			}
			else if (player == 2) {
				eatenby2 += 1;
			}
			system("cls");
			draw();
		}
	}
	//limitaremos que la captura en el centro no sea posible
}

void colocarfichas() {
	int limi = 0;
	bool a;
	int player;
	bool b;
	bool c;
	bool d;
	cout << "Bienvenido al juego, en esta primera etapa colocaremos las fichas" << endl;
	matrix[1][3] = 3;
	matrix[5][3] = 3;
	matrix[3][1] = 2;
	matrix[3][5] = 2;
	cout << "Presiona una tecla para continuar" << endl;
	_getch();
	system("cls");
	draw();
	while (limi < 5 && keepPlaying == true)
	{
		//Turno del jugador 1
		player = 3;
		cout << "Turno del jugador 1" << endl; // Introducción de la primera ficha
		cout << "Inserte el numero de la fila de la ficha 1 de este turno : " << endl;
		cout << "Si desea salir del juego o rendirse ingrese el numero -1" << endl;
		cin >> y_1;
		validateKeepPlaying(y_1, player);
		if (keepPlaying == false) {//Si presiona -1 acaba el juego
			continue;
		}
		cout << "Inserte el numero de la columna de la ficha 1 de este turno : " << endl;
		cout << "Si desea salir del juego o rendirse ingrese el numero -1" << endl;
		cin >> x_1;
		validateKeepPlaying(x_1, player);
		if (keepPlaying == false) {//Si presiona -1 acaba el juego
			continue;
		}
		a = validate_placement(player);
		if (a == false) {
			continue;
		}
		cout << "Turno del jugador 1" << endl;
		cout << "Inserte el numero de la fila de la ficha 2 de este turno : " << endl;
		cout << "Si desea salir del juego o rendirse ingrese el numero -1" << endl; //Introducción de la segunda ficha
		cin >> y_1;
		validateKeepPlaying(y_1, player);
		if (keepPlaying == false) {//Si presiona -1 acaba el juego
			continue;
		}
		cout << "Inserte el numero de la columna de la ficha 2 de este turno : " << endl;
		cout << "Si desea salir del juego o rendirse ingrese el numero -1" << endl;
		cin >> x_1;
		validateKeepPlaying(x_1, player);
		if (keepPlaying == false) {//Si presiona -1 acaba el juego
			continue;
		}
		b = validate_placement(player);
		while (b == false && keepPlaying == true) {
			cout << "Inserte el numero de la fila adecuado : " << endl;
			cout << "Si desea salir del juego o rendirse ingrese el numero -1" << endl;
			cin >> y_1;
			validateKeepPlaying(y_1, player);
			if (keepPlaying == false) {//Si presiona -1 acaba el juego
				continue;
			}
			cout << "Inserte el numero de la columna adecuado : " << endl;
			cout << "Si desea salir del juego o rendirse ingrese el numero -1" << endl;
			cin >> x_1;
			validateKeepPlaying(x_1, player);
			if (keepPlaying == false) {//Si presiona -1 acaba el juego
				continue;
			}
			b = validate_placement(player);
		}
		//Turno del jugador 2
		player = 2;
		cout << "Turno del jugador 2" << endl; // Introducción de la primera ficha
		cout << "Inserte el numero de la fila de la ficha 1 de este turno : " << endl;
		cout << "Si desea salir del juego o rendirse ingrese el numero -1" << endl;
		cin >> y_1;
		validateKeepPlaying(y_1, player);
		if (keepPlaying == false) {//Si presiona -1 acaba el juego
			continue;
		}
		cout << "Inserte el numero de la columna de la ficha 1 de este turno : " << endl;
		cout << "Si desea salir del juego o rendirse ingrese el numero -1" << endl;
		cin >> x_1;
		validateKeepPlaying(x_1, player);
		if (keepPlaying == false) {//Si presiona -1 acaba el juego
			continue;
		}
		c = validate_placement(player);
		while (c == false && keepPlaying == true) {
			cout << "Inserte el numero de la fila adecuado : " << endl;
			cout << "Si desea salir del juego o rendirse ingrese el numero -1" << endl;
			cin >> y_1;
			validateKeepPlaying(y_1, player);
			if (keepPlaying == false) {//Si presiona -1 acaba el juego
				continue;
			}
			cout << "Inserte el numero de la columna adecuado : " << endl;
			cout << "Si desea salir del juego o rendirse ingrese el numero -1" << endl;
			cin >> x_1;
			validateKeepPlaying(x_1, player);
			if (keepPlaying == false) {//Si presiona -1 acaba el juego
				continue;
			}
			c = validate_placement(player);
		}
		cout << "Turno del jugador 2" << endl;
		cout << "Inserte el numero de la fila de la ficha 2 de este turno : " << endl;//Introducción de la segunda ficha
		cout << "Si desea salir del juego o rendirse ingrese el numero -1" << endl;
		cin >> y_1;
		validateKeepPlaying(y_1, player);
		if (keepPlaying == false) {//Si presiona -1 acaba el juego
			continue;
		}
		cout << "Inserte el numero de la columna de la ficha 2 de este turno : " << endl;
		cout << "Si desea salir del juego o rendirse ingrese el numero -1" << endl;
		cin >> x_1;
		validateKeepPlaying(x_1, player);
		if (keepPlaying == false) {//Si presiona -1 acaba el juego
			continue;
		}
		d = validate_placement(player);
		while (d == false && keepPlaying == true) {
			cout << "Inserte el numero de la fila adecuado : " << endl;
			cout << "Si desea salir del juego o rendirse ingrese el numero -1" << endl;
			cin >> y_1;
			validateKeepPlaying(y_1, player);
			if (keepPlaying == false) {//Si presiona -1 acaba el juego
				continue;
			}
			cout << "Inserte el numero de la columna adecuado : " << endl;
			cout << "Si desea salir del juego o rendirse ingrese el numero -1" << endl;
			cin >> x_1;
			validateKeepPlaying(x_1, player);
			if (keepPlaying == false) {//Si presiona -1 acaba el juego
				continue;
			}
			d = validate_placement(player);
		}
		if (a == true && b == true && c == true && d == true) {
			limi++;
		}
	}
}
void moving() {
	bool p;
	bool q;
	bool r;
	bool continue_capturing;
	int player;
	cout << "Gracias por colocar todas las fichas, ahora procederemos a la segunda fase, la fase de movimientos\n";
	while (keepPlaying) {//Aquí Mientras se puede seguir jugando

		//Turno del Jugador 2
		cout << "Turno del jugador 2" << endl;
		player = 2;
		cout << "Inserte el numero de la fila de la ficha que desea mover  : " << endl;
		cout << "Si desea salir del juego ingrese el numero -1" << endl;
		cout << "Si desea ceder el turno ingrese el numero -2" << endl;
		cin >> y;
		validateKeepPlaying(y, player);
		if (keepPlaying == false) {//Si presiona -1 acaba el juego
			continue;
		}
		if (y != -2) {//Si es que no cede el turno sigue jugando
			cout << "Inserte el numero de la columna de la ficha que desea mover  :" << endl;
			cout << "Si desea salir del juego ingrese el numero -1" << endl;
			cout << "Si desea ceder el turno ingrese el numero -2" << endl;
			cin >> x;
			if (x != -2) {//Si es que no cede el turno sigue jugando
				validateKeepPlaying(x, player);
				if (keepPlaying == false) {//Si presiona -1 acaba el juego
					continue;
				}//Si es que no cedió el turno y no salió del juego
				p = validate_selfPiece(player);
				if (p == false) {
					continue;
				}
				q = validate_premovement();
				if (q == false) {
					cout << "La ficha seleccionada no puede moverse" << endl;
					continue;
				}
				cout << "Ingrese el numero de la fila de la casilla destino  : " << endl;
				cin >> y_1;
				cout << "Ingrese el numero de la columna de la casilla destino  : " << endl;
				cin >> x_1;
				r = validate_movement(player);
				while (r == false) {
					cout << "Ingrese el numero adecuado de la fila de la casilla destino  : " << endl;
					cin >> y_1;
					cout << "Ingrese el numero adecuado de la columna de la casilla destino  : " << endl;
					cin >> x_1;
					r = validate_movement(player);
				}
				validaCapturaFila(player);
				validaCapturaColumna(player);
			}
		}
		if (keepPlaying == false) {
			system("cls");
			continue;
		}
		//Turno del primer jugador
		cout << "Turno del jugador 1" << endl;
		player = 3;
		cout << "Inserte el numero de la fila de la ficha que desea mover  : " << endl;
		cout << "Si desea salir del juego ingrese el numero -1" << endl;
		cout << "Si desea ceder el turno ingrese el numero -2" << endl;
		cin >> y;
		validateKeepPlaying(y, player);
		if (keepPlaying == false) {//Si presiona -1 acaba el juego
			continue;
		}
		if (y != -2) {//Si es que no cede el turno sigue jugando
			cout << "Inserte el numero de la columna de la ficha que desea mover  :" << endl;
			cout << "Si desea salir del juego ingrese el numero -1" << endl;
			cout << "Si desea ceder el turno ingrese el numero -2" << endl;
			cin >> x;
			if (x != -2) {//Si es que no cede el turno sigue jugando
				validateKeepPlaying(x, player);
				if (keepPlaying == false) {//Si presiona -1 acaba el juego
					continue;
				}//Si es que no cedió el turno y no salió del juego
				p = validate_selfPiece(player);
				if (p == false) {
					continue;
				}
				q = validate_premovement();
				if (q == false) {
					cout << "La ficha seleccionada no puede moverse" << endl;
					continue;
				}
				cout << "Ingrese el numero de la fila de la casilla destino  : " << endl;
				cin >> y_1;
				cout << "Ingrese el numero de la columna de la casilla destino  : " << endl;
				cin >> x_1;
				r = validate_movement(player);
				while (r == false) {
					cout << "Ingrese el numero adecuado de la fila de la casilla destino  : " << endl;
					cin >> y_1;
					cout << "Ingrese el numero adecuado de la columna de la casilla destino  : " << endl;
					cin >> x_1;
					r = validate_movement(player);
				}
				validaCapturaFila(player);
				validaCapturaColumna(player);
			}
		}
		if (keepPlaying == false) {
			system("cls");
			continue;
		}
	}
}
void game() {
	colocarfichas();
	if (keepPlaying) {
		moving();
	}
	Console::ForegroundColor = ConsoleColor(3);
}
void logo()
{
	cout << "\n.......................................................................................................";
	cout << "\n.......................................................................................................";
	cout << "\n.....  &&&&&&&&&&&&& ...... ########## .... ########## .... %%%%%%%%%%%%% ........... #### ............";
	cout << "\n.....  &&&&&&&&&&&&& ...... ########## .... ########## .... %%%%%%%%%%%%% .......... ###### ...........";
	cout << "\n.....  &&&&&         ...... ###        .... ###        .... %%%           ......... ###  ### ..........";
	cout << "\n.....  &&&&&         ...... ########## .... ########## .... %%%    %%%%%% ........ ###    ### .........";
	cout << "\n.....  &&&&&&&&&&&&& ...... ########## .... ########## .... %%%    %%%%%% ....... ###      ### ........";
	cout << "\n.....  &&&&&&&&&&&&& ...... ###        .... ###        .... %%%       %%% ...... ###        ### .......";
	cout << "\n.....        &&&&&&& ...... ###        .... ###        .... %%%       %%% ..... ################ ......";
	cout << "\n..... &&&&&&&&&&&&&& ...... ########## .... ########## .... %%%%%%%%%%%%% .... ###            ### .....";
	cout << "\n..... &&&&&&&&&&&&&& ...... ########## .... ########## .... %%%%%%%%%%%%% ... ###              ### ....";
	cout << "\n.......................................................................................................";
	cout << "\n......................................... version 6.2 .................................................";
	cout << endl;
	cout << endl;
}
void integrantes() {

	cout << "\nINTEGRANTES: ";
	cout << "\n - Barzola Gutierrez, Geanfranco Edu";
	cout << "\n - Alarcon Rondon, Sandro Fourfive";
	cout << "\n - Bravo Rubina, Conrad Jefferson";
	cout << endl;
	cout << endl;
}
void menu()
{

	cout << "\n\nBienvenido al juego Seega en C++";
	cout << "\n======================================";
	cout << "\nSeleccione una opcion: ";
	cout << "\n\n1. Empezar a jugar";
	cout << "\n2. Leer las intrucciones";
	cout << "\n3. Salir de la consola";
	cout << "\n4. Mostrar integrantes";
	cout << "\n\nElije una opcion: ";
}
void instrucciones()
{
	cout << "\n\tINSTRUCCIONES:";
	cout << "\n******";
	cout << "\n*                                                                                                                    *";
	cout << "\n*  + Cada jugador dispone de 12 fichas de un mismo color ...                                                         *";
	cout << "\n*  + El Juego se divide en 2 fases...                                                                                *";
	cout << "\n*  + La primera fase los 2 jugadores por turno van colocando fichas en cualquier casilla vacia salvo la del centro   *";
	cout << "\n*  + La casilla del centro estara vacia hasta la segunda fase del juego ...                                          *";
	cout << "\n*  + El jugador que coloque las 2 ultimas fichas es quien comienza la segunda fase ...                               *";
	cout << "\n*  + Cada jugador tendra la opcion de mover su pieza ...                                                             *";
	cout << "\n*  + Las fichas se mueven una posicion vertical u horizontal,pero no en diagonal ...                                 *";
	cout << "\n*  + Una ficha es capturada y removida si esta es encerrada entre dos fichas contrarias (no en sentido diagonal)...  *";
	cout << "\n*  + Un solo movimiento puede implicar el encierro y la captura de varias piezas a la vez...                         *";
	cout << "\n*  + El jugador que realiza una captura puede seguir moviendo la misma ficha que ...                                 *";
	cout << "\n*    Realizó el último movimiento mientras siga capturando...                                                        *";
	cout << "\n*  + Una ficha que se coloca voluntariamente entre dos fichas enemigas no es capturada,..                            *";
	cout << "\n*    Salvo si una de las piezas enemigas se retira y vuelve...                                                       *";
	cout << "\n*  + La ficha que ocupa la casilla central (marcada con x) no puede ser capturada..                                  *";
	cout << "\n*  + Cuando un jugador no puede mover le pasa el turno, al contrario...                                              *";
	cout << "\n*  + Una partida finaliza cuando se da una de las siguientes situaciones:                                            *";
	cout << "\n*                                                                                                                    *";
	cout << "\n*  - Un jugador se queda sin piezas sobre el tablero ...                                                             *";
	cout << "\n*  - Un jugador puede construir una barrera (o muro) con fichas detrás de la cual solo se encuentran ...             *";
	cout << "\n*    sus propias fichas que pueden moverse sin peligro de ser capturadas...                                          *";
	cout << "\n*  - En el caso de existir una barrera gana el jugador...                                                            *";
	cout << "\n*    que tiene la mayor cantidad de fichas, si tienen la misma cantidad es un empate...                              *";
	cout << "\n******";
	cout << endl;
}
void introduce_nombre() {
	cout << "Ingrese su nombre" << endl;;
}
int main()
{
	int opcion;
	int opc;
	void draw();
	void game();
	string name1;
	string name2;
	Console::SetWindowSize(100, 40);//Adaptar después
	Console::Title = "SEEGA";
	imprimir_Logo();
	do
	{
		system("cls");
		do {
			system("cls");
			Console::ForegroundColor = ConsoleColor(15);
			logo();
			Console::ForegroundColor = ConsoleColor(3);
			system("pause");
			system("cls");
			menu();
			cin >> opcion;
		} while (opcion < 1 || opcion>4);
		switch (opcion)
		{
		case 1:
		{
			system("cls");
			while (name1.length() == 0 && name2.length() == 0) {
				system("cls");
				cout << "\nPara empezar el juego, primero es necesario que registren sus nombres";
				cout << "\n---------------------------------------------------------------------";
				cout << "\n\nIngrese el nombre del jugador 1: ";
				cin >> name1;
				cout << "\nIngrese el nombre del jugador 2: ";
				cin >> name2;
			}
			system("cls");
			draw();
			game();
			break;
		}
		case 2:
		{
			system("cls");
			instrucciones();
			break;
		}
		case 3:
		{
			return 0;
		}
		case 4:
		{
			system("cls");
			integrantes();
			break;
		}
		}
		new_matrix();//Después de que acaba un juego se limpia el trablero y reinician contadores publicos
		keepPlaying = true;
		eatenby2 = 0;
		eatenby3 = 0;
		new_matrix();
		system("pause");
		cout << "\n\nDesea continuar con el Menu Principal...";
		cout << "\nSi ------ 1";
		cout << "\nNo ------ 2";
		cout << "\nElegir opcion: ";
		cin >> opc;
	} while (opc == 1);
	return 0;
}