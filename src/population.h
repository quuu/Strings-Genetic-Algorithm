#include <string>
#include <vector>
#include <cstdlib>
#include "dna.h"

class Population{

  public:
    //CONSTRUCTOR
    Population(std::string t, float m, int pop);

    //EVOLUTION
    void calcFitness();
    void naturalSelection();
    void generate();
    

    float getAverageFitness();
    
    //ACCESSORS
    std::string getBest();
    bool finished();
    int getGeneration();
    std::string allPhrases();
    


  private:
    std::vector<DNA> population;
    float mutation;
    std::vector<DNA> matingPool;
    std::string target;
    int generation;
    bool done;



};


