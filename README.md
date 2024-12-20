# christmas_counter_c_console
I developed a New Year's timer console application using the C programming language.



## TR:
(2024) c programlama dili dersi aldığım için c programlama dilini öğreniyorum. bende madem öğreniyorum ufakda olsa bişeyler yapmak istedim.
Yılbaşı yaklaşırken iştee size ne kadar zaman kaldığını konsol ekrarında göstericek program 😂😎😁

### hangi kütüphaneler neden kullanıldı?
~time.h kütüphanesi
  veri tipleri: struct tm, time_t
  fonksiyonlar: mktime(), time(), difftime()
  Açıklama: mktime() fonksiyonu struct tm tipinde bir struct alır bu struct'ı time_t tipinde zaman değişkenine çevirir.
  time() fonksiyonu 1900'lerden çalıştırıldığı zamana yani şuana kadar geçen saniyeyi döndürür.
  difftime() fonksiyonu iki tarih arasındaki farkı saniye cinsinden döndürür.
~math.h kütüphanesi
  Açıklama: log10() fonksiyonu girilen sayının 10 tabanında logaritmasını alır.
~ windows.h ve unistd.h kütüphaneleri
  Açıklama: sleep() fonksiyonu girilen saniye kadar programı bekletir.
  Sleep() fonksiyonu girilen milisaniye kadar programı bekletir.


  
### nasıl çalışır?
program algoritması oldukça basittir öyle ki öncelikle yılbaşı(1.1.2025, 0.0) tarihinde bir struct tm değişkeni oluşturuyoruz
ardından mktime() kullanarak bunu time_t tipinde yani 1900 lerden  yılbaşı tarihine kadar geçen saniyeyi hesaplıyoruz.
bir sonraki adımda programın çalıştırıldığı zaman için yani şuan için time_t tipinde geçen saniyeyi alıyoruz.
1900 lerden yılbaşına kadar geçen saniyeden şuana kadar geçen saniyeyi çıkartarak yılbaşına kaç sn kaldığını bulmuş oluyoruz (difftime() fonksiyonu ile)
ardından elimizdeki saniye bilgisini gün saat dakika ve saniye bilgilerine çeviriyoruz.
bir döngüyle bunu her saniye hesaplayıp ekrana yazıcak şekilde ayarlıyoruz. döngünün içinde ekranı temizleyip tekrar yazması için başka bi fonksiyon yazdım.

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

### Nasıl derlenir/kurulur ve çalıştırılır?
öncelikle kaynak dosyasını indirin ve terminalden dosyanın olduğu dizine gelin.
mingw kullanılarak: ```gcc source_app.c -o christmas_counter_app.exe -lm``` (math.h kullanıldığı için -lm bayrağını ekliyoruz)



# EN: 
Since I’m taking a C programming course in 2024, I’m learning the C programming language. I thought, “Well, since I’m learning it, why not create something small?”
So, with the New Year approaching, here’s a program that shows how much time is left until New Year’s on the console screen. 😂😎😁

### Which libraries were used and why?
~time.h library
  Data types: struct tm, time_t
  Functions: mktime(), time(), difftime()
  Explanation: The mktime() function takes a struct of type struct tm and converts it into a time_t time variable.
  The time() function returns the number of seconds that have passed since the 1900s up to the current moment.
  The difftime() function calculates the difference between two dates in seconds.
~math.h library
  Explanation: The log10() function calculates the base-10 logarithm of the given number.
~windows.h and unistd.h libraries
  Explanation: The sleep() function pauses the program for a specified number of seconds.
  The Sleep() function pauses the program for a specified number of milliseconds.


  
### How does it work?
The program’s algorithm is quite simple. First, a struct tm variable is created for New Year’s (January 1, 2025, at 00:00).
Next, the mktime() function is used to calculate the number of seconds from the 1900s to this New Year’s date as a time_t value.
In the following step, the program retrieves the number of seconds that have passed since the 1900s up to the current time using the time() function.
By subtracting the number of seconds elapsed up to the current moment from the seconds elapsed up to New Year’s, the program calculates how many seconds are left until New Year’s (using the difftime() function).
Then, the program converts this remaining seconds value into days, hours, minutes, and seconds.
Finally, using a loop, the program recalculates and displays the countdown every second. I’ve written another function to clear and refresh the screen within this loop.
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

### How to compile/install and run it?
First, download the source file and navigate to the directory where the file is located using the terminal.
Using MinGW: ```gcc source_app.c -o christmas_counter_app.exe -lm``` (Note: The -lm flag is added because the math.h library is used.)
