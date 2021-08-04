/** Nama File : BinaryTree.c
 *  Deskripsi : File Body Binary Tree sebagai perantara untuk membuat tree dalam modul BuildExpressionTree dalam KalkulatorTree.c
 *  Oleh      : Lamda Richo Vanjaya Sumaryadi
 *  Tanggal   : 21 Juli 2021
 * 	Tanggal Modifikasi : 31 Juli 2021 
 */

#include "BinaryTree.h"

/* Return true jika ekspresi tree kosong dan sebaliknya */
boolean IsEmptyTree(BinTree P){
  return (P == Nil); 
}

/*Hasil Alokasi Ekspresi Tree menghasilkan address */
addressTree AlokasiTree(infotypeTree X){
  addressTree P;

  P = (addressTree)malloc(sizeof(treeNode));
  if (P != Nil){
    strcpy(Info(P),X);
    Left(P) = Nil;
    Right(P) = Nil;
  }
  return P;
}

/* Membuat agar sebuah tree punya anak */
void CreateTree(infotypeTree X, BinTree L, BinTree R, BinTree *P){
  *P=AlokasiTree(X);
	if(*P!=Nil) {
		strcpy(Info(*P),X);
	   	Left(*P)=L;
		Right(*P)=R;	
  }
}

/* Membuat sebuah ekspresi Node Tree baru tetapi belum ada anak */
void CreateNodeTree(BinTree *P, infotypeTree X){
 *P=AlokasiTree(X);
	if(*P!=Nil) {
		strcpy(Info(*P),X);
	    Left(*P)=Right(*P)=Nil;
	} 
} 

/* Mengembalikan anak kiri dari sebuah ekspresi tree */
BinTree LeftChild(BinTree P){
  return Left(P);
}

/* Mengembalikan anak kanan dari sebuah ekspresi tree */
BinTree RightChild(BinTree P){
  return Right(P);
}

/* Memperlihatkan informasi dari setiap node dari sebuah ekspresi tree */
void ShowInfoTree(BinTree P){
  BinTree L, R; //L sebagai anak kiri dan R sebagai anak kanan
  
  if(P != Nil){ //Cek apakah node P tidak kosong, jika iya lanjut ke proses selanjutnya
    ShowInfoTree(Left(P)); //rekursif
    printf("Info Node\t: %s\n", Info(P)); //Mencetak output dari info(P)
    if(LeftChild(P) != Nil){ //Cek apakah anak kiri dari node P tidak kosong
      L = LeftChild(P); //L diisi oleh info anak kiri dari P
      printf("Left Child\t: %s\n", Info(L));//Mencetak output dari anak kiri dari P
    } else{ //Jika anak kiri dari node P kosong
      printf("Left Child\t: NULL\n"); //Cetak output null untuk anak kirinya
    }
    if(RightChild(P) != Nil){ //Jika anak kanan tidak kosong
      R = RightChild(P); //R diisi info dari anak kanannya P
      printf("Right Child\t: %s\n", Info(R)); //R dicetak ke layar
    } else{ //Jikan anak kanan kosong
      printf("Right Child\t: NULL\n");//R dicetak ke layar null
    }
    printf("\n");
    ShowInfoTree(Right(P));//Rekursif
  }
}

/* Mengkonversi string menjadi float */
float StringToFloat(String X){
  return atof(X);
}

/* Mengembalikan nilai prioritas dari sebuah operator (semakin besar nilai, prioritas semakin diutamakan) */
int Priority(char x){
  switch(x){
    case ')' : return 0;
    case '(': return 0;
    case '+': return 1;
    case '-': return 1;
    case '*': return 2;
    case 'x': return 2;
    case '/': return 2;
    case ':': return 2;
	case '^': return 3;   
    case 'v': return 3;
  }
}


/* Mengembalikan true jika operator1 memiliki prioritas yang lebih tinggi daripada operator2 */
boolean isPriority(char a, char b){
  return (Priority(a) >= Priority(b));
} 

/* Return true jika karakter yang dicek atau diperiksa merupakan sebuah operator */
boolean isOperator(char c){
  return(c=='+' || c=='-' || c=='*' || c=='x' || c=='/' || c ==':' || c =='^' || c=='v');
}

