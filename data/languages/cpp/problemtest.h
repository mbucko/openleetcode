#ifndef PROBLEMTEST_H
#define PROBLEMTEST_H

#include <fstream>

class ProblemTest {
  public:
    explicit ProblemTest(std::ifstream in, std::ofstream out);

  bool run();

  private:
    std::ifstream in_;
    std::ofstream out_;
    
    ProblemTest(const ProblemTest&) = delete;
    ProblemTest& operator=(const ProblemTest&) = delete;
};

#endif // PROBLEMTEST_H