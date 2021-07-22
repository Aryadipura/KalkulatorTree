/** Nama File : bintree.h
 *  Deskripsi : File header ADT Tree
 *  Oleh      : Lamda Richo Vanjaya Sumaryadi
 *  Tanggal   : 21 Juli 2021
 */

#ifndef BINTREE_H
#define BINTREE_H

#define Nil NULL
#define Info(P) (P)->info
#define Left(P) (P)->left
#define Right(P) (P)->right
#define Next(P) (P)->next

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "stackChar.h" 
#include "boolean.h"

typedef char String[50];

typedef char infotypeTree[10];
typedef struct treeNode *addressTree;
typedef struct treeNode {
			infotypeTree info;
			addressTree left;
			addressTree right;
		} tTreeNode;
typedef addressTree BinTree;

/*Hasil Alokasi Ekspresi Tree menghasilkan address */
addressTree AlokasiTree(infotypeTree X);

/* Return true jika ekspresi tree kosong dan sebaliknya */
boolean isEmptyTree(BinTree P);

/* Mengembalikan anak kiri dari sebuah ekspresi tree */
BinTree LeftChild(BinTree P);

/* Mengembalikan anak kanan dari sebuah ekspresi tree */
BinTree RightChild(BinTree P);

/* Membuat sebuah ekspresi Node Tree baru tetapi belum ada ikatan(tali) dalam tree */
void CreateNode(BinTree *P, infotypeTree X);

/* Membuat agar sebuah tree terdefinisi (punya ikatan) */
void CreateTree(infotypeTree X, BinTree L, BinTree R, BinTree *P);

/* Memperlihatkan informasi tentang beberapa node dari sebuah ekspresi tree */
void ShowInfoTree(BinTree P);

/* Mengkonversi string menjadi float */
float StringToFloat(String X);

/* Return true jika karakter yang dicek atau diperiksa merupakan sebuah operator */
boolean isOperator(char c);

/* Mengembalikan nilai prioritas dari sebuah operator (semakin besar nilai, prioritas semakin diutamakan) */
boolean Priority(char x);

/* Mengembalikan true jika operator1 memiliki prioritas yang lebih tinggi daripada operator2 */
int isPriority(char a, char b);

/* Mengembalikan hasil kalkulasi dari ekspresi sebuah tree */
float CalculationOfTree(BinTree P); 

#endif