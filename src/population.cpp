#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include "population.h"


//constructor
Population::Population(std::string t, float m, int pop){

  target = t;
  mutation = m;

  //initializing the vector
  for (int i=0;i<pop; i++){
    population.push_back(DNA(target.length()));
  }
  
  //initial calculation
  calcFitness();
  
  done = false;
  generation =0;

}


//go through each string, get the fitness
void Population::calcFitness(){
  for(int i=0;i<population.size();i++){
    population[i].fitnessCalc(target);
  }
}

//creates mating pool
void Population::naturalSelection(){

  matingPool.clear();

  float maxFit =0;
  for(int i=0;i<population.size();i++){
    if(population[i].getFitness() > maxFit){
      maxFit= population[i].getFitness();
    }
  }
  //the higher the fitness, the more likely it is to be selected
  //random probability out of 100
  for (int i=0;i<population.size();i++){
    float fitness = (population[i].getFitness()  / maxFit);
    int n = (int) (fitness * 100);
    for(int j=0;j<n;j++){  
      matingPool.push_back(population[i]);
    }
  }
}

//creating a new generation
void Population::generate(){

  //for every gene combination, create a child
  for(int i=0;i<population.size();i++){

    //random index for each parent
    int a =(int)(random() % (matingPool.size()));
    int b =(int)(random() % (matingPool.size()));

    //child production
    DNA partnerA = matingPool[a];
    DNA partnerB = matingPool[b];
    DNA child = partnerA.crossover(partnerB);
    
    //allows for more variation/ more likely to reach desired outcome
    child.mutate(mutation);
    population[i] = child;
  }
  generation++;
}

//determines if the desired has been reached
std::string Population::getBest(){
  float best =0.0;
  int index =0;
  for(int i=0;i<population.size();i++){

    if(population[i].getFitness() > best){
      index=i;
      best = population[i].getFitness();
    }
  }
  
  //if full match, done
  if(best == 1) done = true;
  return population[index].getPhrase();
}

//divides total fitness by the amount in population
float Population::getAverageFitness(){
  float total =0;
  for(int i=0;i<population.size();i++){
    total +=population[i].getFitness();
  }
  return total / (float) population.size();
}

//combines all phrases into one string to print out
std::string Population::allPhrases() {
  std::string everything = "";

  //should be changed to be however big user wants
  //currently displays either 50 lines or less at once
  int displayLimit = std::min((int)population.size(),50);
  for(int i=0;i<displayLimit;i++){
    everything+= population[i].getPhrase() + "\n";
  }
  return everything;
}
