//
// Created by Bahattin on 20.12.2024.
//


#include <stdio.h> //printf(), fflush(), stdout
#include <stdlib.h> //malloc(), sizeof()
#include <time.h> //struct tm, time_t, mktime(), time(), difftime()
#include <math.h> // log10()


/*
 * These macros are used to determine which operating system the application is running on.
 *  __unix__ and __unix
 *  __linux__
 *  _WIN32
 *  _WIN64
 *  __APPLE__
 *  __MACH__
 *  __FreeBSD__
 *  __ANDROID__
 *  _POSIX_VERSION
*/


// check operating system
#ifdef _WIN32
	#include <windows.h> //Sleep()
#else
	#include <unistd.h> //sleep()
#endif




struct tm * create_date(int* my_date);
int * calculate_diff(int* diff_arr, time_t end, time_t start);

void clear_screan(int number_of_char);


int main(){
	
	int newyear[] = {2025, 0, 0, 0, 0,0}; 

	
	struct tm * christmas = create_date(newyear);
	time_t t_christmas = mktime(christmas);	
	
	int* diff_arr = (int*) malloc(sizeof(int)*5);
	if(diff_arr == NULL){
		printf("Bellek hatasi");
		return 1;
	}
	
	time_t now;
	while(1){
		time(&now);
		calculate_diff(diff_arr,t_christmas,now);
	
		printf("%d gun, %d saat, %d dakika, %d saniye",
		diff_arr[0],diff_arr[1],
		diff_arr[2],diff_arr[3]);
		fflush(stdout);
		

		#ifdef _WIN32
			Sleep(1000);
		#else
			sleep(1);
		#endif
		
		clear_screan(29 + diff_arr[4]);

	}


 
	free(diff_arr);
	
	return 0;
}

int * calculate_diff(int* diff_arr, time_t end, time_t start){
	
	double diff_time = difftime(end, start);
	
	// for example: diff_time = 17*24*60*60 + 20*60*60 47*60 + 7
	double temp = diff_time;
	int second = (int) temp%60; // 7
	temp /= 60; // 17*24*60 + 20*60 + 47
	int minute = (int) temp%60; // 47
	temp /= 60; // 17*24 + 20
	int hour = (int) temp%24; // 20
	temp /= 24; // 17
	int day = temp;
	
	
	diff_arr[0] = day;
	diff_arr[1] = hour;
	diff_arr[2] = minute;
	diff_arr[3] = second;
	
	// "The sum of the digits of all the numbers separately
	// tr: tüm sayıların ayrı ayrı basamak sayılarının toplamı
	diff_arr[4] = ((int)log10(day)) + ((int)log10(hour)) +
		      ((int)log10(minute)) + ((int)log10(second)) + 4;
	
	return diff_arr;



}

struct tm *create_date(int *my_date){
	/*
	  my_date: d notation
	  d[0] = year
	  d[1] = month
	  d[2] = day
	  d[3] = hour
	  d[4] = minute
	  d[5] = second
	*/

	static struct tm newdate = {0}; // create new struct tm variable and all variables equalized to zero
	newdate.tm_year = my_date[0] - 1900; // 1900 is beginning year
	newdate.tm_mon  = my_date[1];
	newdate.tm_mday = my_date[2];
	newdate.tm_hour = my_date[3];
	newdate.tm_min  = my_date[4];
	newdate.tm_sec  = my_date[5];

	return &newdate;
}

void clear_screan(int number_of_char){
	while( number_of_char != 0 ){
		printf("\b");
		number_of_char--;
	}


}
