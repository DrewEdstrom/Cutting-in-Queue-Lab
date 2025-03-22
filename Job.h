#include <iostream>

class Job
{
private:
  std::string name;
  int priority;

public:
  Job(std::string n, int p) : name(n), priority(p) {}

  //determines if a Job is greater than another based upon its priority
  //number
  bool operator >(const Job &other) const
  {
    return priority > other.getPriority();
  }

  //determines if a Job is less than another based upon its priority number
  bool operator <(const Job &other) const
  {
    return priority < other.getPriority();
  }

  inline void execute() const
  {
    std::cout << "Running the job with name "
              << name
              << " and priority "
              << priority;
  }

  inline std::string getName() const
  {
    return name;
  }

  inline int getPriority() const
  {
    return priority;
  }
};
