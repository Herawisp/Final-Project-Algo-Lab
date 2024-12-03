#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct alamat{
	char provinsi[50];
	char kota[50];
	char kecamatan[50];
	char kelurahan[50];
	
};


struct UserInfo{
	char username[30];
	struct alamat address;
	char password[15];
	char nomortelepon[14];
};

void SignIn() {
    char username[30], password[15];
    char line[200]; // Buffer untuk membaca setiap baris file
    int found = 0;  // Flag untuk mengecek apakah data ditemukan
    do{
	system("cls");
    printf("Masukkan username: ");
    getchar();
    scanf("%[^\n]", username); // Mengambil input username
    printf("Masukkan password: ");
    scanf("%s", password); // Mengambil input password

    FILE *file = fopen("UserInfo.txt", "r"); // Membuka file dalam mode baca
    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    // Membaca file baris demi baris
    while (fgets(line, sizeof(line), file)) {
        char *file_username = strtok(line, "|");   // Ambil username
        char *file_provinsi = strtok(NULL, "|");  // Skip provinsi
        char *file_kota = strtok(NULL, "|");      // Skip kota
        char *file_kecamatan = strtok(NULL, "|"); // Skip kecamatan
        char *file_kelurahan = strtok(NULL, "|"); // Skip kelurahan
        char *file_password = strtok(NULL, "|"); // Ambil password
        char *file_nomor = strtok(NULL, "\n");   // Skip nomor telepon

        // Bandingkan username dan password
        if (strcmp(username, file_username) == 0 && strcmp(password, file_password) == 0) {
            found = 1;
            break;
        }
    }

    fclose(file); // Menutup file

    if (found) {
    	DisplayUserMenu();
    } else {
        printf("Username atau password salah. Silakan coba lagi.\n");
    }
}while(!found);
    
}

void SignUp(){
	struct UserInfo Signup;
	FILE *file = fopen("UserInfo.txt", "a"); 

    if (file == NULL) {
        printf("Gagal membuka file untuk menulis.\n");
        return;
    }
	system("cls");
	getchar();
	printf("Masukkan nama anda: ");
	scanf("%[^\n]", Signup.username);
	getchar();
	if(strlen(Signup.username)<3 || strlen(Signup.username)> 30 ){
		do{
	 	printf("\033[1A");  
  		  printf("\033[K"); 
  		  printf("Panjang nama harus lebih dari 3 atau kurang dari 30, silahkan masukkan kembali :");
  		  scanf("%[^\n]", Signup.username);
  		  getchar();
		}while(strlen(Signup.username)<3 || strlen(Signup.username)> 30 );
	}
	
	printf("Masukkan Provinsi asal anda: ");
	scanf("%[^\n]",Signup.address.provinsi);
	getchar();
	if(strlen(Signup.address.provinsi)<3 || strlen(Signup.address.provinsi)> 50 ){
		do{
		
	 	printf("\033[1A");  
  		  printf("\033[K"); 
  		  printf("Panjang nama provinsi harus lebih dari 3 atau kurang dari 50, silahkan masukkan kembali :");
  		  scanf("%[^\n]", Signup.address.provinsi);
  		  getchar();
		}while(strlen(Signup.address.provinsi)<3 || strlen(Signup.address.provinsi)> 50 );
	}
	
	printf("Masukkan kota asal anda: ");
	scanf("%[^\n]",Signup.address.kota);
			getchar();
		if(strlen(Signup.address.kota)<3 || strlen(Signup.address.kota)> 50 ){
		do{
		
	 		printf("\033[1A");  
  		  printf("\033[K"); 
  		  printf("Panjang nama kota harus lebih dari 3 atau kurang dari 50, silahkan masukkan kembali :");
  		  scanf("%[^\n]", Signup.address.kota);
  		  getchar();
		}while(strlen(Signup.address.kota)<3 || strlen(Signup.address.kota)> 50 );
	}
	
	printf("Masukkan kecamatan asal anda: ");
	scanf("%[^\n]",Signup.address.kecamatan);
	getchar();
	
	if(strlen(Signup.address.kecamatan)<3 || strlen(Signup.address.kecamatan)> 50 ){
		do{
		
	 		printf("\033[1A");  
  		  printf("\033[K"); 
  		  printf("Panjang nama kecamatan harus lebih dari 3 atau kurang dari 50, silahkan masukkan kembali :");
  		  scanf("%[^\n]", Signup.address.kecamatan);
  		  getchar();
		}while (strlen(Signup.address.kecamatan)<3 || strlen(Signup.address.kecamatan)> 50 );
	}
	
	printf("Masukkan kelurahan asal anda: ");
	scanf("%[^\n]",Signup.address.kelurahan);
	getchar();
	
		if(strlen(Signup.address.kelurahan)<3 || strlen(Signup.address.kelurahan)> 50 ){
		do{
			
	 		printf("\033[1A");  
  		  printf("\033[K"); 
  		  printf("Panjang nama kelurahan harus lebih dari 3 atau kurang dari 50, silahkan masukkan kembali :");
  		  scanf("%[^\n]", Signup.address.kelurahan);
  		  getchar();
		}while(strlen(Signup.address.kelurahan)<3 || strlen(Signup.address.kelurahan)> 50 );
	}
	
	printf("Masukkan password akun : ");
	scanf("%[^\n]",Signup.password);
	getchar();
	if(strlen(Signup.password)<3 || strlen(Signup.password)> 15 ){
		do{
		
	 		printf("\033[1A");  
  		  printf("\033[K"); 
  		  printf("Panjang password harus lebih dari 3 atau kurang dari 15, silahkan masukkan kembali :");
  		  scanf("%[^\n]", Signup.password);
  		  getchar();
		}while(strlen(Signup.password)<3 || strlen(Signup.password)> 50 );
	}
	printf("Masukkan nomor telepon anda : ");
	scanf("%s", Signup.nomortelepon);

	if(strlen(Signup.nomortelepon)<10 || strlen(Signup.nomortelepon)> 15 ){
		do{
		
	 		printf("\033[1A");  
  		  printf("\033[K"); 
  		  printf("Panjang nomor harus lebih dari 10 atau kurang dari 15, silahkan masukkan kembali :");
  		  scanf("%s", Signup.nomortelepon);
  		  getchar();
		}while(strlen(Signup.nomortelepon)<10 || strlen(Signup.nomortelepon)> 15 );
	}
	fprintf(file, "%s|%s|%s|%s|%s|%s|%s\n", 
            Signup.username, 
            Signup.address.provinsi, 
            Signup.address.kota, 
            Signup.address.kecamatan, 
            Signup.address.kelurahan, 
            Signup.password, 
            Signup.nomortelepon);

    fclose(file);  
		SignIn();
	}




void DisplayUserAccount(){
	int input;
	do {
		system("cls");
		printf("1). Sign In\n");
		printf("2). Sign Up\n");
		printf("Pilih opsi (1-2): ");
		scanf("%d", &input);
	}while(input >2 || input <1);
	
	switch (input) {
		case 1 :  SignIn(); break;
		case 2 :  SignUp(); break;
	}
}


