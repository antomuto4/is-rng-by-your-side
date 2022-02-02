#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int health = 100;
int kills;

int prompt;
int r_level;
int c_level;
  
int main(){

  while(1){
    srand(time(0));
    r_level = rand() % 2;
    
    switch(r_level){
    case 0:
      printf("\n\nDo you want to move forward? (enter number)\n1) yes\n2) no\n");
      scanf("%d", &prompt);
      if(prompt == 1){
	printf("\nYou continued to walk..");
	c_level++;
	r_level = rand() % 2;
    }
      
      else {
	printf("\nYou stood still for a moment to catch your breath, and immediately got bitten by a zombie.");
	printf("\nYou survived for: %d level(s)", c_level);
	return 1;
      }
      
      break;
    case 1:
      printf("\n\nThere is a lake in front of you, do you want to cross it?\nCrossing it may decrease your health and cause suffication. Your health is: %i. What will you choose? (enter number)\n1) yes\n2) no\n", health);
      scanf("%d", &prompt);
      if(prompt == 1){
	health -= 10;
	printf("\nYou chose to swim through the lake. You lost 10 hp. Your health is now at: %i", health);
	c_level++;
	r_level = rand() % 2;
      }

      else {
	health + 5;
	printf("\nYou stood still for a while and recovered 5 hp. Your health is now at: %i. But you got killed anyway because you waited too long.", health);
	printf("\nYou survived for: %d level(s)", c_level);
	return 1;
      }
      break;
    default:
      return 1;
      break;
    }
  }
    
    return 0;
  }
