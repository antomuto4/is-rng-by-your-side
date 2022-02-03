#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int health = 100;
int kills; // encounter zombie, take random damage and deal random damage

int prompt;
int r_level;
int c_level;

int rng;
  
int main(){
  printf("\t\033[0;32mHow many \033[0;33mlevels \033[0;31mcan you go through before \033[0;35mfate \033[0;36mchooses not to help you any longer?\n\n");
  printf("\033[0m");

  while(1){
    srand(time(0));
    r_level = rand() % 2;
    rng = rand() % 7;

    printf("\nRNG: %d\nr_level: %d", rng, r_level);
    
    switch(r_level){
    case 0:
      printf("\n\nDo you want to move forward? (enter number)\n1) yes\n2) no\n");
      scanf("%d", &prompt);
      if(prompt == 1){
	printf("\nYou continued to walk..");
	c_level++;
	r_level = rand() % 2;
      }
      
      else if(rng == 0){
	printf("\nYou stood still for a moment to catch your breath, and immediately got bitten by a zombie.");
	printf("\nYou survived for: %d level(s)", c_level);
	return 1;
      }

      else{
	health += 10;
	printf("\nExhaustion was reduced. Health increased by 10. Your health is now at: %d", health);
      }
      
      break;
    case 1:
      printf("\n\nThere is a lake in front of you, do you want to cross it?\nCrossing may decrease your health. Your health is: %i. (enter number)\n1) yes\n2) no\n", health);
      scanf("%d", &prompt);
      if(prompt == 1){
	health -= 10;
	printf("\nYou chose to swim through the lake. You lost 10 hp. Your health is now at: %i", health);
	c_level++;
	r_level = rand() % 2;
      }

      else if(rng == 0){
	printf("You rest for a while. But a zombie jumps out of the water and kills you.");
	printf("\nYou survived for: %d level(s)", c_level);
	return 1;
      }

      else {
	health += 5;
	printf("\nYou stood still for a while and recovered 5 hp. Your health is now at: %d.", health);
      }
      break;
    default:
      return 1;
      break;
    }
  }
    
    return 0;
  }
