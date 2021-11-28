# Tubes IF2111 - Mobitangga!

Tugas besar Algoritma dan Struktur Data. 
Mobitangga adalah sebuah permainan dengan konsep seperti permaianan ular tangga yang dapat dimainkan oleh 2 sampai 4 orang. Pemain akan mendapatkan giliran untuk berjalan sesuai dengan angka dari roll. Pemain yang dapat mencapai petak terakhir pada map dengan panjang N terlebih dahulu akan menjadi pemenang dalam permainan ini!
Permainan ini juga menghadirkan fitur-fitur yang dapat digunakan oleh pemain untuk menambah keseruan game. Fitur tersebut terinspirasi dari alat-alat pada film Doraemon yang dapat dijadikan skill untuk tiap pemain. Oleh karena itu, permainan ini disebut sebagai Mobitangga alias jika kita perhatikan, merupakan gabungan dari Doraemon Nobita dan Ular Tangga! Wah seru sekali kan!


# Kelompok 5
-  18217035 - Joe Putera/JhoPutera
-  18220060 - Laksamana Vixell T H/vixelltanjaya
-  18220086 - Aldi Fadlian Sunan/aldifadlian
-  18220090 - Rofif Fairuz H/fairofif
-  18220091 - Rachita Caronica J/rachitacaron
-  18220092 - Thariq Zhafran S/thoriqzs25

# How to Play
1. Pastikan sudah terinstall gcc ataupun mingw
2. Gunakan terminal/shell/commandprompt lalu masuk ke dalam direktori file ini tersimpan
3. Lalu ketik, < cd "...\Tubes_UlarTangga_IF2111\src" && gcc main.c -o main && "...\Tubes_UlarTangga_IF2111\src\"main > pada terminal tanpa tanda < > (isi ... dengan direktori kamu menyimpan file ini)
4. Ketik NEWGAME untuk memulai permainan baru ataupun ketik LOAD untuk memulai permainan dari penyimpanan terakhir
5. Masukkan jumlah pemain yang akan bermain beserta namanya
6. Selamat Anda sudah masuk ke dalam permainan! Pemain akan mendapatkan skill random untuk setiap ronde serta akan ada tantangan lain berupa teleport untuk menambah keseruan dalam permainan
7. Jika Anda kebingungan di tengah permainan, Anda dapat menggunakan command "HELP" untuk melihat panduan yang ada
8. Jika Anda ingin berhenti bermain sementara dan melanjutkan di lain waktu, Anda dapat menggunakan command "SAVE" untuk menyimpan state permainan pada saat itu. Command ini hanya bisa digunakan setelah pemain pada giliran tersebut sudah menjalankan command "ROLL"
9. Pemain yang berhasil mencapai petak terakhir ialah yang menjadi pemenang!

# ADT yang Digunakan
1. ADT Array (Diimplementasikan dengan nama ADT Map)
2. ADT Mesin Kata
3. ADT Mesin Karakter
4. ADT Player
5. ADT List (Untuk skill, diimplementasikan tergabung dengan ADT Player)
6. ADT Stack (Diimplementasikan dengan nama ADT Round)
