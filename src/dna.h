#include <cstdlib>
#include <string>

class DNA {

  public:
    //CONSTRUCTOR
    DNA(int num);

    //EVOLUTION
    void fitnessCalc(std::string target);
    DNA crossover(DNA partner);
    void mutate(float mutation);
    
    //ACCESSORS
    float getFitness() { return fitness; } 
    std::string getPhrase() { return genes; }
  
  private:
    
    //storage
    std::string genes;

    float fitness;

};


