/** Nama File : KalkulatorTree.c
 *  Deskripsi : File Body ADT Kalkulator
 *  Oleh      : Fiora Berliana Putri
 *  Tanggal   : 24 Juli 2021
 * 
 *  Modifikasi: Lamda Richo Vanjaya Sumaryadi
 *  Tanggal   : 25 Juli 2021 dan 31 Juli 2021
 */

#include "KalkulatorTree.h"

/* Membuat sebuah ekspresi tree dari ekspresi postfix yang sudah didapatkan. 
 * I.S. : Postfix terdefinisi.
 * F.S. : Mengembalikan ekspresi tree.
 */
BinTree BuildExpressionTree(infotypeTree postfix){
	int i = 0, j, k;
	StackTree StackTree;
	BinTree ExpressionTree, Right, Left;
	infotypeStackTree Delete;
	infotypeTree tempOperator, tempStr;
	
	NewStackTree(&StackTree);
	while(i < strlen(postfix)){
		//untuk operand
		if (!isOperator(postfix[i]) && postfix[i] != ' '){
			j = 0;
			tempStr[j] = postfix[i];
			while(!isOperator(postfix[i+1]) && postfix[i+1] != ' '){
				tempStr[j+1] = postfix[i+1];
				j++;
				i++;	
			}
			CreateNodeTree(&ExpressionTree, tempStr);
			for(k = 0; k < strlen(tempStr); k++) {
				tempStr[k] = ' ';
			}
			AddStackTree(&StackTree, ExpressionTree);
		}
		//untuk kasus operasi -
		else if(postfix[i] == '-' && isOperator(postfix[i-4])) { 
		tempOperator[0] = postfix[i];
		CreateNodeTree(&ExpressionTree, tempOperator);
		
		Right = Info(Top(StackTree));
		DellStackTree(&StackTree, &Delete);
							 
		Left = Info(Top(StackTree));
		DellStackTree(&StackTree, &Delete);
			
		CreateTree(tempOperator, Left, Right, &ExpressionTree);
			
		AddStackTree(&StackTree, ExpressionTree); 
		} 
		//untuk kasus operasi -
		else if((postfix[i]=='-' && postfix[i-1]==' ' && postfix[i+1]!=' ' && postfix[i+2]!=' ' && !isOperator(postfix[i+2])) || 
				(postfix[i]=='-' && postfix[i-1]!=' ' && postfix[i+1]==' ') || 
				(postfix[i]=='-' && postfix[i-1]!=' ' && isOperator(postfix[i+1])) ||
				(postfix[i]=='-' && postfix[i-1]==' ' && postfix[i+1]==' ') ||
				(postfix[i]=='-' && postfix[i-1]==' ' && postfix[i+1]!=' ' && isOperator(postfix[i+2])) ||
				(postfix[i]=='-' && postfix[i-1]!=' ' && isOperator(postfix[i+1]) && isOperator(postfix[i+2]) )) { 
			tempOperator[0] = postfix[i];
			CreateNodeTree(&ExpressionTree, tempOperator);
		
			Right = Info(Top(StackTree));
			DellStackTree(&StackTree, &Delete);
			
			Left = Info(Top(StackTree));
			DellStackTree(&StackTree, &Delete);
			
			CreateTree(tempOperator, Left, Right, &ExpressionTree);
			
			AddStackTree(&StackTree, ExpressionTree); 
		}
		//untuk operator
		else if(postfix[i] != ' ') { 
			tempOperator[0] = postfix[i];
			CreateNodeTree(&ExpressionTree, tempOperator);
		
			Right = Info(Top(StackTree));
			DellStackTree(&StackTree, &Delete);
							 
			Left = Info(Top(StackTree));
			DellStackTree(&StackTree, &Delete);
			
			CreateTree(tempOperator, Left, Right, &ExpressionTree);
			
			AddStackTree(&StackTree, ExpressionTree); 
		}
		i++;					
	}
	ExpressionTree = Info(Top(StackTree));
	DellStackTree(&StackTree, &ExpressionTree);
	return ExpressionTree;
}

