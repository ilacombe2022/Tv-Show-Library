#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME 256
#define GENRE 128

//Structure of shows we're looking for
typedef struct{
	char name[NAME];
	char genre[GENRE];
	int rating;
	int aired;
}Shows;

//Functions we're using
void printShows(Shows*, int);
void sortRating(Shows*, int);
void sortName(Shows*, int);
void searchShow(Shows*, int);

int main(int argc, char **argv){

	//Opens and read the file name
	FILE * file = fopen(argv[1], "r");

	char c;
	int length = 1;
	int review, choice;

	//File name must be included in the argument where you run the program
	if(argc != 2){
		printf("Error! Usage: <./> <file>\n");
	}

	else{
		//Checks to see if the file exists
		if(!file){
			printf("File not found!\n");
			return 1;
		}
		
		//Reads the first line of the text file
		fscanf(file, "%d", &review);
		
		//Allocates the memory
		Shows *show = malloc(sizeof(Shows) * review);
		
		//Reads every line of the text file by the number of shows
		for(int i = 0; i < review; i++){
			fscanf(file, "%s", show[i].name);
			fscanf(file, "%s", show[i].genre);
			fscanf(file, "%d", &show[i].rating);
			fscanf(file, "%d", &show[i].aired);
		}

		do{
			printf("\nFeel free to explore the library:\n");
			printf("1. Print All Shows\n");
			printf("2. Sort By Rating\n");
			printf("3. Sort By Name\n");
			printf("4. Search Show\n");
			printf("5. Exit\n");
	
			printf("Enter here: ");
			scanf("%d", &choice);

			//Performs the action of the chosen integer
			switch(choice){
				case 1:{
					printShows(show, review);
					break;
				}

				case 2:{
					sortRating(show, review);
					printShows(show, review);
					break;
				}

				case 3:{
					sortName(show, review);
					printShows(show, review);
					break;
				}
				
				case 4:{
					searchShow(show, review);
					break;
				}
			
				case 5:{
					printf("Enjoy your show!\n");
					exit(0);
					break;
				}

				default:{
					printf("Not an option!\n");
					break;
				}
			}
		}while(choice > 0 && choice < 6);

		fclose(file);

		return 0;
	}
}

//Prints out all the shows included in the library
void printShows(Shows *show, int review){
	printf("All Shows:\n\n");

	for(int i = 0; i < review; i++){
		printf("Show Name: %s\n", show[i].name);
		printf("Show Genre: %s\n", show[i].genre);
		printf("Show Rating: %d\n", show[i].rating);
		printf("Show Aired Date: %d\n", show[i].aired);
		printf("\n\n");
	}
}

//Sorts all the shows by rating
void sortRating(Shows *show, int review){
	Shows tempRating;
	
	printf("Shows By Rating\n\n");

	for(int i = 0; i < review; i++){
		for(int j = 0; j < review - i - 1; j++){
			if(show[j].rating > show[j + 1].rating){
				tempRating = show[j];
				show[j] = show[j + 1];
				show[j + 1] = tempRating;
			}
		}
	}
}

//Sorts all the shows by name
void sortName(Shows *show, int review){
	Shows tempName;

	printf("Sort By Name\n\n");

	for(int i = 0; i < review; i++){
		for(int j = 0; j < review - i - 1; j++){
			if(show[j].name[0] > show[j + 1].name[0]){
				tempName = show[j];
				show[j] = show[j + 1];
				show[j + 1] = tempName;
			}

			if(show[j].name[0] == show[j + 1].name[0]){
				if(show[j].name[0] > show[j + 1].name[0]){
					tempName = show[j];
					show[j] = show[j + 1];
					show[j + 1] = tempName;
				}
			}
		}
	}
}

//Searches for a specific show and prints out the structure of that show
void searchShow(Shows *show, int review){
	char showName[NAME];

	printf("Search for a Show: ");

	scanf("%s", showName);

	for(int i = 0; i < review; i++){
		if(strcmp(show[i].name, showName) == 0){
			printf("\nShow Name: %s\n", show[i].name);
			printf("Show Genre: %s\n", show[i].genre);
			printf("Show Rating: %d\n", show[i].rating);
			printf("Show Aired Date: %d\n", show[i].aired);
			printf("\n\n");
			break;
		}
		
		else{
			printf("We do not have a show called '%s'!\n", showName);
			break;
		}

	}
}


