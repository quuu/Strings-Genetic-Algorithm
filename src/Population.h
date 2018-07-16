#include <string>
#include <vector>
#include <cstdlib>
#include <dna.h>

class Population{

  public:
    Population(std::string t, float m, int pop);
    void calcFitness();
    void naturalSelection();
    void generate();

  private:

    std::vector<DNA> population;
    float mutation;
    std::vector<DNA> matingPool;
    std::string target;
    int generation;
    bool done;
    int perfect;



};


