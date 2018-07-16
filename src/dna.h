#include <cstdlib>
#include <string>

class DNA {

  public:
    DNA(int num);
    std::string getPhrase();
    void fitnessCalc(std::string target);
    DNA crossover(DNA partner);
    void mutate(float mutation);
    float getFitness() { return fitness; } 
  private:
    
    //storage
    std::string genes;

    float fitness;

};