/* Mengkonversi ekspresi infix menjadi ekspresi postfix.
 * I.S. : Infix terdefinisi.
 * F.S. : Infix berhasil dikonversi menjadi ekspresi postfix.
 */
void InfixToPostfix(String infix, String postfix){
	int i, ukuran, index = 0;
	char tempChar;
    StackChar temp;
    
    NewStackChar(&temp);
    
    ukuran = strlen(infix);
    for(i = 0; i < ukuran; i++) {
        switch(infix[i]) {
        	case '.':
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                postfix[index] = infix[i];
                index++;
                break;
            case '+':
            case '-':
            case '*':
            case 'x':
            case '/':
            case ':':
            case '^':
						case 'v':
                postfix[index] = ' ';
                index++;            
                if(isEmptyStackChar(temp)){
                    AddStackChar(&temp,infix[i]);
                }
				else if(!isPriority(Info(Top(temp)),infix[i])){
                    AddStackChar(&temp,infix[i]);
                }
				else{
                    while(!isEmptyStackChar(temp)&&isPriority(Info(Top(temp)),infix[i])){
                        DellStackChar(&temp,&tempChar);
                        postfix[index] = tempChar;
                        index++;
                    }                
                    AddStackChar(&temp,infix[i]);
                }
                break;
            case ')':
                while(!isEmptyStackChar(temp)&&Info(Top(temp))!='('){
                    DellStackChar(&temp,&tempChar);
                    postfix[index] = tempChar;
                    index++;                    
                }
                DellStackChar(&temp,&tempChar);
                break;
            case '(':
                AddStackChar(&temp,infix[i]);
                break;
        }
    }
    while(!isEmptyStackChar(temp)) {
        DellStackChar(&temp,&tempChar);
        postfix[index] = tempChar;
        index++;                  
    }    
    postfix[index] = '\0';
}

/* Mengembalikan hasil kalkuasi dari ekspresi tree.
 * I.S. : P terdefinisi.
 * F.S. : Hasil kalkulasi dari P dikembalikan.
 */
float CalculationOfTree(BinTree P){
	int i;
	  
    if(IsEmptyTree(P)) {
        return 0;  
	}
	//untuk leaf node
    else if(IsEmptyTree(Left(P)) && IsEmptyTree(Right(P))) {
    	//konversi dari char ke float
        return StringToFloat(Info(P));  
    }
  
	//rekursif 
    float left = CalculationOfTree(Left(P));  
    float right = CalculationOfTree(Right(P));  
    
    if(strcmp(Info(P),"+")==0) {
		return left+right;
	}
	else if(strcmp(Info(P),"-")==0) {
		return left-right;
	}
	else if(strcmp(Info(P),"*")==0) {
		return left*right;
	}
	else if(strcmp(Info(P),"x")==0) {
		return left*right;
	}
	else if(strcmp(Info(P),"/")==0) {
		if(right != 0.00){
			return left/right;
		} else{
			puts("Tidak bisa dibagi oleh nol");
			return 0;
		}
	}
	else if(strcmp(Info(P),":")==0) {
		if(right != 0.00){
			return left/right;
		} else{
			puts("Tidak bisa dibagi oleh nol");
			return 0;
		}
	}
	else if(strcmp(Info(P),"^")==0) {
		return pow(left, right);
	}
	else if(strcmp(Info(P),"v")==0){
		return sqrt(right);
	}
}

/* Menampilkan menu untuk kalkulator.
 * I.S. : Sembarang.
 * F.S. : Menu untuk kalkulator ditampilkan.
 */
