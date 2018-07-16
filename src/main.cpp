#include <iostream>
#include "population.h"
#include <iomanip>
int main(){

  std::string target;
  int pop;
  float mutationRate;
  bool found = false;
  
  //getting desired test case
  std::cout<<"Enter a phrase"<<std::endl;
  std::getline(std::cin, target);
  std::cout<<"Enter a poulation (recommended: 200)"<<std::endl;
  std::cin>>pop;
  std::cout<<"Enter a mutation rate (recommended: 0.01)"<<std::endl;
  std::cin>>mutationRate;

  Population* population = new Population(target, mutationRate, pop);

  //continue running until found
  //Can be changed to stop after a certain amount of generations
  while(found != true){
    population->naturalSelection();
    population->generate();
    population->calcFitness();
  

    //shows all the children of one generation, and the most fit from it
    std::cout<<population->allPhrases()<<std::setw(45)<<std::right<<"Most fit from this generation: "<<population->getBest()<<std::endl;
    
    
    //when the target has been created
    if(population->finished()){
      //display results
      std::cout<<"Total Generations: "<<population->getGeneration()<<std::endl;
      std::cout<<"Average Fitness: "<<population->getAverageFitness()*100<<std::endl;
      std::cout<<"Total Population: "<<pop<<std::endl;
      std::cout<<"Mutation Rate: "<<mutationRate<<std::endl;

      found = true;
      
      //memory allocation
      delete population;
    }
  }

  return 1;

}
