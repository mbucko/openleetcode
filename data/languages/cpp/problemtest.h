#ifndef PROBLEMTEST_H
#define PROBLEMTEST_H

#include <string>

#include <nlohmann/json.hpp>

class ProblemTest {
  public:
    explicit ProblemTest(const std::string& test_dir_name,
                         const std::string& results_file_name,
                         const std::string& testcase_name,
                         const std::string& testcase_file_name);

    bool run() const;

  private:
    const std::string test_dir_name_;
    const std::string results_file_name_;
    const std::string testcase_name_;
    const std::string testcase_file_name_;

    bool runTest(const std::string& testcase_file_name,
                                  nlohmann::json& test) const;
    
    ProblemTest(const ProblemTest&) = delete;
    ProblemTest& operator=(const ProblemTest&) = delete;
};

#endif // PROBLEMTEST_H