void MenuKalkulator(){
	BinTree expTree;
	String postfix, input;
	
	system("cls");
	puts("\n\t\t\t Aplikasi Kalkulator \n");
	printf("Petunjuk : ");
	printf("\n1. Gunakan '^' untuk melakukan operasi perpangkatan.");
	printf("\n2. Gunakan '*' atau 'x' untuk melakukan operasi perkalian.");
	printf("\n3. Gunakan ':' atau '/' untuk melakukan operasi pembagian.");
	printf("\n4. Gunakan '+' untuk melakukan operasi penjumlahan.");
	printf("\n5. Gunakan '-' untuk melakukan operasi pengurangan.");
	printf("\n6. Gunakan '2v' untuk melakukan operasi akar pangkat 2.");
	printf("\n7. Dapat menambahkan '(' dan ')' ke dalam operasi perhitungan.");
	printf("\n8. Bilangan yang berlaku adalah bilangan bulat.");
	printf("\n9. Dilarang untuk menggunakan spasi. \n");
	printf("\n\n");
	system("PAUSE");
	system("cls");
	puts("\n\t\t\t Aplikasi Kalkulator \n");
	printf("Lakukan perhitungan :\n\n"); 
	scanf("%s", input);
	InfixToPostfix(input, postfix);
	printf("\n");
	expTree = BuildExpressionTree(postfix);
	printf("= %.2f\n", CalculationOfTree(expTree)); 
	
}

/* Menampilkan menu untuk bangun datar.
 * I.S. : Sembarang.
 * F.S. : Menu untuk bangun datar ditampilkan.
 */
void MenuBangunDatar(){
	int nomor;

	system("cls");
	puts("\n\t\t Bangun Datar ");
	printf("\nBangun datar yang tersedia :\n");
	puts("1. Persegi");
	puts("2. Persegi Panjang");
	puts("3. Segitiga");
	puts("4. Trapesium");
	puts("5. Jajar Genjang");
	puts("6. Belah Ketupat");
	puts("7. Layang-Layang");
	puts("8. Lingkaran");
	
	printf("\nMasukkan pilihan sesuai nomor : ");
	scanf("%d", &nomor);
	switch(nomor) {	
	    case 1 :
	    	system("cls");
	    	HitungPersegi();
			break;
		case 2 :
			system("cls");
			HitungPersegiPanjang();
			break;
		case 3 :
			system("cls"); 
			HitungSegitiga();
			break;
		case 4 :
			system("cls");
			HitungTrapesium();
			break;
		case 5 :
			system("cls");
			HitungJajarGenjang(); 
			break;
		case 6 : 
			system("cls");
			HitungBelahKetupat();
			break;
		case 7 :
			system("cls");
			HitungLayangLayang();
			break;
		case 8 :
			system("cls"); 
			HitungLingkaran();
			break;
		default :
			puts("\nNomor yang Anda masukkan tidak valid!");
			puts("Silakan coba kembali :)");
	}
}

/* Menampilkan informasi mengenai developer.
 * I.S. : Sembarang.
 * F.S. : Informasi mengenai developer ditampilkan.
 */
void About(){
	system("cls");
	printf("\n\t\t About \n");
	printf("\nAplikasi Kalkulator ini dibuat oleh : ");
	printf("\nFiora Berliana Putri - 201524045");
	printf("\nLamda Richo Vanjaya Sumaryadi - 201524049");
	printf("\nMuhamad Aryadipura Sasmita Atmadja - 201524054");
	printf("\nUntuk memenuhi Tugas Besar mata kuliah Struktur Data dan Algoritma.\n");
}

/* Menampilkan menu utama aplikasi kalkulator.
 * I.S. : Sembarang.
 * F.S. : Menu utama aplikasi ditampilkan.
 */
int mainMenu(){
	int i;
	int nomor;
	
	while(i <= 100) {
		puts("\n\t\t Aplikasi Kalkulator \t\t");
		puts("\nMain Menu\n ");
		puts("1. Kalkulator");
		puts("2. Bangun Datar");
		puts("3. About");
		puts("4. Exit");
		printf("Masukkan pilihan sesuai nomor : ");
		scanf("%d", &nomor);
		switch(nomor) {	
		    case 1 :
		    	MenuKalkulator();
				break;
			case 2 : 
				MenuBangunDatar();
				break;
			case 3 : 
				About();
				break;
			case 4 :
				system("cls");
				puts("\nTerima Kasih sudah menggunakan aplikasi kami..");
				return 0;
				break;
			default :
				puts("\nNomor yang Anda masukkan tidak valid!");
		}
		printf("\n");
		system("PAUSE");
		system("cls");
	}
}
