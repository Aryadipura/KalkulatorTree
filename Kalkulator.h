/** Nama File : Kalkulator.h
 *  Deskripsi : File Header ADT Kalkulator
 *  Oleh      : Fiora Berliana Putri
 *  Tanggal   : 24 Juli 2021
 */

#ifndef KALKULATOR_H
#define KALKULATOR_H

#include "StackTree.h"
#include "bintree.h"
#include "BangunDatar.h"

/* Membuat sebuah ekspresi tree dari ekspresi postfix yang sudah didapatkan. 
 * I.S. : Postfix terdefinisi.
 * F.S. : Mengembalikan ekspresi tree.
 */
BinTree BuildExpressionTree(infotypeTree postfix);

/* Mengkonversi ekspresi infix menjadi ekspresi postfix.
 * I.S. : Infix terdefinisi.
 * F.S. : Infix berhasil dikonversi menjadi ekspresi postfix.
 */
void InfixToPostfix(String infix, String postfix);

/* Mengembalikan hasil kalkuasi dari ekspresi tree.
 * I.S. : P terdefinisi.
 * F.S. : Hasil kalkulasi dari P dikembalikan.
 */
float CalculationOfTree(BinTree P);

/* Menampilkan menu untuk kalkulator.
 * I.S. : Sembarang.
 * F.S. : Menu untuk kalkulator ditampilkan.
 */
void MenuKalkulator();

/* Menampilkan menu untuk bangun datar.
 * I.S. : Sembarang.
 * F.S. : Menu untuk bangun datar ditampilkan.
 */
void MenuBangunDatar();

/* Menampilkan informasi mengenai developer.
 * I.S. : Sembarang.
 * F.S. : Informasi mengenai developer ditampilkan.
 */
void About();

/* Menampilkan menu utama aplikasi kalkulator.
 * I.S. : Sembarang.
 * F.S. : Menu utama aplikasi ditampilkan.
 */
int mainMenu();

#endif
