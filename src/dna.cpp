#include <iostream>
#include <cstdlib>
#include <string>
#include "dna.h"


//constructor
DNA::DNA(int num){

  genes = std::string(num, ' ');

  //initializing the vector
  for(int i=0;i<num;i++){
    genes[i] = (char) ((rand() % (126-32)) + 32);
  }
}

//calculates fitness by 
//amount of matching characters to target / size of target
void DNA::fitnessCalc(std::string target){

  int score =0;
  for(int i=0;i<genes.size();i++){

    //linear fitness calculation
    //if character is correct, +1 score, total score: length of string
    if(genes[i] == target[i]){
      score++;
    }
  }
  fitness = float(score)/ (float)target.size();
}

//one way of getting new strings, randomly taking a section of
//both parents
//can be implemented with an alternating pattern too
DNA DNA::crossover(DNA partner){

  DNA child = DNA(genes.size());

  //getting index to start using partner's genes
  int splice = (int) (rand() % genes.size() + 1);

  for(int i=0;i<genes.size();i++){
    if(i >splice)
      child.genes[i] = genes[i];
    else            
      child.genes[i] = partner.genes[i];
  }
  return child;
}

//adds some variation to each generation
//for most cases, reduces runtime
void DNA::mutate(float mutation){
  for(int i =0;i<genes.size();i++){

    if(rand() % 100 < mutation * 100){
      genes[i] = (char) ((rand() % (126-32)) + 32);
    }

  }
}
