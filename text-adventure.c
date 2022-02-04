#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int health = 100;
int kills; // encounter zombie, take random damage and deal random damage

int prompt;
int r_level;
int c_level;

int rng;

void setup(){
    srand(time(0));
    r_level = rand() % 3;
    rng = rand() % 7; 
}

void next(int num){
  c_level++;
  r_level = rand() % num;
}

void game_over(){
  printf("\nYou survived for: %d level(s)\n", c_level);
  health = 100;
  c_level = 0;
}

int game_loop(){
  
  setup();
  
  switch(r_level){
  case 0:
    printf("\n\nDo you want to move forward? (enter number)\n\x1B[32m1) yes\n\x1B[31m2) no\n\033[0m");
    scanf("%d", &prompt);
    if(prompt == 1){
      printf("\nYou continued to walk..");
	next(3);
    }
    
    else if(rng == 0){
      printf("\nYou stood still for a moment to catch your breath, and immediately got bitten by a zombie.");
      game_over();
      return 1;
    }
    
    else{
	health += 10;
	printf("\nExhaustion was reduced. Health increased by 10. Your health is now at: %d", health);
      }
    
    break;
  case 1:
    printf("\n\nThere is a lake in front of you, do you want to cross it?\nCrossing may decrease your health. Your health is: %i. (enter number)\n\x1B[32m1) yes\n\x1B[31m2) no\n\033[0m", health);
    scanf("%d", &prompt);
    if(prompt == 1){
      health -= 10;
      printf("\nYou chose to swim through the lake. You lost 10 hp. Your health is now at: %i", health);
      next(3);
    }
    
    else if(rng == 0){
      printf("You rest for a while. But a zombie jumps out of the water and kills you.");
      game_over();
      return 1;
    }
    
    else {
      health += 5;
      printf("\nYou stood still for a while and recovered 5 hp. Your health is now at: %d.", health);
    }
    break;
    
  case 2:      
    printf("\nYou found an airport. It's possible to find weapons in this area, but it's easy to get spotted. (enter number)\n\x1B[32m1) look around\n\x1B[31m2) forget it\n\033[0m");
    scanf("%d", &prompt);
    
    if(prompt == 1){
      printf("\nYou scan the area..\nThere lies a security guard on the ground, will you search it? (enter number)\n\x1B[32m1) search body\n\x1B[31m2) nevermind, get the hell out of here\n\033[0m");
      scanf("%d", &prompt);
      
      if(prompt == 1){
	if(rng == 0){
	  printf("\nThe zombie woke up and bit you to death.\n");
	  game_over();
	  return 1;
	}
	
	else{
	  printf("\nYou got \x1B[34m<item>\033[0m, this may come in use in the future.");
	  next(3);
	}
      }
    }
    
    
    else{
      next(3);
    }
    
    break;
  default:
    return 1;
    
    break;
  }
  
}

int main(){
  printf("\t\033[0;32mHow many \033[0;33mlevels \033[0;31mcan you go through before \033[0;35mfate \033[0;36mchooses not to help you any longer?\n\n");
  printf("\033[0m");
  
  while(1){
    game_loop();
  }
  
  return 0;
}
